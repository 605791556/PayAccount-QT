#ifndef CGLOBLE_H
#define CGLOBLE_H

#define NOMINMAX

#include "HPSocket.h"
#include "DlgFather.h"
#include <qt_windows.h>
#include <QObject>
#include <qpushbutton.h>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QMessageBox>
#include <QSettings>
#include <QApplication>
#include <QFileInfo>
#include <QTextCodec>
#include <QPainter>
#include <QMouseEvent>
#include <QMovie>
#include <QtConcurrent/QtConcurrent>
#include <QMetaType>
#include <QStandardItemModel>
#include <QComboBox>
#include <QScrollBar>
#include <QHBoxLayout>
#include "common.h"
#include <json/json.h>
#include <json/config.h>
#include <vector>
#include "GeneralHelper.h"
#include "helper.h"
#include <map>

#ifdef _DEBUG
#pragma comment(lib,"json_vc71_libmtd.lib")
#else
#pragma comment(lib,"json_vc71_libmt.lib")
#endif


#define CH(x) QString::fromLocal8Bit(x)

enum NET_STATE
{
	NET_STATE_OK,//��������
	NET_STATE_CLOSE,//����Ͽ�
	NET_STATE_MAX
};
Q_DECLARE_METATYPE(NET_STATE);

enum USER_TYPE
{
	TYPE_COMMON,//��ͨ�û�
	TYPE_MNG,//����Ա
	TYPE_SUPER,//��������Ա
	TYPE_MAX
};
extern QString TypeName[];

//���Ʊ༭�������ַ�����
enum EDIT_TYPE
{
	EDIT_TYPE_NUMBER,//ֻ��������
	EDIT_TYPE_NUMBER_X,//ֻ�������ֺ�X�����������֤������
	EDIT_TYPE_FLOAT,//������
	EDIT_TYPE_NO_CHN,//��������
	EDIT_TYPE_ALL//������
};

enum PROJECT_TYPE
{
	PROJECT_TYPE_JIAODING=1,//����
	PROJECT_TYPE_DY,//��ҳ
	PROJECT_TYPE_ZY,//��ҳ
	PROJECT_TYPE_OTHER,//����
	PROJECT_TYPE_MAX
};

enum EM_DATE_TYPE
{
	EM_DATE_TYPE_ALL,
	EM_DATE_TYPE_1WEEK,
	EM_DATE_TYPE_1MONTH,
	EM_DATE_TYPE_3MONTH,
	EM_DATE_TYPE_6MONTH,
	EM_DATE_TYPE_12MONTH,
	EM_DATE_TYPE_MAX
};
extern QString DateName[];

//��Ŀ����������Χ����
enum PRO_NUM_TYPE
{
	PRO_NUM_TYPE_YS,//ӡ��
	PRO_NUM_TYPE_LS,//����
	PRO_NUM_TYPE_MAX
};
extern QString proNumType[PRO_NUM_TYPE_MAX];

//��Ŀ�����Ƿ���Ҫ��������
enum PRO_STAFF_TYPE
{
	PRO_STAFF_TYPE_YES,//��
	PRO_STAFF_TYPE_NO,//��
	PRO_STAFF_TYPE_MAX
};
extern QString proStaffType[PRO_STAFF_TYPE_MAX];

//ע����dai_number_pay��id������ö����������һ��
enum DAINUMPAY_TYPE
{
	DAINUMPAY_TYPE_W=1,//�������
	DAINUMPAY_TYPE_2,//2000һ��
	DAINUMPAY_TYPE_2_5,//2001~5000
	DAINUMPAY_TYPE_5_9,//5001~9999
	DAINUMPAY_TYPE_10,//10000����
	DAINUMPAY_TYPE_18,//18��10ӡ��
	DAINUMPAY_TYPE_MAX
};

