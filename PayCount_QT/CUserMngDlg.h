#ifndef CUSERMNGDLG_H
#define CUSERMNGDLG_H

#include <QDialog>
#include "ui_CUserMngDlg.h"
#include "cgloble.h"

#define  LISTCOLUMN 5

class CUserMngDlg : public QDialog
{
	Q_OBJECT

public:
	CUserMngDlg(QWidget *parent = 0);
	~CUserMngDlg();

private:
	Ui::CUserMngDlg ui;

public:
	vector<USER_STU> m_vet;

signals:
	void sg_CalBak(void* pdata);
public slots:
	void st_CalBak(void* pdata);
	void BtnAdd();
	void BtnDel();

public:
	void SendToFindUser();
	void SendToDelUser(QString strName);
	void GetUser(Json::Value root);
	void InitListCtrl();
	void SetListCtrlValue();
};

#endif // CUSERMNGDLG_H
