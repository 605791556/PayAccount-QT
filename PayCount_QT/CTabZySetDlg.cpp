#include "CTabZySetDlg.h"

void ZySetCallback(void* p,string strData)
{
	CTabZySetDlg* pThis=(CTabZySetDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CTabZySetDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_GET_ZHEYEPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取数据失败！"));
			else
			{
				GetZheyePay(root);
			}
		}
		break;
	case SOCK_CMD_SET_ZHEYEPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取数据失败！"));
			else
			{
				QMessageBox::information(this, CH("提示"), CH("保存成功！"));
			}
		}
		break;
	}
}

CTabZySetDlg::CTabZySetDlg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(this,&CTabZySetDlg::sg_CalBak,this,&CTabZySetDlg::st_CalBak);
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(st_BtnSave()));
}

CTabZySetDlg::~CTabZySetDlg()
{

}

void CTabZySetDlg::pageIn()
{
	g_Globle.SetCallback(ZySetCallback,this);
	SendToGetZheyePay();
}

void CTabZySetDlg::SendToGetZheyePay()
{
	USES_CONVERSION;
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_ZHEYEPAY;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("错误"), CH("发送网络请求失败，请检查网络是否正常！"));
	}
}

void CTabZySetDlg::SendToSaveZheyePay(STU_ZHEYE_PAY stu)
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_SET_ZHEYEPAY;

	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_AQ4]]=stu.strAQ4.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_A4]]=stu.strA4.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_AD3]]=stu.strAD3.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_A3]]=stu.strA3.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_A2]]=stu.strA2.toStdString();

	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_Q4]]=stu.str_sf_Q4.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_4]]=stu.str_sf_4.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_D3]]=stu.str_sf_D3.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_3]]=stu.str_sf_3.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_2]]=stu.str_sf_2.toStdString();

	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_Q4]]=stu.str_td_Q4.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_4]]=stu.str_td_4.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_D3]]=stu.str_td_D3.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_3]]=stu.str_td_3.toStdString();
	root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_2]]=stu.str_td_2.toStdString();

	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("错误"), CH("发送网络请求失败，请检查网络是否正常！"));
	}
}

void CTabZySetDlg::GetZheyePay(Json::Value root)
{
	STU_ZHEYE_PAY stu;
	stu.strAQ4 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_AQ4]].asCString();
	stu.strA4 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_A4]].asCString();
	stu.strAD3 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_AD3]].asCString();
	stu.strA3 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_A3]].asCString();
	stu.strA2 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_A2]].asCString();

	stu.str_sf_Q4 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_Q4]].asCString();
	stu.str_sf_4 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_4]].asCString();
	stu.str_sf_D3 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_D3]].asCString();
	stu.str_sf_3 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_3]].asCString();
	stu.str_sf_2 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_2]].asCString();

	stu.str_td_Q4 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_Q4]].asCString();
	stu.str_td_4 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_4]].asCString();
	stu.str_td_D3 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_D3]].asCString();
	stu.str_td_3 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_3]].asCString();
	stu.str_td_2 = root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_2]].asCString();

	ui.EDIT_SG_Q4->setText(stu.strAQ4);
	ui.EDIT_SG_4->setText(stu.strA4);
	ui.EDIT_SG_D3->setText(stu.strAD3);
	ui.EDIT_SG_3->setText(stu.strA3);
	ui.EDIT_SG_2->setText(stu.strA2);

	ui.EDIT_S_Q4->setText(stu.str_sf_Q4);
	ui.EDIT_S_4->setText(stu.str_sf_4);
	ui.EDIT_S_D3->setText(stu.str_sf_D3);
	ui.EDIT_S_3->setText(stu.str_sf_3);
	ui.EDIT_S_2->setText(stu.str_sf_2);

	ui.EDIT_G_Q4->setText(stu.str_td_Q4);
	ui.EDIT_G_4->setText(stu.str_td_4);
	ui.EDIT_G_D3->setText(stu.str_td_D3);
	ui.EDIT_G_3->setText(stu.str_td_3);
	ui.EDIT_G_2->setText(stu.str_td_2);
}

void CTabZySetDlg::st_BtnSave()
{
	STU_ZHEYE_PAY stu;
	stu.strAQ4 = ui.EDIT_SG_Q4->text();
	stu.strA4 = ui.EDIT_SG_4->text();
	stu.strAD3 = ui.EDIT_SG_D3->text();
	stu.strA3 = ui.EDIT_SG_3->text();
	stu.strA2 = ui.EDIT_SG_2->text();

	stu.str_sf_Q4 = ui.EDIT_S_Q4->text();
	stu.str_sf_4 = ui.EDIT_S_4->text();
	stu.str_sf_D3 = ui.EDIT_S_D3->text();
	stu.str_sf_3 = ui.EDIT_S_3->text();
	stu.str_sf_2 = ui.EDIT_S_2->text();

	stu.str_td_Q4 = ui.EDIT_G_Q4->text();
	stu.str_td_4 = ui.EDIT_G_4->text();
	stu.str_td_D3 = ui.EDIT_G_D3->text();
	stu.str_td_3 = ui.EDIT_G_3->text();
	stu.str_td_2 = ui.EDIT_G_2->text();

	if (stu.strAQ4.isEmpty() || stu.strA4.isEmpty() || stu.strAD3.isEmpty() || stu.strA3.isEmpty() || stu.strA2.isEmpty())
	{
		QMessageBox::information(this, CH("错误"), CH("请输入完整数据！"));
		return;
	}
	if (stu.str_sf_Q4.isEmpty() || stu.str_sf_4.isEmpty() || stu.str_sf_D3.isEmpty() || stu.str_sf_3.isEmpty() || stu.str_sf_2.isEmpty())
	{
		QMessageBox::information(this, CH("错误"), CH("请输入完整数据！"));
		return;
	}
	if (stu.str_td_Q4.isEmpty() || stu.str_td_4.isEmpty() || stu.str_td_D3.isEmpty() || stu.str_td_3.isEmpty() || stu.str_td_2.isEmpty())
	{
		QMessageBox::information(this, CH("错误"), CH("请输入完整数据！"));
		return;
	}
	SendToSaveZheyePay(stu);
}