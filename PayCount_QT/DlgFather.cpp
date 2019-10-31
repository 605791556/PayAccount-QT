#include "DlgFather.h"

CDlgFather::CDlgFather(QWidget *parent): QDialog(parent)
{
}


CDlgFather::~CDlgFather(void)
{
}

void CDlgFather::DlgDoRun(string strData)
{
	string* pStrData = new string;
	*pStrData = strData;
	emit sg_CalBak(pStrData);
}