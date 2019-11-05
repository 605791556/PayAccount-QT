#include "CDayPayDlg.h"
#include "CTabWorkDayDlg.h"

void DayCheckCallback(void* p,string strData)
{
	CDayPayDlg* pThis=(CDayPayDlg*) p;
	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CDayPayDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_GET_DPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取日薪失败！"));
			else
			{
				GetDPay(root);
				SendToGetBook();
			}
		}
		break;
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
				SendToGetDayPay();
			}
		}
		break;
	case SOCK_CMD_GET_DAYPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取做工统计失败！"));
			else
			{
				GetDayPay(root);
			}	
		}
		break;
	case SOCK_CMD_DEL_DAYPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("保存做工失败！"));
			else
			{
				SendToSaveDayPay();
			}	
		}
		break;
	case SOCK_CMD_SAVE_DAYPAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("保存做工统计失败！"));
			else
			{
				QMessageBox::information(this, CH("提示"), CH("保存成功！"));
				accept();
			}	
		}
		break;
	case SOCK_CMD_GET_PAY:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取单价失败！"));
			else
			{
				GetOnePay(root);
			}	
		}
		break;
	}
}

CDayPayDlg::CDayPayDlg(const QModelIndex & mdIndex,QWidget* tabWkDlg,QWidget *parent)
	: CDlgFather(parent)
{
	ui.setupUi(this);
	
	setWindowFlags(Qt::FramelessWindowHint);//去掉边框
	setAttribute(Qt::WA_TranslucentBackground);//透明
	///背景加载;
	m_pixmapBg.load(":/PayCount_QT/pic/cbg.png");

	m_nx = m_ny = 0;
	m_bmax = false;

	//初始化标题
	InitTitle(mdIndex,tabWkDlg);
	//初始化列表
	InitListCtrl();
	g_Globle.m_DlgMap[EM_DLG_DAYPAY] = this;

	connect(this,&CDayPayDlg::sg_CalBak,this,&CDayPayDlg::st_CalBak);
	connect(ui.BTN_ADD,SIGNAL(clicked()),this,SLOT(st_BtnAdd()));
	connect(ui.BTN_SAVE,SIGNAL(clicked()),this,SLOT(st_BtnSave()));
	connect(ui.edit_payday,SIGNAL(textChanged(const QString &)),this,SLOT(st_SetAllPayCtrl()));
	connect(ui.edit_day,SIGNAL(textChanged(const QString &)),this,SLOT(st_SetAllPayCtrl()));
	connect(ui.edit_delpay,SIGNAL(textChanged(const QString &)),this,SLOT(st_SetAllPayCtrl()));
	connect(ui.BTN_MAX, SIGNAL(clicked()), this, SLOT(st_BtnMax()));

	
	ui.edit_payday->setValidator(g_Globle.dbVtor);
	ui.edit_day->setValidator(g_Globle.dbVtor);
	ui.edit_delpay->setValidator(g_Globle.dbVtor);

	CGloble::SetButtonStyle(ui.BTN_MAX,":/PayCount_QT/pic/max.png",3);
	CGloble::SetButtonStyle(ui.BTN_CLOSE,":/PayCount_QT/pic/close.png",3);
	CGloble::SetButtonStyle(ui.BTN_SAVE,":/PayCount_QT/pic/login_btn.png",3);
	CGloble::SetButtonStyle(ui.BTN_ADD,":/PayCount_QT/pic/ok.png",3);
	SendToGetDPay();
}

CDayPayDlg::~CDayPayDlg()
{
	DeleteTableCtrl();
}

void CDayPayDlg::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawPixmap(this->rect(),m_pixmapBg);
}

void CDayPayDlg::mouseMoveEvent(QMouseEvent *event)
{
	if (m_nx==0 && m_ny==0)
	{
		m_nx = event->x();
		m_ny = event->y();
	}

	if (m_ny<=110)//只在顶层窗口区域拖动有效
	{
		int g_x = event->globalX();
		int g_y = event->globalY();
		move(g_x-m_nx,g_y-m_ny);
	}
}

