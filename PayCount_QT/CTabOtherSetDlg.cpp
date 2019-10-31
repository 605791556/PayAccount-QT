#include "CTabOtherSetDlg.h"

void CTabOtherSetDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_GET_PROJECT:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取项目信息失败！"));
			else
			{
				GetProject(root);
				SendToGetBook();
			}
		}
		break;
	case SOCK_CMD_GET_BOOK:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取图书信息失败！"));
			else
			{
				GetBook(root);
				int ndex = ui.comboBox->currentIndex();
				if (ndex>=0)
				{
					QVariant vt = ui.comboBox->itemData(ndex);
					PROJECT_STU stu= vt.value<PROJECT_STU>();
					if (stu.nAllBook == 0)
						SendToGetOtherPay(stu.nID);
					else
						SetListValue();
				}
			}
		}
		break;
	case SOCK_CMD_GET_OTHERPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("保存数据失败！"));
			else
			{
				GetOtherPay(root);
				SetListValue();
			}
		}
		break;
	case SOCK_CMD_SET_OTHERPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("保存数据失败！"));
			else
			{
				SendToGetProject();
				QMessageBox::information(this, CH("提示"), CH("保存成功！"));
			}
		}
		break;
	case SOCK_CMD_SET_OTHERALLBOOKPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("保存数据失败！"));
			else
			{
				SendToGetProject();
				QMessageBox::information(this, CH("提示"), CH("保存成功！"));
			}
		}
		break;
	}
}

CTabOtherSetDlg::CTabOtherSetDlg(QWidget *parent)
	: CDlgFather(parent)
{
	m_bInitCombox = false;
	ui.setupUi(this);
	connect(this,&CTabOtherSetDlg::sg_CalBak,this,&CTabOtherSetDlg::st_CalBak);
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(st_BtnSave()));
	connect(ui.comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(st_ComboxChanged(int)));
	connect(ui.checkBox,SIGNAL(stateChanged(int)),this,SLOT(st_checkChanged(int)));
	
	ui.EDIT_PAY->setValidator(g_Globle.dbVtor);
	InitListCtrl();
	ui.comboBox->setMaxVisibleItems(40);

	g_Globle.m_DlgMap[EM_DLG_TAB_OTHERSET] = this;
}

CTabOtherSetDlg::~CTabOtherSetDlg()
{

}

void CTabOtherSetDlg::InitListCtrl()
{
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选择
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑
	ui.tableWidget->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget->setFocusPolicy(Qt::NoFocus); //去除选中虚线框
	ui.tableWidget->setFrameShape(QFrame::NoFrame); //设置边框
	ui.tableWidget->setMouseTracking(true);
	ui.tableWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
	ui.tableWidget->verticalHeader()->setVisible(false); //设置垂直头不可见
	ui.tableWidget->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色


	//设置水平、垂直滚动栏样式
	ui.tableWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	ui.tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");

	QStringList headers; 
	headers<<CH("序号")<<CH("图书")<<CH("单价");
	ui.tableWidget->setColumnCount(3); 
	ui.tableWidget->setHorizontalHeaderLabels(headers);
	ui.tableWidget->setColumnWidth(0,50);
	ui.tableWidget->setColumnWidth(1,270);
}

void CTabOtherSetDlg::SetListValue(bool bZero)
{
	QString str;
	ui.tableWidget->clearContents();
	
	int nVecSize = m_vBookList.size();
	for (int i=0;i<nVecSize;i++)
	{
		m_vBookList[i].strPay = "";
	}
	int nOtherSize = m_vOtherPay.size();

	for (int i = 0; i < nOtherSize; i++)
	{
		for (int j = 0; j < nVecSize; j++)
		{
			if (m_vOtherPay[i].strBookID == m_vBookList[j].strBookID)
			{
				m_vBookList[j].strPay = m_vOtherPay[i].strPay;
				break;
			}
		}
	}

	ui.tableWidget->setRowCount(nVecSize);
	for (int i = 0; i < nVecSize; i++)
	{
		BOOK_STU stu = m_vBookList[i];
		//序号
		str = QString("%1").arg(i+1);
		ui.tableWidget->setItem(i,0,new QTableWidgetItem(str));
		//图书
		ui.tableWidget->setItem(i,1,new QTableWidgetItem(stu.strname));
		//单价
		QString strPay = "";
		if(!bZero)
			strPay = stu.strPay;
			
		QLineEdit* line = new QLineEdit(strPay,ui.tableWidget);
		line->setValidator(g_Globle.dbVtor);
		line->setFrame(false);
		line->setAlignment(Qt::AlignmentFlag::AlignHCenter);
		ui.tableWidget->setCellWidget(i,2,line);
	}
}

