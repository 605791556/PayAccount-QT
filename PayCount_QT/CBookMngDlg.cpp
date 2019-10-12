#include "CBookMngDlg.h"
#include "CAddBookDlg.h"

void BookMngCallback(void* p,string strData)
{
	CBookMngDlg* pThis=(CBookMngDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CBookMngDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_GET_BOOK:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取图书信息失败！"));
			else
			{
				GetBook(root);
			}
		}
		break;
	case SOCK_CMD_DEL_BOOK:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("删除失败！"));
			else
			{
				BtnFind();
				QMessageBox::information(this, CH("提示"), CH("删除成功！"));
			}
		}
		break;
	}
}

CBookMngDlg::CBookMngDlg(QWidget *parent)
	: QDialog(parent)
{
	m_nPage=1;
	m_dex=1;
	m_date_Type=EM_DATE_TYPE_1WEEK;
	m_rkType=BOOK_RK_MAX;

	ui.setupUi(this);
	CGloble::SetButtonStyle(ui.BTN_FIND,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_ADD,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_LAST,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_NEXT,":/PayCount_QT/pic/ok.png",3);

	connect(this,&CBookMngDlg::sg_CalBak,this,&CBookMngDlg::st_CalBak);
	connect(ui.BTN_ADD,SIGNAL(clicked()),this,SLOT(BtnAdd()));
	connect(ui.BTN_FIND,SIGNAL(clicked()),this,SLOT(BtnFind()));
	connect(ui.BTN_GO,SIGNAL(clicked()),this,SLOT(BtnGo()));
	connect(ui.BTN_LAST,SIGNAL(clicked()),this,SLOT(BtnLast()));
	connect(ui.BTN_NEXT,SIGNAL(clicked()),this,SLOT(BtnNext()));
	g_Globle.SetCallback(BookMngCallback,this);
	InitListCtrl();
	InitCombox();
	SendToGetBook("",m_rkType,m_date_Type,(m_dex-1)*20,20);
}

CBookMngDlg::~CBookMngDlg()
{

}

void CBookMngDlg::InitListCtrl()
{
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

	QStringList headers; 
	headers<<CH("序号")<<CH("下单日期")<<CH("书名")<<CH("出版社")<<CH("版次")<<CH("成品尺寸")<<CH("开本")<<CH("印张")<<CH("印数")<<CH("包册")<<CH("令数")<<CH("印张类型")<<CH("折页类型")<<CH("入库")<<CH("备注")<<CH("操作");
	ui.tableWidget->setColumnCount(LISTCOLUMN); 
	ui.tableWidget->setHorizontalHeaderLabels(headers);

	ui.tableWidget->setColumnWidth(15,75);
}