void CDayPayDlg::mouseReleaseEvent(QMouseEvent *event)
{
	m_nx = m_ny = 0;
}

void CDayPayDlg::mouseDoubleClickEvent(QMouseEvent *event)
{
	if(event->button()==Qt::LeftButton)
	{
		if (event->y()<=110)
		{
			if (m_bmax)
				showNormal();
			else
				showMaximized();
			m_bmax = !m_bmax;
		}
	}
}

void CDayPayDlg::InitTitle(const QModelIndex & mdIndex,QWidget* widget)
{
	CTabWorkDayDlg* pTabWkDlg = (CTabWorkDayDlg*)widget;
	QDate date = pTabWkDlg->ui.dateEdit->date();

	QString strName = pTabWkDlg->m_pViewModel->item(mdIndex.row(),0)->text();
	m_strStaffID = pTabWkDlg->m_pViewModel->item(mdIndex.row(),0)->accessibleText();
	m_strDate = date.toString("yyyy/MM/dd");
	QString strTitle = strName + " "+m_strDate+CH(" 做工统计");
	ui.label_title->setText(strTitle);
}

void CDayPayDlg::InitListCtrl()
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
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色


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
	headers<<CH("项目")<<CH("书名")<<CH("单价")<<CH("数量")<<CH("金额")<<CH("操作");
	ui.tableWidget->setColumnCount(6); 
	ui.tableWidget->setHorizontalHeaderLabels(headers);
	
	for (int i=0;i<6;i++)
	{
		if(i == 0)
			ui.tableWidget->setColumnWidth(i,210);
		else if(i == 1)
		    ui.tableWidget->setColumnWidth(i,300);
		else if(i == 5)
			ui.tableWidget->setColumnWidth(i,60);
		else
			ui.tableWidget->setColumnWidth(i,(1000-582)/3);
	}
}

void CDayPayDlg::AddTableRow(int oldProIndex,int oldBkIndex,QString dpay,double number,QString money)
{
	int row = ui.tableWidget->rowCount();
	ui.tableWidget->setRowCount(row+1);
	//项目
	QComboBox *proComBox = CreateProCombox(oldProIndex);
	proComBox->setProperty("combox",row);
	connect(proComBox,SIGNAL(currentIndexChanged(int)),this,SLOT(st_comboChanged(int)));
	ui.tableWidget->setCellWidget(row,0,proComBox);
	//图书
	QComboBox *bookComBox = CreateBookCombox(oldBkIndex);
	bookComBox->setProperty("combox",row);
	connect(bookComBox,SIGNAL(currentIndexChanged(int)),this,SLOT(st_comboChanged(int)));
	ui.tableWidget->setCellWidget(row,1,bookComBox);
	//单价
	if (!dpay.isEmpty())
	{
		ui.tableWidget->setItem(row,2,new QTableWidgetItem(dpay));
	}
	//数量
	QLineEdit* edit = new QLineEdit;
	QFont list_font;
	list_font.setPointSize(11);

	edit->setFont(list_font);
	edit->setValidator(g_Globle.dbVtor);
	edit->setProperty("edit",row);
	connect(edit,SIGNAL(textChanged(const QString &)),this,SLOT(st_numberEditChanged(const QString &)));
	edit->setStyleSheet("border-width:0;border-style:outset");
	edit->setPlaceholderText(CH("点击输入数量"));
	edit->setAlignment(Qt::AlignHCenter);
	ui.tableWidget->setCellWidget(row,3,edit);
	if(number > 0)
	{
		QString str = QString("%1").arg(number);
		edit->setText(str);
	}
	//金额
	QLineEdit* edit2 = new QLineEdit;
	edit2->setFont(list_font);
	connect(edit2,SIGNAL(textChanged(const QString &)),this,SLOT(st_SetAllPayCtrl()));
	edit2->setFocusPolicy(Qt::NoFocus);
	edit2->setStyleSheet("border-width:0;border-style:outset");
	edit2->setAlignment(Qt::AlignHCenter);
	ui.tableWidget->setCellWidget(row,4,edit2);
	if (!money.isEmpty())
		edit2->setText(money);
	//删除
	QPushButton* btn = new QPushButton;
	CGloble::SetButtonStyle(btn,":/PayCount_QT/pic/yc2.png",3);
	btn->setProperty("button",row);
	connect(btn,&QPushButton::clicked,this,&CDayPayDlg::st_BtnDel);

	QWidget *widget = new QWidget(this);
	QHBoxLayout *hLayout = new QHBoxLayout(this);
	hLayout->addWidget( btn);
	hLayout->setMargin(0);
	hLayout->setAlignment(widget, Qt::AlignCenter);
	hLayout->setContentsMargins(10, 0, 20, 0);
	widget->setLayout(hLayout);
	ui.tableWidget->setCellWidget(row,5,widget);
}

