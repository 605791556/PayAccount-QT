#include "CStaffMngDlg.h"
#include "CAddStaffDlg.h"

void CStaffMngDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_GET_STAFF:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取职工信息失败！"));
			else
			{
				GetStaff(root);
			}
		}
		break;
	case SOCK_CMD_DEL_STAFF:
	case SOCK_CMD_PLDEL_STAFF:
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

CStaffMngDlg::CStaffMngDlg(QWidget *parent)
	: CDlgFather(parent)
{
	m_nPage=1;
	m_dex=1;

	ui.setupUi(this);
	setWindowFlags(windowFlags() &~ (Qt::WindowMinMaxButtonsHint));
	CGloble::SetButtonStyle(ui.BTN_FIND,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_ADD,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_LAST,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_NEXT,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_PL_DEL,":/PayCount_QT/pic/ok.png",3);

	connect(this,&CStaffMngDlg::sg_CalBak,this,&CStaffMngDlg::st_CalBak);
	connect(ui.BTN_FIND,SIGNAL(clicked()),this,SLOT(BtnFind()));
	connect(ui.BTN_ADD,SIGNAL(clicked()),this,SLOT(BtnAdd()));
	connect(ui.BTN_GO,SIGNAL(clicked()),this,SLOT(BtnGo()));
	connect(ui.BTN_LAST,SIGNAL(clicked()),this,SLOT(BtnLast()));
	connect(ui.BTN_NEXT,SIGNAL(clicked()),this,SLOT(BtnNext()));
	connect(ui.BTN_PL_DEL,SIGNAL(clicked()),this,SLOT(st_BtnPlDel()));

	g_Globle.m_DlgMap[EM_DLG_MNGSTAFF] = this;

	showMaximized();
	InitListCtrl();
	SendToGetStaff("",(m_dex-1)*20,20);
}

CStaffMngDlg::~CStaffMngDlg()
{
	
}

void CStaffMngDlg::InitListCtrl()
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
	headers<<CH("")<<CH("序号")<<CH("姓名")<<CH("性别")<<CH("年龄")<<CH("入职时间")<<CH("联系方式")<<CH("类型")<<CH("日薪")<<CH("操作");
	ui.tableWidget->setColumnCount(LISTCOLUMN); 
	ui.tableWidget->setHorizontalHeaderLabels(headers);

	ui.tableWidget->setColumnWidth(9,75);
}

