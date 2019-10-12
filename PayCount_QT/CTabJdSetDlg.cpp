#include "CTabJdSetDlg.h"

void JdSetCallback(void* p,string strData)
{
	CTabJdSetDlg* pThis=(CTabJdSetDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CTabJdSetDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_GET_DAIPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取数据失败！"));
			else
			{
				GetDaiPay(root);
			}
		}
		break;
	case SOCK_CMD_SET_DAIPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("保存数据失败！"));
			else
			{
				QMessageBox::information(this, CH("提示"), CH("保存成功！"));
			}
		}
		break;
	}
}

CTabJdSetDlg::CTabJdSetDlg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(this,&CTabJdSetDlg::sg_CalBak,this,&CTabJdSetDlg::st_CalBak);
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(st_BtnSave()));

	ui.EDIT_SG_W->setValidator(g_Globle.dbVtor);
	ui.EDIT_SG_2->setValidator(g_Globle.dbVtor);
	ui.EDIT_SG_2_5->setValidator(g_Globle.dbVtor);
	ui.EDIT_SG_5_9->setValidator(g_Globle.dbVtor);
	ui.EDIT_SG_10->setValidator(g_Globle.dbVtor);
	ui.EDIT_SG_18->setValidator(g_Globle.dbVtor);

	ui.EDIT_S_W->setValidator(g_Globle.dbVtor);
	ui.EDIT_S_2->setValidator(g_Globle.dbVtor);
	ui.EDIT_S_2_5->setValidator(g_Globle.dbVtor);
	ui.EDIT_S_5_9->setValidator(g_Globle.dbVtor);
	ui.EDIT_S_10->setValidator(g_Globle.dbVtor);
	ui.EDIT_S_18->setValidator(g_Globle.dbVtor);

	ui.EDIT_G_W->setValidator(g_Globle.dbVtor);
	ui.EDIT_G_2->setValidator(g_Globle.dbVtor);
	ui.EDIT_G_2_5->setValidator(g_Globle.dbVtor);
	ui.EDIT_G_5_9->setValidator(g_Globle.dbVtor);
	ui.EDIT_G_10->setValidator(g_Globle.dbVtor);
	ui.EDIT_G_18->setValidator(g_Globle.dbVtor);

	g_Globle.SetCallback(JdSetCallback,this);
	SendToGetDaiPay();
}

CTabJdSetDlg::~CTabJdSetDlg()
{

}

void CTabJdSetDlg::pageIn()
{
	g_Globle.SetCallback(JdSetCallback,this);
	SendToGetDaiPay();
}

void CTabJdSetDlg::SendToGetDaiPay()
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_DAIPAY;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("错误"), CH("发送网络请求失败，请检查网络是否正常！"));
	}
}

void CTabJdSetDlg::GetDaiPay(Json::Value root)
{
	STU_DAI_PAY stu;
	stu.strA_w = root[CMD_DAIPAY[EM_DAI_PAY_A_W]].asCString();
	stu.strSf_w = root[CMD_DAIPAY[EM_DAI_PAY_Sf_w]].asCString();
	stu.strTd_w = root[CMD_DAIPAY[EM_DAI_PAY_Td_w]].asCString();
	
	stu.strA_2 = root[CMD_DAIPAY[EM_DAI_PAY_2]].asCString();
	stu.strSf_2 = root[CMD_DAIPAY[EM_DAI_PAY_Sf_2]].asCString();
	stu.strTd_2 = root[CMD_DAIPAY[EM_DAI_PAY_Td_2]].asCString();

	stu.strA_2_5 = root[CMD_DAIPAY[EM_DAI_PAY_2_5]].asCString();
	stu.strSf_2_5 = root[CMD_DAIPAY[EM_DAI_PAY_Sf_2_5]].asCString();
	stu.strTd_2_5 = root[CMD_DAIPAY[EM_DAI_PAY_Td_2_5]].asCString();

	stu.strA_5_9 = root[CMD_DAIPAY[EM_DAI_PAY_5_9]].asCString();
	stu.strSf_5_9 = root[CMD_DAIPAY[EM_DAI_PAY_Sf_5_9]].asCString();
	stu.strTd_5_9 = root[CMD_DAIPAY[EM_DAI_PAY_Td_5_9]].asCString();

	stu.strA_10 = root[CMD_DAIPAY[EM_DAI_PAY_10]].asCString();
	stu.strSf_10 = root[CMD_DAIPAY[EM_DAI_PAY_Sf_10]].asCString();
	stu.strTd_10 = root[CMD_DAIPAY[EM_DAI_PAY_Td_10]].asCString();

	stu.strA_18 = root[CMD_DAIPAY[EM_DAI_PAY_18]].asCString();
	stu.strSf_18 = root[CMD_DAIPAY[EM_DAI_PAY_Sf_18]].asCString();
	stu.strTd_18 = root[CMD_DAIPAY[EM_DAI_PAY_Td_18]].asCString();

	ui.EDIT_SG_W->setText(stu.strA_w);
	ui.EDIT_SG_2->setText(stu.strA_2);
	ui.EDIT_SG_2_5->setText(stu.strA_2_5);
	ui.EDIT_SG_5_9->setText(stu.strA_5_9);
	ui.EDIT_SG_10->setText(stu.strA_10);
	ui.EDIT_SG_18->setText(stu.strA_18);

	ui.EDIT_S_W->setText(stu.strSf_w);
	ui.EDIT_S_2->setText(stu.strSf_2);
	ui.EDIT_S_2_5->setText(stu.strSf_2_5);
	ui.EDIT_S_5_9->setText(stu.strSf_5_9);
	ui.EDIT_S_10->setText(stu.strSf_10);
	ui.EDIT_S_18->setText(stu.strSf_18);

	ui.EDIT_G_W->setText(stu.strTd_w);
	ui.EDIT_G_2->setText(stu.strTd_2);
	ui.EDIT_G_2_5->setText(stu.strTd_2_5);
	ui.EDIT_G_5_9->setText(stu.strTd_5_9);
	ui.EDIT_G_10->setText(stu.strTd_10);
	ui.EDIT_G_18->setText(stu.strTd_18);
}

