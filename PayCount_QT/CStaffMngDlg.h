#ifndef CUSERDLG_H
#define CUSERDLG_H

#include <QDialog>
#include "ui_CStaffMngDlg.h"
#include "cgloble.h"

#define  LISTCOLUMN 10

class CStaffMngDlg : public CDlgFather
{
	Q_OBJECT

public:
	CStaffMngDlg(QWidget *parent = 0);
	~CStaffMngDlg();

	Ui::CStaffMngDlg ui;
	void resizeEvent(QResizeEvent *);

public slots:
	void st_CalBak(void* pdata);
	void st_BtnEdit();
	void st_BtnDel();
	void st_BtnPlDel();
	void BtnFind();
	void BtnAdd();
	void BtnGo();
	void BtnLast();
	void BtnNext();

public:
	int m_nCount;//数据总数
	int m_dex;//当前页数
	int m_nPage;//总页数
	QString m_strKeyWord;
	vector<STAFF_STU> m_vet;

	void InitListCtrl();
	void SendToGetStaff(QString strKeyWord,int nStart,int nNum);
	void SendToDelStaff(QString strStaffID);
	void SendToPlDelStaff(string strListID);
	void GetStaff(Json::Value root);
	void SetListCtrlValue();
};

#endif // CUSERDLG_H
