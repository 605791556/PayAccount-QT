#ifndef CBOOKMNGDLG_H
#define CBOOKMNGDLG_H

#include <QDialog>
#include "ui_CBookMngDlg.h"
#include "cgloble.h"

#define LISTCOLUMN 17

class CBookMngDlg : public CDlgFather
{
	Q_OBJECT

public:
	CBookMngDlg(QWidget *parent = 0);
	~CBookMngDlg();

	Ui::CBookMngDlg ui;
	void resizeEvent(QResizeEvent *);


public slots:
	void st_CalBak(void* pdata);
	void st_BtnEdit();
	void st_BtnDel();
	void BtnFind();
	void BtnAdd();
	void BtnGo();
	void BtnLast();
	void BtnNext();
	void BtnRk();
	//批量删除
	void BtnPlDel();

public:
	void InitListCtrl();
	void SetListCtrlValue();
	void InitCombox();
	void SendToGetBook(QString strKeyWord,BOOK_RK rkType,EM_DATE_TYPE date_Type,int nStart,int nNum);
	void SendToDelBook(QString strBookID);
	void SendToPlDelBook(string strList);
	void SendToRk(string strList);
	void GetBook(Json::Value root);
	//比较两个时间字符串的先后顺序strDate1<strDate2,返回值小于0,,相等返回0，否则大于0
	int JudgeDateStringSize(QString strDate1,QString strDate2);
	void FindBook(int pageDex);

public:
	int m_nCount;//数据总数
	int m_dex;//当前页数
	int m_nPage;//总页数
	QString m_strKeyWord;
	vector<BOOK_STU> m_vet;
	BOOK_RK m_rkType;
	EM_DATE_TYPE m_date_Type;
};

#endif // CBOOKMNGDLG_H