//ע����zheye_number_pay��id������ö����������һ��
enum ZHEYEPAY_TYPE
{
	ZHEYEPAY_TYPE_Q4 = 1,//ȫ������ҳ
	ZHEYEPAY_TYPE_4,//����ҳ
	ZHEYEPAY_TYPE_D3,//������ҳ
	ZHEYEPAY_TYPE_3,//����ҳ
	ZHEYEPAY_TYPE_2,//����ҳ
	ZHEYEPAY_TYPE_MAX
};
extern QString ZyType[];

enum BOOK_RK
{
	BOOK_RK_NO,//δ���
	BOOK_RK_YES,//�����
	BOOK_RK_MAX
};
extern QString rkType[];

enum BOOK_TYPE
{
	BOOK_TYPE_QUAN,//ȫ��
	BOOK_TYPE_DUI,//�Կ�
	BOOK_TYPE_MAX
};
extern QString BookType[];

enum STAFF_TYPE
{
	STAFF_TYPE_PT,//��ͨ����
	STAFF_TYPE_SF,//ʦ��
	STAFF_TYPE_PT_SF,//ʦ��+����
	STAFF_TYPE_MAX
};
extern QString StaffType[];

enum DAYPAY_TYPE
{
	DAYPAY_TYPE_DAY,//����
	DAYPAY_TYPE_JIJIAN,//�Ƽ�
	DAYPAY_TYPE_DEL,//�۳�
	DAYPAY_TYPE_MAX
};



//��ϸ
struct STU_DETAIL
{
	QString strName;
	QString stridCard;
	int number;
};

struct WOCKCAL
{
	int proID;//��ĿID
	QString strProName;
	QString strBookID;//ͼ��ID
	QString strBookName;
	int number;//����
	QString strTime;
};

struct DAYPAY
{
	int id;
	DAYPAY_TYPE type;//���㷽ʽ
	int     proID;//��ĿID
	QString strProName;
	QString strBookID;//ͼ��ID
	QString strBookName;
	QString pay;//����
	double number;//����
	QString money;

	QString strMsg;

	QString strPayDay;
	QString strDays;

	DAYPAY()
	{
		type = DAYPAY_TYPE_MAX;
		number = 0;
	}
};

struct STAFF_STU
{
public:
	CString  str2;
	QString strname;
	QString strSex;
	int     age;
	QString strStaffID;
	QString strIdCard;
	QString strInTime;
	QString strTel;
	STAFF_TYPE type;
	double  fDaypay;//��ְ���չ�����
	int sort;
	int nFirstAscii;//ƴ������ĸasciiֵ����������
};

//���ڱ���ͻ�ȡ������Ŀ����
struct OTHER_PRO_PAY
{
	QString strBookID;
	QString strPay;
};

struct MONTHPAY_DAY
{
	QString strDate;
	int ndex;
	double d_money;

	MONTHPAY_DAY()
	{
		d_money = 0;
	}
};

struct MONTH_PAY_STAFF
{
	QString strStaffID;
	QString strStaffName;
	list<MONTHPAY_DAY> vDays;
	double m_money;

	MONTH_PAY_STAFF()
	{
		m_money = 0;
	}

	void resetValue()
	{
		vDays.clear();
		m_money = 0;
	}
};

struct BOOK_STU
{
	QString strBookID;
	QString strname;
	QString strCbs;
	QString strDate;
	int nBc1,nBc2;
	int nSize1,nSize2;
	int nKb;
	double fYz;
	int nYs;
	int nBc;
	double fLs;
	QString strPay;
	BOOK_TYPE type;
	ZHEYEPAY_TYPE  zyType;
	BOOK_RK rkType;
	QString strMsg;
	BOOK_STU()
	{
		type = BOOK_TYPE_MAX;
		zyType = ZHEYEPAY_TYPE_MAX;
		rkType = BOOK_RK_MAX;
	}
};

struct USER_STU
{
public:
	QString strname;
	QString strPass;
	int type;
	int show_pass;//1:��ס���� 0������
	QString strTime;
};
Q_DECLARE_METATYPE(USER_STU);