void CTabOtherSetDlg::st_ComboxChanged(int ndex)
{
	if (m_bInitCombox && ndex >= 0)
	{
		QVariant vt = ui.comboBox->itemData(ndex);
		PROJECT_STU stu = vt.value<PROJECT_STU>();
		if (stu.nAllBook == 1)
		{
			ui.checkBox->setChecked(true);
			ui.EDIT_PAY->setText(stu.strPay);
			ui.EDIT_PAY->setEnabled(true);
			ui.label_2->setEnabled(true);
			ui.tableWidget->setEnabled(false);
			SetListValue(true);
		}
		else
		{
			ui.checkBox->setChecked(false);
			ui.EDIT_PAY->setText("");
			ui.EDIT_PAY->setEnabled(false);
			ui.label_2->setEnabled(false);
			ui.tableWidget->setEnabled(true);
			SendToGetOtherPay(stu.nID);
		}
	}
}

void CTabOtherSetDlg::st_checkChanged(int state)
{
	if (state > 0)
	{
		ui.EDIT_PAY->setEnabled(true);
		ui.label_2->setEnabled(true);
		ui.tableWidget->setEnabled(false);
	}
	else
	{
		ui.EDIT_PAY->setEnabled(false);
		ui.label_2->setEnabled(false);
		ui.tableWidget->setEnabled(true);
	}
}

void CTabOtherSetDlg::pageIn()
{
	SendToGetProject();
}

