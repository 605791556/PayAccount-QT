#include "CAddBookDlg.h"
#include "CBookMngDlg.h"

void AddBookCallback(void* p,string strData)
{
	CAddBookDlg* pThis=(CAddBookDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CAddBookDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_ADD_BOOK:
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
	case SOCK_CMD_MDF_BOOK:
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
	case SOCK_CMD_JUDGE_BOOK:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("提示"), CH("判断图书是否存在时发生错误！"));
			else
			{
				bool bHad = root[CMD_JUDGEBOOK[EM_JUDGE_BOOK_BHAD]].asBool();
				if(bHad)
				{
					int nType = QMessageBox::warning(this,CH("提示"),CH("该图书名称已存在，是否继续添加？"),
						QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
					if(nType == QMessageBox::Ok)
						SendToAddOrMdfBook();
				}
				else
					SendToAddOrMdfBook();
			}
		}
		break;
	}
}

CAddBookDlg::CAddBookDlg(QWidget* stfMng,bool bAdd,int row,QWidget *parent)
	: QDialog(parent)
{
	m_bAdd = bAdd;
	m_row  = row;

	ui.setupUi(this);
	CGloble::SetButtonStyle(ui.BTN_SAVE,":/PayCount_QT/pic/ok.png",3);
	connect(this,&CAddBookDlg::sg_CalBak,this,&CAddBookDlg::st_CalBak);
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(st_BtnSave()));

	ui.EDIT_YZ->setValidator(g_Globle.dbVtor);
	ui.EDIT_LS->setValidator(g_Globle.dbVtor);
	ui.EDIT_BC1->setValidator(g_Globle.itVtor);
	ui.EDIT_BC2->setValidator(g_Globle.itVtor);
	ui.EDIT_CC1->setValidator(g_Globle.itVtor);
	ui.EDIT_CC2->setValidator(g_Globle.itVtor);
	ui.EDIT_KB->setValidator(g_Globle.itVtor);
	ui.EDIT_YS->setValidator(g_Globle.itVtor);
	ui.EDIT_BC->setValidator(g_Globle.itVtor);
	InitDlg(stfMng,bAdd);
	g_Globle.SetCallback(AddBookCallback,this);
}

CAddBookDlg::~CAddBookDlg()
{

}

void CAddBookDlg::InitDlg(QWidget* stfMng,bool bAdd)
{
	//初始化combobox
	for (int i = 0; i < ZHEYEPAY_TYPE_MAX-1;i++)
		ui.CBX_ZY->addItem(ZyType[i]);

	for (int i=0;i<BOOK_RK_MAX;i++)
		ui.CBX_RK->addItem(rkType[i]);

	QDate date = QDate::currentDate();
	ui.EDIT_DATE->setDate(date);

	if (!bAdd)
	{
		QString str;
		CBookMngDlg* pDlg = (CBookMngDlg*)stfMng;
		//bookID
		m_strBookID = pDlg->ui.tableWidget->item(m_row,1)->data(1).toString();
		//下单日期
		QString strDate =  pDlg->ui.tableWidget->item(m_row,2)->text();
		QDate date2 = QDate::fromString(strDate,"yyyy/MM/dd");
		ui.EDIT_DATE->setDate(date2);
		//书名
		QString strName =  pDlg->ui.tableWidget->item(m_row,3)->text();
		ui.EDIT_NAME->setText(strName);
		//出版社
		QString strCbs =  pDlg->ui.tableWidget->item(m_row,4)->text();
		ui.EDIT_CBS->setText(strCbs);
		//版次
		int nBc1 = pDlg->m_vet[m_row].nBc1;
		int nBc2 = pDlg->m_vet[m_row].nBc2;
		str = QString("%1").arg(nBc1);
		ui.EDIT_BC1->setText(str);
		str = QString("%1").arg(nBc2);
		ui.EDIT_BC2->setText(str);
		//成品尺寸
		int nCc1 = pDlg->m_vet[m_row].nSize1;
		int nCc2 = pDlg->m_vet[m_row].nSize2;
		str = QString("%1").arg(nCc1);
		ui.EDIT_CC1->setText(str);
		str = QString("%1").arg(nCc2);
		ui.EDIT_CC2->setText(str);
		//开本
		QString strKb =  pDlg->ui.tableWidget->item(m_row,7)->text();
		ui.EDIT_KB->setText(strKb);
		//印张
		QString strYz =  pDlg->ui.tableWidget->item(m_row,8)->text();
		ui.EDIT_YZ->setText(strYz);
		//印数
		QString strYs =  pDlg->ui.tableWidget->item(m_row,9)->text();
		ui.EDIT_YS->setText(strYs);
		//包册
		QString strBc =  pDlg->ui.tableWidget->item(m_row,10)->text();
		ui.EDIT_BC->setText(strBc);
		//令数
		QString strLs =  pDlg->ui.tableWidget->item(m_row,11)->text();
		ui.EDIT_LS->setText(strLs);

		//印张类型
		BOOK_TYPE yzType = pDlg->m_vet[m_row].type;
		if(yzType ==  BOOK_TYPE_QUAN)
			ui.RDO_QK->setChecked(true);
		else if(yzType == BOOK_TYPE_DUI)
			ui.RDO_DK->setChecked(true);

		//折页类型
		int zyType = pDlg->m_vet[m_row].zyType;
		ui.CBX_ZY->setCurrentIndex(zyType-1);
		//入库类型
		ui.CBX_RK->setCurrentIndex(pDlg->m_vet[m_row].rkType);
		//备注
		ui.EDIT_BZ->setText(pDlg->m_vet[m_row].strMsg);

		ui.BTN_SAVE->setText(CH("保存"));
	}
}

