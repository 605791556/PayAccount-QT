#include "CTabDetailDlg.h"

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
	string* pStrData = (string*)pdata;
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
				SendToGetDetails();
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
		}
		break;
	}
}

CTabDetailDlg::CTabDetailDlg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(this,&CTabDetailDlg::sg_CalBak,this,&CTabDetailDlg::st_CalBak);
	connect(ui.cbx_rk,SIGNAL(currentIndexChanged(int)),this,SLOT(st_rkCbxChanged(int)));
	connect(ui.cbx_book,SIGNAL(currentIndexChanged(int)),this,SLOT(st_bookCbxChanged(int)));
	CGloble::SetButtonStyle(ui.BTN_UPDATE,":/PayCount_QT/pic/ok.png",3);

	//初始化入库combox
	ui.cbx_rk->addItem(CH("全部"));
	for (int i=0;i<BOOK_RK_MAX;i++)
	{
		ui.cbx_rk->addItem(rkType[i]);
	}
	ui.cbx_rk->setCurrentIndex(1);
	ui.cbx_book->setMaxVisibleItems(40);
}

CTabDetailDlg::~CTabDetailDlg()
{

}

void CTabDetailDlg::pageIn()
{
	g_Globle.SetCallback(DetailCallback,this);
	SendToGetBook();
}

void CTabDetailDlg::st_BtnUpdate()
{
	pageIn();
}

void CTabDetailDlg::st_rkCbxChanged(int ndex)
{
	SendToGetBook();
}

void CTabDetailDlg::st_bookCbxChanged(int ndex)
{
	if(ndex>=0)
		m_LastBookID = ui.cbx_book->itemData(ndex).value<QString>();
	SendToGetDetails();
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

void CTabDetailDlg::SendToGetDetails()
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
		g_Globle.SendTo(temp);
	}
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
	int* n = new int[nNum];
	for (int i=0;i<nNum;i++)
		n[i] = 0;

	QString strDate;
	strDate = root[CMD_BOOKMSG[BOOKMSG_DATE]].asCString();
	int nYs = root[CMD_BOOKMSG[BOOKMSG_YS]].asInt();
	double fLs = root[CMD_BOOKMSG[BOOKMSG_LS]].asDouble();

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
								STU_DETAIL stu;
								Json::Value one2 = root2[j];
								const char* cstr = one2[CMD_DETAILMSG[EM_DETAIL_MSG_NAME]].asCString();
								stu.strName=CH(cstr);
								stu.stridCard = one2[CMD_DETAILMSG[EM_DETAIL_MSG_IDCARD]].asCString();
								stu.number = one2[CMD_DETAILMSG[EM_DETAIL_MSG_NUMBER]].asInt();
								proDtl.vDetails.push_back(stu);
							}
							//对vDetails容器处理，如有相同姓名的明细则合并
							for (int j=0;j<proDtl.vDetails.size();j++)
							{
								if (proDtl.vDetails.size() >= 2 && j<proDtl.vDetails.size()-1)
								{
									vector<STU_DETAIL>::iterator it ;
									vector<STU_DETAIL>::iterator src = proDtl.vDetails.begin()+j;
									for(it=proDtl.vDetails.begin()+j+1;it!=proDtl.vDetails.end();)
									{
										if(src->stridCard == it->stridCard)
										{
											src->number+=it->number;
											it=proDtl.vDetails.erase(it);  
										}
										else
											++it;
									}
								}
								else
									break;
							}
							n[i] = proDtl.vDetails.size();
						}
					}
					vts.push_back(proDtl);
				}
			}	
		}
	}
	SetListValue(strDate,nYs,fLs, nNum,n,vts);
}

void CTabDetailDlg::InitListCtrl()
{
	ui.tableWidget->clear();

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

void CTabDetailDlg::SetListValue(QString strDate,int nYs,double fLs, int nNum,int* n,vector<PRO_DETAIL> vts)
{
	ui.tableWidget->clearContents();

	int max=0,dex=0;
	for (int i=0;i<nNum;i++)
	{
		if (n[i]>max)
		{
			max = n[i];
			dex=i;
		}
	}
	if(max <=0)
		return;

	ui.tableWidget->setRowCount(max+1);
	//基本信息
	QString str;
	ui.tableWidget->setItem(0,0,new QTableWidgetItem(strDate));//下单日期
	str = QString("%1").arg(nYs);
	ui.tableWidget->setItem(0,1,new QTableWidgetItem(str));//印数
	str = QString::number(fLs,'f',2);
	ui.tableWidget->setItem(0,2,new QTableWidgetItem(str));//令数

	for (int i=0;i<n[dex];i++)
	{
		QString str;
		for (int j=0;j<nNum;j++)
		{
			int nTmp = vts[j].vDetails.size();
			if (i < nTmp)
				str = QString("%1: %2").arg(vts[j].vDetails[i].strName).arg(vts[j].vDetails[i].number);
			else
				str="";

			ui.tableWidget->setItem(i,3+vts[j].ndex,new QTableWidgetItem(str));
		}
	}

	for (int i = 0;i<nNum;i++)
	{
		int number_all = 0;
		int nTmp = vts[i].vDetails.size();
		for (int j =0;j<nTmp;j++)
		{
			number_all+=vts[i].vDetails[j].number;
		}
		str = QString(CH("合计：%1")).arg(number_all);
		ui.tableWidget->setItem(max,3+vts[i].ndex,new QTableWidgetItem(str));
	}
	delete[] n;
}