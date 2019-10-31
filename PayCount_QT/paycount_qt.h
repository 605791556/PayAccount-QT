#ifndef PAYCOUNT_QT_H
#define PAYCOUNT_QT_H

#include <QtWidgets/QMainWindow>
#include "ui_paycount_qt.h"
#include "cgloble.h"
#include "CTabMonthDlg.h"
#include "CTabWorkDayDlg.h"
#include "CTabDetailDlg.h"
#include "CTabProcessDlg.h"

enum EM_PAGE_TYPE
{
	EM_PAGE_JD,//����
	EM_PAGE_MX,//��ϸ
	EM_PAGE_ZGTJ,//����ͳ��
	EM_PAGE_YHS,//�º���
	EM_PAGE_MAX
};

class PayCount_QT : public QMainWindow
{
	Q_OBJECT

public:
	PayCount_QT(QWidget *parent = 0);
	~PayCount_QT();

private:
	Ui::PayCount_QTClass ui;
	QPixmap m_pixmapBg;
	int     m_nx;//�϶����ڣ����հ���ʱ��x����
	int     m_ny;//�϶����ڣ����հ���ʱ��y����
	bool    m_bmax;//true:��ǰ�������
	bool    m_bInitTab;

	CTabMonthDlg*   m_pTabMonthDlg;
	CTabWorkDayDlg* m_pTabWorkDlg;
	CTabDetailDlg*  m_pTabDetailDlg;
	CTabProcessDlg* m_pTabProcessDlg;

protected:
	//���ر���ͼƬ
	void paintEvent(QPaintEvent *);
	//�ؼ�λ���洰�ڴ�С�ı���ı�
	void resizeEvent(QResizeEvent *);
	//����ƶ��¼��������϶�����
	void mouseMoveEvent(QMouseEvent *);
	//����ͷ��¼��������ж��϶����
	void mouseReleaseEvent(QMouseEvent *);
	//˫���ı䴰�ڴ�С
	void mouseDoubleClickEvent(QMouseEvent *);
	void InitTabCtrl();

signals:
	void sg_CalBak(void* pdata);

public slots:
	void BtnMax();
	void ConnectState(NET_STATE state);
	void st_CalBak(void* pdata);
	void st_tabChanged(int index);
	void BtnInit();
	void BtnAccount();//�˺Ź���
	void BtnPwd();//�����޸�
	void BtnStaff();//Ա������
	void BtnBook();
	void BtnProject();
	void BtnPay();
	void BtnLog();
	void BtnLock();
	void BtnClose();
};

#endif // PAYCOUNT_QT_H