void CAddBookDlg::st_BtnSave()
{
	m_bookstu.strname = ui.EDIT_NAME->text();
	m_bookstu.strCbs = ui.EDIT_CBS->text();

	QDate date = ui.EDIT_DATE->date();
	m_bookstu.strDate = date.toString("yyyy/MM/dd");
	
	m_bookstu.nBc1 = ui.EDIT_BC1->text().toInt();
	m_bookstu.nBc2 = ui.EDIT_BC2->text().toInt();

	m_bookstu.nSize1 = ui.EDIT_CC1->text().toInt();
	m_bookstu.nSize2 = ui.EDIT_CC2->text().toInt();

	m_bookstu.nKb = ui.EDIT_KB->text().toInt();//开本

	m_bookstu.fYz = ui.EDIT_YZ->text().toDouble();//印张
	m_bookstu.nYs = ui.EDIT_YS->text().toInt();

	m_bookstu.nBc = ui.EDIT_BC->text().toInt();//包册

	m_bookstu.fLs = ui.EDIT_LS->text().toDouble();//令数

	if (m_bookstu.strname == "" || m_bookstu.nBc1==0 || m_bookstu.nBc2==0 ||m_bookstu.nSize1==0||m_bookstu.nSize2==0||m_bookstu.nKb==0||m_bookstu.fYz==0||m_bookstu.nYs==0|| m_bookstu.nBc==0||m_bookstu.fLs==0)
	{
		QMessageBox::information(this, CH("提示"), CH("请将信息填写完整！"));
		return;
	}
	BOOK_TYPE type = BOOK_TYPE_MAX;
	if (ui.RDO_QK->isChecked())
		m_bookstu.type = BOOK_TYPE_QUAN;
	else if (ui.RDO_DK->isChecked())
		m_bookstu.type = BOOK_TYPE_DUI;

	if (m_bookstu.type == BOOK_TYPE_MAX)
	{
		QMessageBox::information(this, CH("提示"), CH("请选择印张类型！"));
		return;
	}

	//折页类型
	m_bookstu.zyType = (ZHEYEPAY_TYPE)(ui.CBX_ZY->currentIndex()+1);

	//入库状态
	m_bookstu.rkType = (BOOK_RK)ui.CBX_RK->currentIndex();
	//备注
	m_bookstu.strMsg = ui.EDIT_BZ->toPlainText();

	if(m_bAdd)
	{
		//生成唯一ID
		m_bookstu.strBookID = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
		SendToJudgeBook(m_bookstu.strname);
	}
	else
	{
		m_bookstu.strBookID = m_strBookID;
		SendToAddOrMdfBook(SOCK_CMD_MDF_BOOK);
	}
}

void CAddBookDlg::SendToJudgeBook(QString strName)
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_JUDGE_BOOK;
	string sstrname = strName.toLocal8Bit();
	root[CMD_JUDGEBOOK[EM_JUDGE_BOOK_NAME]]=sstrname;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CAddBookDlg::SendToAddOrMdfBook(EM_SOCK_CMD type)
{
	Json::Value root;
	root[CONNECT_CMD]=type;
	root[CMD_BOOKMSG[BOOKMSG_ID]]=m_bookstu.strBookID.toStdString();
	string strname = m_bookstu.strname.toLocal8Bit();
	root[CMD_BOOKMSG[BOOKMSG_NAME]]=strname;
	string strCbs = m_bookstu.strCbs.toLocal8Bit();
	root[CMD_BOOKMSG[BOOKMSG_CBS]]=strCbs;
	root[CMD_BOOKMSG[BOOKMSG_DATE]]=m_bookstu.strDate.toStdString();;
	root[CMD_BOOKMSG[BOOKMSG_BC1]]=m_bookstu.nBc1;
	root[CMD_BOOKMSG[BOOKMSG_BC2]]=m_bookstu.nBc2;
	root[CMD_BOOKMSG[BOOKMSG_SIZE1]]=m_bookstu.nSize1;
	root[CMD_BOOKMSG[BOOKMSG_SIZE2]]=m_bookstu.nSize2;
	root[CMD_BOOKMSG[BOOKMSG_KB]]=m_bookstu.nKb;
	root[CMD_BOOKMSG[BOOKMSG_YZ]]=m_bookstu.fYz;
	root[CMD_BOOKMSG[BOOKMSG_YS]]=m_bookstu.nYs;
	root[CMD_BOOKMSG[BOOKMSG_BC]]=m_bookstu.nBc;
	root[CMD_BOOKMSG[BOOKMSG_LS]]=m_bookstu.fLs;
	root[CMD_BOOKMSG[BOOKMSG_B_TYPE]]=m_bookstu.type;
	root[CMD_BOOKMSG[BOOKMSG_ZY_TYPE]]=m_bookstu.zyType;
	root[CMD_BOOKMSG[BOOKMSG_RK_TYPE]]=m_bookstu.rkType;
	string strMsg = m_bookstu.strMsg.toLocal8Bit();
	root[CMD_BOOKMSG[BOOKMSG_MSG]]=strMsg;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}
