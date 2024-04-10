#include "cgloble.h"

#ifdef WIN32
#include <windows.h>
#pragma comment(lib, "version.lib")
#pragma comment(lib,"ws2_32.lib")
#endif

CGloble g_Globle;

QString TypeName[] = {  CH("普通用户"),  CH("管理员"),  CH("超级管理员"),  CH("书籍录入员") };
QString BookType[] = { CH("全开"), CH("对开")};
QString StaffType[] = {  CH("工人"),  CH("师傅") ,  CH("师傅+工人")};
QString ZyType[] = { CH("全开四折页"), CH("四折页"), CH("大三折页"), CH("三折页"), CH("二折页")};
QString rkType[] = {CH("未入"),CH("已入")};
QString proNumType[] = {CH("印数"),CH("令数")};
QString proStaffType[] = {CH("是"),CH("否")};
QString DateName[] = {CH("全部"),CH("最近一周"), CH("最近一个月"), CH("最近三个月"), CH("半年内"), CH("一年内")};

DWORD WINAPI hreatThread(LPVOID lpParam);
CGloble::CGloble(QObject *parent)
	: QObject(parent),m_Client(this)
{
	m_state = NET_STATE_MAX;
	m_psetting = nullptr;
	m_heart = INVALID_HANDLE_VALUE;
	m_hExit = CreateEvent(NULL,TRUE,FALSE,NULL);//初始无信号
	m_pCallBack = NULL;
	m_pHand = NULL;
	m_bAsyncConn = FALSE;
	dbVtor = new QDoubleValidator;
	itVtor = new QIntValidator;
	QRegExp regx("[a-zA-Z0-9]+$");
	nzVtor = new QRegExpValidator(regx);
}

CGloble::~CGloble()
{
	if (m_psetting)
	{
		delete m_psetting;
		m_psetting = nullptr;
	}
	SetEvent(m_hExit);
	if (m_heart != INVALID_HANDLE_VALUE)
	{
		WaitForSingleObject(m_heart,INFINITE);
		m_heart = INVALID_HANDLE_VALUE;
	}
	m_Client->Stop();
	if(m_hExit)   
		CloseHandle(m_hExit);

	delete dbVtor;
}

QString CGloble::version()
{
#ifdef WIN32
	char szFilePath[MAX_PATH + 1] = { 0 };
	GetModuleFileNameA(NULL, szFilePath, MAX_PATH);

	QString result = "";
	QString fullName = QString::fromUtf8(szFilePath);
	char* pData = nullptr;
	do
	{
		unsigned int dwLen = GetFileVersionInfoSize(fullName.toStdWString().c_str(), 0);
		if (0 == dwLen)
		{
			break;
		}
		pData = new char[dwLen + 1];
		BOOL bSuccess = GetFileVersionInfo(fullName.toStdWString().c_str(), 0, dwLen, pData);
		if (!bSuccess)
		{
			break;
		}

		VS_FIXEDFILEINFO* pVsInfo;
		if (VerQueryValueA(pData, "\\VarFileInfo\\Translation", (void**)&pVsInfo, &dwLen))
		{
			unsigned int version_len = 0;
			if (VerQueryValueA(pData, "\\", (void**)&pVsInfo, &version_len))
			{
				sprintf(pData, "%d.%d.%d.%d", HIWORD(pVsInfo->dwFileVersionMS), LOWORD(pVsInfo->dwFileVersionMS), HIWORD(pVsInfo->dwFileVersionLS), LOWORD(pVsInfo->dwFileVersionLS));
				result = pData;
			}
		}
	} while (0);

	if (nullptr != pData)
	{
		delete pData;
	}

	auto v = result.split(".");
	if (v.length() == 4)
	{
		result = QString("%1.%2.%3").arg(v[0]).arg(v[1]).arg(v[2]);
	}
	return result;
#else
	return "";
#endif
}

bool CGloble::InitGloble()
{
	QString strIniPathName = qApp->applicationDirPath() + "/config/config.ini";
	QFileInfo Finfo (strIniPathName);
	if (!Finfo.isFile())
	{
		::MessageBox(NULL,L"找不到配置文件",L"错误",NULL);
		return false;
	}
	else
	{
		m_psetting = new QSettings(strIniPathName, QSettings::IniFormat);
		m_psetting->setIniCodec(QTextCodec::codecForName("GB2312"));

		m_strIP = GetIniValue("SOCKET","ip").toString();
		m_nPort = GetIniValue("SOCKET","port").toInt();
		m_strName = GetIniValue("SOCKET","name").toString();
		m_strTitle = GetIniValue("SOCKET","title").toString();
		m_strVersion = version();// GetIniValue("SOCKET", "verson").toString();
		return true;
	}
}

