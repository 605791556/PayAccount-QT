#include "CLockDlg.h"
#include "paycount_qt.h"

void LockCallback(void* p,string strData)
{
	CLockDlg* pThis=(CLockDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CLockDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_CHECKPWD:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("密码错误！"));
			else
			{
				QString strPwd = ui.EDIT_PWD->text();
				g_Globle.m_strUserPwd = strPwd;
				accept();
			}
		}
		break;
	}
}

CLockDlg::CLockDlg(QWidget* MainDlg,bool bLock,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint);//去掉边框
	setAttribute(Qt::WA_TranslucentBackground, true);
	ui.label->setStyleSheet("color: #FFFAFA");
	connect(ui.BTN_OK,SIGNAL(clicked()),this,SLOT(BtnOk()));
	connect(ui.BTN_CANCEL,SIGNAL(clicked()),this,SLOT(BtnCancel()));
	connect(this,&CLockDlg::sg_CalBak,this,&CLockDlg::st_CalBak);

	CGloble::SetButtonStyle(ui.BTN_OK,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_CANCEL,":/PayCount_QT/pic/ok.png",3);

	QImage *img=new QImage; //新建一个image对象
	img->load(":/PayCount_QT/pic/key.png");

	ui.label_pic->setPixmap(QPixmap::fromImage(*img));

	if(bLock)
	{
		ui.BTN_CANCEL->setVisible(false);
		ui.label->setText(CH("输入密码解锁："));
		ui.BTN_OK->setText(CH("解锁"));
	}
	else
	{
		ui.label->setText(CH("初始化验证："));
	    ui.BTN_OK->setText(CH("验证"));
	}

	InitDlg(MainDlg);
	g_Globle.SetCallback(LockCallback,this);
}

CLockDlg::~CLockDlg()
{
	
}

void CLockDlg::InitDlg(QWidget* MainDlg)
{
	int width = MainDlg->width();
	int height = MainDlg->height();
	this->setFixedSize(width,height);
}

void CLockDlg::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(0,0,0, 100));
}

void CLockDlg::BtnOk()
{
	QString strPwd = ui.EDIT_PWD->text();
	if (!strPwd.isEmpty())
	{
		Json::Value root;
		root[CONNECT_CMD]=SOCK_CMD_CHECKPWD;
		root[CMD_CHECKPWD[EM_CHECKPWD_NAME]]=g_Globle.m_strUserName.toStdString();
		root[CMD_CHECKPWD[EM_CHECKPWD_PWD]]=strPwd.toStdString();
		Json::FastWriter writer;  
		string temp = writer.write(root);
		g_Globle.SendTo(temp);
	}
}

void CLockDlg::BtnCancel()
{
	reject();
}