void CStaffMngDlg::SetListCtrlValue()
{
	ui.tableWidget->clearContents();
	QString str;
	int nCount = m_vet.size();
	ui.tableWidget->setRowCount(nCount);
	int n = 1;
	for (int i=0;i<nCount;i++)
	{
		//checkbox
		QCheckBox* cbox = new QCheckBox();
		cbox->setProperty("cbox",i);
		QWidget *widget2 = new QWidget(ui.tableWidget);
		QHBoxLayout *hLayout2 = new QHBoxLayout(ui.tableWidget);
		hLayout2->addWidget(cbox);
		hLayout2->setMargin(0);
		hLayout2->setAlignment(widget2, Qt::AlignCenter);
		hLayout2->setContentsMargins(5, 0, 0, 0);
		widget2->setLayout(hLayout2);
		ui.tableWidget->setCellWidget(i,0,widget2);
		//序号
		str = QString("%1").arg(n+(m_dex-1)*20);
		ui.tableWidget->setItem(i,1,new QTableWidgetItem(str));
		//姓名
		ui.tableWidget->setItem(i,2,new QTableWidgetItem(m_vet[i].strname));
		//绑定ID
	    QVariant vt;
		vt.setValue<QString>(m_vet[i].strStaffID);
		ui.tableWidget->item(i,1)->setData(1,vt);
		//性别
		ui.tableWidget->setItem(i,3,new QTableWidgetItem(m_vet[i].strSex));
		//年龄
		str = QString("%1").arg(m_vet[i].age);
		ui.tableWidget->setItem(i,4,new QTableWidgetItem(str));
		//入职时间
		ui.tableWidget->setItem(i,5,new QTableWidgetItem(m_vet[i].strInTime));
		//联系方式
		ui.tableWidget->setItem(i,6,new QTableWidgetItem(m_vet[i].strTel));
		//类型
		ui.tableWidget->setItem(i,7,new QTableWidgetItem(StaffType[m_vet[i].type]));
		//日薪
		str = QString::number(m_vet[i].fDaypay,'f',2);
		ui.tableWidget->setItem(i,8,new QTableWidgetItem(str));
		//编辑
		QPushButton* btn = new QPushButton(this);
		CGloble::SetButtonStyle(btn,":/PayCount_QT/pic/edit.png",3);
		btn->setProperty("button",i);
		btn->setToolTip(CH("编辑"));
		connect(btn,&QPushButton::clicked,this,&CStaffMngDlg::st_BtnEdit);

		QLabel* label = new QLabel("|",this);
		//删除
		QPushButton* delBtn = new QPushButton(this);
		CGloble::SetButtonStyle(delBtn,":/PayCount_QT/pic/yc2.png",3);
		delBtn->setProperty("button",i);
		delBtn->setToolTip(CH("删除"));
		connect(delBtn,&QPushButton::clicked,this,&CStaffMngDlg::st_BtnDel);

		QWidget *widget = new QWidget(this);
		QHBoxLayout *hLayout = new QHBoxLayout(this);
		hLayout->addWidget( btn);
		hLayout->addWidget( label);
		hLayout->addWidget( delBtn);
		hLayout->setMargin(0);
		hLayout->setAlignment(widget, Qt::AlignCenter);
		hLayout->setContentsMargins(10, 0, 20, 0);
		widget->setLayout(hLayout);
		ui.tableWidget->setCellWidget(i,9,widget);
		n++;
	}

	str = QString(CH("共%1条记录")).arg(m_nCount);
	ui.label_number->setText(str);
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

void CStaffMngDlg::resizeEvent(QResizeEvent *event)
{
	int w = ui.tableWidget->width();
	for (int i=0;i<LISTCOLUMN;i++)
	{
		if(i==1|| i==3 || i==4)
			ui.tableWidget->setColumnWidth(i,48);
		else if(i==0)
			ui.tableWidget->setColumnWidth(i,25);
		else if(i==7)
			ui.tableWidget->setColumnWidth(i,75);
		else if(i==9)
			ui.tableWidget->setColumnWidth(i,75);
		else
			ui.tableWidget->setColumnWidth(i,(w-75*2-48*3-25)/(LISTCOLUMN-6));
	}
}

void CStaffMngDlg::SendToGetStaff(QString strKeyWord,int nStart,int nNum)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_MNGSTAFF;
	root[CONNECT_CMD]=SOCK_CMD_GET_STAFF;
	string strkey = strKeyWord.toLocal8Bit();
	root[CMD_GETSTAFF[EM_GET_STAFF_KEYWORD]]=strkey;
	root[CMD_GETSTAFF[EM_GET_STAFF_NSTART]]=nStart;
	root[CMD_GETSTAFF[EM_GET_STAFF_NUMBER]]=nNum;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CStaffMngDlg::SendToDelStaff(QString strStaffID)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_MNGSTAFF;
	root[CONNECT_CMD]=SOCK_CMD_DEL_STAFF;
	root[CMD_DELSTAFF[EM_DEL_STAFF_ID]]=strStaffID.toStdString();
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CStaffMngDlg::SendToPlDelStaff(string strListID)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_MNGSTAFF;
	root[CONNECT_CMD]=SOCK_CMD_PLDEL_STAFF;
	root[CMD_DELSTAFF[EM_DEL_STAFF_ID]]=strListID;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CStaffMngDlg::GetStaff(Json::Value root)
{
	m_nCount = 0;
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
				const char* cstr = js[i][CMD_STAFFMSG[EM_STAFF_MSG_NAME]].asCString();
				stu.strname=CH(cstr);
				const char* cstr2 = js[i][CMD_STAFFMSG[EM_STAFF_MSG_SEX]].asCString();
				stu.strSex=CH(cstr2);
				stu.age = js[i][CMD_STAFFMSG[EM_STAFF_MSG_AGE]].asInt();
				stu.strStaffID = js[i][CMD_STAFFMSG[EM_STAFF_MSG_STAFFID]].asCString();
				stu.strIdCard = js[i][CMD_STAFFMSG[EM_STAFF_MSG_IDCARD]].asCString();
				stu.strInTime = js[i][CMD_STAFFMSG[EM_STAFF_MSG_INTIME]].asCString();
				stu.strTel = js[i][CMD_STAFFMSG[EM_STAFF_MSG_TEL]].asCString();
				stu.type = (STAFF_TYPE)js[i][CMD_STAFFMSG[EM_STAFF_MSG_TYPE]].asInt();
				stu.sort = js[i][CMD_STAFFMSG[EM_STAFF_MSG_SORT]].asInt();
				stu.fDaypay = js[i][CMD_STAFFMSG[EM_STAFF_MSG_DAYPAY]].asDouble();
				m_vet.push_back(stu);
			}
		}
	}
	m_nCount = root[CMD_STAFFMSG[EM_STAFF_MSG_COUNT]].asInt();
	SetListCtrlValue();
}

