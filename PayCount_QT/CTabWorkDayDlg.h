#ifndef CTABWORKDAYDLG_H
#define CTABWORKDAYDLG_H

#include <QWidget>
#include "ui_CTabWorkDayDlg.h"
#include "cgloble.h"

struct WORKMONEY
{
	QString strStaffID;
	QString strName;
	double  day_money;//按天工资
	double  jj_money;//计件工资
	double  del_money;//扣除工资

	WORKMONEY()
	{
		day_money = 0;
		jj_money = 0;
		del_money = 0;
	}
};

class CTabWorkDayDlg : public QWidget
{
	Q_OBJECT

public:
	CTabWorkDayDlg(QWidget *parent = 0);
	~CTabWorkDayDlg();

	Ui::CTabWorkDayDlg ui;
	QMovie* m_pMovie;

signals:
	void sg_CalBak(void* pdata);

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
	bool SendToGetOnePayList();
	void GetOnePayList(Json::Value root);
	void SetCtrlVisible(bool bLoadOk);

public:
	bool                m_bDateInit;
	vector<int>         m_vItem;//高亮选中行
	vector<STAFF_STU>   m_vet;
	vector<WORKMONEY>   m_vWorkCal;
	QStandardItemModel* m_pViewModel;
};

#endif // CTABWORKDAYDLG_H