struct PROJECT_STU
{
public:
	int nID;
	int ndex;//��ʾ��ţ���1��ʼ
	QString strName;
	PRO_NUM_TYPE pn_type;
	PRO_STAFF_TYPE ps_type;
	int nAllBook;//�����Ƿ�����ȫ��
	QString strPay;

	PROJECT_STU()
	{
		ndex = 0;
		nAllBook = 0;
		pn_type = PRO_NUM_TYPE_MAX;
		ps_type = PRO_STAFF_TYPE_MAX;
	}
};
Q_DECLARE_METATYPE(PROJECT_STU);

struct STU_DAI_PAY
{
	QString strA_w;
	QString strA_2;
	QString strA_2_5;
	QString strA_5_9;
	QString strA_10;
	QString strA_18;
	QString strSf_w;
	QString strSf_2;
	QString strSf_2_5;
	QString strSf_5_9;
	QString strSf_10;
	QString strSf_18;
	QString strTd_w;
	QString strTd_2;
	QString strTd_2_5;
	QString strTd_5_9;
	QString strTd_10;
	QString strTd_18;
};

struct STU_ZHEYE_PAY
{
	QString strAQ4;
	QString strA4;
	QString strAD3;
	QString strA3;
	QString strA2;

	QString str_sf_Q4;
	QString str_sf_4;
	QString str_sf_D3;
	QString str_sf_3;
	QString str_sf_2;

	QString str_td_Q4;
	QString str_td_4;
	QString str_td_D3;
	QString str_td_3;
	QString str_td_2;

};


void Log(char* fmt, ...);
typedef void (*FUN_CALLBACK)(void* p,string strData);
class CGloble : public QObject ,public CTcpPullClientListener
{
	Q_OBJECT

public:
	CGloble(QObject *parent = 0);
	~CGloble();

private:
	virtual EnHandleResult OnConnect(ITcpClient* pSender, CONNID dwConnID);
	virtual EnHandleResult OnSend(ITcpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength);
	virtual EnHandleResult OnReceive(ITcpClient* pSender, CONNID dwConnID, int iLength);
	virtual EnHandleResult OnClose(ITcpClient* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode);

public:
	//��ʼ��
	bool InitGloble();
	//��ťͼƬ��Ƭ
	static void SetButtonStyle(QPushButton *button, QString imgsrc, int CutSec);
	//���ÿؼ�ֻ����������
	static void SetEditOnlyNumber(QLineEdit* lineEdit, QObject* ts);
	//д�������ļ�
	void SetIniValue(QString qstrnodename,QString qstrkeyname,QVariant qvarvalue);
	QVariant GetIniValue(QString qstrnodename,QString qstrkeyname);
	bool ConnectSer();
	void SetCallback(FUN_CALLBACK callback,void* param);
	int SendTo(string strData);
	string GetLogFileName();
	string GetAppDataPath();
	void DoRun(string strData);
	int GetDays(int year,int month);
public:
	map<EM_DLG,CDlgFather*> m_DlgMap;

	QString    m_strIP;
	int        m_nPort;
	QString    m_strName;
	QString    m_strTitle;
	QString    m_strVersion;
	QString    m_strIniFilePath;
	QSettings *m_psetting;
	QString    m_strUserName;
	QString    m_strUserPwd;
	int        m_nType;

	string     m_LogRootPath;
	string     m_LogPath;

	BOOL       m_bAsyncConn;
	TPkgInfo   m_pkgInfo;
	CTcpPullClientPtr m_Client;
	HANDLE            m_heart;
	HANDLE            m_hExit;
	NET_STATE         m_state;//����������״̬
	FUN_CALLBACK      m_pCallBack;
	void*             m_pHand;
	QDoubleValidator* dbVtor; //������
	QIntValidator*    itVtor; //����
	QValidator*       nzVtor;//����+��ĸ
signals:
	void sgl_ConnectState(NET_STATE);
};
extern CGloble g_Globle;
#endif // CGLOBLE_H
