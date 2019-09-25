#ifndef CADDSTAFFDLG_H
#define CADDSTAFFDLG_H

#include <QDialog>
#include "ui_CAddStaffDlg.h"
#include "cgloble.h"

class CAddStaffDlg : public QDialog
{
	Q_OBJECT

public:
	CAddStaffDlg(QWidget *parent = 0);
	~CAddStaffDlg();

private:
	Ui::CAddStaffDlg ui;

signals:
	void sg_CalBak(void* pdata);
public slots:
	void st_CalBak(void* pdata);
	void st_BtnSave();

};

#endif // CADDSTAFFDLG_H
