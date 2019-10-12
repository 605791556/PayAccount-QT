#include "CProMngDlg.h"
#include "CAddProDlg.h"

void ProMngCallback(void* p,string strData)
{
	CProMngDlg* pThis=(CProMngDlg*) p;

	if ( pThis==NULL)
		return;
	else
	{
		string* pStrData = new string;
		*pStrData = strData;
		emit pThis->sg_CalBak(pStrData);
	}
}

void CProMngDlg::st_CalBak(void* pdata)
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
				QMessageBox::information(this, CH("����"), CH("��ȡ��Ŀ��Ϣʧ�ܣ�"));
			else
			{
				GetProject(root);
			}
		}
		break;
	case SOCK_CMD_DEL_PROJECT:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("����"), CH("ɾ��ʧ�ܣ�"));
			else
			{
				SendToGetProject();
				QMessageBox::information(this, CH("��ʾ"), CH("ɾ���ɹ���"));
			}
		}
		break;
	case SOCK_CMD_SAVE_PRONDEX:
		{
			if (ret == NET_CMD_FAIL)
				QMessageBox::information(this, CH("����"), CH("��������˳��ʧ�ܣ�"));
			else
			{
				SendToGetProject();
				QMessageBox::information(this, CH("��ʾ"), CH("��������˳��ɹ���"));
			}
		}
		break;
	}
}

CProMngDlg::CProMngDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	CGloble::SetButtonStyle(ui.BTN_ADD,":/PayCount_QT/pic/ok.png",3);
	CGloble::SetButtonStyle(ui.BTN_SAVE_DEX,":/PayCount_QT/pic/login_btn.png",3);

	connect(this,&CProMngDlg::sg_CalBak,this,&CProMngDlg::st_CalBak);
	connect(ui.BTN_ADD,SIGNAL(clicked()),this,SLOT(BtnAdd()));
	connect(ui.BTN_SAVE_DEX,SIGNAL(clicked()),this,SLOT(BtnSaveDex()));
	g_Globle.SetCallback(ProMngCallback,this);
	InitListCtrl();
	SendToGetProject();
}

CProMngDlg::~CProMngDlg()
{

}

void CProMngDlg::InitListCtrl()
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
	headers<<CH("���")<<CH("��Ŀ")<<CH("������Χ")<<CH("��������")<<CH("����˳��")<<CH("����");
	ui.tableWidget->setColumnCount(LISTCOLUMN); 
	ui.tableWidget->setHorizontalHeaderLabels(headers);

	ui.tableWidget->setColumnWidth(5,75);
}

void CProMngDlg::SetListValue()
{
	QString str;
	ui.tableWidget->clearContents();
	int nCount = m_vet.size();
	ui.tableWidget->setRowCount(nCount);
	for (int i=0;i<nCount;i++)
	{
		//���
		str = QString("%1").arg(i+1);
		ui.tableWidget->setItem(i,0,new QTableWidgetItem(str));
		//��Ŀ
		ui.tableWidget->setItem(i,1,new QTableWidgetItem(m_vet[i].strName));
		//������Χ
		ui.tableWidget->setItem(i,2,new QTableWidgetItem(proNumType[m_vet[i].pn_type]));
		//��������
		ui.tableWidget->setItem(i,3,new QTableWidgetItem(proStaffType[m_vet[i].ps_type]));
		//����˳��
		str = QString("%1").arg(m_vet[i].ndex);
		QLineEdit* line = new QLineEdit(str,this);
		line->setValidator(g_Globle.itVtor);
		line->setFrame(false);
		line->setAlignment(Qt::AlignmentFlag::AlignHCenter);
		ui.tableWidget->setCellWidget(i,4,line);
		//�༭
		QPushButton* btn = new QPushButton(this);
		CGloble::SetButtonStyle(btn,":/PayCount_QT/pic/edit.png",3);
		btn->setProperty("button",i);
		btn->setToolTip(CH("�༭"));
		connect(btn,&QPushButton::clicked,this,&CProMngDlg::st_BtnEdit);

		QLabel* label = new QLabel("|",this);
		//ɾ��
		QPushButton* delBtn = new QPushButton(this);
		CGloble::SetButtonStyle(delBtn,":/PayCount_QT/pic/yc2.png",3);
		delBtn->setProperty("button",i);
		delBtn->setToolTip(CH("ɾ��"));
		connect(delBtn,&QPushButton::clicked,this,&CProMngDlg::st_BtnDel);

		QWidget *widget = new QWidget(this);
		QHBoxLayout *hLayout = new QHBoxLayout(this);
		hLayout->addWidget( btn);
		hLayout->addWidget( label);
		hLayout->addWidget( delBtn);
		hLayout->setMargin(0);
		hLayout->setAlignment(widget, Qt::AlignCenter);
		hLayout->setContentsMargins(10, 0, 20, 0);
		widget->setLayout(hLayout);
		ui.tableWidget->setCellWidget(i,5,widget);
	}
}

