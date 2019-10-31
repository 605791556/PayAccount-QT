#ifndef CTABJDSETDLG_H
#define CTABJDSETDLG_H

#include <QWidget>
#include "ui_CTabJdSetDlg.h"
#include "cgloble.h"

class CTabJdSetDlg : public CDlgFather
{
	Q_OBJECT

public:
	CTabJdSetDlg(QWidget *parent = 0);
	~CTabJdSetDlg();

private:
	Ui::CTabJdSetDlg ui;

public slots:
	void st_CalBak(void* pdata);
	void st_BtnSave();

public:
	void pageIn();
	void SendToGetDaiPay();
	void GetDaiPay(Json::Value root);
	void SendToSaveDaiPay(STU_DAI_PAY stu);
};

#endif // CTABJDSETDLG_H
