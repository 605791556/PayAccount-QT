#include "CPaySetDlg.h"
#include "CTabJdSetDlg.h"
#include "CTabZySetDlg.h"
#include "CTabDySetDlg.h"
#include "CTabOtherSetDlg.h"

CPaySetDlg::CPaySetDlg(QWidget *parent)
	: CDlgFather(parent)
{
	m_bInitTab = false;
	ui.setupUi(this);

	CGloble::SetButtonStyle(ui.BTN_CLOSE,":/PayCount_QT/pic/close.png",3);
	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(st_tabChanged(int)));
	setWindowFlags(Qt::FramelessWindowHint);//去掉边框
	setAttribute(Qt::WA_TranslucentBackground);//透明
	///背景加载;
	m_pixmapBg.load(":/PayCount_QT/pic/cbg2.png");
	//初始化tabctrl
	InitTabCtrl();

	m_nx = m_ny = 0;
}

CPaySetDlg::~CPaySetDlg()
{

}

void CPaySetDlg::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawPixmap(this->rect(),m_pixmapBg);
}

void CPaySetDlg::InitTabCtrl()
{
	m_pTabJdDlg = new CTabJdSetDlg(this);
	m_pTabZyDlg = new CTabZySetDlg(this);
	m_pTabDyDlg = new CTabDySetDlg(this);
	m_pTabOtherDlg = new CTabOtherSetDlg(this);

	ui.tabWidget->clear();
	ui.tabWidget->setTabPosition(QTabWidget::North);

	ui.tabWidget->insertTab(EM_SPAGE_TYPE_JD,m_pTabJdDlg,CH("胶订"));
	ui.tabWidget->insertTab(EM_SPAGE_TYPE_ZY,m_pTabZyDlg,CH("折页"));
	ui.tabWidget->insertTab(EM_SPAGE_TYPE_DY,m_pTabDyDlg,CH("点页"));
	ui.tabWidget->insertTab(EM_SPAGE_TYPE_OTHER,m_pTabOtherDlg,CH("其它"));

	ui.tabWidget->setTabShape(QTabWidget::Rounded);//设置选项卡的形状
	m_bInitTab = true;
}

void CPaySetDlg::st_tabChanged(int index)
{
	if(!m_bInitTab)
		return;
	if (index == EM_SPAGE_TYPE_JD)
	    m_pTabJdDlg->pageIn();
	else if (index == EM_SPAGE_TYPE_ZY)
	    m_pTabZyDlg->pageIn();
	else if (index == EM_SPAGE_TYPE_DY)
	    m_pTabDyDlg->pageIn();
	else if (index == EM_SPAGE_TYPE_OTHER)
	    m_pTabOtherDlg->pageIn();
}

void CPaySetDlg::mouseMoveEvent(QMouseEvent *event)
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

void CPaySetDlg::mouseReleaseEvent(QMouseEvent *event)
{
	m_nx = m_ny = 0;
}