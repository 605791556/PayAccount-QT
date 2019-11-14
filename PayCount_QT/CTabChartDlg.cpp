#include "CTabChartDlg.h"

void CTabChartDlg::st_CalBak(void* pdata)
{
	string* pStrData = (string*)pdata;
	Json::Reader r;
	Json::Value root;
	r.parse(*pStrData, root);
	delete pStrData;

	EM_SOCK_CMD cmd = (EM_SOCK_CMD)root[CONNECT_CMD].asInt();
	EM_CMD_RET ret = (EM_CMD_RET)root[CMD_RetType[EM_CMD_RETYPE_RESULT]].asInt();

	switch (cmd)
	{
	case SOCK_CMD_GET_CHART_YEAR:
	{
		GetYearChart(root);
		break;
	}
	case SOCK_CMD_GET_CHART_MONTH:
	{
		GetMonthChart(root);
		break;
	}
	}
}

CTabChartDlg::CTabChartDlg(QWidget *parent)
	: CDlgFather(parent)
{
	ui.setupUi(this);

	m_checkid = 0;
	m_bInitCombox = false;
	rdoGroup = new QButtonGroup(this);
	rdoGroup->addButton(ui.rdo_year, 0);
	rdoGroup->addButton(ui.rdo_month, 1);
	ui.cbx_year->setVisible(false);
	ui.label->setVisible(false);
	ui.rdo_year->setChecked(true);

	m_pYearChart = new QChart();
	m_pMonthChart = new QChart();
	m_pYearSeries = new QPieSeries();

	g_Globle.m_DlgMap[EM_DLG_TAB_CHART] = this;

	InitCbxValue();

	connect(this, &CTabChartDlg::sg_CalBak, this, &CTabChartDlg::st_CalBak);
	connect(ui.cbx_year, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(st_ComboxChanged(const QString &)));
	connect(ui.rdo_year, SIGNAL(clicked()), this, SLOT(st_rdoBtn()));
	connect(ui.rdo_month, SIGNAL(clicked()), this, SLOT(st_rdoBtn()));
}

CTabChartDlg::~CTabChartDlg()
{
	delete m_pYearChart;
	delete m_pMonthChart;
	delete m_pYearSeries;
}

void CTabChartDlg::pageIn()
{
	if (m_checkid == 0)
		SendToGetYearChart();
	else
		SendToGetMonthChart();
}

void CTabChartDlg::InitCbxValue()
{
	//初始化年份控件
	QDate tm = QDate::currentDate();
	int year = tm.year();
	for (int i = 0; i < 8; i++)
	{
		QString str = QString("%1").arg(year - (8 - i - 1));
		ui.cbx_year->insertItem(i, str);
		if (i == 7)
			ui.cbx_year->setCurrentIndex(i);
	}
	m_bInitCombox = true;
}

void CTabChartDlg::st_rdoBtn()
{
	m_checkid = rdoGroup->checkedId();
	switch (m_checkid)
	{
	case 0://年份表
	{
		ui.cbx_year->setVisible(false);
		ui.label->setVisible(false);
		SendToGetYearChart();
		break;
	}
	case 1://月份表
	{
		ui.cbx_year->setVisible(true);
		ui.label->setVisible(true);
		SendToGetMonthChart();
		break;
	}
	}
}

void CTabChartDlg::st_ComboxChanged(const QString &)
{
	if (m_bInitCombox)
	{
		SendToGetMonthChart();
	}
}

