#ifndef CTABWORKDAYDLG_H
#define CTABWORKDAYDLG_H

#include <QWidget>
#include "cgloble.h"
#include "ui_CTabWorkDayDlg.h"

struct WORKMONEY
{
	QString strStaffID;
	QString strName;
	double  day_money;//按天工资
	double  jj_money;//计件工资
	double  del_money;//扣除工资
	double  bz_money;//补助工资

	WORKMONEY()
	{
		day_money = 0;
		jj_money = 0;
		del_money = 0;
		bz_money = 0;
	}
};

class CTabWorkDayDlg : public CDlgFather
{
	Q_OBJECT

public:
	CTabWorkDayDlg(QWidget *parent = 0);
	~CTabWorkDayDlg();

	Ui::CTabWorkDayDlg ui;

public slots:
	void st_CalBak(void* pdata);
	void st_KeyWordChanged(const QString &);
	void st_DateChanged(const QDate &date);
	void st_RowDoubleClicked(const QModelIndex &);
	void st_BtnUpdate();
public:
	void pageIn();
	void InitDateCtrl();
	void InitListCtrl();
	void SetListValue();
	void SendToGetStaff();
	void GetStaff(Json::Value root);
	void SendToGetOnePayList();
	void GetOnePayList(Json::Value root);

public:
	bool                m_bDateInit;
	vector<int>         m_vItem;//高亮选中行
	vector<STAFF_STU>   m_vet;
	vector<WORKMONEY>   m_vWorkCal;
	QStandardItemModel* m_pViewModel;
};

#endif // CTABWORKDAYDLG_H
