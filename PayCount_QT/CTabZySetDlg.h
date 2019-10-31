#ifndef CTABZYSETDLG_H
#define CTABZYSETDLG_H

#include <QWidget>
#include "ui_CTabZySetDlg.h"
#include "cgloble.h"

class CTabZySetDlg : public CDlgFather
{
	Q_OBJECT

public:
	CTabZySetDlg(QWidget *parent = 0);
	~CTabZySetDlg();

private:
	Ui::CTabZySetDlg ui;

public slots:
	void st_CalBak(void* pdata);
	void st_BtnSave();

public:
	void pageIn();
	void SendToGetZheyePay();
	void GetZheyePay(Json::Value root);
	void SendToSaveZheyePay(STU_ZHEYE_PAY stu);
};

#endif // CTABZYSETDLG_H
