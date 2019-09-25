#include "CStaffMngDlg.h"
#include "CAddStaffDlg.h"

void StaffMngCallback(void* p,string strData)
{
	CStaffMngDlg* pThis=(CStaffMngDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

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
				QMessageBox::information(this, CH("����"), CH("��ȡְ����Ϣʧ�ܣ�"));
			else
			{
				GetStaff(root);
			}
		}
		break;
	case SOCK_CMD_DEL_STAFF:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("����"), CH("ɾ��ʧ�ܣ�"));
			else
			{
				BtnFind();
				QMessageBox::information(this, CH("��ʾ"), CH("ɾ���ɹ���"));
			}
		}
		break;
	}
}

CStaffMngDlg::CStaffMngDlg(QWidget *parent)
	: QDialog(parent)
{
	m_nPage=1;
	m_dex=1;

	ui.setupUi(this);
	setWindowFlags(windowFlags() &~ (Qt::WindowMinMaxButtonsHint));
	CGloble::SetButtonStyle(ui.BTN_FIND,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_ADD,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_LAST,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_NEXT,":/PayCount_QT/pic/ok.png",3);

	connect(this,&CStaffMngDlg::sg_CalBak,this,&CStaffMngDlg::st_CalBak);
	connect(ui.BTN_FIND,SIGNAL(clicked()),this,SLOT(BtnFind()));
	connect(ui.BTN_ADD,SIGNAL(clicked()),this,SLOT(BtnAdd()));
	connect(ui.BTN_GO,SIGNAL(clicked()),this,SLOT(BtnGo()));
	connect(ui.BTN_LAST,SIGNAL(clicked()),this,SLOT(BtnLast()));
	connect(ui.BTN_NEXT,SIGNAL(clicked()),this,SLOT(BtnNext()));

	g_Globle.SetCallback(StaffMngCallback,this);
	InitListCtrl();
	SendToGetStaff("",(m_dex-1)*20,20);
}

CStaffMngDlg::~CStaffMngDlg()
{
	
}

void CStaffMngDlg::InitListCtrl()
{
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//��ֹ�༭
	ui.tableWidget->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget->setFocusPolicy(Qt::NoFocus); //ȥ��ѡ�����߿�
	ui.tableWidget->setFrameShape(QFrame::NoFrame); //���ñ߿�
	ui.tableWidget->setMouseTracking(true);
	//ui.tableWidget->horizontalHeader()->setStretchLastSection(true); //���ó�������
	ui.tableWidget->verticalHeader()->setVisible(false); //���ô�ֱͷ���ɼ�
	ui.tableWidget->setStyleSheet("selection-background-color:lightblue;"); //����ѡ�б���ɫ


	//����ˮƽ����ֱ��������ʽ
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
	headers<<CH("���")<<CH("����")<<CH("�Ա�")<<CH("����")<<CH("��ְʱ��")<<CH("��ϵ��ʽ")<<CH("����")<<CH("��н")<<CH("����");
	ui.tableWidget->setColumnCount(LISTCOLUMN); 
	ui.tableWidget->setHorizontalHeaderLabels(headers);

	ui.tableWidget->setColumnWidth(8,75);
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
		//���
		str = QString("%1").arg(n+(m_dex-1)*20);
		ui.tableWidget->setItem(i,0,new QTableWidgetItem(str));
		//����
		ui.tableWidget->setItem(i,1,new QTableWidgetItem(m_vet[i].strname));
		//��ID
	    QVariant vt;
		vt.setValue<QString>(m_vet[i].strStaffID);
		ui.tableWidget->item(i,1)->setData(1,vt);
		//�Ա�
		ui.tableWidget->setItem(i,2,new QTableWidgetItem(m_vet[i].strSex));
		//����
		str = QString("%1").arg(m_vet[i].age);
		ui.tableWidget->setItem(i,3,new QTableWidgetItem(str));
		//��ְʱ��
		ui.tableWidget->setItem(i,4,new QTableWidgetItem(m_vet[i].strInTime));
		//��ϵ��ʽ
		ui.tableWidget->setItem(i,5,new QTableWidgetItem(m_vet[i].strTel));
		//����
		ui.tableWidget->setItem(i,6,new QTableWidgetItem(StaffType[m_vet[i].type]));
		//��н
		str = QString::number(m_vet[i].fDaypay,'f',2);
		ui.tableWidget->setItem(i,7,new QTableWidgetItem(str));
		//�༭
		QPushButton* btn = new QPushButton(this);
		CGloble::SetButtonStyle(btn,":/PayCount_QT/pic/edit.png",3);
		btn->setProperty("button",i);
		btn->setToolTip(CH("�༭"));
		connect(btn,&QPushButton::clicked,this,&CStaffMngDlg::st_BtnEdit);

		QLabel* label = new QLabel("|",this);
		//ɾ��
		QPushButton* delBtn = new QPushButton(this);
		CGloble::SetButtonStyle(delBtn,":/PayCount_QT/pic/yc2.png",3);
		delBtn->setProperty("button",i);
		delBtn->setToolTip(CH("ɾ��"));
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
		ui.tableWidget->setCellWidget(i,8,widget);
		n++;
	}

	str = QString(CH("��%1����¼")).arg(nCount);
	ui.label_number->setText(str);
	int ns = m_nCount%20;
	m_nPage = m_nCount/20;
	if(ns>0)
		m_nPage+=1;
	if (m_nPage==0)
		m_nPage=1;
	str = QString(CH("��%1ҳ  ��%2ҳ")).arg(m_nPage).arg(m_dex);
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
		if(i==0|| i==2 || i==3)
			ui.tableWidget->setColumnWidth(i,40);
		else if(i==6)
			ui.tableWidget->setColumnWidth(i,75);
		else if(i==8)
			ui.tableWidget->setColumnWidth(i,75);
		else
			ui.tableWidget->setColumnWidth(i,(w-75*2-40*3)/(LISTCOLUMN-5));
	}
}

void CStaffMngDlg::SendToGetStaff(QString strKeyWord,int nStart,int nNum)
{
	USES_CONVERSION;
	Json::Value root;
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
	USES_CONVERSION;
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_DEL_STAFF;
	root[CMD_DELSTAFF[EM_DEL_STAFF_ID]]=strStaffID.toStdString();
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
	
}
void CStaffMngDlg::st_BtnDel()
{
	QObject *pObject = this->sender();
	QPushButton *btn = qobject_cast<QPushButton *>(pObject);
	int nRow = btn->property("button").toInt();
	QString strStaffID = ui.tableWidget->item(nRow,1)->data(1).toString();
	QString strStaffName = ui.tableWidget->item(nRow,1)->text();

	QString str = QString(CH("ɾ��ְ������ɾ����ְ����ص����й�����¼��ȷ��ɾ�� %1��")).arg(strStaffName);
	int nType = QMessageBox::warning(this,CH("����"),str,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
	switch(nType)
	{
	case QMessageBox::Ok:
		{
			SendToDelStaff(strStaffID);
		}
		break;
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
	dlg.exec();
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
