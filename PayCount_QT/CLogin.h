#ifndef CLOGIN_H
#define CLOGIN_H

#include <QDialog>
#include "ui_CLogin.h"
#include "cgloble.h"

class CLogin : public CDlgFather
{
	Q_OBJECT

public:
	CLogin(QWidget *parent = 0);
	~CLogin();

private:
	Ui::CLogin ui;
	QPixmap m_pixmapBg;
	int     m_nx;//�϶����ڣ����հ���ʱ��x����
	int     m_ny;//�϶����ڣ����հ���ʱ��y����
	
	vector<USER_STU> m_vet;

private:
	//���ر���ͼƬ
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);
	//����ƶ��¼��������϶�����
	void mouseMoveEvent(QMouseEvent *);
	//����ͷ��¼��������ж��϶����
	void mouseReleaseEvent(QMouseEvent *);
	void GetUser(Json::Value root);
	void SendToLogin(QString strName,QString strPass,int show_pass);
	void GetLogin(Json::Value root);

//signals:
//	virtual void sg_CalBak(void* pdata);

public slots:
	void BtnSet();
	void BtnLogin();
	void BtnClose();
	void st_CalBak(void* pdata);
	void st_comboChanged(int index);
};

#endif // CLOGIN_H
