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
	int     m_nx;//拖动窗口，鼠标刚按下时的x坐标
	int     m_ny;//拖动窗口，鼠标刚按下时的y坐标
	
	vector<USER_STU> m_vet;

private:
	//加载背景图片
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);
	//鼠标移动事件，用于拖动窗口
	void mouseMoveEvent(QMouseEvent *);
	//鼠标释放事件，用于判断拖动完成
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
