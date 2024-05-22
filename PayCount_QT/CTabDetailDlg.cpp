#include "CTabDetailDlg.h"
#include <QCompleter>

void DetailCallback(void* p,string strData)
{
	CTabDetailDlg* pThis=(CTabDetailDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CTabDetailDlg::st_CalBak(void* pdata)
{
	string str;
	string* pStrData = (string*)pdata;
	str = *pStrData;
	Json::Reader r;
	Json::Value root;
	r.parse(*pStrData,root);
	delete pStrData;

	EM_SOCK_CMD cmd = (EM_SOCK_CMD)root[CONNECT_CMD].asInt();
	EM_CMD_RET ret = (EM_CMD_RET)root[CMD_RetType[EM_CMD_RETYPE_RESULT]].asInt();

	switch (cmd)
	{
	case SOCK_CMD_GET_SAMPLE_BOOK:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取图书信息失败！"));
			else
			{
				GetBook(root);
				SendToGetProject();
			}
		}
		break;
	case SOCK_CMD_GET_PROJECT:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取项目信息失败！"));
			else
			{
				GetProject(root);
				InitListCtrl();
				/*if (SendToGetDetails())
					SetCtrlVisible(false);*/
			}
		}
		break;
	case SOCK_CMD_GET_DETAILS:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取明细失败！"));
			else
			{
				GetDetails(root);
			}
			SetCtrlVisible(true);
		}
		break;
	}
}

CTabDetailDlg::CTabDetailDlg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(this,&CTabDetailDlg::sg_CalBak,this,&CTabDetailDlg::st_CalBak);
	connect(ui.BTN_UPDATE, SIGNAL(clicked()), this, SLOT(st_BtnUpdate()));
	connect(ui.cbx_rk,SIGNAL(currentIndexChanged(int)),this,SLOT(st_rkCbxChanged(int)));
	connect(ui.cbx_book,SIGNAL(currentIndexChanged(int)),this,SLOT(st_bookCbxChanged(int)));
	connect(ui.cbx_xd_time, SIGNAL(currentIndexChanged(int)), this, SLOT(st_xdTimeCbxChanged(int)));
	CGloble::SetButtonStyle(ui.BTN_UPDATE,":/PayCount_QT/pic/ok.png",3);

	//初始化入库combox
	ui.cbx_rk->addItem(CH("全部"));
	for (int i=0;i<BOOK_RK_MAX;i++)
	{
		ui.cbx_rk->addItem(rkType[i]);
	}
	//初始化下单时间combox
	for (int i = 0; i < EM_DATE_TYPE_MAX; i++)
	{
		ui.cbx_xd_time->addItem(DateName[i]);
	}
	ui.cbx_xd_time->setCurrentIndex(1);

	ui.cbx_rk->setCurrentIndex(1);
	ui.cbx_book->setMaxVisibleItems(40);
	ui.cbx_book->setEditable(true);
	m_pMovie = new QMovie(":/PayCount_QT/pic/load.gif");
	ui.label_load->setMovie(m_pMovie);
	ui.label_load->setVisible(false);

	//QTimer::singleShot(1000, this, SLOT(st_init()));
}

CTabDetailDlg::~CTabDetailDlg()
{
	delete m_pMovie;
}

//void CTabDetailDlg::st_init()
//{
//	SendToGetBook();
//	SendToGetProject();
//}

void CTabDetailDlg::pageIn()
{
	g_Globle.SetCallback(DetailCallback,this);
	SendToGetBook();
}

void CTabDetailDlg::SetCtrlVisible(bool bLoadOk)
{
	ui.cbx_rk->setEnabled(bLoadOk);
	ui.cbx_book->setEnabled(bLoadOk);
	ui.BTN_UPDATE->setEnabled(bLoadOk);
	ui.tableWidget->setVisible(bLoadOk);
	ui.label_load->setVisible(!bLoadOk);

	ui.label_5->setVisible(bLoadOk);
	ui.label_all_money->setVisible(bLoadOk);

	if (bLoadOk)
		m_pMovie->stop();
	else
		m_pMovie->start();
}

void CTabDetailDlg::st_BtnUpdate()
{
	if (SendToGetDetails())
		SetCtrlVisible(false);
}

void CTabDetailDlg::st_rkCbxChanged(int ndex)
{
	SendToGetBook();
}

void CTabDetailDlg::st_bookCbxChanged(int ndex)
{
	if(ndex>=0)
		m_LastBookID = ui.cbx_book->itemData(ndex).value<QString>();

	/*if (SendToGetDetails())
		SetCtrlVisible(false);*/
}

void CTabDetailDlg::st_xdTimeCbxChanged(int)
{
	SendToGetBook();
}

