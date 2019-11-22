#ifndef CADDSTAFFDLG_H
#define CADDSTAFFDLG_H

#include <QDialog>
#include "ui_CAddStaffDlg.h"
#include "cgloble.h"

class CAddStaffDlg : public CDlgFather
{
	Q_OBJECT

public:
	CAddStaffDlg(QWidget* stfMng=0,bool bAdd=true,int row = -1,QWidget *parent = 0);
	~CAddStaffDlg();

	Ui::CAddStaffDlg ui;

public:
	bool m_bAdd;
	int  m_row;//当为修改时，代表行索引
	QString strOldIdcard;//修改职工，该职工修改前的身份证号
	QString m_strStaffID;

public slots:
	void st_CalBak(void* pdata);
	void st_BtnSave();

public:
	void InitDlg(QWidget* stfMng,bool bAdd);
	void SendToJudgeStaff(QString strName);
	void SendToAddStaff();
	void SendToMdfStaff(QString strName,QString strSex,int age,QString strStaffID, QString strIdcard,QString strTel,STAFF_TYPE type,int sort,double fDaypay);
};

#endif // CADDSTAFFDLG_H
