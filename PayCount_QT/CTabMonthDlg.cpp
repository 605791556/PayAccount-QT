#include "CTabMonthDlg.h"

CTabMonthDlg* gTabMonthDlg = NULL;

void CalBakThread(void* pdata);
void MonthCheckCallback(void* p,string strData);

CTabMonthDlg::CTabMonthDlg(QWidget *parent)
	: QWidget(parent)
{
	qRegisterMetaType<EM_CMD_RET>("EM_CMD_RET");
	qRegisterMetaType<EM_SOCK_CMD>("EM_SOCK_CMD");

	m_pViewModel = nullptr;
	m_oldDays = 0;
	m_bInitCombox = false;
	gTabMonthDlg = this;

	ui.setupUi(this);
	CGloble::SetButtonStyle(ui.BTN_UPDATE,":/PayCount_QT/pic/ok.png",3);
	connect(ui.BTN_UPDATE,SIGNAL(clicked()),this,SLOT(BtnUpdate()));
	connect(this,SIGNAL(sg_CalBak(void*)),this,SLOT(st_CalBak(void*)),Qt::QueuedConnection);
	connect(ui.CB_YEAR,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(st_ComboxChanged(const QString &)));
	connect(ui.CB_MONTH,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(st_ComboxChanged(const QString &)));
	connect(ui.EDIT_KEYWORD,SIGNAL(textChanged(const QString &)),this,SLOT(st_KeyWordChanged(const QString &)));
	connect(this,&CTabMonthDlg::sg_ThCal,this,&CTabMonthDlg::st_ThCal);
	InitCtrlValue();
	InitListCtrl();

	m_pMovie = new QMovie(":/PayCount_QT/pic/load.gif");
	ui.label_load->setMovie(m_pMovie);
	ui.label_load->setVisible(false);
}

CTabMonthDlg::~CTabMonthDlg()
{
	if (m_pViewModel)
	{
		delete m_pViewModel;
	}
}

void CTabMonthDlg::pageIn()
{
	g_Globle.SetCallback(MonthCheckCallback,this);
	SendToGetStaff();
}

void CTabMonthDlg::InitCtrlValue()
{
	//初始化年份控件
	QDate tm = QDate::currentDate();
	int year = tm.year();
	for (int i = 0; i < 8; i++)
	{
		QString str = QString("%1").arg(year - (8 - i-1));
		ui.CB_YEAR->insertItem(i,str);
		if (i == 7)
		{
			ui.CB_YEAR->setCurrentIndex(i);
		}
	}

	//初始化月份控件
	for (int i = 0; i < 12; i++)
	{
		QString str = QString("%1").arg(i + 1);
		ui.CB_MONTH->insertItem(i,str);
		if (i + 1 == tm.month())
		{
			ui.CB_MONTH->setCurrentIndex(i);
		}
	}
	m_bInitCombox = true;
}