//按钮图片切片
void CGloble::SetButtonStyle(QPushButton *button, QString imgsrc, int CutSec)  
{  
	int img_w=QPixmap(imgsrc).width();  
	int img_h=QPixmap(imgsrc).height();  
	int PicWidth = img_w/CutSec;  
	button->setFixedSize(PicWidth,img_h);  
	button->setStyleSheet(QString("QPushButton{color: rgb(255, 255, 255);border-width: %1px; border-image: url(%2)  0 0 0 %3 repeat  repeat;border-width: 0px; border-radius: 0px;}")  
		.append("QPushButton::hover{border-image: url(%2) 0 0 0 %4  repeat  repeat;}")  
		.append("QPushButton::checked{border-image: url(%2) 0  0 0 %4 repeat  repeat;}")
		.append("QPushButton::pressed{border-image: url(%2) 0  0 0 %5 repeat  repeat;}")  
		.arg(img_w).arg(imgsrc).arg(0).arg(PicWidth*1).arg(PicWidth*2));  
}

void CGloble::SetEditOnlyNumber(QLineEdit* lineEdit, QObject* ts)
{
	QRegExp regx("[0-9]+$");
	lineEdit->setValidator(new QRegExpValidator(regx, ts));
}

void CGloble::SetIniValue(QString qstrnodename,QString qstrkeyname,QVariant qvarvalue)
{
	if (m_psetting)
		m_psetting->setValue(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname), qvarvalue);
}

QVariant CGloble::GetIniValue(QString qstrnodename,QString qstrkeyname)
{
	QVariant qvar;
	if (m_psetting)
	{
		qvar = m_psetting->value(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname));
	}
	return qvar;
}

void CGloble::DoRun(string strData)
{
	try
	{
		if (m_pCallBack && m_pHand)
		{
			m_pCallBack(m_pHand,strData);
		}
	}
	catch (...)
	{
	}
}

EnHandleResult CGloble::OnConnect(ITcpClient* pSender, CONNID dwConnID)
{
	return HR_OK;
}

EnHandleResult CGloble::OnSend(ITcpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
	return HR_OK;
}

EnHandleResult CGloble::OnReceive(ITcpClient* pSender, CONNID dwConnID, int iLength)
{
	ITcpPullClient* pClient	= ITcpPullClient::FromS(pSender);

	int required = m_pkgInfo.length;
	int remain = iLength;

	while(remain >= required)
	{
		remain -= required;
		CBufferPtr buffer(required);

		EnFetchResult result = pClient->Fetch(buffer, (int)buffer.Size());
		if(result == FR_OK)
		{
			if(m_pkgInfo.is_header)
			{
				TPkgHeader* pHeader = (TPkgHeader*)buffer.Ptr();
				required = pHeader->body_len;
			}
			else
			{
				TPkgBody* pBody = (TPkgBody*)buffer.Ptr();
				DoRun(pBody->desc);

				required = sizeof(TPkgHeader);
			}

			m_pkgInfo.is_header	= !m_pkgInfo.is_header;
			m_pkgInfo.length	= required;
		}
	}
	return HR_OK;
}

EnHandleResult CGloble::OnClose(ITcpClient* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	m_state = NET_STATE_CLOSE;
	emit sgl_ConnectState(m_state);
	return HR_OK;
}

std::string CGloble::parseIp(const char* adress)
{
#ifdef WIN32
	struct hostent* hptr = gethostbyname(adress);
	if (hptr == nullptr)
		return nullptr;
	else
	{
		char ip[20];
		memset(ip, 0, 20);
		memcpy(&ip, inet_ntoa(*((struct in_addr*)hptr->h_addr_list[0])), 20);
		std::string strIp = ip;
		return strIp;
	}
#else

#endif
}

bool CGloble::ConnectSer()
{
	m_pkgInfo.Reset();
	
	const ushort* str = m_strIP.utf16();
	const wchar_t* p = (const wchar_t*)str;

	m_strIP = "127.0.0.1";
	m_nPort = 48467;

	std::string ip = parseIp(m_strIP.toStdString().c_str());
	BOOL bRet = m_Client->Start((LPCTSTR)ip.c_str(), m_nPort, m_bAsyncConn);
	if(bRet)
	{
		if (m_heart == INVALID_HANDLE_VALUE)
		{
			m_heart = CreateThread(NULL,0,hreatThread,this,NULL,0);
		}
		m_state = NET_STATE_OK;
	}
	else
		m_state = NET_STATE_CLOSE;

	emit sgl_ConnectState(m_state);
	return bRet;
}

