#include "CAddUserDlg.h"

void UserAddCallback(void* p,string strData)
{
	CAddUserDlg* pThis=(CAddUserDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CAddUserDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_ADD_USER:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("����"), CH("���ʧ�ܣ�"));
			else
			{
				QMessageBox::information(this, CH("��ʾ"), CH("��ӳɹ���"));
				accept();
			}
		}
		break;
	case SOCK_CMD_JUDGE_USER:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("����"), CH("�ж��˺��Ƿ����ʱ��������"));
			else
			{
				bool bHad = root[CMD_JUDGEUSER[EM_JUDGE_USER_BHAD]].asBool();
				if(bHad)
					QMessageBox::information(this, CH("����"), CH("���˺��Ѵ��ڣ�"));
				else
					SendToAddUser();
			}
		}
		break;
	}
}

CAddUserDlg::CAddUserDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(this,&CAddUserDlg::sg_CalBak,this,&CAddUserDlg::st_CalBak);
	connect(ui.BTN_ADD,SIGNAL(clicked()),this,SLOT(st_BtnAdd()));

	QRegExpValidator* pRevalidotor = new QRegExpValidator(QRegExp("[A-Za-z0-9_-@#$%&*]+&*"), this);
	ui.EDIT_USER->setValidator(pRevalidotor);
	ui.EDIT_PWD->setValidator(pRevalidotor);
	ui.EDIT_PWD2->setValidator(pRevalidotor);

	g_Globle.SetCallback(UserAddCallback,this);
}

CAddUserDlg::~CAddUserDlg()
{

}

void CAddUserDlg::SendToJudgeUser(QString strName)
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_JUDGE_USER;
	root[CMD_JUDGEUSER[EM_JUDGE_USER_NAME]]=strName.toStdString();
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CAddUserDlg::SendToAddUser()
{
	USER_TYPE type = TYPE_MAX;
	QString strName = ui.EDIT_USER->text();
	QString strPwd  = ui.EDIT_PWD->text();
	QString strPwd2 = ui.EDIT_PWD2->text();

	bool nCk = ui.RDO_COMMON->isChecked();//��ͨ�û�
	bool nCk2 = ui.RDO_MANAGE->isChecked();//����Ա
	bool nCk3 = ui.RDO_BKADD->isChecked();//ͼ��¼��Ա

	if(nCk)
		type = TYPE_COMMON;
	else if(nCk2)
		type = TYPE_MNG;
	else if (nCk3)
		type = TYPE_ONLY_BK;

	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_ADD_USER;
	root[CMD_ADDUSER[EM_ADD_USER_NAME]]=strName.toStdString();
	root[CMD_ADDUSER[EM_ADD_USER_PWD]]=strPwd.toStdString();
	root[CMD_ADDUSER[EM_ADD_USER_TYPE]]=type;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CAddUserDlg::st_BtnAdd()
{
	QString strName = ui.EDIT_USER->text();
	QString strPwd  = ui.EDIT_PWD->text();
	QString strPwd2 = ui.EDIT_PWD2->text();

	bool nCk = ui.RDO_COMMON->isChecked();//��ͨ�û�
	bool nCk2 = ui.RDO_MANAGE->isChecked();//����Ա
	bool nCk3 = ui.RDO_BKADD->isChecked();//ͼ��¼��Ա

	if (strName.isEmpty())
	{
		QMessageBox::information(this, CH("��ʾ"), CH("�������˺ţ�"));
		return;
	}
	else if (strPwd.isEmpty())
	{
		QMessageBox::information(this, CH("��ʾ"), CH("���������룡"));
		return;
	}
	else if (strPwd2.isEmpty())
	{
		QMessageBox::information(this, CH("��ʾ"), CH("������ȷ�����룡"));
		return;
	}
	else if (strPwd!=strPwd2)
	{
		QMessageBox::information(this, CH("��ʾ"), CH("���벻һ�£�"));
		return;
	}
	else if (!nCk && !nCk2 && !nCk3)
	{
		QMessageBox::information(this, CH("��ʾ"), CH("��ѡ���û�Ȩ�ޣ�"));
		return;
	}

	SendToJudgeUser(strName);
}