void CDayPayDlg::DeleteTableCtrl()
{
	int nRows = ui.tableWidget->rowCount();
	for (int i=0;i<nRows;i++)
	{
		QComboBox* proCombox = (QComboBox*)ui.tableWidget->cellWidget(i,0);
		QComboBox* bkCombox = (QComboBox*)ui.tableWidget->cellWidget(i,1);
		QLineEdit* number_edit = (QLineEdit*)ui.tableWidget->cellWidget(i,3);
		QLineEdit* money_edit = (QLineEdit*)ui.tableWidget->cellWidget(i,4);
		QPushButton* button = (QPushButton*)ui.tableWidget->cellWidget(i,2);
		delete proCombox;
		delete bkCombox;
		delete number_edit;
		delete money_edit;
		delete button;
	}
	ui.tableWidget->clearContents();
}

void CDayPayDlg::SetListCtrlValue()
{
	for (int i = 0; i < m_vCal.size(); i++)
	{
		if (m_vCal[i].type == DAYPAY_TYPE_JIJIAN)
		{
			AddTableRow(i,i,m_vCal[i].pay,m_vCal[i].number,m_vCal[i].money);
		}
		else if (m_vCal[i].type == DAYPAY_TYPE_DAY)
		{
			ui.edit_payday->setText(m_vCal[i].strPayDay);
			ui.edit_day->setText(m_vCal[i].strDays);
		}
		else if (m_vCal[i].type == DAYPAY_TYPE_DEL)
		{
			ui.edit_delpay->setText(m_vCal[i].money);
			ui.edit_delmsg->setText(m_vCal[i].strMsg);
		}
	}
}

void CDayPayDlg::st_numberEditChanged(const QString & strNumber)
{
	// 获取发送者
	QObject *pObject = this->sender();
	QLineEdit* edit = qobject_cast<QLineEdit *>(pObject);
	//获取行索引
	int nRow = edit->property("edit").toInt();
	//获取单价
	double fdpay = 0;
	QTableWidgetItem* item = ui.tableWidget->item(nRow,2);
	if (item)
		fdpay = item->text().toDouble();

	double fmoney = fdpay * strNumber.toDouble();
	QString str = QString::number(fmoney,'f',2);
	//设置金额
	QLineEdit* money_edit = (QLineEdit*)ui.tableWidget->cellWidget(nRow,4);
	if (money_edit)
	{
		money_edit->setText(str);
	}
}

void CDayPayDlg::st_SetAllPayCtrl()
{
	QString strMoney;
	double day_money = 0;
	double jj_money = 0;
	double del_money = 0;
	double all_money = 0;
	//按天
	double f_payday = ui.edit_payday->text().toDouble();
	double f_day = ui.edit_day->text().toDouble();
	day_money = f_payday * f_day;
	all_money += day_money;
	strMoney = QString(CH("按天金额："))+QString::number(day_money,'f',2);
	ui.label_tpay->setText(strMoney);
	//扣除
	del_money = ui.edit_delpay->text().toDouble();
	all_money -= del_money;
	//计件
	int nCount = ui.tableWidget->rowCount();
	for (int i = 0; i < nCount; i++)
	{
		QLineEdit* edit = (QLineEdit*)ui.tableWidget->cellWidget(i,4);
		jj_money += edit->text().toDouble();
	}
	strMoney = QString(CH("计件金额："))+QString::number(jj_money,'f',2);
	ui.label_jpay->setText(strMoney);
	all_money += jj_money;
	//总计
	strMoney = QString(CH("总计："))+QString::number(all_money,'f',2);
	ui.label_all->setText(strMoney);
}

