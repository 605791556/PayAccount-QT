#include "CAddStaffDlg.h"
#include "CStaffMngDlg.h"

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
					SendToAddStaff();	
			}
		}
		break;
	}
}

CAddStaffDlg::CAddStaffDlg(QWidget* stfMng,bool bAdd,int row,QWidget *parent)
	: CDlgFather(parent)
{
	m_bAdd = bAdd;
	m_row  = row;
	ui.setupUi(this);
	CGloble::SetButtonStyle(ui.BTN_SAVE,":/PayCount_QT/pic/ok.png",3);
	connect(this,&CAddStaffDlg::sg_CalBak,this,&CAddStaffDlg::st_CalBak);
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(st_BtnSave()));
	InitDlg(stfMng,bAdd);

	ui.EDIT_AGE->setValidator(g_Globle.itVtor);
	ui.EDIT_IDCARD->setValidator(g_Globle.nzVtor);
	ui.EDIT_TEL->setValidator(g_Globle.itVtor);
	ui.EDIT_DEX->setValidator(g_Globle.itVtor);
	ui.EDIT_DAYPAY->setValidator(g_Globle.dbVtor);

	g_Globle.m_DlgMap[EM_DLG_ADDSTAFF] = this;
}

CAddStaffDlg::~CAddStaffDlg()
{

}

void CAddStaffDlg::InitDlg(QWidget* stfMng,bool bAdd)
{
	ui.COMBO_SEX->addItem(CH("男"));
	ui.COMBO_SEX->addItem(CH("女"));
	ui.COMBO_SEX->setCurrentIndex(0);

	for (int i =0;i<STAFF_TYPE_MAX;i++)
	{
		ui.COMBO_TYPE->addItem(StaffType[i]);
	}

	if (!bAdd)
	{
		CStaffMngDlg* pDlg = (CStaffMngDlg*)stfMng;
		m_strStaffID = pDlg->ui.tableWidget->item(m_row,1)->data(1).toString();

		QString strname= pDlg->ui.tableWidget->item(m_row,1)->text();
		ui.EDIT_NAME->setText(strname);
		QString strsex= pDlg->ui.tableWidget->item(m_row,2)->text();
		if (strsex == "男")
			ui.COMBO_SEX->setCurrentIndex(0);
		else
			ui.COMBO_SEX->setCurrentIndex(1);

		QString strage=pDlg->ui.tableWidget->item(m_row,3)->text();
		ui.EDIT_AGE->setText(strage);

		QString idcard=pDlg->m_vet[m_row].strIdCard;
		strOldIdcard=idcard;
		ui.EDIT_IDCARD->setText(idcard);

		QString strtell=pDlg->ui.tableWidget->item(m_row,5)->text();
		ui.EDIT_TEL->setText(strtell);

		QString strDex = QString("%1").arg(pDlg->m_vet[m_row].sort);
		ui.EDIT_DEX->setText(strDex);

		QString strType = pDlg->ui.tableWidget->item(m_row,6)->text();
		for (int i =0;i<STAFF_TYPE_MAX;i++)
		{
			if (strType == StaffType[i])
				ui.COMBO_TYPE->setCurrentIndex(i);
		}

		QString strDaypay=pDlg->ui.tableWidget->item(m_row,7)->text();
		ui.EDIT_DAYPAY->setText(strDaypay);

		ui.BTN_SAVE->setText(CH("保存"));
	}
}

