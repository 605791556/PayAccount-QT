#include "paycount_qt.h"
#include "CLockDlg.h"
#include "CStaffMngDlg.h"
#include "CSetPwdDlg.h"
#include "CUserMngDlg.h"
#include "CBookMngDlg.h"
#include "CProMngDlg.h"

void PayAccountCallback(void* p,string strData)
{
	USES_CONVERSION;
	PayCount_QT* pThis=(PayCount_QT*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void PayCount_QT::st_CalBak(void* pdata)
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
	case SOCK_CMD_INIT:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("初始化失败！"));
			else
				QMessageBox::information(this, CH("提示"), CH("初始化成功！"));
		}
		break;
	}
}

PayCount_QT::PayCount_QT(QWidget *parent)
	: QMainWindow(parent)
{
	m_bInitTab = false;
	qRegisterMetaType<NET_STATE>("NET_STATE");

	ui.setupUi(this);
	CGloble::SetButtonStyle(ui.BTN_PAY,":/PayCount_QT/pic/pay.png",3);
	CGloble::SetButtonStyle(ui.BTN_ACCOUNT,":/PayCount_QT/pic/account.png",3);
	CGloble::SetButtonStyle(ui.BTN_INIT,":/PayCount_QT/pic/init.png",3);
	CGloble::SetButtonStyle(ui.BTN_LOCK,":/PayCount_QT/pic/lock.png",3);
	CGloble::SetButtonStyle(ui.BTN_USER,":/PayCount_QT/pic/staff.png",3);
	CGloble::SetButtonStyle(ui.BTN_BOOK,":/PayCount_QT/pic/book.png",3);
	CGloble::SetButtonStyle(ui.BTN_PWD,":/PayCount_QT/pic/pwd.png",3);
	CGloble::SetButtonStyle(ui.BTN_PRO,":/PayCount_QT/pic/pro.png",3);
	CGloble::SetButtonStyle(ui.BTN_LOG,":/PayCount_QT/pic/log.png",3);
	CGloble::SetButtonStyle(ui.BTN_MIN,":/PayCount_QT/pic/min.png",3);
	CGloble::SetButtonStyle(ui.BTN_MAX,":/PayCount_QT/pic/max.png",3);
	CGloble::SetButtonStyle(ui.BTN_CLOSE,":/PayCount_QT/pic/close.png",3);
	if (g_Globle.m_strUserName != "admin")
	{
		ui.BTN_INIT->setVisible(false);
	}

	setWindowFlags(Qt::FramelessWindowHint);//去掉边框
	setAttribute(Qt::WA_TranslucentBackground);//透明
	///背景加载;
	m_pixmapBg.load(":/PayCount_QT/pic/frame.png");

	connect(ui.BTN_MAX, SIGNAL(clicked()), this, SLOT(BtnMax()));
	connect(&g_Globle,&CGloble::sgl_ConnectState,this,&PayCount_QT::ConnectState);
	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(st_tabChanged(int)));
	connect(ui.BTN_INIT, SIGNAL(clicked()), this, SLOT(BtnInit()));
	connect(ui.BTN_ACCOUNT, SIGNAL(clicked()), this, SLOT(BtnAccount()));
	connect(ui.BTN_PWD, SIGNAL(clicked()), this, SLOT(BtnPwd()));
	connect(ui.BTN_USER, SIGNAL(clicked()), this, SLOT(BtnStaff()));
	connect(ui.BTN_BOOK, SIGNAL(clicked()), this, SLOT(BtnBook()));
	connect(ui.BTN_PRO, SIGNAL(clicked()), this, SLOT(BtnProject()));
	connect(ui.BTN_PAY, SIGNAL(clicked()), this, SLOT(BtnPay()));
	connect(ui.BTN_LOG, SIGNAL(clicked()), this, SLOT(BtnLog()));
	connect(ui.BTN_LOCK, SIGNAL(clicked()), this, SLOT(BtnLock()));

	m_pTabMonthDlg = new CTabMonthDlg;
	m_pTabWorkDlg = new CTabWorkDayDlg;

	//初始化tabctrl
	InitTabCtrl();

	m_nx = m_ny = 0;
	m_bmax = false;

	QString str = QString(CH("欢迎登录：%1 (%2)")).arg(g_Globle.m_strUserName).arg(TypeName[g_Globle.m_nType]);
	ui.label_2->setText(str);
	ui.label_2->setStyleSheet("color: white");
	str = QString("%1 %2").arg(g_Globle.m_strTitle).arg(g_Globle.m_strVersion);
	ui.label->setText(str);
	ui.label->setStyleSheet("color: white");
}

PayCount_QT::~PayCount_QT()
{
	delete m_pTabMonthDlg;
	delete m_pTabWorkDlg;
}

