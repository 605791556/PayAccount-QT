#include "CSetPwdDlg.h"

void MdfPwdCallback(void* p,string strData)
{
	CSetPwdDlg* pThis=(CSetPwdDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CSetPwdDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_MDFPWD:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("����"), CH("�޸�ʧ�ܣ�"));
			else
			{
				g_Globle.m_strUserPwd = ui.EDIT_NEWPWD->text();
				QMessageBox::information(this, CH("��ʾ"), CH("�޸ĳɹ���"));
				reject();
			}
		}
		break;
	}
}

CSetPwdDlg::CSetPwdDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(this,&CSetPwdDlg::sg_CalBak,this,&CSetPwdDlg::st_CalBak);
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(BtnSave()));

	QRegExpValidator* pRevalidotor = new QRegExpValidator(QRegExp("[A-Za-z0-9_-@#$%&*]+&*"), this);
	ui.EDIT_OLDPWD->setValidator(pRevalidotor);
	ui.EDIT_NEWPWD->setValidator(pRevalidotor);
	ui.EDIT_NEWPWD2->setValidator(pRevalidotor);

	g_Globle.SetCallback(MdfPwdCallback,this);
}

CSetPwdDlg::~CSetPwdDlg()
{

}

void CSetPwdDlg::SendToMdfPwd(QString strName,QString strPwd)
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_MDFPWD;
	root[CMD_MDFPWD[EM_MDFPWD_NAME]]=strName.toStdString();
	root[CMD_MDFPWD[EM_MDFPWD_PWD]]=strPwd.toStdString();
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CSetPwdDlg::BtnSave()
{
	QString strOldPwd = ui.EDIT_OLDPWD->text();
	QString strNewPwd = ui.EDIT_NEWPWD->text();
	QString strNewPwd2 = ui.EDIT_NEWPWD2->text();


	if (strOldPwd.isEmpty())
	{
		QMessageBox::information(this, CH("��ʾ"), CH("���������룡"));
		return;
	}
	else if (strOldPwd!=g_Globle.m_strUserPwd)
	{
		QMessageBox::information(this, CH("��ʾ"), CH("ԭ�������"));
		return;
	}
	else if (strNewPwd.isEmpty())
	{
		QMessageBox::information(this, CH("��ʾ"), CH("�����������룡"));
		return;
	}
	else if (strNewPwd.length()<6)
	{
		QMessageBox::information(this, CH("��ʾ"), CH("���볤�Ȳ���С��6λ��"));
		return;
	}
	else if (strNewPwd2.isEmpty())
	{
		QMessageBox::information(this, CH("��ʾ"), CH("������ȷ�����룡"));
		return;
	}
	else if (strNewPwd!=strNewPwd2)
	{
		QMessageBox::information(this, CH("��ʾ"), CH("�����벻һ�£����������룡"));
		return;
	}
	else
	{
		SendToMdfPwd(g_Globle.m_strUserName, strNewPwd);
	}
}
