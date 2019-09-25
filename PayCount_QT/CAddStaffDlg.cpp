#include "CAddStaffDlg.h"

void AddStaffCallback(void* p,string strData)
{
	CAddStaffDlg* pThis=(CAddStaffDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CAddStaffDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_ADD_STAFF:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("添加失败！"));
			else
			{
				QMessageBox::information(this, CH("提示"), CH("添加成功！"));
				accept();
			}
		}
		break;
	case SOCK_CMD_MDF_STAFF:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("修改失败！"));
			else
			{
				QMessageBox::information(this, CH("提示"), CH("修改成功！"));
				accept();
			}
		}
		break;
	case SOCK_CMD_JUDGE_STAFF:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("判断职工是否存在时发生错误！"));
			else
			{
				bool bHad = root[CMD_JUDGESTAFF[EM_JUDGE_STAFF_BHAD]].asBool();
				if(bHad)
					QMessageBox::information(this, CH("错误"), CH("该身份证职工已存在！"));
				else
				{
					//SendToAddStaff();	
				}
			}
		}
		break;
	}
}

CAddStaffDlg::CAddStaffDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CAddStaffDlg::~CAddStaffDlg()
{

}

void CAddStaffDlg::st_BtnSave()
{

}
