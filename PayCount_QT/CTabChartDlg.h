#pragma once

#include <QWidget>
#include "cgloble.h"
#include "ui_CTabChartDlg.h"

struct STU_Year
{
	QString strYear;
	double  fValue;
};

struct STU_Month
{
	QString strMonth;
	double  fValue;
};

class CTabChartDlg : public CDlgFather
{
	Q_OBJECT

public:
	CTabChartDlg(QWidget *parent = 0);
	~CTabChartDlg();

private:
	Ui::CTabChartDlg ui;

	public slots:
	void st_CalBak(void* pdata);
	void st_rdoBtn();
	void st_ComboxChanged(const QString &);

public:
	int  m_checkid;
	bool m_bInitCombox;
	QButtonGroup *rdoGroup;
	vector<STU_Year> m_vYear;
	vector<STU_Month> m_vMonth;

	QChart*     m_pYearChart;
	QPieSeries* m_pYearSeries;
	QChart*     m_pMonthChart;

public:
	void pageIn();
	void InitCbxValue();
	void SendToGetYearChart();
	void SendToGetMonthChart();
	void GetYearChart(Json::Value root);
	void WriteYearChart();
	void GetMonthChart(Json::Value root);
	void WriteMonthChart();
};
