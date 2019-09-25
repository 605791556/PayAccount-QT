#ifndef CSETDLG_H
#define CSETDLG_H

#include <QDialog>
#include "ui_CSetDlg.h"
#include "cgloble.h"

class CSetDlg : public QDialog
{
	Q_OBJECT

public:
	CSetDlg(QWidget *parent = 0);
	~CSetDlg();

private:
	Ui::CSetDlg ui;

public slots:
	void BtnSave();
	void BtnCancel();
};

#endif // CSETDLG_H
