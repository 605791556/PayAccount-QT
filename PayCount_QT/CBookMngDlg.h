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
	//����ɾ��
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
	//�Ƚ�����ʱ���ַ������Ⱥ�˳��strDate1<strDate2,����ֵС��0,,��ȷ���0���������0
	int JudgeDateStringSize(QString strDate1,QString strDate2);
	void FindBook(int pageDex);

public:
	int m_nCount;//��������
	int m_dex;//��ǰҳ��
	int m_nPage;//��ҳ��
	QString m_strKeyWord;
	vector<BOOK_STU> m_vet;
	BOOK_RK m_rkType;
	EM_DATE_TYPE m_date_Type;
};

#endif // CBOOKMNGDLG_H
