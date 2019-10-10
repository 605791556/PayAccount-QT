#ifndef CPROMNGDLG_H
#define CPROMNGDLG_H

#include <QDialog>
#include "ui_CProMngDlg.h"
#include "cgloble.h"

#define  LISTCOLUMN 6

class CProMngDlg : public QDialog
{
	Q_OBJECT

public:
	CProMngDlg(QWidget *parent = 0);
	~CProMngDlg();

	Ui::CProMngDlg ui;
	void resizeEvent(QResizeEvent *);

public:
	vector<PROJECT_STU> m_vet;

signals:
	void sg_CalBak(void* pdata);
public slots:
	void st_CalBak(void* pdata);
	void st_BtnEdit();
	void st_BtnDel();
	void BtnSaveDex();
	void BtnAdd();

public:
	void InitListCtrl();
	void SetListValue();
	void SendToGetProject();
	void SendToSaveProNdex();
	void SendToDelProject(int nProID);
	void GetProject(Json::Value root);
	
};

#endif // CPROMNGDLG_H
