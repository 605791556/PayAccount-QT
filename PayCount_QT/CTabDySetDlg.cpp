#include "CTabDySetDlg.h"

void CTabDySetDlg::st_CalBak(void* pdata)
{
	string* pStrData = (string*)pdata;
	Json::Reader r;
	Json::Value root;
	r.parse(*pStrData,root);
	delete pStrData;

	EM_SOCK_CMD cmd = (EM_SOCK_CMD)root[CONNECT_CMD].asInt();
	EM_CMD_RET ret = (EM_CMD_RET)root[CMD_RetType[EM_CMD_RETYPE_RESULT]].asInt();

	switch (cmd)
	{
	case SOCK_CMD_GET_DYPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("����"), CH("��ȡ����ʧ�ܣ�"));
			else
			{
				GetDyPay(root);
			}
		}
		break;
	case SOCK_CMD_SET_DYPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("����"), CH("��������ʧ�ܣ�"));
			else
			{
				QMessageBox::information(this, CH("��ʾ"), CH("����ɹ���"));
			}
		}
		break;
	}
}

CTabDySetDlg::CTabDySetDlg(QWidget *parent)
	: CDlgFather(parent)
{
	ui.setupUi(this);
	connect(this,&CTabDySetDlg::sg_CalBak,this,&CTabDySetDlg::st_CalBak);
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(st_BtnSave()));

	ui.EDIT_W_DOWN->setValidator(g_Globle.dbVtor);
	ui.EDIT_W_UP->setValidator(g_Globle.dbVtor);

	g_Globle.m_DlgMap[EM_DLG_TAB_DYSET] = this;
}

CTabDySetDlg::~CTabDySetDlg()
{

}

void CTabDySetDlg::pageIn()
{
	SendToGetDyPay();
}

void CTabDySetDlg::SendToGetDyPay()
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_TAB_DYSET;
	root[CONNECT_CMD]=SOCK_CMD_GET_DYPAY;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("����"), CH("������������ʧ�ܣ����������Ƿ�������"));
	}
}

void CTabDySetDlg::SendToSaveDyPay(QString strDown,QString strUp)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_TAB_DYSET;
	root[CONNECT_CMD]=SOCK_CMD_SET_DYPAY;

	root[CMD_DYPAY[EM_DY_PAY_DOWN]]= strDown.toStdString();
	root[CMD_DYPAY[EM_DY_PAY_UP]]= strUp.toStdString();

	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("����"), CH("������������ʧ�ܣ����������Ƿ�������"));
	}
}

void CTabDySetDlg::GetDyPay(Json::Value root)
{
	QString strdown,strup;
	strdown = root[CMD_DYPAY[EM_DY_PAY_DOWN]].asCString();
	strup = root[CMD_DYPAY[EM_DY_PAY_UP]].asCString();

	ui.EDIT_W_DOWN->setText(strdown);
	ui.EDIT_W_UP->setText(strup);
}

void CTabDySetDlg::st_BtnSave()
{
	QString strdown,strup;
	strdown = ui.EDIT_W_DOWN->text();
	strup =   ui.EDIT_W_UP->text();

	if (strdown.isEmpty() || strup.isEmpty())
	{
		QMessageBox::information(this, CH("��ʾ"), CH("�������������ݣ�"));
		return;
	}
	SendToSaveDyPay(strdown,strup);
}