void CBookMngDlg::SetListCtrlValue()
{
	ui.tableWidget->clearContents();
	QString str;
	int nCount = m_vet.size();
	ui.tableWidget->setRowCount(nCount);
	int n = 1;
	for (int i=0;i<nCount;i++)
	{
		//序号
		str = QString("%1").arg(n+(m_dex-1)*20);
		ui.tableWidget->setItem(i,0,new QTableWidgetItem(str));
		//下单日期
		ui.tableWidget->setItem(i,1,new QTableWidgetItem(m_vet[i].strDate));
		//绑定ID
		QVariant vt;
		vt.setValue<QString>(m_vet[i].strBookID);
		ui.tableWidget->item(i,1)->setData(1,vt);
		//书名
		ui.tableWidget->setItem(i,2,new QTableWidgetItem(m_vet[i].strname));
		//出版社
		str = QString("%1").arg(m_vet[i].strCbs);
		ui.tableWidget->setItem(i,3,new QTableWidgetItem(str));
		//版次
		str = QString("%1-%2").arg(m_vet[i].nBc1).arg(m_vet[i].nBc2);
		ui.tableWidget->setItem(i,4,new QTableWidgetItem(str));
		//成品尺寸
		str = QString("%1*%2").arg(m_vet[i].nSize1).arg(m_vet[i].nSize2);
		ui.tableWidget->setItem(i,5,new QTableWidgetItem(str));
		//开本
		str = QString("%1").arg(m_vet[i].nKb);
		ui.tableWidget->setItem(i,6,new QTableWidgetItem(str));
		//印张
		str = QString::number(m_vet[i].fYz,'f',2);
		ui.tableWidget->setItem(i,7,new QTableWidgetItem(str));
		//印数
		str = QString("%1").arg(m_vet[i].nYs);
		ui.tableWidget->setItem(i,8,new QTableWidgetItem(str));
		//包册
		str = QString("%1").arg(m_vet[i].nBc);
		ui.tableWidget->setItem(i,9,new QTableWidgetItem(str));
		//令数
		str = QString::number(m_vet[i].fLs,'f',2);
		ui.tableWidget->setItem(i,10,new QTableWidgetItem(str));
		//印张类型
		if (m_vet[i].type != BOOK_TYPE_MAX)
		{
			ui.tableWidget->setItem(i,11,new QTableWidgetItem(BookType[m_vet[i].type]));
		}
		if (m_vet[i].zyType != ZHEYEPAY_TYPE_MAX)
		{
			ui.tableWidget->setItem(i,12,new QTableWidgetItem(ZyType[m_vet[i].zyType-1]));
		}
		if (m_vet[i].rkType != BOOK_RK_MAX)
		{
			ui.tableWidget->setItem(i,13,new QTableWidgetItem(rkType[m_vet[i].rkType]));
		}
		//备注
		ui.tableWidget->setItem(i,14,new QTableWidgetItem(m_vet[i].strMsg));

		//编辑
		QPushButton* btn = new QPushButton(this);
		CGloble::SetButtonStyle(btn,":/PayCount_QT/pic/edit.png",3);
		btn->setProperty("button",i);
		btn->setToolTip(CH("编辑"));
		connect(btn,&QPushButton::clicked,this,&CBookMngDlg::st_BtnEdit);

		QLabel* label = new QLabel("|",this);
		//删除
		QPushButton* delBtn = new QPushButton(this);
		CGloble::SetButtonStyle(delBtn,":/PayCount_QT/pic/yc2.png",3);
		delBtn->setProperty("button",i);
		delBtn->setToolTip(CH("删除"));
		connect(delBtn,&QPushButton::clicked,this,&CBookMngDlg::st_BtnDel);

		QWidget *widget = new QWidget(this);
		QHBoxLayout *hLayout = new QHBoxLayout(this);
		hLayout->addWidget( btn);
		hLayout->addWidget( label);
		hLayout->addWidget( delBtn);
		hLayout->setMargin(0);
		hLayout->setAlignment(widget, Qt::AlignCenter);
		hLayout->setContentsMargins(10, 0, 20, 0);
		widget->setLayout(hLayout);
		ui.tableWidget->setCellWidget(i,15,widget);
		n++;
	}

	str = QString(CH("共%1条记录")).arg(m_nCount);
	ui.label_all->setText(str);
	int ns = m_nCount%20;
	m_nPage = m_nCount/20;
	if(ns>0)
		m_nPage+=1;
	if (m_nPage==0)
		m_nPage=1;
	str = QString(CH("共%1页  第%2页")).arg(m_nPage).arg(m_dex);
	ui.label_dex->setText(str);

	if (m_nPage == 1)
	{
		ui.BTN_LAST->setEnabled(false);
		ui.BTN_NEXT->setEnabled(false);
	}
	else if (m_nPage>1)
	{
		if (m_dex==1)
			ui.BTN_LAST->setEnabled(false);
		else if (m_dex>1)
			ui.BTN_LAST->setEnabled(true);
		if (m_dex<m_nPage)
			ui.BTN_NEXT->setEnabled(true);
		else
			ui.BTN_NEXT->setEnabled(false);
	}
}

void CBookMngDlg::InitCombox()
{
	ui.COMBO_RK->addItem(CH("全部"));
	for (int i=0;i<BOOK_RK_MAX;i++)
	{
		ui.COMBO_RK->addItem(rkType[i]);
	}

	for (int i=0;i<EM_DATE_TYPE_MAX;i++)
	{
		ui.COMBO_DATE->addItem(DateName[i]);
	}
	ui.COMBO_DATE->setCurrentIndex(1);
}

void CBookMngDlg::resizeEvent(QResizeEvent *event)
{
	int w = ui.tableWidget->width();
	for (int i=0;i<LISTCOLUMN;i++)
	{
		if(i==0|| i==4 || i==6|| i==9||  i==13)
			ui.tableWidget->setColumnWidth(i,40);
		else if(i==1)
			ui.tableWidget->setColumnWidth(i,110);
		else if(i==2)
			ui.tableWidget->setColumnWidth(i,300);
		else if(i==15)
			ui.tableWidget->setColumnWidth(i,75);
	}
}