QComboBox* CDayPayDlg::CreateProCombox(int oldIndex)
{
	QComboBox *comBox = new QComboBox();
	comBox->setMaxVisibleItems(25);
	if (oldIndex < 0)
	{
		QString str;
		int nCount = m_vProjects.size();
		for (int i=0;i<nCount;i++)
		{
			QVariant var;
			var.setValue(m_vProjects[i].nID);
			str = QString("%1.%2").arg(i+1).arg(m_vProjects[i].strName);
			comBox->addItem(str,var);
		}
	}
	else
	{
		QVariant var;
		var.setValue(m_vCal[oldIndex].proID);
		comBox->addItem(m_vCal[oldIndex].strProName,var);
	}
	return comBox;
}

QComboBox* CDayPayDlg::CreateBookCombox(int oldIndex)
{
	QString str;
	QComboBox *comBox = new QComboBox();
	comBox->setMaxVisibleItems(25);
	if (oldIndex < 0)
	{
		int nCount = m_vBooks.size();
		for (int i=0;i<nCount;i++)
		{
			QVariant var;
			var.setValue(m_vBooks[i].strBookID);
			str = QString("%1.%2").arg(i+1).arg(m_vBooks[i].strname);
			comBox->addItem(str,var);
		}
	}
	else
	{
		QVariant var;
		var.setValue(m_vCal[oldIndex].strBookID);
		comBox->addItem(m_vCal[oldIndex].strBookName,var);
	}
	return comBox;
}

void CDayPayDlg::st_comboChanged(int index)
{
	// 获取发送者
	QObject *pObject = this->sender();
	QComboBox *pCombox = qobject_cast<QComboBox *>(pObject);
	//获取行索引
	int nRow = pCombox->property("combox").toInt();

	QComboBox* proCombox = (QComboBox*)ui.tableWidget->cellWidget(nRow,0);
	int pro_dex = proCombox->currentIndex();
	int proID = proCombox->itemData(pro_dex).toInt();

	QComboBox* bkCombox = (QComboBox*)ui.tableWidget->cellWidget(nRow,1);
	int bk_dex = bkCombox->currentIndex();
	QString strBookID = bkCombox->itemData(bk_dex).toString();
	SendToGetOnePay(proID, strBookID,nRow);
}

void CDayPayDlg::st_BtnDel()
{
	// 获取发送者
	QObject *pObject = this->sender();
	QPushButton *pButton = qobject_cast<QPushButton *>(pObject);
	//获取行索引
	int row = pButton->property("button").toInt();
	//删除前先修改控件属性（行索引）
	int nRows = ui.tableWidget->rowCount();
	for (int i = row+1;i<nRows;i++)
	{
		//获取单元格中的控件
		QComboBox* proCombox = (QComboBox*)ui.tableWidget->cellWidget(i,0);
		QComboBox* bkCombox = (QComboBox*)ui.tableWidget->cellWidget(i,1);
		QPushButton* button = (QPushButton*)ui.tableWidget->cellWidget(i,5);
		proCombox->setProperty("combox",i-1);
		bkCombox->setProperty("combox",i-1);
		button->setProperty("button",i-1);
	}
	//删除行，释放控件
	QComboBox* proCombox = (QComboBox*)ui.tableWidget->cellWidget(row,0);
	QComboBox* bkCombox = (QComboBox*)ui.tableWidget->cellWidget(row,1);
	QLineEdit* edit = (QLineEdit*)ui.tableWidget->cellWidget(row,3);
	QLineEdit* edit2 = (QLineEdit*)ui.tableWidget->cellWidget(row,4);
	ui.tableWidget->removeRow(row);
	delete proCombox;
	delete bkCombox;
	delete edit;
	delete edit2;
	delete pButton;

	st_SetAllPayCtrl();
}

