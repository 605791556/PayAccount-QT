#ifndef CTABOTHERSETDLG_H
#define CTABOTHERSETDLG_H

#include <QWidget>
#include "ui_CTabOtherSetDlg.h"
#include "cgloble.h"

class CTabOtherSetDlg : public QWidget
{
	Q_OBJECT

public:
	CTabOtherSetDlg(QWidget *parent = 0);
	~CTabOtherSetDlg();

private:
	Ui::CTabOtherSetDlg ui;

signals:
	void sg_CalBak(void* pdata);

public slots:
	void st_CalBak(void* pdata);
	void st_ComboxChanged(int);
	void st_checkChanged(int);
	void st_BtnSave();

public:
	void pageIn();
	void InitListCtrl();
	void SendToGetProject();
	void SendToGetBook();
	void SendToGetOtherPay(int nID);
	void SendToSetOtherPay(int proID, vector<OTHER_PRO_PAY> vec);
	void SendToSetOtherAllBookPay(int proID,QString strPay);
	void GetProject(Json::Value root);
	void GetBook(Json::Value root);
	void GetOtherPay(Json::Value root);
	void SetListValue(bool bZero = false);

public:
	bool m_bInitCombox;
	vector<PROJECT_STU> m_vProList;
	vector<BOOK_STU> m_vBookList;
	vector<OTHER_PRO_PAY> m_vOtherPay;
};

#endif // CTABOTHERSETDLG_H
