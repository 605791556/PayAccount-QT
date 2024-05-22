#include "CLogin.h"
#include "CSetDlg.h"

void LoginCallback(void* p,string strData);
CLogin::CLogin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.BTN_SET,SIGNAL(clicked()),this,SLOT(BtnSet()));
	connect(ui.BTN_LOGIN,SIGNAL(clicked()),this,SLOT(BtnLogin()));
	connect(ui.BTN_CLOSE,SIGNAL(clicked()),this,SLOT(BtnClose()));
	connect(this,SIGNAL(sg_CalBak(void*)),this,SLOT(st_CalBak(void*)),Qt::QueuedConnection);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(st_comboChanged(int)));
	
	setWindowFlags(Qt::FramelessWindowHint);//去掉边框
	setAttribute(Qt::WA_TranslucentBackground);//透明
	//背景加载
	m_pixmapBg.load(":/PayCount_QT/pic/login_bg.png");
	QImage *img=new QImage; //新建一个image对象

	img->load(":/PayCount_QT/pic/no_pic.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
	ui.label_pic->setPixmap(QPixmap::fromImage(*img));

	CGloble::SetButtonStyle(ui.BTN_MIN,":/PayCount_QT/pic/min.png",3);
	CGloble::SetButtonStyle(ui.BTN_CLOSE,":/PayCount_QT/pic/close.png",3);
	CGloble::SetButtonStyle(ui.BTN_SET,":/PayCount_QT/pic/set.png",3);
	CGloble::SetButtonStyle(ui.BTN_LOGIN,":/PayCount_QT/pic/login_btn.png",3);

	//设置回调
	g_Globle.SetCallback(LoginCallback,this);
	if (g_Globle.InitGloble())
	{
		QString strTitle = g_Globle.m_strTitle;
		QString strVersion = "v" + g_Globle.m_strVersion;
		ui.label_title->setText(strTitle);
		ui.label_title->setStyleSheet("color: white");
		ui.label_v->setText(strVersion);
		ui.label_v->setStyleSheet("color: white");
		if (g_Globle.ConnectSer())
		{
			ui.label_msg->setText("");
			Json::Value root;
			root[CONNECT_CMD]=SOCK_CMD_GET_USER;
			Json::FastWriter writer;  
			string temp = writer.write(root);
			g_Globle.SendTo(temp);
		}
		else
			ui.label_msg->setText(CH("服务器连接失败！"));

	}
	else
		ui.label_msg->setText(CH("服务器连接失败！"));

	m_nx = m_ny = 0;


}

CLogin::~CLogin()
{
}

void CLogin::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawPixmap(this->rect(),m_pixmapBg);
}

//控件位置随窗口大小改变而改变
void CLogin::resizeEvent(QResizeEvent *event)
{
	int width = this->width();
	int height = this->height();
	ui.BTN_MIN->setGeometry(width-57,5,26,26);
	ui.BTN_CLOSE->setGeometry(width-31,5,26,26);
	ui.label_msg->move(5,height - 25);
}

void CLogin::mouseMoveEvent(QMouseEvent *event)
{
	if (m_nx==0 && m_ny==0)
	{
		m_nx = event->x();
		m_ny = event->y();
	}

	if (m_ny<=140)//只在顶层窗口区域拖动有效
	{
		int g_x = event->globalX();
		int g_y = event->globalY();
		move(g_x-m_nx,g_y-m_ny);
	}
}

void CLogin::mouseReleaseEvent(QMouseEvent *event)
{
	m_nx = m_ny = 0;
}

void CLogin::BtnClose()
{
	reject();
}

void CLogin:: BtnSet()
{
	CSetDlg dlg;
	if(dlg.exec() == QDialog::Accepted)
		reject();
}

void CLogin:: BtnLogin()
{
	QString strUser = ui.comboBox->currentText();
	QString strPwd = ui.EDIT_PWD->text();
	bool bCheck = false;
    if( ui.checkBox->checkState() == Qt::Checked)
		bCheck = true;
	SendToLogin(strUser,strPwd,bCheck);
}

void CLogin::SendToLogin(QString strName,QString strPass,int show_pass)
{
	Json::Value root;
	{
		root[CONNECT_CMD]=SOCK_CMD_LOGIN;
		root[CMD_LOGIN[EM_LOGIN_NAME]] = strName.toStdString();
		root[CMD_LOGIN[EM_LOGIN_PASS]]= strPass.toStdString();
		root[CMD_LOGIN[EM_LOGIN_SHOWPASS]]=show_pass;
	}
	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("提示"), CH("发送网络请求失败，请检查网络是否正常！"));
	}
}

void CLogin::GetUser(Json::Value root)
{
	Json:: Value js = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
	if (js.isArray())
	{
		int nCount = js.size();
		for (int i=0;i<nCount;i++)
		{
			USER_STU stu;
			stu.strname = js[i][CMD_GETUSER[EM_USER_NAME]].asCString();
			stu.type = js[i][CMD_GETUSER[EM_USER_TYPE]].asInt();
			stu.strTime = js[i][CMD_GETUSER[EM_USER_TIME]].asCString();
			stu.show_pass = js[i][CMD_GETUSER[EM_USER_SHOWPASS]].asInt();
			stu.strPass = js[i][CMD_GETUSER[EM_USER_PASS]].asCString();
			m_vet.push_back(stu);
		}

		nCount = m_vet.size();
		for (int i = 0; i < nCount; i++)
		{
			if (m_vet[i].show_pass)
			{
				 QVariant var;
				 var.setValue(m_vet[i]);
				 ui.comboBox->addItem(m_vet[i].strname,var);
			}
		}
	}
}

void CLogin::st_comboChanged(int index)
{
	QVariant var = ui.comboBox->itemData(index);
	USER_STU stu = var.value<USER_STU>();
	if (stu.show_pass)
		ui.checkBox->setCheckState(Qt::Checked);
	else
		ui.checkBox->setCheckState(Qt::Unchecked);
}

void CLogin::GetLogin(Json::Value root)
{
	bool bOk = root[CMD_LOGINMSG[EM_LOGINMSG_BOK]].asBool();
	if (bOk)
	{
		g_Globle.m_strUserName = root[CMD_LOGINMSG[EM_LOGINMSG_NAME]].asCString();
		g_Globle.m_strUserPwd = root[CMD_LOGINMSG[EM_LOGINMSG_PASS]].asCString();
		g_Globle.m_nType = root[CMD_LOGINMSG[EM_LOGINMSG_TYPE]].asInt();
		g_Globle.SetCallback(NULL,NULL);
		accept();
	}
	else
	{
		bool bLogind = root[CMD_LOGINMSG[EM_LOGINMSG_LOGIND]].asBool();
		if(bLogind)
			QMessageBox::information(this, CH("提示"), CH("该账号已登录"));
		else
			QMessageBox::information(this, CH("提示"), CH("账号或密码错误，请重新输入"));

		return;
	}
}

void LoginCallback(void* p,string strData)
{
	CLogin* pThis=(CLogin*) p;

	if ( pThis==NULL || !pThis->isWindow())
	{
		return;
	}
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CLogin::st_CalBak(void* pdata)
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
	case SOCK_CMD_GET_USER:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取账号信息失败！"));
			else
				GetUser(root);
		}
		break;
	case SOCK_CMD_LOGIN:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("登录失败！"));
			else
				GetLogin(root);
		}
		break;
	}
}