void CBookMngDlg::SendToGetBook(QString strKeyWord,BOOK_RK rkType,EM_DATE_TYPE date_Type,int nStart,int nNum)
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_BOOK;
	string strkey = strKeyWord.toLocal8Bit();
	root[CMD_GETBOOK[GETBOOK_KEYWORD]] = strkey; 
	root[CMD_GETBOOK[GETBOOK_RKTYPE]] = rkType;
	root[CMD_GETBOOK[GETBOOK_DATE]] = date_Type;
	root[CMD_GETBOOK[GETBOOK_NSTART]] = nStart;
	root[CMD_GETBOOK[GETBOOK_NUMBER]] = nNum;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CBookMngDlg::SendToDelBook(QString strBookID)
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_DEL_BOOK;
	root[CMD_DELBOOK[GETBOOK_KEYWORD]] = strBookID.toStdString(); 
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CBookMngDlg::GetBook(Json::Value root)
{
	m_nCount = 0;
	m_vet.clear();

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
		const char* cstr2 = one[CMD_BOOKMSG[BOOKMSG_CBS]].asCString();
		stu.strCbs=CH(cstr2);
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
		const char* cstr3 = one[CMD_BOOKMSG[BOOKMSG_MSG]].asCString();
		stu.strMsg=CH(cstr3);
		//按时间排序
		if(m_vet.size() == 0)
			m_vet.push_back(stu);
		else
		{
			bool bInset=false;
			vector <BOOK_STU>::iterator it;
			for ( it = m_vet.begin( ) ; it != m_vet.end( ) ; it++ )
			{
				if (JudgeDateStringSize(stu.strDate,it->strDate)<=0)
				{
					bInset = true;
					m_vet.insert(it,stu);
					break;
				}
			}
			if(!bInset)
				m_vet.push_back(stu);
		}
	}
	m_nCount = root[CMD_BOOKMSG[BOOKMSG_XCOUNT]].asInt();
	SetListCtrlValue();
}

int CBookMngDlg::JudgeDateStringSize(QString strDate1,QString strDate2)
{
	QDate date1 = QDate::fromString(strDate1,"yyyy/MM/dd");
	QDate date2 = QDate::fromString(strDate2,"yyyy/MM/dd");
	uint n1 = date1.toJulianDay();
	uint n2 = date2.toJulianDay();
	return n1 -n2;
}

void CBookMngDlg::FindBook(int pageDex)
{
	QString strKeyWord= ui.EDIT_KEY->text();
	SendToGetBook(strKeyWord,m_rkType,m_date_Type,(pageDex-1)*20,20);
}

void CBookMngDlg::st_BtnEdit()
{
	QObject *pObject = this->sender();
	QPushButton *btn = qobject_cast<QPushButton *>(pObject);
	int nRow = btn->property("button").toInt();
	QString strBookID = ui.tableWidget->item(nRow,1)->data(1).toString();
	CAddBookDlg dlg(this,false,nRow);
	int nType = dlg.exec();
	g_Globle.SetCallback(BookMngCallback,this);
	if(nType == QDialog::Accepted)
		BtnFind();
}

void CBookMngDlg::st_BtnDel()
{
	QObject *pObject = this->sender();
	QPushButton *btn = qobject_cast<QPushButton *>(pObject);
	int nRow = btn->property("button").toInt();
	QString strBookID = ui.tableWidget->item(nRow,1)->data(1).toString();
	QString strName = ui.tableWidget->item(nRow,2)->text();

	QString str = QString(CH("该操作将会删除与该书相关的所有记录，包括（进度，明细，做工统计），确认删除 %1？")).arg(strName);
	int nType = QMessageBox::warning(this,CH("警告"),str,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
	if (nType == QMessageBox::Ok)
	{
		SendToDelBook(strBookID);
	}
}

void CBookMngDlg::BtnFind()
{
	m_dex = 1;
	int ndex = ui.COMBO_RK->currentIndex();
	if (ndex == 0)
		m_rkType = BOOK_RK_MAX;
	else
		m_rkType = BOOK_RK(ndex -1);

	m_date_Type = (EM_DATE_TYPE)ui.COMBO_DATE->currentIndex();

	FindBook(m_dex);
}
void CBookMngDlg::BtnAdd()
{
	CAddBookDlg dlg;
	int nType = dlg.exec();
	g_Globle.SetCallback(BookMngCallback,this);
	if(nType == QDialog::Accepted)
		BtnFind();
}
void CBookMngDlg::BtnGo()
{
	int ndex =ui.EDIT_GO->text().toInt();
	if (ndex==0 || ndex> m_nPage)
		return;
	else
	{
		m_dex=ndex;
		FindBook(m_dex);
	}
}
void CBookMngDlg::BtnLast()
{
	if (m_dex>1)
	{
		m_dex--;
		FindBook(m_dex);
	}
}
void CBookMngDlg::BtnNext()
{
	if (m_dex<m_nPage)
	{
		m_dex++;
		FindBook(m_dex);
	}
}