void PayCount_QT::InitTabCtrl()
{
	ui.tabWidget->clear();

	QWidget *tabSports=new QWidget(this);
	QWidget *tabMusic=new QWidget(this);

	ui.tabWidget->setTabPosition(QTabWidget::North);

	ui.tabWidget->insertTab(EM_PAGE_JD,tabSports,CH("进度"));
	ui.tabWidget->insertTab(EM_PAGE_MX,tabMusic,CH("明细"));
	ui.tabWidget->insertTab(EM_PAGE_ZGTJ,m_pTabWorkDlg,CH("做工统计"));
	ui.tabWidget->insertTab(EM_PAGE_YHS,m_pTabMonthDlg,CH("月核算"));

	ui.tabWidget->setTabShape(QTabWidget::Rounded);//设置选项卡的形状
	m_bInitTab = true;
}

void PayCount_QT::st_tabChanged(int index)
{
	if(!m_bInitTab)
		return;
	if (index == EM_PAGE_YHS)
		m_pTabMonthDlg->pageIn();
	else if (index == EM_PAGE_ZGTJ)
		m_pTabWorkDlg->pageIn();
}

void PayCount_QT::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawPixmap(this->rect(),m_pixmapBg);
}

//控件位置随窗口大小改变而改变
void PayCount_QT::resizeEvent(QResizeEvent *event)
{
	int width = this->width();
	int height = this->height();
	ui.BTN_MIN->setGeometry(width-78,0,26,26);
	ui.BTN_MAX->setGeometry(width-52,0,26,26);
	ui.BTN_CLOSE->setGeometry(width-26,0,26,26);
	ui.tabWidget->setGeometry(0,100,width+2,height-123);
	ui.label_2->move(width-ui.label_2->width()-5,45);
	ui.label_3->move(ui.label_3->x(),height-22);
	ui.label_4->move(ui.label_4->x(),height-22);
}

void PayCount_QT::mouseMoveEvent(QMouseEvent *event)
{
	if (m_nx==0 && m_ny==0)
	{
		m_nx = event->x();
		m_ny = event->y();
	}

	if (m_ny<=110)//只在顶层窗口区域拖动有效
	{
		int g_x = event->globalX();
		int g_y = event->globalY();
		move(g_x-m_nx,g_y-m_ny);
	}
}

void PayCount_QT::mouseReleaseEvent(QMouseEvent *event)
{
	m_nx = m_ny = 0;
}

void PayCount_QT::mouseDoubleClickEvent(QMouseEvent *event)
{
	if(event->button()==Qt::LeftButton)
	{
		if (event->y()<=110)
		{
			if (m_bmax)
				showNormal();
			else
				showMaximized();
			m_bmax = !m_bmax;
		}
	}
}

void PayCount_QT::BtnMax()
{
	if (m_bmax)
		showNormal();
	else
		showMaximized();
	m_bmax = !m_bmax;
}

void PayCount_QT::BtnInit()
{
	int nType = QMessageBox::warning(this,CH("警告"),CH("初始化操作将会清除所有数据！确认继续此操作？"),
		QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
	switch(nType)
	{
	case QMessageBox::Ok:
		{
			CLockDlg dlg(this);
			if(dlg.exec() == QDialog::Accepted)
			{
				g_Globle.SetCallback(PayAccountCallback,this);
				Json::Value root;
				root[CONNECT_CMD]=SOCK_CMD_INIT;
				Json::FastWriter writer;  
				string temp = writer.write(root);
				g_Globle.SendTo(temp);
			}
		}
		break;
	}
}
void PayCount_QT::BtnAccount()
{
	CUserMngDlg dlg;
	dlg.exec();
}
void PayCount_QT::BtnPwd()
{
	CSetPwdDlg dlg;
	dlg.exec();
}
void PayCount_QT::BtnStaff()
{
	CStaffMngDlg dlg;
	dlg.exec();
}
void PayCount_QT::BtnBook()
{
	CBookMngDlg dlg;
	dlg.exec();
}
void PayCount_QT::BtnProject()
{
	CProMngDlg dlg;
	dlg.exec();
}
void PayCount_QT::BtnPay()
{

}
void PayCount_QT::BtnLog()
{

}
void PayCount_QT::BtnLock()
{
	CLockDlg dlg(this,true);
	dlg.exec();
}

void PayCount_QT::ConnectState(NET_STATE state)
{
	switch (state)
	{
	case NET_STATE_CLOSE:
		{
			ui.label_4->setText(CH("断开"));
			ui.label_4->setStyleSheet("color: red");
			break;
		}
	case NET_STATE_OK:
		{
			ui.label_4->setText(CH("正常"));
			ui.label_4->setStyleSheet("color: #22f165");
			break;
		}
	}
}