void CTabOtherSetDlg::SendToGetProject()
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_TAB_OTHERSET;
	root[CONNECT_CMD]=SOCK_CMD_GET_PROJECT;
	root[CMD_GETPRO[EM_GETPRO_BWRITE]] = PRO_STAFF_TYPE_MAX;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabOtherSetDlg::SendToGetBook()
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_TAB_OTHERSET;
	root[CONNECT_CMD]=SOCK_CMD_GET_BOOK;
	root[CMD_GETBOOK[GETBOOK_KEYWORD]] = ""; 
	root[CMD_GETBOOK[GETBOOK_RKTYPE]] = BOOK_RK_NO;
	root[CMD_GETBOOK[GETBOOK_NSTART]] = 0;
	root[CMD_GETBOOK[GETBOOK_NUMBER]] = 1000;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabOtherSetDlg::SendToGetOtherPay(int nID)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_TAB_OTHERSET;
	root[CONNECT_CMD]=SOCK_CMD_GET_OTHERPAY;
	root[CMD_OTHERPAY[EM_OTHER_PAY_PROID]] = nID;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabOtherSetDlg::SendToSetOtherPay(int proID, vector<OTHER_PRO_PAY> vec)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_TAB_OTHERSET;
	root[CONNECT_CMD]=SOCK_CMD_SET_OTHERPAY;
	for (int i=0;i<vec.size();i++)
	{
		Json::Value one;
		one[CMD_OTHERPAYMSG[EM_OTHER_PAY_MSG_BOOKID]] = vec[i].strBookID.toStdString();
		one[CMD_OTHERPAYMSG[EM_OTHER_PAY_MSG_PAY]] = vec[i].strPay.toStdString();
		root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
	}
	root[CMD_OTHERPAY[EM_OTHER_PAY_PROID]] = proID;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabOtherSetDlg::SendToSetOtherAllBookPay(int proID,QString strPay)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_TAB_OTHERSET;
	root[CONNECT_CMD]=SOCK_CMD_SET_OTHERALLBOOKPAY;
	root[CMD_PROMSG[EM_PROMSG_ID]] = proID;
	root[CMD_PROMSG[EM_PROMSG_PAY]] = strPay.toStdString();
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabOtherSetDlg::GetProject(Json::Value root)
{
	m_bInitCombox = false;
	m_vProList.clear();
	ui.comboBox->clear();
	Json::FastWriter writer;  
	string temp = writer.write(root);

	int nCount = root[CMD_PROMSG[EM_PROMSG_COUNT]].asInt();
	for (int i=0;i<nCount;i++)
	{
		char str[25]={0};
		PROJECT_STU stu;
		Json::Value one = root[itoa(i,str,10)];

		stu.nID=one[CMD_PROMSG[EM_PROMSG_ID]].asInt();
		const char* cstr = one[CMD_PROMSG[EM_PROMSG_NAME]].asCString();
		stu.strName=CH(cstr);
		stu.pn_type=(PRO_NUM_TYPE)one[CMD_PROMSG[EM_PROMSG_NUM_TYPE]].asInt();
		stu.ps_type=(PRO_STAFF_TYPE)one[CMD_PROMSG[EM_PROMSG_BWRITE]].asInt();
		stu.ndex=one[CMD_PROMSG[EM_PROMSG_NDEX]].asInt();
		stu.nAllBook=one[CMD_PROMSG[EM_PROMSG_ALL_BOOK]].asInt();
		stu.strPay=one[CMD_PROMSG[EM_PROMSG_PAY]].asCString();
		//按ndex从小到大排列
		if(m_vProList.size() == 0)
			m_vProList.push_back(stu);
		else
		{
			bool bInset=false;
			vector <PROJECT_STU>::iterator it;
			for ( it = m_vProList.begin( ) ; it != m_vProList.end( ) ; it++ )
			{
				if (stu.ndex<(*it).ndex)
				{
					bInset = true;
					m_vProList.insert(it,stu);
					break;
				}
			}
			if(!bInset)
				m_vProList.push_back(stu);
		}
	}

	nCount = m_vProList.size();
	for (int i = 0; i < nCount; i++)
	{
		if (m_vProList[i].nID >= PROJECT_TYPE_OTHER)
		{
			QVariant vt;
			vt.setValue<PROJECT_STU>(m_vProList[i]);
			ui.comboBox->addItem(m_vProList[i].strName,vt);
		}
	}
	if (nCount>0)
	{
		QVariant vt = ui.comboBox->itemData(0);
		PROJECT_STU stu = vt.value<PROJECT_STU>();
		if (stu.nAllBook == 1)
		{
			ui.checkBox->setChecked(true);
			ui.EDIT_PAY->setText(stu.strPay);
			ui.EDIT_PAY->setEnabled(true);
			ui.label_2->setEnabled(true);
			ui.tableWidget->setEnabled(false);
		}
		else
		{
			ui.checkBox->setChecked(false);
			ui.EDIT_PAY->setText("");
			ui.EDIT_PAY->setEnabled(false);
			ui.label_2->setEnabled(false);
			ui.tableWidget->setEnabled(true);
		
		}
		ui.comboBox->setCurrentIndex(0);
		m_bInitCombox = true;
	}
}

