#include "CAddProDlg.h"
#include "CProMngDlg.h"

void CAddProDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_ADD_PROJECT:
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
	case SOCK_CMD_MDF_PROJECT:
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
	case SOCK_CMD_JUDGE_PROJECT:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("判断项目是否存在时发生错误！"));
			else
			{
				bool bHad = root[CMD_JUDGEPROJECT[EM_JUDGE_PROJECT_BHAD]].asBool();
				if(bHad)
				{
					QMessageBox::information(this, CH("提示"), CH("该项目名称已存在！"));
				}
				else
				{
					SendToAddOrMdfProject();	
				}
			}
		}
		break;
	}
}

CAddProDlg::CAddProDlg(QWidget* proMng,bool bAdd,int row,QWidget *parent)
	: CDlgFather(parent)
{
	m_bAdd = bAdd;
	m_row  = row;
	ui.setupUi(this);
	CGloble::SetButtonStyle(ui.BTN_SAVE,":/PayCount_QT/pic/ok.png",3);
	connect(this,&CAddProDlg::sg_CalBak,this,&CAddProDlg::st_CalBak);
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(st_BtnSave()));
	InitDlg(proMng,bAdd);

	g_Globle.m_DlgMap[EM_DLG_ADDPRO] = this;
}

CAddProDlg::~CAddProDlg()
{

}

void CAddProDlg::InitDlg(QWidget* proMng,bool bAdd)
{
	m_btnGroup1 = new QButtonGroup(this);
	m_btnGroup2 = new QButtonGroup(this);
	m_btnGroup1->addButton(ui.RDO_ZLS,1);
	m_btnGroup1->addButton(ui.RDO_ZYS,2);
	m_btnGroup2->addButton(ui.RDO_YES,3);
	m_btnGroup2->addButton(ui.RDO_NO,4);

	if (!bAdd)
	{
		CProMngDlg* pDlg = (CProMngDlg*)proMng;
		m_proID = pDlg->m_vet[m_row].nID;
		QString strName = pDlg->m_vet[m_row].strName;
		PRO_NUM_TYPE pro_num_type = pDlg->m_vet[m_row].pn_type;
		PRO_STAFF_TYPE pro_staff_type = pDlg->m_vet[m_row].ps_type;

		ui.EDIT_PRONAME->setText(strName);
		if(m_proID <= 8)
			ui.EDIT_PRONAME->setEnabled(false);

		if(pro_num_type == PRO_NUM_TYPE_YS)
			ui.RDO_ZYS->setChecked(true);
		else if(pro_num_type == PRO_NUM_TYPE_LS)
			ui.RDO_ZLS->setChecked(true);

		if(pro_staff_type == PRO_STAFF_TYPE_YES)
			ui.RDO_YES->setChecked(true);
		else if(pro_staff_type == PRO_STAFF_TYPE_NO)
			ui.RDO_NO->setChecked(true);
	}
}

void CAddProDlg::SendToJudgePro(QString strProName)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_ADDPRO;
	root[CONNECT_CMD]=SOCK_CMD_JUDGE_PROJECT;
	string sstrname = strProName.toLocal8Bit();
	root[CMD_JUDGEBOOK[EM_JUDGE_PROJECT_NAME]]=sstrname;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("错误"), CH("发送网络请求失败，请检查网络是否正常！"));
	}
}

void CAddProDlg::SendToAddOrMdfProject(EM_SOCK_CMD type)
{
	PRO_NUM_TYPE pm_type = PRO_NUM_TYPE_MAX;
	PRO_STAFF_TYPE pf_type = PRO_STAFF_TYPE_MAX;
	QString strName = ui.EDIT_PRONAME->text();

	if(ui.RDO_ZYS->isChecked())
		pm_type = PRO_NUM_TYPE_YS;
	else if(ui.RDO_ZLS->isChecked())
		pm_type = PRO_NUM_TYPE_LS;

	if(ui.RDO_YES->isChecked())
		pf_type = PRO_STAFF_TYPE_YES;
	else if(ui.RDO_NO->isChecked())
		pf_type = PRO_STAFF_TYPE_NO;

	Json::Value root;
	root[CMD_DLG]=EM_DLG_ADDPRO;
	root[CONNECT_CMD]=type;
	string sstrname = strName.toLocal8Bit();
	root[CMD_PROMSG[EM_PROMSG_NAME]]=sstrname;
	root[CMD_PROMSG[EM_PROMSG_NUM_TYPE]]=pm_type;
	root[CMD_PROMSG[EM_PROMSG_BWRITE]]=pf_type;
	if (type == SOCK_CMD_MDF_PROJECT)
	{
		root[CMD_PROMSG[EM_PROMSG_ID]]=m_proID;
	}
	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("错误"), CH("发送网络请求失败，请检查网络是否正常！"));
	}
}

void CAddProDlg::st_BtnSave()
{
	PRO_NUM_TYPE pm_type = PRO_NUM_TYPE_MAX;
	PRO_STAFF_TYPE pf_type = PRO_STAFF_TYPE_MAX;
	QString strName = ui.EDIT_PRONAME->text();

	if(ui.RDO_ZYS->isChecked())
		pm_type = PRO_NUM_TYPE_YS;
	else if(ui.RDO_ZLS->isChecked())
		pm_type = PRO_NUM_TYPE_LS;

	if(ui.RDO_YES->isChecked())
		pf_type = PRO_STAFF_TYPE_YES;
	else if(ui.RDO_NO->isChecked())
		pf_type = PRO_STAFF_TYPE_NO;

	if (strName.isEmpty())
	{
		QMessageBox::information(this, CH("提示"), CH("请输入项目名称！"));
		return;
	}
	else if (pm_type == PRO_NUM_TYPE_MAX)
	{
		QMessageBox::information(this, CH("提示"), CH("请选择范围类型！"));
		return;
	}
	else if (pf_type == PRO_STAFF_TYPE_MAX)
	{
		QMessageBox::information(this, CH("提示"), CH("请选择是否工人填入！"));
		return;
	}

	if (m_bAdd)
		SendToJudgePro(strName);
	else
		SendToAddOrMdfProject(SOCK_CMD_MDF_PROJECT);
}
