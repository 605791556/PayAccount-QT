#include "CSetPwdDlg.h"

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
				QMessageBox::information(this, CH("错误"), CH("修改失败！"));
			else
			{
				g_Globle.m_strUserPwd = ui.EDIT_NEWPWD->text();
				QMessageBox::information(this, CH("提示"), CH("修改成功！"));
				reject();
			}
		}
		break;
	}
}

CSetPwdDlg::CSetPwdDlg(QWidget *parent)
	: CDlgFather(parent)
{
	ui.setupUi(this);
	connect(this,&CSetPwdDlg::sg_CalBak,this,&CSetPwdDlg::st_CalBak);
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(BtnSave()));
	g_Globle.m_DlgMap[EM_DLG_SETPWD] = this;
}

CSetPwdDlg::~CSetPwdDlg()
{

}

void CSetPwdDlg::SendToMdfPwd(QString strName,QString strPwd)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_SETPWD;
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
		QMessageBox::information(this, CH("提示"), CH("请输入密码！"));
		return;
	}
	else if (strOldPwd!=g_Globle.m_strUserPwd)
	{
		QMessageBox::information(this, CH("提示"), CH("原密码错误！"));
		return;
	}
	else if (strNewPwd.isEmpty())
	{
		QMessageBox::information(this, CH("提示"), CH("请输入新密码！"));
		return;
	}
	else if (strNewPwd.length()<6)
	{
		QMessageBox::information(this, CH("提示"), CH("密码长度不能小于6位！"));
		return;
	}
	else if (strNewPwd2.isEmpty())
	{
		QMessageBox::information(this, CH("提示"), CH("请输入确认密码！"));
		return;
	}
	else if (strNewPwd!=strNewPwd2)
	{
		QMessageBox::information(this, CH("提示"), CH("新密码不一致，请重新输入！"));
		return;
	}
	else
	{
		SendToMdfPwd(g_Globle.m_strUserName, strNewPwd);
	}
}