void CDayPayDlg::st_BtnMax()
{
	if (m_bmax)
		showNormal();
	else
		showMaximized();
	m_bmax = !m_bmax;
}

void CDayPayDlg::st_BtnAdd()
{
	AddTableRow();
}

void CDayPayDlg::st_BtnSave()
{
	m_vSaves.clear();

	//天
	QString strDayPay = ui.edit_payday->text();
	QString strDays = ui.edit_day->text();
	double  money = strDayPay.toDouble() * strDays.toDouble();
	if (money > 0)
	{
		DAYPAY day_cal;
		day_cal.type = DAYPAY_TYPE_DAY;
		QString strMoney = QString::number(money,'f',2);
		day_cal.strPayDay = strDayPay;
		day_cal.strDays = strDays;
		day_cal.money = strMoney;
		m_vSaves.push_back(day_cal);
	}

	//扣除
	QString strDelMoney = ui.edit_delpay->text();
	QString strDelMsg = ui.edit_delmsg->text();
	if (strDelMoney.toDouble() != 0)
	{
		DAYPAY cal;
		cal.type = DAYPAY_TYPE_DEL;
		cal.money = strDelMoney;
		cal.strMsg = strDelMsg;
		m_vSaves.push_back(cal);
	}

	//件
	int nRows = ui.tableWidget->rowCount();
	for (int i=0;i<nRows;i++)
	{
		DAYPAY cal;
		cal.type = DAYPAY_TYPE_JIJIAN;
		QComboBox* proCombox = (QComboBox*)ui.tableWidget->cellWidget(i,0);
		QComboBox* bkCombox = (QComboBox*)ui.tableWidget->cellWidget(i,1);
		QLineEdit* number_edit = (QLineEdit*)ui.tableWidget->cellWidget(i,3);
		QLineEdit* money_edit = (QLineEdit*)ui.tableWidget->cellWidget(i,4);

		int proDex = proCombox->currentIndex();
		int bkDex  = bkCombox->currentIndex();
		if (proDex <0 || bkDex < 0)
		{
			QMessageBox::information(this, CH("提示"), CH("缺少数据项！"));
			return;
		}
		else
		{
			//项目
			cal.proID = proCombox->itemData(proDex).toInt();
			cal.strProName = proCombox->currentText();
			//图书
			cal.strBookID = bkCombox->itemData(bkDex).toString();
			cal.strBookName = bkCombox->currentText();
			//单价
			QTableWidgetItem* itm = ui.tableWidget->item(i,2);
			if (!itm || itm->text().isEmpty())
			{
				QMessageBox::information(this, CH("提示"), CH("单价缺损！"));
				return;
			}
			else
				cal.pay = itm->text();
			//数量
			cal.number = number_edit->text().toDouble();
			if (number_edit->text().isEmpty())
			{
				QMessageBox::information(this, CH("提示"), CH("请输入数量！"));
				return;
			}
			//金额
			cal.money = money_edit->text();
			m_vSaves.push_back(cal);
		}
	}
	//先删除，再保存
	SendToDelDayPay();
}

void CDayPayDlg::SendToGetDPay()
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_DAYPAY;
	root[CONNECT_CMD]=SOCK_CMD_GET_DPAY;
	root[CMD_STAFFMSG[EM_STAFF_MSG_STAFFID]] = m_strStaffID.toStdString();
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CDayPayDlg::SendToGetBook()
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_DAYPAY;
	root[CONNECT_CMD]=SOCK_CMD_GET_SAMPLE_BOOK;
	root[CMD_GETBOOK[GETBOOK_RKTYPE]] = BOOK_RK_NO;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CDayPayDlg::SendToGetProject()
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_DAYPAY;
	root[CONNECT_CMD]=SOCK_CMD_GET_PROJECT;
	root[CMD_GETPRO[EM_GETPRO_BWRITE]]=PRO_STAFF_TYPE_MAX;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("提示"), CH("发送网络请求失败，请检查网络是否正常！"));
	}
}

