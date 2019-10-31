#ifndef CSETPWDDLG_H
#define CSETPWDDLG_H

#include <QDialog>
#include "ui_CSetPwdDlg.h"
#include "cgloble.h"

class CSetPwdDlg : public CDlgFather
{
	Q_OBJECT

public:
	CSetPwdDlg(QWidget *parent = 0);
	~CSetPwdDlg();

private:
	Ui::CSetPwdDlg ui;

public slots:
	void st_CalBak(void* pdata);
	void BtnSave();
	void SendToMdfPwd(QString strName,QString strPwd);
};

#endif // CSETPWDDLG_H