void CGloble::SetCallback(FUN_CALLBACK callback,void* param)
{
	m_pCallBack = callback;
	m_pHand = param;
}

string CGloble::GetAppDataPath()
{
	USES_CONVERSION;
	TCHAR szPath[MAX_PATH];
	memset(szPath,0,MAX_PATH);
	string strPath;
#ifdef _DEBUG
	GetCurrentDirectory(MAX_PATH,szPath);//获取当前工作路径
	strPath = W2A(szPath);
#else
	GetModuleFileName(NULL,szPath,MAX_PATH);
	string str = W2A(szPath);
	int ndex = str.rfind('\\');
	strPath=str.substr(0,ndex);
#endif
	return strPath;
}

string CGloble::GetLogFileName()
{
	static string file;
	if(file.empty())
	{
		char tmp[1024]={0};
		sprintf(tmp,"%s\\Log\\",GetAppDataPath().c_str());
		::CreateDirectoryA(tmp,0);
		m_LogRootPath = tmp;

		time_t t;
		tm* time2;
		t=time(NULL);
		time2=localtime(&t);
		sprintf(tmp+strlen(tmp),"%04d%02d%02d.log",time2->tm_year+1900,time2->tm_mon+1,time2->tm_mday);
		file=tmp;
	}
	return file;
}

void Log(char* fmt, ...)
{
	va_list args;
	va_start (args, fmt);
	char* tmp=new char[1024*10];
	memset(tmp,0,1024*10);
	vsprintf(tmp,fmt, args);

	time_t t;
	tm* time2;
	t=time(NULL);
	time2=localtime(&t);
	FILE* fp=fopen(g_Globle.m_LogPath.c_str(),"a+");
	if(fp)
	{
		int len = strlen(tmp);
		char *ctmp=new char[len+1024];
		memset(ctmp,0,len+1024);
		sprintf(ctmp,"%04d/%02d/%02d %02d:%02d:%02d\t%s\n",time2->tm_year+1900,time2->tm_mon+1,time2->tm_mday,time2->tm_hour,time2->tm_min,time2->tm_sec,tmp);
		cout<<ctmp;
		fprintf(fp,ctmp);
		fclose(fp);
		delete[] ctmp;
	}
#ifdef DEBUG_LOG
	string str=tmp;
	str+="\r\n";
	::OutputDebugStringA(str.c_str());
#endif

	delete[] tmp;
	va_end(args);
}

int CGloble::SendTo(string strData)
{
	static DWORD SEQ = 0;//流水号
	LPCSTR desc = strData.c_str();
	int desc_len = (int)strlen(desc) + 1;
	int body_len = offsetof(TPkgBody, desc) + desc_len;

	TPkgHeader header;
	header.seq = ++SEQ;
	header.em_LinkType = LINK_TYPE_CLIENT;
	header.body_len = body_len;

	//TPkgBody* pBody = (TPkgBody*)_alloca(body_len);
	TPkgBody* pBody = new TPkgBody[body_len];
	memset(pBody, 0, body_len);
	strcpy(pBody->desc, desc);

	WSABUF bufs[2];
	bufs[0].len = sizeof(TPkgHeader);
	bufs[0].buf = (char*)&header;
	bufs[1].len = body_len;
	bufs[1].buf = (char*)pBody;

	if (m_Client->SendPackets(bufs, 2))
	{
		delete[] pBody;
		return 0;
	}
	else
	{
		delete[] pBody;
		int err = ::SYS_GetLastError();
		Log("send error：%d",err);
		return  err;
	}
}

DWORD WINAPI hreatThread(LPVOID lpParam)
{
	CGloble* pGloble = (CGloble*)lpParam;
	DWORD dw = WaitForSingleObject(pGloble->m_hExit,2000);
	while (dw != WAIT_OBJECT_0)
	{
		EnServiceState state = pGloble->m_Client->GetState();
		if (state == SS_STOPPED)
		{
			pGloble->ConnectSer();
		}
		dw = WaitForSingleObject(pGloble->m_hExit,2000);
	}
	return 0;
}

int CGloble::GetDays(int year,int month)
{
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			return 29;
		else 
			return 28;
	}
	switch (month)
	{
	case 1:return 31;
	case 3:return 31;
	case 4:return 30;
	case 5:return 31;
	case 6:return 30;
	case 7:return 31;
	case 8:return 31;
	case 9:return 30;
	case 10:return 31;
	case 11:return 30;
	case 12:return 31;
	}
	return 0;
}