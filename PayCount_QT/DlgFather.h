#pragma once
#include <QDialog>
#include <string>

using std::string;

class CDlgFather: public QDialog
{
	Q_OBJECT
public:
	CDlgFather(QWidget *parent = 0);
	~CDlgFather(void);

	virtual void DlgDoRun(string strData);

signals:
	void sg_CalBak(void* pdata);
};