void CTabMonthDlg::InitListCtrl()
{
	if (m_pViewModel == nullptr)
	{
		m_pViewModel = new QStandardItemModel(this);
		ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
		ui.tableView ->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
		ui.tableView->horizontalHeader()->setHighlightSections(false);
		ui.tableView->verticalHeader()->setVisible(false); //设置垂直头不可见
		ui.tableView->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
		ui.tableView->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
		ui.tableView->setFocusPolicy(Qt::NoFocus); //去除选中虚线框
		ui.tableView->setFrameShape(QFrame::NoFrame); //设置边框
		ui.tableView->setFont(QFont("Helvetica"));
		ui.tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色


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

	QString strYear, strMonth,strDate;
	strYear = ui.CB_YEAR->currentText();
	strMonth = ui.CB_MONTH->currentText();

	int nYear = strYear.toInt();
	int nMonth = strMonth.toInt();
	int nDays = g_Globle.GetDays(nYear, nMonth);

	if (m_oldDays != nDays)
	{
		m_pViewModel->setColumnCount(nDays+2);
		if (m_oldDays == 0)
		{
			QStringList listHeader;
			for (int i=0;i< nDays+2;i++)
			{
				if (i == 0)
					listHeader<<CH("姓名");
				else if(i == 1)
					listHeader<<CH("总额");
				else
				{
					//QString str = QString::number(i+1-2) + CH("月");
					listHeader<<QString::number(i+1-2);
				}

				ui.tableView->setColumnWidth(i,65);
			}
			m_pViewModel->setHorizontalHeaderLabels(listHeader);
		}
		else if (m_oldDays > nDays)//删除列
		{
			int nMoveColumns = m_oldDays - nDays;
			m_pViewModel->removeColumns(nDays+2,nMoveColumns);
		}
		else if (m_oldDays < nDays)//添加列
		{
			int nAddColumns = nDays - m_oldDays;
			for (int i = 0;i<nAddColumns;i++)
			{
				m_pViewModel->setHeaderData(m_oldDays+2+i,Qt::Horizontal, m_oldDays+i+1);
			}
		}
		m_oldDays = nDays;	
	}
}

void CTabMonthDlg::SetListValue()
{
	ui.tableView->setUpdatesEnabled(false);  //暂停界面刷新
	int nRows = m_vStaffs.size();
	for (int i=0;i<nRows;i++)
	{
		QString str;
		MONTH_PAY_STAFF staff = m_vStaffs[i];
		m_pViewModel->setItem(i,0,new QStandardItem(staff.strStaffName));
		str = QString::number(staff.m_money,'f',2);
		m_pViewModel->setItem(i,1,new QStandardItem(str));
		for (auto it = staff.vDays.begin();it!= staff.vDays.end();it++)
		{
			str = QString::number(it->d_money,'f',2);
			m_pViewModel->setItem(i,it->ndex,new QStandardItem(str));
		}
	}
	ui.tableView->setUpdatesEnabled(true);  //恢复界面刷新
	
	for (int i=0;i<nRows;i++)
	{
		m_pViewModel->item(i, 0)->setBackground(QBrush(QColor("#eeefd7")));
		m_pViewModel->item(i, 1)->setBackground(QBrush(QColor("#b7d6f5")));
	}
}

int findDay(QString strDate)
{
	int nfind = strDate.lastIndexOf("/");
	QString str = strDate.mid(nfind+1);
	return str.toInt();
}

void CTabMonthDlg::SendToGetStaff()
{
	USES_CONVERSION;
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_SAMPLE_STAFF;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabMonthDlg::GetStaff(Json::Value root)
{
	m_vet.clear();
	m_vStaffs.clear();
	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		Json:: Value js = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
		if (js.isArray())
		{
			int nCount = js.size();
			for (int i=0;i<nCount;i++)
			{
				STAFF_STU stu;
				stu.strname = js[i][CMD_STAFFMSG[EM_STAFF_MSG_NAME]].asCString();
				stu.strStaffID = js[i][CMD_STAFFMSG[EM_STAFF_MSG_STAFFID]].asCString();
				m_vet.push_back(stu);

				MONTH_PAY_STAFF staff;
				std::string str = js[i][CMD_STAFFMSG[EM_STAFF_MSG_NAME]].asCString();
				staff.strStaffName =CH(str.data());
				staff.strStaffID = js[i][CMD_STAFFMSG[EM_STAFF_MSG_STAFFID]].asCString();
				m_vStaffs.push_back(staff);
			}
		}
	}
}

bool CTabMonthDlg::SendToGetMonthPay()
{
	//先清空数据
	m_pViewModel->removeRows(0,m_pViewModel->rowCount());//清空

	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_MPAY;

	QString strYear, strMonth,strDate,strTmp;
	strYear = ui.CB_YEAR->currentText();
	strMonth = ui.CB_MONTH->currentText();

	int nYear = strYear.toInt();
	int nMonth = strMonth.toInt();
	strDate = QString("%1/%2").arg(nYear).arg(nMonth,2,10,QChar('0'));
	root[MPAYMSG[EM_GET_MPAY_DATE]]=strDate.toStdString();

	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
		return false;
	else
		return true;
}

QString CTabMonthDlg::GetMonthPay(Json::Value root)
{
	for (auto it = m_vStaffs.begin();it!=m_vStaffs.end();it++)
		it->resetValue();

	Json::FastWriter writer;  
	string strData = writer.write(root);

	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		Json::Value js = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
		int size = js.size();
		for (int i=0;i<size;i++)
		{
			Json::Value one = js[i];

			MONTH_PAY_STAFF staff;
			staff.strStaffID = one[MPAYMSG[EM_GET_MPAY_STAFFID]].asCString();
			std::string str = one[MPAYMSG[EM_GET_MPAY_STAFFNAME]].asString();
			staff.strStaffName =CH(str.data());

			MONTHPAY_DAY day;
			day.strDate = one[MPAYMSG[EM_GET_MPAY_DATE]].asCString();
			day.ndex = findDay(day.strDate)+1;

			DAYPAY day_pay;
			day_pay.type = (DAYPAY_TYPE)one[MPAYMSG[EM_GET_MPAY_TYPE]].asInt();
			day_pay.money = one[MPAYMSG[EM_GET_MPAY_MONEY]].asCString();

			for (int j = 0;j<m_vStaffs.size();j++)
			{
				if (m_vStaffs[j].strStaffID == staff.strStaffID)
				{
					QString strDate;
					strDate = one[MPAYMSG[EM_GET_MPAY_DATE]].asCString();

					if (m_vStaffs[j].vDays.size() == 0)
					{
						if (day_pay.type == DAYPAY_TYPE_DEL)
						{
							day.d_money -= day_pay.money.toDouble();
							m_vStaffs[j].m_money -= day_pay.money.toDouble();
						}
						else
						{
							day.d_money += day_pay.money.toDouble();
							m_vStaffs[j].m_money += day_pay.money.toDouble();
						}

						m_vStaffs[j].vDays.push_back(day);
					}
					else
					{
						bool bInsert = false;
						for (auto it = m_vStaffs[j].vDays.begin();it != m_vStaffs[j].vDays.end();it++)
						{
							if (it->strDate == strDate)//该日期已经插入
							{
								bInsert = true;
								if (day_pay.type == DAYPAY_TYPE_DEL)
								{
									it->d_money -= day_pay.money.toDouble();
									m_vStaffs[j].m_money -= day_pay.money.toDouble();
								}
								else
								{
									it->d_money += day_pay.money.toDouble();
									m_vStaffs[j].m_money += day_pay.money.toDouble();
								}
								break;
							}
						}
						if (bInsert == false)//该日期还没插入
						{
							if (day_pay.type == DAYPAY_TYPE_DEL)
							{
								day.d_money -= day_pay.money.toDouble();
								m_vStaffs[j].m_money -= day_pay.money.toDouble();
							}
							else
							{
								day.d_money += day_pay.money.toDouble();
								m_vStaffs[j].m_money += day_pay.money.toDouble();
							}

							m_vStaffs[j].vDays.push_back(day);
						}
					}
					break;
				}
			}
		}
	}

	double fTotal = 0;
	for (int i=0;i<m_vStaffs.size();i++)
		fTotal+=m_vStaffs[i].m_money;

	QString tmp = CH("总支出：") + QString::number(fTotal,'f',2);
	return tmp;
}

