#include "CTabProcessDlg.h"

void ProcessCallback(void* p,string strData)
{
	CTabProcessDlg* pThis=(CTabProcessDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CTabProcessDlg::st_CalBak(void* pdata)
{
	string* pStrData = (string*)pdata;
	Json::Reader r;
	Json::Value root;
	r.parse(*pStrData,root);
	delete pStrData;

	EM_SOCK_CMD cmd = (EM_SOCK_CMD)root[CONNECT_CMD].asInt();
	EM_CMD_RET ret = (EM_CMD_RET)root[CMD_RetType[EM_CMD_RETYPE_RESULT]].asInt();

	switch (cmd)
	{
	case SOCK_CMD_GET_SAMPLE_BOOK:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取图书信息失败！"));
			else
				GetBook(root);
		}
		break;
	case SOCK_CMD_GET_PROJECT:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取项目信息失败！"));
			else
				GetProject(root);
		}
		break;
	case SOCK_CMD_GET_PROGRESS:
		{
			Json::FastWriter writer;  
			string temp = writer.write(root);

			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取进度信息失败！"));
			else
				GetProgress(root);
		}
		break;
	default:
		break;
	}
}

CTabProcessDlg::CTabProcessDlg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(this,&CTabProcessDlg::sg_CalBak,this,&CTabProcessDlg::st_CalBak);
	connect(ui.cbx_rk,SIGNAL(currentIndexChanged(int)),this,SLOT(st_rkCbxChanged(int)));
	connect(ui.cbx_book,SIGNAL(currentIndexChanged(int)),this,SLOT(st_bookCbxChanged(int)));
	CGloble::SetButtonStyle(ui.BTN_UPDATE,":/PayCount_QT/pic/ok.png",3);

	//初始化入库combox
	ui.cbx_rk->addItem(CH("全部"));
	for (int i=0;i<BOOK_RK_MAX;i++)
	{
		ui.cbx_rk->addItem(rkType[i]);
	}
	ui.cbx_rk->setCurrentIndex(1);
	ui.cbx_book->setMaxVisibleItems(40);
	pageIn();
}

CTabProcessDlg::~CTabProcessDlg()
{

}

void CTabProcessDlg::InitListCtrl()
{
	ui.tableWidget->clear();

	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选择
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑
	ui.tableWidget->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget->setFocusPolicy(Qt::NoFocus); //去除选中虚线框
	ui.tableWidget->setFrameShape(QFrame::NoFrame); //设置边框
	ui.tableWidget->setMouseTracking(true);
	//ui.tableWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
	ui.tableWidget->verticalHeader()->setVisible(false); //设置垂直头不可见
	ui.tableWidget->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色


	//设置水平、垂直滚动栏样式
	ui.tableWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	ui.tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");

	QStringList strList;
	strList<<CH("印数")<<CH("令数");
	int nSize = m_vPro.size();
	for (int i=0;i<nSize;i++)
	{
		strList<<m_vPro[i].strName;
	}
	ui.tableWidget->setColumnCount(2+nSize); 
	ui.tableWidget->setHorizontalHeaderLabels(strList);
	ui.tableWidget->setRowCount(20);
	SetListCtrlValue();
}

void CTabProcessDlg::SetListCtrlValue()
{
	ui.tableWidget->clearContents();
	//基本信息
	CString str,strBookID;
	int ndex = ui.cbx_book->currentIndex();
	if (ndex>=0)
	{
		QVariant vt = ui.cbx_book->itemData(ndex);
		QString strBookID = vt.value<QString>();
		SendToGetProgress(strBookID);
	}
}

void CTabProcessDlg::pageIn()
{
	g_Globle.SetCallback(ProcessCallback,this);
	SendToGetBook();
}

void CTabProcessDlg::st_BtnUpdate()
{
	pageIn();
}

void CTabProcessDlg::st_rkCbxChanged(int ndex)
{
	SendToGetBook();
}

void CTabProcessDlg::st_bookCbxChanged(int ndex)
{
	if(ndex>=0)
	{
		QVariant vt = ui.cbx_book->itemData(ndex);
		m_LastBookID = vt.value<QString>();
	}
	InitListCtrl();
}

