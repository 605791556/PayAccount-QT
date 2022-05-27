#ifndef CADDSTAFFDLG_H
#define CADDSTAFFDLG_H

#include <QDialog>
#include "ui_CAddStaffDlg.h"
#include "cgloble.h"

class CAddStaffDlg : public QDialog
{
	Q_OBJECT

public:
	CAddStaffDlg(QWidget* stfMng=0,bool bAdd=true,int row = -1,QWidget *parent = 0);
	~CAddStaffDlg();

	Ui::CAddStaffDlg ui;

public:
	bool m_bAdd;
	int  m_row;//��Ϊ�޸�ʱ������������
	QString strOldIdcard;//�޸�ְ������ְ���޸�ǰ�����֤��
	QString m_strStaffID;
signals:
	void sg_CalBak(void* pdata);
public slots:
	void st_CalBak(void* pdata);
	void st_BtnSave();

public:
	void InitDlg(QWidget* stfMng,bool bAdd);
	void SendToJudgeStaff(QString strIdcard);
	void SendToAddStaff();
	void SendToMdfStaff(QString strName,QString strSex,QString strStaffID, QString strIdcard,QString strTel,STAFF_TYPE type,int sort,double fDaypay);
};

#endif // CADDSTAFFDLG_H
