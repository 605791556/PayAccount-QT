#ifndef PAYCOUNT_QT_H
#define PAYCOUNT_QT_H

#include <QtWidgets/QMainWindow>
#include "ui_paycount_qt.h"
#include "cgloble.h"
#include "CTabMonthDlg.h"
#include "CTabWorkDayDlg.h"
#include "CTabDetailDlg.h"
#include "CTabProcessDlg.h"

enum EM_PAGE_TYPE
{
	EM_PAGE_JD,//进度
	EM_PAGE_MX,//明细
	EM_PAGE_ZGTJ,//做工统计
	EM_PAGE_YHS,//月核算
	EM_PAGE_MAX
};

class PayCount_QT : public QMainWindow
{
	Q_OBJECT

public:
	PayCount_QT(QWidget *parent = 0);
	~PayCount_QT();

private:
	Ui::PayCount_QTClass ui;
	QPixmap m_pixmapBg;
	int     m_nx;//拖动窗口，鼠标刚按下时的x坐标
	int     m_ny;//拖动窗口，鼠标刚按下时的y坐标
	bool    m_bmax;//true:当前窗口最大化
	bool    m_bInitTab;

	CTabMonthDlg*   m_pTabMonthDlg;
	CTabWorkDayDlg* m_pTabWorkDlg;
	CTabDetailDlg*  m_pTabDetailDlg;
	CTabProcessDlg* m_pTabProcessDlg;

protected:
	//加载背景图片
	void paintEvent(QPaintEvent *);
	//控件位置随窗口大小改变而改变
	void resizeEvent(QResizeEvent *);
	//鼠标移动事件，用于拖动窗口
	void mouseMoveEvent(QMouseEvent *);
	//鼠标释放事件，用于判断拖动完成
	void mouseReleaseEvent(QMouseEvent *);
	//双击改变窗口大小
	void mouseDoubleClickEvent(QMouseEvent *);
	void InitTabCtrl();

signals:
	void sg_CalBak(void* pdata);

public slots:
	void BtnMax();
	void ConnectState(NET_STATE state);
	void st_CalBak(void* pdata);
	void st_tabChanged(int index);
	void BtnInit();
	void BtnAccount();//账号管理
	void BtnPwd();//密码修改
	void BtnStaff();//员工管理
	void BtnBook();
	void BtnProject();
	void BtnPay();
	void BtnLog();
	void BtnLock();
	void BtnClose();
};

#endif // PAYCOUNT_QT_H