void CTabChartDlg::SendToGetYearChart()
{
	Json::Value root;
	root[CMD_DLG] = EM_DLG_TAB_CHART;
	root[CONNECT_CMD] = SOCK_CMD_GET_CHART_YEAR;
	Json::FastWriter writer;
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabChartDlg::SendToGetMonthChart()
{
	QString strYear = ui.cbx_year->currentText();
	Json::Value root;
	root[CMD_DLG] = EM_DLG_TAB_CHART;
	root[CONNECT_CMD] = SOCK_CMD_GET_CHART_MONTH;
	root[CHART_MONTH[EM_GET_CHART_MONTH_YEAR]] = strYear.toStdString();
	Json::FastWriter writer;
	string temp = writer.write(root);
	g_Globle.SendTo(temp);
}

void CTabChartDlg::GetYearChart(Json::Value root)
{
	m_vYear.clear();
	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		Json::Value js = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
		if (js.isArray())
		{
			int nCount = js.size();
			for (int i = 0; i < nCount; i++)
			{
				STU_Year stu;
				stu.strYear = js[i][CHART_YEAR[EM_GET_CHART_YEAR_YEAR]].asCString();
				stu.strYear = stu.strYear + CH("年");
				stu.fValue = js[i][CHART_YEAR[EM_GET_CHART_YEAR_VALUE]].asDouble();
				m_vYear.push_back(stu);
			}
		}
	}
	WriteYearChart();
}

void CTabChartDlg::GetMonthChart(Json::Value root)
{
	m_vMonth.clear();
	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		Json::Value js = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
		if (js.isArray())
		{
			int nCount = js.size();
			for (int i = 0; i < nCount; i++)
			{
				STU_Month stu;
				stu.strMonth = js[i][CHART_MONTH[EM_GET_CHART_MONTH_MONTH]].asCString();
				stu.strMonth = stu.strMonth + CH("月");
				stu.fValue = js[i][CHART_MONTH[EM_GET_CHART_MONTH_VALUE]].asDouble();
				m_vMonth.push_back(stu);
			}
		}
	}
	WriteMonthChart();
}

void CTabChartDlg::WriteYearChart()
{
	m_pYearChart->setTitle(CH("近五年支出统计表"));
	m_pYearChart->setAnimationOptions(QChart::AllAnimations);

	m_pYearSeries->clear();
	int nRows = m_vYear.size();
	for (int i = nRows - 1; i >= 0; i--)
	{
		STU_Year stu = m_vYear[i];
		*m_pYearSeries << new QPieSlice(stu.strYear, stu.fValue);
	}
	m_pYearSeries->setLabelsVisible();
	m_pYearSeries->setLabelsPosition(QT_CHARTS_NAMESPACE::QPieSlice::LabelOutside);
	m_pYearChart->addSeries(m_pYearSeries);

	ui.frame->setChart(m_pYearChart);
	m_pYearChart->setTheme(QChart::ChartThemeBlueCerulean);
	ui.frame->setRenderHint(QPainter::Antialiasing);
}

void CTabChartDlg::WriteMonthChart()
{
	QString strYear = ui.cbx_year->currentText();
	strYear += CH("年支出统计表");

	QBarSet* pMonthBarSet = new QBarSet(strYear,this);
	while (pMonthBarSet->count())
		pMonthBarSet->remove(0);

	QStringList categories;
	int nRows = m_vMonth.size();
	for (int i= 0; i<nRows; i++)
	{
		STU_Month stu = m_vMonth[i];
		categories << stu.strMonth;
		*pMonthBarSet << stu.fValue;
	}

	QBarSeries* pMonthSeries = new QBarSeries(this);
	pMonthSeries->append(pMonthBarSet);

	m_pMonthChart->removeAllSeries();
	m_pMonthChart->addSeries(pMonthSeries);
	
	m_pMonthChart->setTitle("");
	m_pMonthChart->setTheme(QChart::ChartThemeBlueCerulean);
	m_pMonthChart->setAnimationOptions(QChart::SeriesAnimations);


	QBarCategoryAxis *axis = new QBarCategoryAxis();
	axis->append(categories);
	m_pMonthChart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
	m_pMonthChart->setAxisX(axis, pMonthSeries);//设置坐标轴

	m_pMonthChart->legend()->setVisible(true); //设置图例为显示状态
	m_pMonthChart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部

	ui.frame->setChart(m_pMonthChart);
	ui.frame->setRenderHint(QPainter::Antialiasing);
}
