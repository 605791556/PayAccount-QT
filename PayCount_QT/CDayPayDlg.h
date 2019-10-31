#ifndef CDAYPAYDLG_H
#define CDAYPAYDLG_H

#include <QDialog>
#include "ui_CDayPayDlg.h"
#include "cgloble.h"

class CDayPayDlg : public CDlgFather
{
	Q_OBJECT

public:
	CDayPayDlg(const QModelIndex & mdIndex,QWidget* tabWkDlg,QWidget *parent = 0);
	~CDayPayDlg();

private:
	Ui::CDayPayDlg ui;
	QPixmap m_pixmapBg;
	int     m_nx;//拖动窗口，鼠标刚按下时的x坐标
	int     m_ny;//拖动窗口，鼠标刚按下时的y坐标
	bool    m_bmax;//true:当前窗口最大化

protected:
	//加载背景图片
	void paintEvent(QPaintEvent *);
	//鼠标移动事件，用于拖动窗口
	void mouseMoveEvent(QMouseEvent *);
	//鼠标释放事件，用于判断拖动完成
	void mouseReleaseEvent(QMouseEvent *);
	//双击改变窗口大小
	void mouseDoubleClickEvent(QMouseEvent *);

public slots:
		void st_CalBak(void* pdata);
		void st_BtnMax();
		void st_BtnAdd();
		void st_BtnSave();
		void st_BtnDel();
		void st_comboChanged(int);
		void st_numberEditChanged(const QString &);
		void st_SetAllPayCtrl();
public:
	void InitTitle(const QModelIndex & mdIndex,QWidget* widget);
	void InitListCtrl();
	void SetListCtrlValue();
	QComboBox* CreateProCombox(int oldIndex = -1);
	QComboBox* CreateBookCombox(int oldIndex = -1);
	void AddTableRow(int oldProIndex = -1,int oldBkIndex = -1,QString dpay = "",double number = 0,QString money = "");
	void DeleteTableCtrl();

	void SendToGetDPay();//获取该职工日薪
	void GetDPay(Json::Value root);
	void SendToGetBook();
	void GetBook(Json::Value root);
	void SendToGetProject();
	void GetProject(Json::Value root);
	void SendToGetDayPay();
	void GetDayPay(Json::Value root);
	void SendToDelDayPay();
	void SendToSaveDayPay();
	void SendToGetOnePay(int proID,QString strBookID,int nItem);
	void GetOnePay(Json::Value root);

public:
	double  m_fDaypay;
	QString m_strDate;
	QString m_strStaffID;
	QString m_strStaffName;

	QString m_LastStaffID;
	vector<DAYPAY> m_vCal;
	vector<PROJECT_STU> m_vProjects;
	vector<BOOK_STU> m_vBooks;
	vector<DAYPAY> m_vSaves;//保存时调用
};

#endif // CDAYPAYDLG_H