void CAddStaffDlg::SendToJudgeStaff(QString strIdcard)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_ADDSTAFF;
	root[CONNECT_CMD]=SOCK_CMD_JUDGE_STAFF;
	root[CMD_JUDGESTAFF[EM_JUDGE_STAFF_IDCARD]]=strIdcard.toStdString();
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CAddStaffDlg::SendToAddStaff()
{
	QString strName=ui.EDIT_NAME->text();
	QString strSex= ui.COMBO_SEX->currentText();
	int age = ui.EDIT_AGE->text().toInt();
	QString strIDCARD= ui.EDIT_IDCARD->text();
	QString strTel= ui.EDIT_TEL->text();
	STAFF_TYPE type = (STAFF_TYPE)ui.COMBO_TYPE->currentIndex();
	int sort = ui.EDIT_DEX->text().toInt();

	QString strDayPay= ui.EDIT_DAYPAY->text();
	double fDayPay = strDayPay.toDouble();

	//生成唯一ID
	QString  strStaffID = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");

	Json::Value root;
	root[CMD_DLG]=EM_DLG_ADDSTAFF;
	root[CONNECT_CMD]=SOCK_CMD_ADD_STAFF;
	string sstrname = strName.toLocal8Bit();
	root[CMD_STAFFMSG[EM_STAFF_MSG_NAME]]=sstrname;
	string sstrsex = strSex.toLocal8Bit();
	root[CMD_STAFFMSG[EM_STAFF_MSG_SEX]]=sstrsex;
	root[CMD_STAFFMSG[EM_STAFF_MSG_AGE]]=age;
	root[CMD_STAFFMSG[EM_STAFF_MSG_STAFFID]]=strStaffID.toStdString();
	root[CMD_STAFFMSG[EM_STAFF_MSG_IDCARD]]=strIDCARD.toStdString();
	root[CMD_STAFFMSG[EM_STAFF_MSG_TEL]]=strTel.toStdString();
	root[CMD_STAFFMSG[EM_STAFF_MSG_TYPE]]=type;
	root[CMD_STAFFMSG[EM_STAFF_MSG_SORT]]=sort;
	root[CMD_STAFFMSG[EM_STAFF_MSG_DAYPAY]]=fDayPay;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);

}

void CAddStaffDlg::SendToMdfStaff(QString strName,QString strSex,int age,QString strStaffID, QString strIdcard,QString strTel,STAFF_TYPE type,int sort,double fDaypay)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_ADDSTAFF;
	root[CONNECT_CMD]=SOCK_CMD_MDF_STAFF;
	string sstrname = strName.toLocal8Bit();
	root[CMD_STAFFMSG[EM_STAFF_MSG_NAME]]=sstrname;
	string sstrsex = strSex.toLocal8Bit();
	root[CMD_STAFFMSG[EM_STAFF_MSG_SEX]]=sstrsex;
	root[CMD_STAFFMSG[EM_STAFF_MSG_AGE]]=age;
	root[CMD_STAFFMSG[EM_STAFF_MSG_STAFFID]]=strStaffID.toStdString();
	root[CMD_STAFFMSG[EM_STAFF_MSG_IDCARD]]=strIdcard.toStdString();
	root[CMD_STAFFMSG[EM_STAFF_MSG_TEL]]=strTel.toStdString();
	root[CMD_STAFFMSG[EM_STAFF_MSG_TYPE]]=type;
	root[CMD_STAFFMSG[EM_STAFF_MSG_SORT]]=sort;
	root[CMD_STAFFMSG[EM_STAFF_MSG_DAYPAY]]=fDaypay;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CAddStaffDlg::st_BtnSave()
{
	QString strName=ui.EDIT_NAME->text();
	QString strSex= ui.COMBO_SEX->currentText();
	int age = ui.EDIT_AGE->text().toInt();
	QString strIDCARD= ui.EDIT_IDCARD->text();
	QString strTel= ui.EDIT_TEL->text();
	STAFF_TYPE type = (STAFF_TYPE)ui.COMBO_TYPE->currentIndex();
	int sort = ui.EDIT_DEX->text().toInt();

	QString strDayPay= ui.EDIT_DAYPAY->text();
	double fDayPay = strDayPay.toDouble();

	if (strName.isEmpty())
	{
		QMessageBox::information(this, CH("提示"), CH("请输入姓名！"));
		return;
	}

	if(m_bAdd)
	{
		if (strIDCARD.isEmpty())
			SendToAddStaff();
		else
			SendToJudgeStaff(strIDCARD);
		
	}
	else
	{
		if (m_row<0)
		{
			QMessageBox::information(this, CH("错误"), CH("参数错误！"));
			return;
		}
		
		SendToMdfStaff(strName,strSex,age,m_strStaffID,strIDCARD,strTel,type,sort,fDayPay);
	}
}
