#ifndef CTABPROCESSDLG_H
#define CTABPROCESSDLG_H

#include <QWidget>
#include "ui_CTabProcessDlg.h"
#include "cgloble.h"

class CTabProcessDlg : public CDlgFather
{
	Q_OBJECT

public:
	CTabProcessDlg(QWidget *parent = 0);
	~CTabProcessDlg();

private:
	Ui::CTabProcessDlg ui;

public slots:
	void st_CalBak(void* pdata);
	void st_rkCbxChanged(int);
	void st_bookCbxChanged(int);
	void st_BtnUpdate();

public:
	void pageIn();
	void SendToGetBook();
	void SendToGetPro();
	void SendToGetProgress(QString strBookID);
	void GetBook(Json::Value root);
	void GetProject(Json::Value root);
	void GetProgress(Json::Value root);
	void InitListCtrl();
	void SetListCtrlValue();

public:
	vector<BOOK_STU> m_vet;
	vector<PROJECT_STU> m_vPro;
	QString m_LastBookID;
};

#endif // CTABPROCESSDLG_H
