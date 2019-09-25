#include "CSetDlg.h"

CSetDlg::CSetDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(BtnSave()));
	connect(ui.BTN_CANCEL,SIGNAL(clicked()),this,SLOT(BtnCancel()));

	CGloble::SetEditOnlyNumber(ui.EDIT_PORT,this);
	if (g_Globle.m_psetting)
	{
		ui.EDIT_IP->setText(g_Globle.m_strIP);
		ui.EDIT_PORT->setText(QString::number(g_Globle.m_nPort));
		ui.EDIT_NAME->setText(g_Globle.m_strName);
		ui.EDIT_TITLE->setText(g_Globle.m_strTitle);
	}
}

CSetDlg::~CSetDlg()
{

}

void CSetDlg::BtnSave()
{
	QString strIP = ui.EDIT_IP->text();
	QString strPort = ui.EDIT_PORT->text();
	QString strName = ui.EDIT_NAME->text();
	QString strTitle = ui.EDIT_TITLE->text();
	if (strIP.isEmpty() || strPort.isEmpty())
	{
		QMessageBox::information(this, CH("提示"), CH("请输入完整信息"));
		return;
	}
	else
	{
		g_Globle.SetIniValue("SOCKET","ip",strIP);
		g_Globle.SetIniValue("SOCKET","port",strPort);
		g_Globle.SetIniValue("SOCKET","name",strName);
		g_Globle.SetIniValue("SOCKET","title",strTitle);

		QMessageBox::information(this, CH("提示"), CH("保存成功，请重新启动程序。"));
		accept();
	}
}

void CSetDlg::BtnCancel()
{
	reject();
}
