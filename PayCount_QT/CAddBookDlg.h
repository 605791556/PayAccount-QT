#ifndef CADDBOOKDLG_H
#define CADDBOOKDLG_H

#include <QDialog>
#include "ui_CAddBookDlg.h"
#include "cgloble.h"

class CAddBookDlg : public CDlgFather
{
	Q_OBJECT

public:
	CAddBookDlg(QWidget* stfMng=0,bool bAdd=true,int row = -1,QWidget *parent = 0);
	~CAddBookDlg();

private:
	Ui::CAddBookDlg ui;

public:
	bool m_bAdd;
	int  m_row;//��Ϊ�޸�ʱ������������
	QString m_strBookID;
	BOOK_STU m_bookstu;

//signals:
//	void sg_CalBak(void* pdata);
public slots:
	void st_CalBak(void* pdata);
	void st_BtnSave();

public:
	void InitDlg(QWidget* stfMng,bool bAdd);
	void SendToJudgeBook(QString strName);
	void SendToAddOrMdfBook(EM_SOCK_CMD type=SOCK_CMD_ADD_BOOK);
};

#endif // CADDBOOKDLG_H