void CTabMonthDlg::SetCtrlVisible(bool bLoadOk)
{
	ui.CB_YEAR->setEnabled(bLoadOk);
	ui.CB_MONTH->setEnabled(bLoadOk);
	ui.BTN_UPDATE->setEnabled(bLoadOk);
	ui.tableView->setVisible(bLoadOk);
	ui.label_pay->setVisible(bLoadOk);
	ui.label_load->setVisible(!bLoadOk);
	//m_pMovie->setPaused(bLoadOk);
	if(bLoadOk)
		m_pMovie->stop();
	else
		m_pMovie->start();
}

void CTabMonthDlg::st_ComboxChanged(const QString &)
{
	if (m_bInitCombox)
	{
		InitListCtrl();
		if(!SendToGetMonthPay())
			QMessageBox::information(this, CH("提示"), CH("发送网络请求失败，请检查网络是否正常！"));
		else
			SetCtrlVisible(false);
	}
}

void CTabMonthDlg::st_KeyWordChanged(const QString & strKeyWord)
{
	m_vItem.clear();
	if (!strKeyWord.isEmpty())
	{
		int nCount = m_vStaffs.size();
		for (int i=0;i<nCount;i++)
		{
			int nFind = m_vStaffs[i].strStaffName.indexOf(strKeyWord);
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

void CTabMonthDlg::BtnUpdate()
{
	SendToGetStaff();
}

void MonthCheckCallback(void* p,string strData)
{
	CTabMonthDlg* pThis=(CTabMonthDlg*) p;

	if ( pThis==NULL)
	{
		return;
	}
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CTabMonthDlg::st_CalBak(void* pdata)
{
	QtConcurrent::run(CalBakThread,pdata);
}

void CalBakThread(void* pdata)
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
				emit gTabMonthDlg->sg_ThCal(SOCK_CMD_GET_SAMPLE_STAFF,NET_CMD_FAIL);
			else
			{
				gTabMonthDlg->GetStaff(root);
				if(!gTabMonthDlg->SendToGetMonthPay())
					emit gTabMonthDlg->sg_ThCal(SOCK_CMD_GET_SAMPLE_STAFF,NET_CMD_SUC,false);
				else
					emit gTabMonthDlg->sg_ThCal(SOCK_CMD_GET_SAMPLE_STAFF,NET_CMD_SUC,true);
			}
		}
		break;
	case SOCK_CMD_GET_MPAY:
		{
			if (ret == NET_CMD_FAIL)
			{
				emit gTabMonthDlg->sg_ThCal(SOCK_CMD_GET_MPAY,NET_CMD_FAIL);
			}
			else
			{
				QString strPay = gTabMonthDlg->GetMonthPay(root);
				emit gTabMonthDlg->sg_ThCal(SOCK_CMD_GET_MPAY,NET_CMD_SUC,true,strPay);
			}
		}
		break;

	}
}

void CTabMonthDlg::st_ThCal(EM_SOCK_CMD cmd,EM_CMD_RET ret,bool rst,QString strPay)
{
	switch (cmd)
	{
	case SOCK_CMD_GET_SAMPLE_STAFF:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取职工信息失败！"));
			else
			{
				 if (!rst)
					 QMessageBox::information(this, CH("提示"), CH("发送网络请求失败，请检查网络是否正常！"));
				 else
					 SetCtrlVisible(false);
			}

		}
		break;
	case SOCK_CMD_GET_MPAY:
		{
			if (ret == NET_CMD_FAIL)
			{
				SetCtrlVisible(true);
				QMessageBox::information(this, CH("错误"), CH("获取数据失败！"));
			}
			else
			{
				ui.label_pay->setText(strPay);
				SetCtrlVisible(true);
				SetListValue();
			}
		}
		break;

	}
}