#ifndef CTABWORKDAYDLG_H
#define CTABWORKDAYDLG_H

#include <QWidget>
#include "cgloble.h"
#include "ui_CTabWorkDayDlg.h"

struct WORKMONEY
{
	QString strStaffID;
	QString strName;
	double  day_money;//���칤��
	double  jj_money;//�Ƽ�����
	double  del_money;//�۳�����
	double  bz_money;//��������

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
	vector<int>         m_vItem;//����ѡ����
	vector<STAFF_STU>   m_vet;
	vector<WORKMONEY>   m_vWorkCal;
	QStandardItemModel* m_pViewModel;
};

#endif // CTABWORKDAYDLG_H
