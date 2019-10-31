#ifndef CTABDYSETDLG_H
#define CTABDYSETDLG_H

#include <QWidget>
#include "ui_CTabDySetDlg.h"
#include "cgloble.h"

class CTabDySetDlg : public CDlgFather
{
	Q_OBJECT

public:
	CTabDySetDlg(QWidget *parent = 0);
	~CTabDySetDlg();

private:
	Ui::CTabDySetDlg ui;

public slots:
	void st_CalBak(void* pdata);
	void st_BtnSave();

public:
	void pageIn();
	void SendToGetDyPay();
	void GetDyPay(Json::Value root);
	void SendToSaveDyPay(QString strDown,QString strUp);
};

#endif // CTABDYSETDLG_H
