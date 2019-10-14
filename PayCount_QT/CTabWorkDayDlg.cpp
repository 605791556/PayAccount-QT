#include "CTabWorkDayDlg.h"
#include "CDayPayDlg.h"

void WorkCalCallback(void* p,string strData)
{
	CTabWorkDayDlg* pThis=(CTabWorkDayDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CTabWorkDayDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_GET_SAMPLE_STAFF:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取职工信息失败！"));
			else
			{
				GetStaff(root);
				SendToGetOnePayList();
			}
		}
		break;
	case SOCK_CMD_GET_DAYPAY_LIST:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取做工统计列表失败！"));
			else
			{
				GetOnePayList(root);
				SetListValue();
			}
		}
		break;
	}
}

CTabWorkDayDlg::CTabWorkDayDlg(QWidget *parent)
	: QWidget(parent)
{
	m_pViewModel = nullptr;
	m_bDateInit = false;

	ui.setupUi(this);
	connect(ui.dateEdit,&QDateEdit::userDateChanged,this,&CTabWorkDayDlg::st_DateChanged);
	connect(this,&CTabWorkDayDlg::sg_CalBak,this,&CTabWorkDayDlg::st_CalBak);
	connect(ui.BTN_UPDATE,SIGNAL(clicked()),this,SLOT(st_BtnUpdate()));
	connect(ui.edit_keyword,SIGNAL(textChanged(const QString &)),this,SLOT(st_KeyWordChanged(const QString &)));
	connect(ui.tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(st_RowDoubleClicked(const QModelIndex &)));
	
	CGloble::SetButtonStyle(ui.BTN_UPDATE,":/PayCount_QT/pic/ok.png",3);
	
	InitDateCtrl();
	InitListCtrl();

	ui.label_2->setStyleSheet("color:red;");
}

CTabWorkDayDlg::~CTabWorkDayDlg()
{
	if (m_pViewModel)
	{
		delete m_pViewModel;
	}
}

void CTabWorkDayDlg::pageIn()
{
	g_Globle.SetCallback(WorkCalCallback,this);
	SendToGetStaff();
}

void CTabWorkDayDlg::InitDateCtrl()
{
	QDate date = QDate::currentDate();
	ui.dateEdit->setDate(date);
	m_bDateInit = true;
}

void CTabWorkDayDlg::InitListCtrl()
{
	if (m_pViewModel == nullptr)
	{
		m_pViewModel = new QStandardItemModel(this);
		ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
		ui.tableView ->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
		ui.tableView->horizontalHeader()->setHighlightSections(false);
		ui.tableView->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
		//ui.tableView->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
		ui.tableView->setFocusPolicy(Qt::NoFocus); //去除选中虚线框
		ui.tableView->setFrameShape(QFrame::NoFrame); //设置边框
		ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
		//ui.tableView->setFont(QFont("Helvetica"));

		//设置水平、垂直滚动栏样式
		ui.tableView->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
			"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
			"QScrollBar::handle:hover{background:gray;}"
			"QScrollBar::sub-line{background:transparent;}"
			"QScrollBar::add-line{background:transparent;}");
		ui.tableView->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
			"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
			"QScrollBar::handle:hover{background:gray;}"
			"QScrollBar::sub-line{background:transparent;}"
			"QScrollBar::add-line{background:transparent;}");

		ui.tableView->setModel(m_pViewModel);
	}
	QStringList listHeader;
	listHeader<<CH("姓名")<<CH("按天工资")<<CH("计件工资")<<CH("扣除")<<CH("共计");
	m_pViewModel->setHorizontalHeaderLabels(listHeader);
	ui.tableView->setColumnWidth(5,0);
	for (int i=0;i<5;i++)
	{
		ui.tableView->setColumnWidth(i,850/5);
	}
}

void CTabWorkDayDlg::SetListValue()
{
	ui.tableView->setUpdatesEnabled(false);  //暂停界面刷新

	double all_money = 0;
	QString str;

	int nNum = m_vet.size();
	for (int j=0;j<nNum;j++)
	{
		int bFind = false;
		int nCount = m_vWorkCal.size();
		for (int i=0;i<nCount;i++)
		{
			if (m_vet[j].strStaffID == m_vWorkCal[i].strStaffID)
			{
				bFind = true;
				double money = 0;
				money = m_vWorkCal[i].day_money + m_vWorkCal[i].jj_money - m_vWorkCal[i].del_money;

				m_pViewModel->setItem(j,0,new QStandardItem(m_vWorkCal[i].strName));//姓名
				m_pViewModel->item(j,0)->setAccessibleText(m_vWorkCal[i].strStaffID);
				if (m_vWorkCal[i].day_money == 0)
					str = "0";
				else
					str = QString::number(m_vWorkCal[i].day_money,'f',2);

				m_pViewModel->setItem(j,1,new QStandardItem(str));//按天工资

				if (m_vWorkCal[i].jj_money == 0)
					str = "0";
				else
					str = QString::number(m_vWorkCal[i].jj_money,'f',2);

				m_pViewModel->setItem(j,2,new QStandardItem(str));//计件工资

				if (m_vWorkCal[i].del_money == 0)
					str = "0";
				else
					str = QString::number(m_vWorkCal[i].del_money,'f',2);

				m_pViewModel->setItem(j,3,new QStandardItem(str));//扣除工资

				str = QString::number(money,'f',2);
				m_pViewModel->setItem(j,4,new QStandardItem(str));//共计

				all_money += money;
				break;
			}
		}
		if (!bFind)
		{
			m_pViewModel->setItem(j,0,new QStandardItem(m_vet[j].strname));//姓名
			m_pViewModel->item(j,0)->setAccessibleText(m_vet[j].strStaffID);
			m_pViewModel->setItem(j,1,new QStandardItem("0"));//按天工资
			m_pViewModel->setItem(j,2,new QStandardItem("0"));//计件工资
			m_pViewModel->setItem(j,3,new QStandardItem("0"));//扣除工资
			m_pViewModel->setItem(j,4,new QStandardItem("0"));//共计
		}
	}

	for (int i=0;i<nNum;i++)
	{
		m_pViewModel->item(i, 0)->setBackground(QBrush(QColor("#eeefd7")));
	}

	str = CH("总计：")+QString::number(all_money,'f',4);
	ui.label_total->setText(str);

	ui.tableView->setUpdatesEnabled(true);  //恢复界面刷新
}

