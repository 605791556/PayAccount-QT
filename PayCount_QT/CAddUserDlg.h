#ifndef CADDUSERDLG_H
#define CADDUSERDLG_H

#include <QDialog>
#include "ui_CAddUserDlg.h"
#include "cgloble.h"

class CAddUserDlg : public QDialog
{
	Q_OBJECT

public:
	CAddUserDlg(QWidget *parent = 0);
	~CAddUserDlg();

private:
	Ui::CAddUserDlg ui;

public:
	void SendToJudgeUser(QString strName);
	void SendToAddUser();

signals:
	void sg_CalBak(void* pdata);
public slots:
	void st_CalBak(void* pdata);
	void st_BtnAdd();
};

#endif // CADDUSERDLG_H