void CTabProcessDlg::GetBook(Json::Value root)
{
	m_vet.clear();
	ui.cbx_book->clear();
	Json::FastWriter writer;  
	string temp = writer.write(root);

	int nCount = root[CMD_BOOKMSG[BOOKMSG_COUNT]].asInt();
	for (int i=0;i<nCount;i++)
	{
		char str[125]={0};
		BOOK_STU stu;
		Json::Value one = root[itoa(i,str,10)];

		stu.strBookID=one[CMD_BOOKMSG[BOOKMSG_ID]].asCString();
		const char* cstr = one[CMD_BOOKMSG[BOOKMSG_NAME]].asCString();
		stu.strname=CH(cstr);

		m_vet.push_back(stu);
	}
	nCount = m_vet.size();
	int nFindex = 0;
	for (int i = 0; i < nCount; i++)
	{
		QVariant vt;
		vt.setValue<QString>(m_vet[i].strBookID);
		ui.cbx_book->addItem(m_vet[i].strname,vt);
		if(m_LastBookID == m_vet[i].strBookID)
			nFindex = i;
	}
	if (nCount>0)
	{
		ui.cbx_book->setCurrentIndex(nFindex);
	}

	//发送获取项目的网络请求
	SendToGetPro();
}

void CTabProcessDlg::GetProject(Json::Value root)
{
	m_vPro.clear();
	Json::FastWriter writer;  
	string temp = writer.write(root);

	int nCount = root[CMD_PROMSG[EM_PROMSG_COUNT]].asInt();
	for (int i=0;i<nCount;i++)
	{
		char str[25]={0};
		PROJECT_STU stu;
		Json::Value one = root[itoa(i,str,10)];

		stu.nID=one[CMD_PROMSG[EM_PROMSG_ID]].asInt();
		const char* cstr = one[CMD_PROMSG[EM_PROMSG_NAME]].asCString();
		stu.strName=CH(cstr);
		stu.pn_type=(PRO_NUM_TYPE)one[CMD_PROMSG[EM_PROMSG_NUM_TYPE]].asInt();
		stu.ps_type=(PRO_STAFF_TYPE)one[CMD_PROMSG[EM_PROMSG_BWRITE]].asInt();
		stu.ndex=one[CMD_PROMSG[EM_PROMSG_NDEX]].asInt();
		//按ndex从小到大排列
		if(m_vPro.size() == 0)
			m_vPro.push_back(stu);
		else
		{
			bool bInset=false;
			vector <PROJECT_STU>::iterator it;
			for ( it = m_vPro.begin( ) ; it != m_vPro.end( ) ; it++ )
			{
				if (stu.ndex<(*it).ndex)
				{
					bInset = true;
					m_vPro.insert(it,stu);
					break;
				}
			}
			if(!bInset)
				m_vPro.push_back(stu);
		}
	}
	InitListCtrl();
}

void CTabProcessDlg::GetProgress(Json::Value root)
{
	QString str;
	int ys = root[CMD_PROGRESSMSG[EM_PROGRESSMSG_YS]].asInt();
	double fls = root[CMD_PROGRESSMSG[EM_PROGRESSMSG_YS]].asDouble();

	str = QString("%1").arg(ys);
	ui.tableWidget->setItem(0,0,new QTableWidgetItem(str));//印数
	str = QString::number(fls,'f',2);
	ui.tableWidget->setItem(0,1,new QTableWidgetItem(str));//令数

	if(root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		Json::Value jss=root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
		if (jss.isArray())
		{
			for (int i=0;i<jss.size();i++)
			{
				double number=0;
				int ndex = jss[i][CMD_PROGRESSMSG[EM_PROGRESSMSG_NDEX]].asInt();
				number = jss[i][CMD_PROGRESSMSG[EM_PROGRESSMSG_NUMBER]].asDouble();

				str = QString::number(number,'f',2);
				ui.tableWidget->setItem(0,ndex,new QTableWidgetItem(str));
			}
		}
	}
}

void CTabProcessDlg::SendToGetBook()
{
	BOOK_RK em_rk;
	int ndex = ui.cbx_rk->currentIndex();
	if (ndex == 0)
		em_rk = BOOK_RK_MAX;
	else
		em_rk = BOOK_RK(ndex -1);

	int n = 0;

	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_SAMPLE_BOOK;
	root[CMD_GETBOOK[GETBOOK_RKTYPE]] = em_rk;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabProcessDlg::SendToGetPro()
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_PROJECT;
	root[CMD_GETPRO[EM_GETPRO_BWRITE]] = PRO_STAFF_TYPE_YES;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabProcessDlg::SendToGetProgress(QString strBookID)
{
	Json::Value root;
	int num = m_vPro.size();
	for (int i=0;i<num;i++)
	{
		Json::Value one;
		one[CMD_GETPROGRESS[EM_GETPROGRESS_PROID]] = m_vPro[i].nID;
		one[CMD_GETPROGRESS[EM_GETPROGRESS_INDEX]] = i+2;
		root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
	}
	root[CONNECT_CMD]=SOCK_CMD_GET_PROGRESS;
	root[CMD_GETPROGRESS[EM_GETPROGRESS_BOOKID]] = strBookID.toStdString();

	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}
