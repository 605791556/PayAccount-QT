#ifndef CPAYSETDLG_H
#define CPAYSETDLG_H

#include <QDialog>
#include "ui_CPaySetDlg.h"
#include "cgloble.h"

class CTabJdSetDlg;
class CTabZySetDlg;
class CTabDySetDlg;
class CTabOtherSetDlg;

enum EM_SPAGE_TYPE
{
	EM_SPAGE_TYPE_JD,//����
	EM_SPAGE_TYPE_ZY,//��ҳ
	EM_SPAGE_TYPE_DY,//��ҳ
	EM_SPAGE_TYPE_OTHER,//����
	EM_SPAGE_TYPE_MAX
};

class CPaySetDlg : public CDlgFather
{
	Q_OBJECT

public:
	CPaySetDlg(QWidget *parent = 0);
	~CPaySetDlg();

private:
	Ui::CPaySetDlg ui;
	QPixmap m_pixmapBg;
	bool    m_bInitTab;
	int     m_nx;//�϶����ڣ����հ���ʱ��x����
	int     m_ny;//�϶����ڣ����հ���ʱ��y����

	CTabJdSetDlg*    m_pTabJdDlg;
	CTabZySetDlg*    m_pTabZyDlg;
	CTabDySetDlg*    m_pTabDyDlg;
	CTabOtherSetDlg* m_pTabOtherDlg;

protected:
	//���ر���ͼƬ
	void paintEvent(QPaintEvent *);
	void InitTabCtrl();
	//����ƶ��¼��������϶�����
	void mouseMoveEvent(QMouseEvent *);
	//����ͷ��¼��������ж��϶����
	void mouseReleaseEvent(QMouseEvent *);

public slots:
	void st_tabChanged(int index);

public:
	
};

#endif // CPAYSETDLG_H