void CTabDetailDlg::SendToGetBook()
{
	BOOK_RK em_rk;
	int ndex = ui.cbx_rk->currentIndex();
	if (ndex == 0)
		em_rk = BOOK_RK_MAX;
	else
		em_rk = BOOK_RK(ndex -1);

	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_SAMPLE_BOOK;
	root[CMD_GETBOOK[GETBOOK_RKTYPE]] = em_rk;
	root[CMD_GETBOOK[GETBOOK_DATE]] = ui.cbx_xd_time->currentIndex();
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabDetailDlg::SendToGetProject()
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_PROJECT;
	root[CMD_GETPRO[EM_GETPRO_BWRITE]] = PRO_STAFF_TYPE_MAX;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

bool CTabDetailDlg::SendToGetDetails()
{
	int ndex = ui.cbx_book->currentIndex();
	int nSize = m_vPro.size();
	if (ndex>=0 && nSize>0)
	{
		QVariant vt = ui.cbx_book->itemData(ndex);
		QString strBookID = vt.value<QString>();

		Json::Value root;
		root[CONNECT_CMD]=SOCK_CMD_GET_DETAILS;
		root[CMD_GETDETAILS[EM_GET_DETAILS_BOOKID]] = strBookID.toStdString();
		for (int i=0;i<nSize;i++)
		{
			Json::Value one;
			one[CMD_GETDETAILS[EM_GET_DETAILS_PROID]] = m_vPro[i].nID;
			one[CMD_GETDETAILS[EM_GET_DETAILS_NDEX]] = i;
			root[CMD_GETDETAILS[EM_GET_DETAILS_PROIDS]].append(one);
		}
		Json::FastWriter writer;  
		string temp = writer.write(root);
		if (g_Globle.SendTo(temp) != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}
void CTabDetailDlg::GetBook(Json::Value root)
{
	m_vet.clear();
	ui.cbx_book->clear();
	Json::FastWriter writer;  
	string temp = writer.write(root);

	int nCount = root[CMD_BOOKMSG[BOOKMSG_COUNT]].asInt();
	for (int i=0;i<nCount;i++)
	{
		char str[25]={0};
		BOOK_STU stu;
		Json::Value one = root[itoa(i,str,10)];

		stu.strBookID=one[CMD_BOOKMSG[BOOKMSG_ID]].asCString();
		const char* cstr = one[CMD_BOOKMSG[BOOKMSG_NAME]].asCString();
		stu.strname=CH(cstr);
		m_vet.push_back(stu);
	}
	nCount = m_vet.size();
	int nFindex = 0;
	for (int i = 0; i < nCount; i++)
	{
		QVariant vt;
		vt.setValue<QString>(m_vet[i].strBookID);
		ui.cbx_book->addItem(m_vet[i].strname,vt);
		if(m_LastBookID == m_vet[i].strBookID)
			nFindex = i;
	}
	if (nCount>0)
	{
		ui.cbx_book->setCurrentIndex(nFindex);
	}

	/*QCompleter* completer = ui.cbx_book->completer();
	if (completer)
		completer->setModel(ui.cbx_book->model());
	else
	{
		QCompleter* completer = new QCompleter(ui.cbx_book->model(), this);
		completer->setFilterMode(Qt::MatchContains);
		ui.cbx_book->setCompleter(completer);
	}*/
	QCompleter* completer = new QCompleter(ui.cbx_book->model(), this);
	completer->setFilterMode(Qt::MatchContains);
	ui.cbx_book->setCompleter(completer);
}

void CTabDetailDlg::GetProject(Json::Value root)
{
	m_vPro.clear();
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
		//按ndex从小到大排列
		if(m_vPro.size() == 0)
			m_vPro.push_back(stu);
		else
		{
			bool bInset=false;
			vector <PROJECT_STU>::iterator it;
			for ( it = m_vPro.begin( ) ; it != m_vPro.end( ) ; it++ )
			{
				if (stu.ndex<(*it).ndex)
				{
					bInset = true;
					m_vPro.insert(it,stu);
					break;
				}
			}
			if(!bInset)
				m_vPro.push_back(stu);
		}
	}
}

void CTabDetailDlg::GetDetails(Json::Value root)
{
	int nNum = m_vPro.size();
	QString strDate;
	strDate = root[CMD_BOOKMSG[BOOKMSG_DATE]].asCString();
	int nYs = root[CMD_BOOKMSG[BOOKMSG_YS]].asInt();
	double fLs = root[CMD_BOOKMSG[BOOKMSG_LS]].asDouble();
	double all_money = 0.;

	vector<PRO_DETAIL> vts;
	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		Json::Value root1 = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
		if (root1.isArray())
		{
			int nSize1 = root1.size();
			if (nSize1 == nNum)
			{
				for (int i=0;i<nNum;i++)//项目遍历
				{
					PRO_DETAIL proDtl;
					Json::Value one1 = root1[i];
					proDtl.nProID = one1[CMD_DETAILMSG[EM_DETAIL_MSG_PROID]].asInt();
					proDtl.ndex = one1[CMD_DETAILMSG[EM_DETAIL_MSG_NDEX]].asInt();
					if (one1.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
					{
						Json::Value root2 = one1[CMD_RetType[EM_CMD_RETYPE_VALUE]];
						if (root2.isArray())
						{
							int nSize2 = root2.size();
							for (int j=0;j<nSize2;j++)//明细遍历
							{
								Json::Value one2 = root2[j];
								const char* cstr = one2[CMD_DETAILMSG[EM_DETAIL_MSG_NAME]].asCString();
								QString strName=CH(cstr);
								QString stridCard = one2[CMD_DETAILMSG[EM_DETAIL_MSG_IDCARD]].asCString();
								QString strDate = one2[CMD_DETAILMSG[EM_DETAIL_MSG_DATE]].asCString();
								int number = one2[CMD_DETAILMSG[EM_DETAIL_MSG_NUMBER]].asInt();
								double money = one2[CMD_DETAILMSG[EM_DETAIL_MSG_MONEY]].asDouble();
								all_money += money;

								if (proDtl.vDetails.contains(strDate))
								{
									QMap<QString, STU_DETAIL> day_alls = proDtl.vDetails[strDate];//1天的所有职工数据
									if (day_alls.contains(stridCard))
									{
										int has_num = day_alls[stridCard].number;
										day_alls[stridCard].number = has_num + number;
										proDtl.vDetails[strDate] = day_alls;
									}
									else
									{
										STU_DETAIL stu;
										stu.number = number;
										stu.strName = strName;
										day_alls[stridCard] = stu;
										proDtl.vDetails[strDate] = day_alls;
									}
								}
								else
								{
									QMap<QString, STU_DETAIL> day_alls;
									STU_DETAIL stu;
									stu.number = number;
									stu.strName = strName;
									day_alls[stridCard] = stu;
									proDtl.vDetails[strDate] = day_alls;
								}
							}
						}
					}
					vts.push_back(proDtl);
				}
			}	
		}
	}
	SetListValue(strDate,nYs,fLs,vts, all_money);
}

void CTabDetailDlg::InitListCtrl()
{
	ui.tableWidget->clear();
	ui.tableWidget->clearContents();
	ui.tableWidget->setRowCount(0);

	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选择
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑
	ui.tableWidget->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget->setFocusPolicy(Qt::NoFocus); //去除选中虚线框
	ui.tableWidget->setFrameShape(QFrame::NoFrame); //设置边框
	ui.tableWidget->setMouseTracking(true);
	//ui.tableWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
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

	QStringList strList;
	strList<<CH("下单日期")<<CH("印数")<<CH("令数");
	int nSize = m_vPro.size();
	for (int i=0;i<nSize;i++)
	{
		strList<<m_vPro[i].strName;
	}
	ui.tableWidget->setColumnCount(3+nSize); 
	ui.tableWidget->setHorizontalHeaderLabels(strList);
}

//nNum:项目个数
//n:有多少个不同的日期
void CTabDetailDlg::SetListValue(QString strDate,int nYs,double fLs, const vector<PRO_DETAIL>& vts,double money)
{
	ui.tableWidget->clearContents();
	ui.tableWidget->setRowCount(0);

	int max = 0;//最大行数
	for (int i=0;i<vts.size();i++)
	{
		if (vts[i].vDetails.count() > max)
			max = vts[i].vDetails.count();
	}

	QString strmoney = QString::number(money, 'f', 2);
	ui.label_all_money->setText(strmoney);
	ui.label_all_money->setStyleSheet("QLabel { color: red; }");

	ui.tableWidget->setRowCount(max+1);
	//基本信息
	QString str;
	ui.tableWidget->setItem(0,0,new QTableWidgetItem(strDate));//下单日期
	str = QString("%1").arg(nYs);
	ui.tableWidget->setItem(0,1,new QTableWidgetItem(str));//印数
	str = QString::number(fLs,'f',2);
	ui.tableWidget->setItem(0,2,new QTableWidgetItem(str));//令数

	for (int i = 0; i < vts.size(); i++)
	{
		int number_all = 0;
		QString str;
		PRO_DETAIL onePro = vts[i];
		QMapIterator<QString, QMap<QString, STU_DETAIL>> day_map(onePro.vDetails);
		int day_index = 0;//当前第几个日期
		while (day_map.hasNext())
		{
			day_map.next();
			str = day_map.key();//date
			QMap<QString, STU_DETAIL> tails_map = day_map.value();
			
			QMapIterator<QString, STU_DETAIL> staff_map(tails_map);
			int staff_num = 0;//多少个职工
			while (staff_map.hasNext())
			{
				staff_map.next();
				QString strName = staff_map.value().strName;
				int number = staff_map.value().number;
				QString strStaffMsg = QString("%1: %2").arg(strName).arg(number);
				str += ("\r\n" + strStaffMsg);
				number_all += number;
				staff_num++;
			}
			int curHeight = ui.tableWidget->rowHeight(day_index);//当前行高度
			int wantHeight = (staff_num + 1) * 30;//预置高度
			int realHeight = curHeight > wantHeight ? curHeight : wantHeight;
			ui.tableWidget->setRowHeight(day_index, realHeight);//设置当前行的高度
			ui.tableWidget->setItem(day_index, 3 + vts[i].ndex, new QTableWidgetItem(str));
			day_index++;
		}
		//当前项目统计总数
		str = QString(CH("合计：%1")).arg(number_all);
		ui.tableWidget->setItem(max, 3 + vts[i].ndex, new QTableWidgetItem(str));
	}
}