void CProMngDlg::resizeEvent(QResizeEvent *event)
{
	int w = ui.tableWidget->width();
	for (int i=0;i<LISTCOLUMN;i++)
	{
		if(i==0)
			ui.tableWidget->setColumnWidth(i,40);
		else if(i==5)
			ui.tableWidget->setColumnWidth(i,75);
		else
			ui.tableWidget->setColumnWidth(i,(w-75-40)/(LISTCOLUMN-2));
	}
}

void CProMngDlg::SendToGetProject()
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_GET_PROJECT;
	root[CMD_GETPRO[EM_GETPRO_BWRITE]]=PRO_STAFF_TYPE_MAX;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("��ʾ"), CH("������������ʧ�ܣ����������Ƿ�������"));
	}
}

void CProMngDlg::GetProject(Json::Value root)
{
	m_vet.clear();
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
		//��ndex��С��������
		if(m_vet.size() == 0)
			m_vet.push_back(stu);
		else
		{
			bool bInset=false;
			vector <PROJECT_STU>::iterator it;
			for ( it = m_vet.begin( ) ; it != m_vet.end( ) ; it++ )
			{
				if (stu.ndex<(*it).ndex)
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
	SetListValue();
}

void CProMngDlg::SendToDelProject(int nProID)
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_DEL_PROJECT;
	root[CMD_DELPROJECT[EM_DEL_PROJECT_ID]]=nProID;
	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("��ʾ"), CH("������������ʧ�ܣ����������Ƿ�������"));
	}
}

void CProMngDlg::SendToSaveProNdex()
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_SAVE_PRONDEX;

	int nSize = ui.tableWidget->rowCount();
	if (nSize>0)
	{
		for (int i = 0; i < nSize; i++)
		{
			Json::Value one;
			QLineEdit* number_edit = (QLineEdit*)ui.tableWidget->cellWidget(i,4);
			int ndex = number_edit->text().toInt();

			one[CMD_PROMSG[EM_PROMSG_ID]] = m_vet[i].nID;
			one[CMD_PROMSG[EM_PROMSG_NDEX]] = ndex;
			root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
		}

		Json::FastWriter writer;  
		string temp = writer.write(root);
		if(g_Globle.SendTo(temp) != 0)
		{
			QMessageBox::information(this, CH("��ʾ"), CH("������������ʧ�ܣ����������Ƿ�������"));
		}
	}
}

void CProMngDlg::st_BtnEdit()
{
	QObject *pObject = this->sender();
	QPushButton *btn = qobject_cast<QPushButton *>(pObject);
	int nRow = btn->property("button").toInt();
	CAddProDlg dlg(this,false,nRow);
	int ret = dlg.exec();
	g_Globle.SetCallback(ProMngCallback,this);
	if (ret == QDialog::Accepted)
	{
		SendToGetProject();
	}

}
void CProMngDlg::st_BtnDel()
{
	QObject *pObject = this->sender();
	QPushButton *btn = qobject_cast<QPushButton *>(pObject);
	int nRow = btn->property("button").toInt();
	int proID = m_vet[nRow].nID;
	QString strName = ui.tableWidget->item(nRow,1)->text();

	if (proID>=1 && proID<=8)
	{
		QMessageBox::information(this, CH("��ʾ"), CH("�����ֹɾ����"));
		return;
	}

	QString str = QString(CH("�ò�������ɾ�������Ŀ������صļ�¼�����������ȣ���ϸ�������ȣ���ȷ��ɾ����Ŀ '%1'��")).arg(strName);
	int nType = QMessageBox::warning(this,CH("����"),str,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
	switch(nType)
	{
	case QMessageBox::Ok:
		{
			SendToDelProject(proID);
		}
		break;
	}
}

void CProMngDlg::BtnSaveDex()
{
	Json::Value root;
	root[CONNECT_CMD]=SOCK_CMD_SAVE_PRONDEX;
	int nCount = ui.tableWidget->rowCount();
	if(nCount == 0)
	{
		QMessageBox::information(this, CH("��ʾ"), CH("�ޱ����"));
		return;
	}

	for (int i=0;i<nCount;i++)
	{
		int nProID = m_vet[i].nID;
		QLineEdit* edit = (QLineEdit*)ui.tableWidget->cellWidget(i,4);
		if (edit)
		{
			int ndex = edit->text().toInt();
			Json::Value one;
			one[CMD_PROMSG[EM_PROMSG_ID]] = nProID;
			one[CMD_PROMSG[EM_PROMSG_NDEX]] = ndex;
			root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
		}
	}

	Json::FastWriter writer;  
	string temp = writer.write(root);
	if(g_Globle.SendTo(temp) != 0)
	{
		QMessageBox::information(this, CH("����"), CH("������������ʧ�ܣ����������Ƿ�������"));
	}
}

void CProMngDlg::BtnAdd()
{
	CAddProDlg dlg;
	int ret  = dlg.exec();
	g_Globle.SetCallback(ProMngCallback,this);
	if (ret == QDialog::Accepted)
	{
		SendToGetProject();
	}
}