void CStaffMngDlg::st_BtnEdit()
{
	QObject *pObject = this->sender();
	QPushButton *btn = qobject_cast<QPushButton *>(pObject);
	int nRow = btn->property("button").toInt();
	QString strStaffID = ui.tableWidget->item(nRow,1)->data(1).toString();

	CAddStaffDlg dlg(this,false,nRow);
	int nType = dlg.exec();
	if(nType == QDialog::Accepted)
		BtnFind();
	
}
void CStaffMngDlg::st_BtnDel()
{
	QObject *pObject = this->sender();
	QPushButton *btn = qobject_cast<QPushButton *>(pObject);
	int nRow = btn->property("button").toInt();
	QString strStaffID = ui.tableWidget->item(nRow,1)->data(1).toString();
	QString strStaffName = ui.tableWidget->item(nRow,2)->text();

	QString str = QString(CH("该操作不会删除与该职工相关的工作记录，确认删除 %1？")).arg(strStaffName);
	int nType = QMessageBox::warning(this,CH("警告"),str,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
	switch(nType)
	{
	case QMessageBox::Ok:
		{
			SendToDelStaff(strStaffID);
		}
		break;
	}
}

void CStaffMngDlg::st_BtnPlDel()
{
	string strList;
	int nCount = ui.tableWidget->rowCount();
	for (int i=0;i<nCount;i++)
	{
		QWidget* wt = (QWidget*)ui.tableWidget->cellWidget(i,0);
		QHBoxLayout* lyt = (QHBoxLayout*)wt->layout();
		QLayoutItem* item = lyt->layout()->itemAt(0);
		QCheckBox* box = qobject_cast<QCheckBox *>(item->widget());
		int nRow = box->property("cbox").toInt();
		if (box && box->isChecked())
		{
			QString strStaffID = ui.tableWidget->item(i,1)->data(1).toString();
			strList += strStaffID.toStdString() + ";";
		}
	}
	if (nCount > 0 && strList.empty())
		QMessageBox::information(this, CH("提示"), CH("请先勾选需要删除的职工！"));	
	else
	{
		QString str = QString(CH("该操作不会删除与之相关的记录，确认删除？"));
		int nType = QMessageBox::warning(this,CH("警告"),str,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
		if (nType == QMessageBox::Ok)
			SendToPlDelStaff(strList);
	}
}

void CStaffMngDlg::BtnFind()
{
	m_dex = 1;
	m_strKeyWord = ui.EDIT_KEY->text();
	SendToGetStaff(m_strKeyWord,(m_dex-1)*20,20);
}
void CStaffMngDlg::BtnAdd()
{
	CAddStaffDlg dlg;
	int nType = dlg.exec();
	if(nType == QDialog::Accepted)
		BtnFind();
}
void CStaffMngDlg::BtnGo()
{
	int ndex = ui.EDIT_DEX->text().toInt();
	if (ndex==0 || ndex> m_nPage)
		return;
	else
	{
		m_dex=ndex;
		SendToGetStaff(m_strKeyWord,(m_dex-1)*20,20);
	}
}
void CStaffMngDlg::BtnLast()
{
	if (m_dex>1)
	{
		m_dex--;
		SendToGetStaff(m_strKeyWord,(m_dex-1)*20,20);
	}
}
void CStaffMngDlg::BtnNext()
{
	if (m_dex<m_nPage)
	{
		m_dex++;
		SendToGetStaff(m_strKeyWord,(m_dex-1)*20,20);
	}
}
