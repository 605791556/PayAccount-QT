#ifndef CTABMONTHDLG_H
#define CTABMONTHDLG_H

#include <QWidget>
#include "cgloble.h"
#include <QDate>
#include "ui_CTabMonthDlg.h"


class CTabMonthDlg : public QWidget
{
	Q_OBJECT

public:
	CTabMonthDlg(QWidget *parent = 0);
	~CTabMonthDlg();

private:
	Ui::CTabMonthDlg ui;
	QMovie* m_pMovie;

public:
	vector<int>  m_vItem;//高亮选中行
	vector<STAFF_STU> m_vet;
	vector<MONTH_PAY_STAFF> m_vStaffs;
	QStandardItemModel* m_pViewModel;
	int m_oldDays;
	bool m_bInitCombox;

signals:
	void sg_CalBak(void* pdata);
	void sg_ThCal(EM_SOCK_CMD cmd,EM_CMD_RET ret,bool rst = true,QString strPay = "");

public slots:
	void st_CalBak(void* pdata);
	void BtnUpdate();
	void st_ComboxChanged(const QString &);
	void st_KeyWordChanged(const QString &);
	void st_ThCal(EM_SOCK_CMD cmd,EM_CMD_RET ret,bool rst = true,QString strPay = "");

public:
	void InitCtrlValue();
	void InitListCtrl();
	void SetListValue();
	bool SendToGetMonthPay();
	void SendToGetStaff();
	void GetStaff(Json::Value root);
	QString GetMonthPay(Json::Value root);
	void pageIn();
	void SetCtrlVisible(bool bLoadOk);
};

#endif // CTABMONTHDLG_H