void CDayPayDlg::SendToGetDayPay()
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_DAYPAY;
	root[CONNECT_CMD]=SOCK_CMD_GET_DAYPAY;
	root[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFID]]=m_strStaffID.toStdString();
	root[CMD_GETDAYPAY[EM_GET_DAYPAY_DATE]]=m_strDate.toStdString();
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CDayPayDlg::SendToDelDayPay()
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_DAYPAY;
	root[CONNECT_CMD]=SOCK_CMD_DEL_DAYPAY;
	root[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFID]]=m_strStaffID.toStdString();
	root[CMD_GETDAYPAY[EM_GET_DAYPAY_DATE]]=m_strDate.toStdString();
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CDayPayDlg::SendToGetOnePay(int proID,QString strBookID,int nItem)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_DAYPAY;
	root[CONNECT_CMD]=SOCK_CMD_GET_PAY;
	root[GETPAYMSG[EM_GET_PAY_STAFFID]]=m_strStaffID.toStdString();
	root[GETPAYMSG[EM_GET_PAY_PROID]]=proID;
	root[GETPAYMSG[EM_GET_PAY_BOOKID]]=strBookID.toStdString();
	root[GETPAYMSG[EM_GET_PAY_NITEM]]=nItem;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CDayPayDlg::SendToSaveDayPay()
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_DAYPAY;
	root[CONNECT_CMD]=SOCK_CMD_SAVE_DAYPAY;
	root[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFID]]=m_strStaffID.toStdString();
	root[CMD_GETDAYPAY[EM_GET_DAYPAY_DATE]]=m_strDate.toStdString();
	int nSize = m_vSaves.size();
	if (nSize > 0)
	{
		for (int i=0;i<nSize;i++)
		{
			Json::Value one;
			if (m_vSaves[i].type == DAYPAY_TYPE_DEL)
			{
				string strMsg = m_vSaves[i].strMsg.toLocal8Bit();
				one[DAYPAYMSG[EM_DAYPAY_MSG_DELMSG]] = strMsg;//中文
			}
			else if (m_vSaves[i].type == DAYPAY_TYPE_DAY)
			{
				one[DAYPAYMSG[EM_DAYPAY_MSG_PAYDAY]] = m_vSaves[i].strPayDay.toStdString();
				one[DAYPAYMSG[EM_DAYPAY_MSG_DAYS]] = m_vSaves[i].strDays.toStdString();
			}
			else if (m_vSaves[i].type == DAYPAY_TYPE_JIJIAN)
			{
				one[DAYPAYMSG[EM_DAYPAY_MSG_PROID]] = m_vSaves[i].proID;
				one[DAYPAYMSG[EM_DAYPAY_MSG_BOOKID]] = m_vSaves[i].strBookID.toStdString();
				one[DAYPAYMSG[EM_DAYPAY_MSG_PAY]] = m_vSaves[i].pay.toStdString();
				one[DAYPAYMSG[EM_DAYPAY_MSG_NUMBER]] = m_vSaves[i].number;

				string strProName = m_vSaves[i].strProName.toLocal8Bit();
				string strBookName = m_vSaves[i].strBookName.toLocal8Bit();
				
				one[DAYPAYMSG[EM_DAYPAY_MSG_PRONAME]] = strProName;//中文
				one[DAYPAYMSG[EM_DAYPAY_MSG_BOOKNAME]] = strBookName;//中文
			}
			one[DAYPAYMSG[EM_DAYPAY_MSG_MONEY]] = m_vSaves[i].money.toStdString();
			one[DAYPAYMSG[EM_DAYPAY_MSG_TYPE]] = m_vSaves[i].type;
			root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
		}
		Json::FastWriter writer;  
		string temp = writer.write(root);
		g_Globle.SendTo(temp);
	}
	else
		QMessageBox::information(this, CH("提示"), CH("保存成功！"));
}

