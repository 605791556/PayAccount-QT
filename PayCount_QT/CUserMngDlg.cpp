#include "CUserMngDlg.h"
#include "CAddUserDlg.h"

void CUserMngDlg::st_CalBak(void* pdata)
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
	case SOCK_CMD_GET_USER:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("获取账号信息失败！"));
			else
				GetUser(root);
		}
		break;
	case SOCK_CMD_DEL_USER:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("错误"), CH("删除失败！"));
			else
			{
				SendToFindUser();
				QMessageBox::information(this, CH("提示"), CH("删除成功！"));
			}
		}
		break;
	}
}

CUserMngDlg::CUserMngDlg(QWidget *parent)
	: CDlgFather(parent)
{
	ui.setupUi(this);
	connect(this,&CUserMngDlg::sg_CalBak,this,&CUserMngDlg::st_CalBak);
	connect(ui.BTN_ADD,SIGNAL(clicked()),this,SLOT(BtnAdd()));
	g_Globle.m_DlgMap[EM_DLG_MNGUSER] = this;
	InitListCtrl();
	SendToFindUser();
}

CUserMngDlg::~CUserMngDlg()
{

}

void CUserMngDlg::InitListCtrl()
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
	headers<<CH("序号")<<CH("账号")<<CH("类型")<<CH("创建时间")<<CH("操作");
	ui.tableWidget->setColumnCount(LISTCOLUMN); 
	ui.tableWidget->setHorizontalHeaderLabels(headers);

	ui.tableWidget->setColumnWidth(0,50);
	ui.tableWidget->setColumnWidth(4,75);
}

void CUserMngDlg::SendToFindUser()
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_MNGUSER;
	root[CONNECT_CMD]=SOCK_CMD_GET_USER;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CUserMngDlg::SendToDelUser(QString strName)
{
	Json::Value root;
	root[CMD_DLG]=EM_DLG_MNGUSER;
	root[CONNECT_CMD]=SOCK_CMD_DEL_USER;
	root[CMD_DELUSER[EM_DEL_USER_NAME]]=strName.toStdString();
	Json::FastWriter writer;  
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CUserMngDlg::GetUser(Json::Value root)
{
	m_vet.clear();
	Json:: Value js = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
	if (js.isArray())
	{
		int nCount = js.size();
		for (int i=0;i<nCount;i++)
		{
			USER_STU stu;
			stu.strname = js[i][CMD_GETUSER[EM_USER_NAME]].asCString();
			stu.type = js[i][CMD_GETUSER[EM_USER_TYPE]].asInt();
			stu.strTime = js[i][CMD_GETUSER[EM_USER_TIME]].asCString();
			stu.show_pass = js[i][CMD_GETUSER[EM_USER_SHOWPASS]].asInt();
			stu.strPass = js[i][CMD_GETUSER[EM_USER_PASS]].asCString();
			m_vet.push_back(stu);
		}
	}
	SetListCtrlValue();
}

void CUserMngDlg::SetListCtrlValue()
{
	ui.tableWidget->clearContents();
	QString str;
	int nCount = m_vet.size();
	ui.tableWidget->setRowCount(nCount);
	for (int i = 0; i < nCount; i++)
	{
		str = QString("%1").arg(i+1);
		ui.tableWidget->setItem(i,0,new QTableWidgetItem(str));
		ui.tableWidget->setItem(i,1,new QTableWidgetItem(m_vet[i].strname));
		int tmp = m_vet[i].type;
		ui.tableWidget->setItem(i,2,new QTableWidgetItem(TypeName[tmp]));
		ui.tableWidget->setItem(i,3,new QTableWidgetItem(m_vet[i].strTime));
		//删除
		QPushButton* delBtn = new QPushButton(this);
		CGloble::SetButtonStyle(delBtn,":/PayCount_QT/pic/yc2.png",3);
		delBtn->setProperty("button",i);
		delBtn->setToolTip(CH("删除"));
		connect(delBtn,&QPushButton::clicked,this,&CUserMngDlg::BtnDel);
		QWidget *widget = new QWidget(this);
		QHBoxLayout *hLayout = new QHBoxLayout(this);
		hLayout->addWidget( delBtn);
		hLayout->setMargin(0);
		hLayout->setAlignment(widget, Qt::AlignCenter);
		hLayout->setContentsMargins(10, 0, 20, 0);
		widget->setLayout(hLayout);
		ui.tableWidget->setCellWidget(i,4,widget);
	}
}

void CUserMngDlg::BtnAdd()
{
	CAddUserDlg dlg;
	int ret = dlg.exec();
	if(ret == QDialog::Accepted)
		SendToFindUser();
}

void CUserMngDlg::BtnDel()
{
	QObject *pObject = this->sender();
	QPushButton *btn = qobject_cast<QPushButton *>(pObject);
	int nRow = btn->property("button").toInt();
	if (nRow>=0)
	{
		QString strName = ui.tableWidget->item(nRow,1)->text();
		if (strName=="admin")
		{
			QMessageBox::information(this, CH("错误"), CH("超级管理员作为保留账号，不能将其删除！"));
			return;
		}

		QString str = QString(CH("确认删除账号%1?")).arg(strName);
		int nType = QMessageBox::question(this,CH("警告"),str,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
		switch(nType)
		{
		case QMessageBox::Ok:
			{
				SendToDelUser(strName);
			}
			break;
		}
	}
}
