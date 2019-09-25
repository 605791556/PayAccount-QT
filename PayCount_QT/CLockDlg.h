#ifndef CLOCKDLG_H
#define CLOCKDLG_H

#include <QDialog>
#include "ui_CLockDlg.h"
#include "cgloble.h"

class CLockDlg : public QDialog
{
	Q_OBJECT

public:
	CLockDlg(QWidget* MainDlg,bool bLock = false,QWidget *parent = 0);
	~CLockDlg();

private:
	Ui::CLockDlg ui;
	QPixmap m_pixmapBg;

	void paintEvent(QPaintEvent *);
	void InitDlg(QWidget* MainDlg);

signals:
	void sg_CalBak(void* pdata);
public slots:
	void BtnOk();
	void BtnCancel();
	void st_CalBak(void* pdata);

};

#endif // CLOCKDLG_H