void CDayPayDlg::GetDPay(Json::Value root)
{
	m_fDaypay = root[CMD_STAFFMSG[EM_STAFF_MSG_DAYPAY]].asDouble();
	QString str = QString::number(m_fDaypay,'f',4);
	ui.edit_payday->setText(str);
}

void CDayPayDlg::GetBook(Json::Value root)
{
	m_vBooks.clear();
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
		m_vBooks.push_back(stu);
	}
}

void CDayPayDlg::GetProject(Json::Value root)
{
	m_vProjects.clear();
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
		if(m_vProjects.size() == 0)
			m_vProjects.push_back(stu);
		else
		{
			bool bInset=false;
			vector <PROJECT_STU>::iterator it;
			for ( it = m_vProjects.begin( ) ; it != m_vProjects.end( ) ; it++ )
			{
				if (stu.ndex<(*it).ndex)
				{
					bInset = true;
					m_vProjects.insert(it,stu);
					break;
				}
			}
			if(!bInset)
				m_vProjects.push_back(stu);
		}
	}
}

void CDayPayDlg::GetDayPay(Json::Value root)
{
	m_vCal.clear();
	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		Json:: Value js = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
		if (js.isArray())
		{
			int nCount = js.size();
			for (int i=0;i<nCount;i++)
			{
				DAYPAY stu;
				stu.id = js[i][DAYPAYMSG[EM_DAYPAY_MSG_ID]].asInt();
				stu.type = (DAYPAY_TYPE)js[i][DAYPAYMSG[EM_DAYPAY_MSG_TYPE]].asInt();
				if (stu.type == DAYPAY_TYPE_DEL)
				{
					const char*  str = js[i][DAYPAYMSG[EM_DAYPAY_MSG_DELMSG]].asCString();
					stu.strMsg = CH(str);
				}
				else if (stu.type == DAYPAY_TYPE_DAY)
				{
					stu.strPayDay = js[i][DAYPAYMSG[EM_DAYPAY_MSG_PAYDAY]].asCString();
					stu.strDays = js[i][DAYPAYMSG[EM_DAYPAY_MSG_DAYS]].asCString();
				}
				else if(stu.type == DAYPAY_TYPE_JIJIAN)
				{
					stu.proID = js[i][DAYPAYMSG[EM_DAYPAY_MSG_PROID]].asInt();
					stu.strBookID = js[i][DAYPAYMSG[EM_DAYPAY_MSG_BOOKID]].asCString();
					stu.pay = js[i][DAYPAYMSG[EM_DAYPAY_MSG_PAY]].asCString();
					stu.number = js[i][DAYPAYMSG[EM_DAYPAY_MSG_NUMBER]].asDouble();

					const char* str = js[i][DAYPAYMSG[EM_DAYPAY_MSG_PRONAME]].asCString();
					stu.strProName = CH(str);

					const char* str2 = js[i][DAYPAYMSG[EM_DAYPAY_MSG_BOOKNAME]].asCString();
					stu.strBookName = CH(str2);
				}		
				stu.money = js[i][DAYPAYMSG[EM_DAYPAY_MSG_MONEY]].asCString();		
				m_vCal.push_back(stu);
			}
		}
	}
	SetListCtrlValue();
}

void CDayPayDlg::GetOnePay(Json::Value root)
{
	int nItem = root[GETPAYMSG[EM_GET_PAY_NITEM]].asInt();
	QString strPay = root[GETPAYMSG[EM_GET_PAY_PAY]].asCString();
	ui.tableWidget->setItem(nItem,2,new QTableWidgetItem(strPay));
	
	//获取数量
	QLineEdit* number_edit = (QLineEdit*)ui.tableWidget->cellWidget(nItem,3);
	double fNumber = number_edit->text().toDouble();
	double fMoney = fNumber * strPay.toDouble();
	//设置金额
	QLineEdit* money_edit = (QLineEdit*)ui.tableWidget->cellWidget(nItem,4);
	QString str = QString::number(fMoney,'f',2);
	money_edit->setText(str);
}