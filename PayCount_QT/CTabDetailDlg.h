#ifndef CTABDETAILDLG_H
#define CTABDETAILDLG_H

#include <QWidget>
#include "ui_CTabDetailDlg.h"
#include "cgloble.h"

struct PRO_DETAIL
{
	int nProID;
	int ndex;//listctrl排列顺序，从0开始
	vector<STU_DETAIL> vDetails;
};

class CTabDetailDlg : public CDlgFather
{
	Q_OBJECT

public:
	CTabDetailDlg(QWidget *parent = 0);
	~CTabDetailDlg();

private:
	Ui::CTabDetailDlg ui;

public slots:
	void st_CalBak(void* pdata);
	void st_rkCbxChanged(int);
	void st_bookCbxChanged(int);
	void st_BtnUpdate();

public:
	void pageIn();
	void SendToGetBook();
	void SendToGetProject();
	void SendToGetDetails();
	void GetBook(Json::Value root);
	void GetProject(Json::Value root);
	void GetDetails(Json::Value root);
	void InitListCtrl();
	void SetListValue(QString strDate,int nYs,double fLs, int nNum,int* n,vector<PRO_DETAIL> vts);

public:
	vector<BOOK_STU> m_vet;
	vector<PROJECT_STU> m_vPro;
	QString m_LastBookID;
};

#endif // CTABDETAILDLG_H
