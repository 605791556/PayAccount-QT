#ifndef CADDPRODLG_H
#define CADDPRODLG_H

#include <QDialog>
#include "ui_CAddProDlg.h"
#include "cgloble.h"

class CAddProDlg : public QDialog
{
	Q_OBJECT

public:
	CAddProDlg(QWidget* proMng=0,bool bAdd=true,int row = -1,QWidget *parent = 0);
	~CAddProDlg();

private:
	Ui::CAddProDlg ui;
	QButtonGroup *m_btnGroup1;
	QButtonGroup *m_btnGroup2;

public:
	bool m_bAdd;
	int  m_row;//当为修改时，代表行索引
	int  m_proID;

signals:
	void sg_CalBak(void* pdata);
public slots:
	void st_CalBak(void* pdata);
	void st_BtnSave();

public:
	void InitDlg(QWidget* proMng,bool bAdd);
	void SendToJudgePro(QString strProName);
	void SendToAddOrMdfProject(EM_SOCK_CMD type=SOCK_CMD_ADD_PROJECT);
};

#endif // CADDPRODLG_H
