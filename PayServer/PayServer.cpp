
// PayServer.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "PayServer.h"
#include "PayServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPayServerApp

BEGIN_MESSAGE_MAP(CPayServerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CPayServerApp ����

CPayServerApp::CPayServerApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴����ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CPayServerApp ����

CPayServerApp theApp;


// CPayServerApp ��ʼ��

BOOL CPayServerApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("���ƹ���ϵͳ"));

	HANDLE hMutex=::CreateMutex(NULL,TRUE,"PayServer-HP2");//����������FirstName������ƿ�������ȡ���ڶ�������ҪΪTRUE��ʾ��ǰʵ��ռ�ô˻������
	if (hMutex!=NULL)
	{
		if (GetLastError()==ERROR_ALREADY_EXISTS)
		{
			CloseHandle(hMutex);
			hMutex = NULL;
			MessageBox(NULL,"�Ѿ���һ������������,��Ҫ�������У����ȹرշ���","��ʾ",MB_OK);
			return 0;
		}
	}

	CString strDbFilePath;
	m_dbData = new CDbData();
	int nRet = m_dbData->InitSqlite3(strDbFilePath);
	if(nRet == -1)
	{
		CString str;
		str.Format("db file: %s not exist !",strDbFilePath);
		MessageBox(NULL,str, "error",NULL);
		return FALSE;
	}
	else if(nRet == -2)
	{
		MessageBox(NULL, "InitSqlite3 error!", "error",NULL);
		return FALSE;
	}

	CPayServerDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô�����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô�����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