void CTabJdSetDlg::SendToSaveDaiPay(STU_DAI_PAY stu)
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_SET_DAIPAY;

	root[CMD_DAIPAY[EM_DAI_PAY_A_W]]=stu.strA_w.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Sf_w]]=stu.strSf_w.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Td_w]] = stu.strTd_w.toStdString();

	root[CMD_DAIPAY[EM_DAI_PAY_2]]=stu.strA_2.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Sf_2]]=stu.strSf_2.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Td_2]] = stu.strTd_2.toStdString();

	root[CMD_DAIPAY[EM_DAI_PAY_2_5]]=stu.strA_2_5.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Sf_2_5]]=stu.strSf_2_5.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Td_2_5]] =stu.strTd_2_5.toStdString();

	root[CMD_DAIPAY[EM_DAI_PAY_5_9]]=stu.strA_5_9.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Sf_5_9]]=stu.strSf_5_9.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Td_5_9]] =stu.strTd_5_9.toStdString();

	root[CMD_DAIPAY[EM_DAI_PAY_10]]=stu.strA_10.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Sf_10]]=stu.strSf_10.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Td_10]] =stu.strTd_10.toStdString();

	root[CMD_DAIPAY[EM_DAI_PAY_18]]=stu.strA_18.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Sf_18]]=stu.strSf_18.toStdString();
	root[CMD_DAIPAY[EM_DAI_PAY_Td_18]] =stu.strTd_18.toStdString();

	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("错误"), CH("发送网络请求失败，请检查网络是否正常！"));
	}
}

void CTabJdSetDlg::st_BtnSave()
{
	STU_DAI_PAY stu;
	stu.strA_w = ui.EDIT_SG_W->text();
	stu.strA_2= ui.EDIT_SG_2->text();
	stu.strA_2_5= ui.EDIT_SG_2_5->text();
	stu.strA_5_9= ui.EDIT_SG_5_9->text();
	stu.strA_10= ui.EDIT_SG_10->text();
	stu.strA_18= ui.EDIT_SG_18->text();
	stu.strSf_w= ui.EDIT_S_W->text();
	stu.strSf_2= ui.EDIT_S_2->text();
	stu.strSf_2_5= ui.EDIT_S_2_5->text();
	stu.strSf_5_9= ui.EDIT_S_5_9->text();
	stu.strSf_10= ui.EDIT_S_10->text();
	stu.strSf_18= ui.EDIT_S_18->text();
	stu.strTd_w= ui.EDIT_G_W->text();
	stu.strTd_2= ui.EDIT_G_2->text();
	stu.strTd_2_5= ui.EDIT_G_2_5->text();
	stu.strTd_5_9= ui.EDIT_G_5_9->text();
	stu.strTd_10= ui.EDIT_G_10->text();
	stu.strTd_18= ui.EDIT_G_18->text();

	if (stu.strA_w.isEmpty() || stu.strA_2.isEmpty() || stu.strA_2_5.isEmpty() || stu.strA_5_9.isEmpty() || stu.strA_10.isEmpty() || stu.strA_18.isEmpty())
	{
		QMessageBox::information(this, CH("提示"), CH("请输入完整数据！"));
		return;
	}
	if (stu.strSf_w.isEmpty() || stu.strSf_2.isEmpty() || stu.strSf_2_5.isEmpty() || stu.strSf_5_9.isEmpty() || stu.strSf_10.isEmpty() || stu.strSf_18.isEmpty())
	{
		QMessageBox::information(this, CH("提示"), CH("请输入完整数据！"));
		return;
	}
	if (stu.strTd_w.isEmpty() || stu.strTd_2.isEmpty() || stu.strTd_2_5.isEmpty() || stu.strTd_5_9.isEmpty() || stu.strTd_10.isEmpty() || stu.strTd_18.isEmpty())
	{
		QMessageBox::information(this, CH("提示"), CH("请输入完整数据！"));
		return;
	}

	SendToSaveDaiPay(stu);
}