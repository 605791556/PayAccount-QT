#ifndef CPAYSETDLG_H
#define CPAYSETDLG_H

#include <QDialog>
#include "ui_CPaySetDlg.h"
#include "cgloble.h"

class CTabJdSetDlg;
class CTabZySetDlg;
class CTabDySetDlg;
class CTabOtherSetDlg;

enum EM_SPAGE_TYPE
{
	EM_SPAGE_TYPE_JD,//胶订
	EM_SPAGE_TYPE_ZY,//折页
	EM_SPAGE_TYPE_DY,//点页
	EM_SPAGE_TYPE_OTHER,//其它
	EM_SPAGE_TYPE_MAX
};

class CPaySetDlg : public CDlgFather
{
	Q_OBJECT

public:
	CPaySetDlg(QWidget *parent = 0);
	~CPaySetDlg();

private:
	Ui::CPaySetDlg ui;
	QPixmap m_pixmapBg;
	bool    m_bInitTab;
	int     m_nx;//拖动窗口，鼠标刚按下时的x坐标
	int     m_ny;//拖动窗口，鼠标刚按下时的y坐标

	CTabJdSetDlg*    m_pTabJdDlg;
	CTabZySetDlg*    m_pTabZyDlg;
	CTabDySetDlg*    m_pTabDyDlg;
	CTabOtherSetDlg* m_pTabOtherDlg;

protected:
	//加载背景图片
	void paintEvent(QPaintEvent *);
	void InitTabCtrl();
	//鼠标移动事件，用于拖动窗口
	void mouseMoveEvent(QMouseEvent *);
	//鼠标释放事件，用于判断拖动完成
	void mouseReleaseEvent(QMouseEvent *);

public slots:
	void st_tabChanged(int index);

public:
	
};

#endif // CPAYSETDLG_H