void CTabWorkDayDlg::st_DateChanged(const QDate &date)
{
	if(!m_bDateInit)
		return;
	g_Globle.SetCallback(WorkCalCallback,this);
	SendToGetOnePayList();
}

void CTabWorkDayDlg::st_KeyWordChanged(const QString & strKeyWord)
{
	m_vItem.clear();
	if (!strKeyWord.isEmpty())
	{
		int nCount = m_vet.size();
		for (int i=0;i<nCount;i++)
		{
			int nFind = m_vet[i].strname.indexOf(strKeyWord);
			if (nFind>=0)
			{
				m_vItem.push_back(i);
			}
		}
	}

	int nRows = m_pViewModel->rowCount();
	for (int i=0;i<nRows;i++)
		m_pViewModel->item(i, 0)->setBackground(QBrush(QColor("#eeefd7")));//默认色

	int nrow = m_vItem.size();
	for (int i=0;i<nrow;i++)
		m_pViewModel->item(m_vItem[i], 0)->setBackground(QBrush(QColor(99, 184, 255)));//关键色 
}

void CTabWorkDayDlg::st_RowDoubleClicked(const QModelIndex & mdIndex)
{
	CDayPayDlg dlg(mdIndex,this);
	int ret = dlg.exec();
	g_Globle.SetCallback(WorkCalCallback,this);
	if (ret == QDialog::Accepted)
	{
		SendToGetOnePayList();
	}
}

void CTabWorkDayDlg::st_BtnUpdate()
{
	pageIn();
}

void CTabWorkDayDlg::SendToGetStaff()
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_SAMPLE_STAFF;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabWorkDayDlg::GetStaff(Json::Value root)
{
	USES_CONVERSION;
	m_vet.clear();
	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		Json:: Value js = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
		if (js.isArray())
		{
			int nCount = js.size();
			for (int i=0;i<nCount;i++)
			{
				STAFF_STU stu;
				string str = js[i][CMD_STAFFMSG[EM_STAFF_MSG_NAME]].asCString();
				stu.str2 = A2T(str.data());
				stu.strname = CH(str.data());
				stu.strStaffID = js[i][CMD_STAFFMSG[EM_STAFF_MSG_STAFFID]].asCString();
				stu.fDaypay = js[i][CMD_STAFFMSG[EM_STAFF_MSG_DAYPAY]].asDouble();
				m_vet.push_back(stu);
			}
		}
	}
}

void CTabWorkDayDlg::SendToGetOnePayList()
{
	USES_CONVERSION;
	if(!m_pViewModel)
		return;

	//先清空数据
	m_pViewModel->removeRows(0,m_pViewModel->rowCount());//清空

	QDate date = ui.dateEdit->date();
	QString strDate = date.toString("yyyy/MM/dd");

	int nSize = m_vet.size();
	if (nSize>0)
	{
		Json::Value root;
		root[CONNECT_CMD]=SOCK_CMD_GET_DAYPAY_LIST;
		root[CMD_GETDAYPAY[EM_GET_DAYPAY_DATE]]=strDate.toStdString();
		for (int i = 0; i < nSize;i++)
		{
			Json::Value one1;
			one1[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFID]]=m_vet[i].strStaffID.toStdString();
			one1[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFNAME]]=T2A(m_vet[i].str2);
			root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one1);
		}
		Json::FastWriter writer;  
		string temp = writer.write(root);
		g_Globle.SendTo(temp);
	}
}

void CTabWorkDayDlg::GetOnePayList(Json::Value root)
{
	Json::FastWriter writer;  
	string temp = writer.write(root);
	m_vWorkCal.clear();
	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		Json:: Value ones1 = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
		if (ones1.isArray())
		{
			int nCount = ones1.size();
			for (int i=0;i<nCount;i++)//人数循环
			{
				Json:: Value one1 = ones1[i];
				WORKMONEY cal;
				cal.strStaffID = one1[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFID]].asCString();
				string str = one1[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFNAME]].asCString();
				cal.strName = CH(str.data());
				if (one1.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
				{
					Json:: Value ones = one1[CMD_RetType[EM_CMD_RETYPE_VALUE]];
					if (ones.isArray())
					{
						int nNum = ones.size();
						for (int j=0;j<nNum;j++)//做工循环
						{
							Json:: Value one = ones[j];

							DAYPAY_TYPE type;
							type = (DAYPAY_TYPE)one[DAYPAYMSG[EM_DAYPAY_MSG_TYPE]].asInt();

							CString strMoney;
							strMoney = one[DAYPAYMSG[EM_DAYPAY_MSG_MONEY]].asCString();

							if (type == DAYPAY_TYPE_DEL)
							{
								cal.del_money += _ttof(strMoney);
							}
							else if (type == DAYPAY_TYPE_DAY)
							{
								cal.day_money += _ttof(strMoney);
							}
							else if(type == DAYPAY_TYPE_JIJIAN)
							{
								cal.jj_money += _ttof(strMoney);
							}				
						}
						m_vWorkCal.push_back(cal);
					}
				}
			}
		}
	}
	SetListValue();
}