void CTabOtherSetDlg::GetBook(Json::Value root)
{
	m_vBookList.clear();
	Json::FastWriter writer;  
	string temp = writer.write(root);

	int nCount = root[CMD_BOOKMSG[BOOKMSG_COUNT]].asInt();
	for (int i=0;i<nCount;i++)
	{
		char str[25]={0};
		BOOK_STU stu;
		Json::Value one = root[itoa(i,str,10)];

		stu.nBc1=one[CMD_BOOKMSG[BOOKMSG_BC1]].asInt();
		stu.strBookID=one[CMD_BOOKMSG[BOOKMSG_ID]].asCString();
		const char* cstr = one[CMD_BOOKMSG[BOOKMSG_NAME]].asCString();
		stu.strname=CH(cstr);

		stu.strCbs=one[CMD_BOOKMSG[BOOKMSG_CBS]].asCString();
		stu.strDate=one[CMD_BOOKMSG[BOOKMSG_DATE]].asCString();

		stu.nBc2=one[CMD_BOOKMSG[BOOKMSG_BC2]].asInt();
		stu.nSize1=one[CMD_BOOKMSG[BOOKMSG_SIZE1]].asInt();
		stu.nSize2=one[CMD_BOOKMSG[BOOKMSG_SIZE2]].asInt();
		stu.nKb=one[CMD_BOOKMSG[BOOKMSG_KB]].asInt();
		stu.fYz=one[CMD_BOOKMSG[BOOKMSG_YZ]].asDouble();
		stu.nYs=one[CMD_BOOKMSG[BOOKMSG_YS]].asInt();
		stu.nBc=one[CMD_BOOKMSG[BOOKMSG_BC]].asInt();
		stu.fLs=one[CMD_BOOKMSG[BOOKMSG_LS]].asDouble();
		stu.type=(BOOK_TYPE)one[CMD_BOOKMSG[BOOKMSG_B_TYPE]].asInt();
		stu.zyType=(ZHEYEPAY_TYPE)one[CMD_BOOKMSG[BOOKMSG_ZY_TYPE]].asInt();
		stu.rkType=(BOOK_RK)one[CMD_BOOKMSG[BOOKMSG_RK_TYPE]].asInt();
		stu.strMsg=one[CMD_BOOKMSG[BOOKMSG_MSG]].asCString();
		m_vBookList.push_back(stu);
	}
}

void CTabOtherSetDlg::GetOtherPay(Json::Value root)
{
	m_vOtherPay.clear();
	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		Json::Value value = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
		if (value.isArray())
		{
			for (int i=0;i<value.size();i++)
			{
				OTHER_PRO_PAY pay;
				pay.strBookID=value[i][CMD_OTHERPAYMSG[EM_OTHER_PAY_MSG_BOOKID]].asCString();
				pay.strPay=value[i][CMD_OTHERPAYMSG[EM_OTHER_PAY_MSG_PAY]].asCString();
				m_vOtherPay.push_back(pay);
			}
		}
	}
}

void CTabOtherSetDlg::st_BtnSave()
{
	int proID=0;
	int ndex = ui.comboBox->currentIndex();
	if (ndex>=0)
	{
		QVariant vt = ui.comboBox->itemData(ndex);
		PROJECT_STU stu = vt.value<PROJECT_STU>();
		proID = stu.nID;
	}
	else
	{
		QMessageBox::information(this, CH("提示"), CH("请先添加项目信息！"));
		return;
	}
	
	bool bCheck = ui.checkBox->isChecked();
	if (bCheck)
	{
		QString strPay = ui.EDIT_PAY->text();
		if (strPay.isEmpty())
		{
			QMessageBox::information(this, CH("提示"), CH("请先输入单价！"));
			return;
		}
		else
		{
			SendToSetOtherAllBookPay(proID,strPay);
		}
	}
	else
	{
		vector<OTHER_PRO_PAY> vec;
		int nSize = ui.tableWidget->rowCount();
		for (int i = 0; i < nSize;i++)
		{
			OTHER_PRO_PAY one;
			one.strBookID = m_vBookList[i].strBookID;
			QLineEdit* edit = (QLineEdit*)ui.tableWidget->cellWidget(i,2);
			one.strPay =  edit->text();
			QString strOldPay = m_vBookList[i].strPay;
			if (one.strPay.isEmpty() && !strOldPay.isEmpty())
			{
				vec.push_back(one);
			}
			else if (!one.strPay.isEmpty())
			{
				vec.push_back(one);
			}
		}
		if (vec.size()==0)
		{
			QMessageBox::information(this, CH("提示"), CH("请先添加信息！"));
			return;
		}
		SendToSetOtherPay(proID,vec);
	}
}
