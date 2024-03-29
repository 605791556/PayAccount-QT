#include "stdafx.h"
#include "dbData.h"
#include <ctime>
#include <io.h>
#include  <stdio.h>
#include  <stdlib.h>
#include "..\common\common.h"
#include "..\common\globle.h"

#pragma comment(lib,"sqlite3.lib")

CDbData::CDbData()
{
	m_sqlite=NULL;
	m_strSql="";
	m_hOnePay = CreateMutex(NULL, FALSE, NULL);
	m_hBook = CreateMutex(NULL, FALSE, NULL);
	m_hStaff = CreateMutex(NULL, FALSE, NULL);
}

CDbData::~CDbData()
{
	if (m_sqlite)
	{
		delete m_sqlite;
	}
	CloseHandle(m_hOnePay);
	CloseHandle(m_hBook);
	CloseHandle(m_hStaff);
}

CString CDbData::GetTimeNow()
{
	CString str;
	CTime tm=CTime::GetCurrentTime();
	str.Format("%d/%02d/%02d", tm.GetYear(), tm.GetMonth(), tm.GetDay());
	return str;
}

int CDbData::InitSqlite3(CString& strdbFilePath)
{
	USES_CONVERSION;
	TCHAR szModule[MAX_PATH];
	GetModuleFileName(NULL, szModule, MAX_PATH);//得到本程序自身的全路径
	CString strModule = szModule;
	int nFind = strModule.ReverseFind('\\');
	CString strWorkDir = strModule.Mid(0,nFind);
	//CString strWorkPath = g_Globle.GetWorkDir();
	CString strdbPathName = strWorkDir+"/db/bkmng.db";
	strdbFilePath = strdbPathName;
	int iRtn = _access(strdbPathName, 0);
	if (iRtn == -1)
	{
		return iRtn;
	}
	if(sqlite3_open(g_Globle.EncodeToUTF8(strdbPathName),&m_sqlite) != SQLITE_OK)
	{
		return -2;
	}
	return 0;
}

bool CDbData::_JudgeStaff(CString strStaffName, Json::Value& root)
{
	USES_CONVERSION;
	bool ret = false;
	bool bExit = false;
	try
	{
		m_sql.Format("SELECT name FROM staff WHERE staff.name='%s' AND del='0'", g_Globle.EncodeToUTF8(strStaffName));
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret=true;
			// 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				bExit=true;
				break;
			}
			root[CMD_JUDGESTAFF[EM_JUDGE_STAFF_BHAD]]=bExit;
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret=false;
	}
	return ret;
}

bool CDbData::AddStaff(CString strName,CString strSex,CString strStaffID,CString idcard,CString strTel,int type,int sort,double fDaypay)
{
	WaitForSingleObject(m_hStaff, INFINITE); 
	USES_CONVERSION;
	bool ret=false;
	try
	{
		CString strTime = GetTimeNow();
		m_sql.Format("INSERT INTO staff(name,sex,idcard,intime,tell,type,sort,staffID,day_pay) VALUES('%s','%s','%s','%s','%s','%d','%d','%s','%.04f');",
			g_Globle.EncodeToUTF8(strName),
			g_Globle.EncodeToUTF8(strSex),
			idcard, strTime, strTel,type,sort, strStaffID,
			fDaypay);

		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret=true;
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret=false;
	}
	ReleaseMutex(m_hStaff);
	return ret;
}

bool CDbData::AddUser(CString strName, CString strPass, int nType)
{
	USES_CONVERSION;
	bool ret = false;
	try
	{
		CString strTime = GetTimeNow();
		m_sql.Format("INSERT INTO user(name,pass,type,time,show_pass) VALUES('%s','%s','%d','%s','%d');",
			strName, strPass, nType, strTime,0);

		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::_JudgePro(CString strName, Json::Value& root)
{
	bool ret = false;
	bool bExit = false;
	USES_CONVERSION;
	try
	{
		m_sql.Format("SELECT name FROM project WHERE name='%s' AND del='0'", g_Globle.EncodeToUTF8(strName));
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret = true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				bExit = true;
				break;
			}
		}
		sqlite3_finalize(stmt);
		root[CMD_JUDGEPROJECT[EM_JUDGE_PROJECT_BHAD]] = bExit;
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::AddProject(CString strProName,PRO_NUM_TYPE pn_type,PRO_STAFF_TYPE ps_type)
{
	USES_CONVERSION;
	bool ret = false;
	try
	{
		m_sql.Format("INSERT INTO project(name,pro_num_type,staff_write,ndex) VALUES('%s','%d','%d','%d');",
			g_Globle.EncodeToUTF8(strProName),
			pn_type,
			ps_type,
			0);

		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::SaveProNdex(Json::Value root)
{
	m_sql = "";
	USES_CONVERSION;
	bool ret=false;
	try
	{
		char *errmsg;
		int result = 0;
		if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
		{
			Json::Value js = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
			if (js.isArray())
			{
				int nSize = js.size();
				if (nSize>0)
				{
					for (int i=0;i<nSize;i++)
					{
						CString sql_one;
						int nProID = js[i][CMD_PROMSG[EM_PROMSG_ID]].asInt();
						int ndex = js[i][CMD_PROMSG[EM_PROMSG_NDEX]].asInt();
						sql_one.Format("UPDATE project SET ndex = '%d' WHERE id='%d';", ndex,nProID);
						m_sql += sql_one;
					}
					sqlite3_exec( m_sqlite, "begin transaction", 0, 0, &errmsg ); //开始一个事务
					if(SQLITE_OK==sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg))
					{
						if(SQLITE_OK==sqlite3_exec( m_sqlite, "commit transaction", 0, 0, &errmsg ))
							ret = true;
					}
					if (!ret)
					{
						// 如果操作错误,回滚
						sqlite3_exec( m_sqlite , "rollback transaction" , 0 , 0 ,NULL);
					}
				}	
			}
		}
	}
	catch (...)
	{
		ret =false;
	}
	return ret;
}

bool CDbData::DelOneProject(int id)
{
	USES_CONVERSION;
	bool ret=false;
	try
	{
		char *errmsg;
		int result = 0;

		m_sql.Format("UPDATE project SET del='1' WHERE project.id='%d';", id);
		result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
		{
			ret = true;
		}
	}
	catch (CException* e)
	{
		ret=false;
	}
	return ret;
}

bool CDbData::DelOtherPay(CString strIDs)
{
	m_sql = "";
	bool ret = false;
	USES_CONVERSION;
	try
	{
		char *errmsg;
		int result = 0;

		int nFind =strIDs.Find(';');
		while (nFind>0)
		{
			CString strID = strIDs.Mid(0,nFind);
			CString sql_one;
			sql_one.Format("DELETE FROM other_number_pay WHERE proID='%d';", _ttoi(strID));
			m_sql += sql_one;
			strIDs = strIDs.Mid(nFind+1);
			nFind = strIDs.Find(';');
		}

		result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
		{
			ret = true;
		}

	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::DelProgressByBookID(CString strBookID)
{
	bool ret = false;
	USES_CONVERSION;
	try
	{
		m_sql.Format("DELETE FROM progress WHERE bookID='%s'", strBookID);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);

	}
	catch (CException* e)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::DelProgressByProID(int proID)
{
	bool ret = false;
	USES_CONVERSION;
	try
	{
		m_sql.Format("DELETE FROM progress WHERE proID='%d'",proID);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);

	}
	catch (CException* e)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::SetLastLoginName(CString strName)
{
	USES_CONVERSION;
	bool ret = false;
	
	try
	{
		m_sql.Format("UPDATE common SET LastLoginName='%s' WHERE common.id='1'", strName);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::GetLastLoginName(CString& strName)
{
	USES_CONVERSION;
	bool ret = false;
	
	try
	{
		m_sql.Format("SELECT LastLoginName FROM common WHERE id='1'");
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret = true;
			// 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				strName = (char*)sqlite3_column_text(stmt, 0);
			}
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::_GetDyPay(Json::Value& root)
{
	USES_CONVERSION;
	bool ret = false;
	
	try
	{
		m_sql.Format("SELECT w_down,w_up FROM dianye_number_pay WHERE id='1'");
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret = true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				root[CMD_DYPAY[EM_DY_PAY_DOWN]] = (char*)sqlite3_column_text(stmt, 0);
				root[CMD_DYPAY[EM_DY_PAY_UP]] = (char*)sqlite3_column_text(stmt, 1);
			}
		}
		else
			ret = false;
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::DelStaff(CString strStaffID)
{
	WaitForSingleObject(m_hStaff, INFINITE); 
	USES_CONVERSION;
	bool ret=false;
	
	try
	{
		char *errmsg;
		int result = 0;

		m_sql.Format("UPDATE staff SET del='1' WHERE staff.staffID='%s';", strStaffID);
		sqlite3_stmt *stmt = NULL;
		result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);
	}
	catch (CException* e)
	{
		ret=false;
	}
	ReleaseMutex(m_hStaff); 
	return ret;
}

bool CDbData::PlDelStaff(string strListID)
{
	WaitForSingleObject(m_hStaff, INFINITE);
	bool ret=false;
	
	char *errmsg;
	int result = 0;
	m_sql = "";
	try
	{
		int nFind = strListID.find(';');
		while(nFind>0)
		{
			string strStaffID = strListID.substr(0,nFind);
			strListID = strListID.substr(nFind+1);
			nFind = strListID.find(';');

			CString csql;
			csql.Format("UPDATE staff SET del='1' WHERE staff.staffID='%s';", strStaffID.c_str());
			m_sql += csql;
		}
		result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
			ret = true;
	}
	catch (CException* e)
	{
		ret=false;
	}

	ReleaseMutex(m_hStaff); 
	return ret;
}

bool CDbData::GetStaffs(CString strKeyWord,Json::Value& root,int nstart,int number)
{
	int xcount = 0;
	USES_CONVERSION;

	//获取条数
	try
	{
		
		if(strKeyWord.IsEmpty())
			m_sql.Format("SELECT COUNT(*) AS num FROM staff WHERE del = '0'");
		else
			m_sql.Format("SELECT COUNT(*) AS num FROM staff WHERE del = '0' AND staff.name like '%%%s%%'",g_Globle.EncodeToUTF8(strKeyWord));

		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				xcount = sqlite3_column_int(stmt,0);
			}
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
	}

	try
	{
		
		if (strKeyWord.IsEmpty())
		{
			m_sql.Format("SELECT* FROM staff WHERE del = '0' ORDER BY sort LIMIT '%d','%d'",nstart,number);
		}
		else
		{
			m_sql.Format("SELECT* FROM staff WHERE del = '0' AND staff.name like '%%%s%%' ORDER BY sort LIMIT '%d','%d'",g_Globle.EncodeToUTF8(strKeyWord),nstart,number);
		}
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one;
				const char* tmp = (const char*)sqlite3_column_text(stmt, 1);
				one[CMD_STAFFMSG[EM_STAFF_MSG_NAME]]=g_Globle.UTF8ToEncode(tmp);
				const char* tmp2 = (const char*)sqlite3_column_text(stmt, 2);
				one[CMD_STAFFMSG[EM_STAFF_MSG_SEX]]=g_Globle.UTF8ToEncode(tmp2);
				one[CMD_STAFFMSG[EM_STAFF_MSG_AGE]]=sqlite3_column_int(stmt, 3);
				one[CMD_STAFFMSG[EM_STAFF_MSG_IDCARD]]=(char*)sqlite3_column_text(stmt, 4);
				one[CMD_STAFFMSG[EM_STAFF_MSG_INTIME]]=(char*)sqlite3_column_text(stmt, 5);
				one[CMD_STAFFMSG[EM_STAFF_MSG_TEL]]=(char*)sqlite3_column_text(stmt, 6);
				one[CMD_STAFFMSG[EM_STAFF_MSG_TYPE]] = (STAFF_TYPE)sqlite3_column_int(stmt, 7);
				one[CMD_STAFFMSG[EM_STAFF_MSG_STAFFID]]=(char*)sqlite3_column_text(stmt, 8);
				one[CMD_STAFFMSG[EM_STAFF_MSG_SORT]]=sqlite3_column_int(stmt, 9);
				one[CMD_STAFFMSG[EM_STAFF_MSG_DAYPAY]]=sqlite3_column_double(stmt, 10);
				
				root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
			}
		}
		else
		{
			sqlite3_finalize(stmt);
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
	root[CMD_STAFFMSG[EM_STAFF_MSG_COUNT]] = xcount;
	return true;
}

bool CDbData::GetSampleStaffs(Json::Value& root)
{
	USES_CONVERSION;
	try
	{
		m_sql.Format("SELECT staffID,name,day_pay FROM staff WHERE del = '0' ORDER BY sort");

		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one;
				one[CMD_STAFFMSG[EM_STAFF_MSG_STAFFID]]=(char*)sqlite3_column_text(stmt, 0);
				const char* tmp = (const char*)sqlite3_column_text(stmt, 1);
				one[CMD_STAFFMSG[EM_STAFF_MSG_NAME]]=g_Globle.UTF8ToEncode(tmp);
				one[CMD_STAFFMSG[EM_STAFF_MSG_DAYPAY]]=sqlite3_column_double(stmt, 2);

				root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
			}
		}
		else
		{
			sqlite3_finalize(stmt);
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool CDbData::GetDPay(CString strStaffID,Json::Value& root)
{
	USES_CONVERSION;
	try
	{
		double fdaypay = 0;
		
		m_sql.Format("SELECT day_pay FROM staff WHERE staffID=%s", strStaffID);

		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				fdaypay=sqlite3_column_double(stmt, 0);
			}
			root[CMD_STAFFMSG[EM_STAFF_MSG_DAYPAY]]=fdaypay;
		}
		else
		{
			root[CMD_STAFFMSG[EM_STAFF_MSG_DAYPAY]]=fdaypay;
			sqlite3_finalize(stmt);
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool CDbData::AddBook(CString strID, CString strName,CString strCbs,CString strDate,int nBc1,int nBc2, int nSize1,int nSize2,int nKb, double yz,int ys,int bc,double ls,int yzType,int zyType,int rkType,CString strMsg)
{
	WaitForSingleObject(m_hBook, INFINITE); 
	USES_CONVERSION;
	bool ret=false;
	try
	{
		m_sql.Format("INSERT INTO book(bookID,name,cbs,xd_date,bc1,bc2,size1,size2,kb,yz,ys,baoce,ls,yz_type,zy_type,rk_type,msg) VALUES('%s','%s','%s','%s','%d','%d','%d','%d','%d','%f','%d','%d','%f','%d','%d','%d','%s');",
			strID,
			g_Globle.EncodeToUTF8(strName),
			g_Globle.EncodeToUTF8(strCbs),
			strDate,
			nBc1,
			nBc2,
			nSize1,
			nSize2,
			nKb,
			yz,
			ys,
			bc,
			ls,
			yzType,
			zyType,
			rkType,
			g_Globle.EncodeToUTF8(strMsg));
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret=true;
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret=false;
	}
	ReleaseMutex(m_hBook);
	return ret;
}

bool CDbData::ModifyStaff(CString strName,CString strSex,CString strStaffID,CString idcard,CString strTel,int type,int sort,double fDaypay)
{
	WaitForSingleObject(m_hStaff, INFINITE); 
	USES_CONVERSION;
	bool ret=false;
	try
	{
		m_sql.Format("UPDATE staff SET name='%s',sex='%s',tell='%s',type='%d',sort='%d',idcard='%s',day_pay='%.04f' WHERE staffID='%s'",
			g_Globle.EncodeToUTF8(strName),
			g_Globle.EncodeToUTF8(strSex),
			strTel,
			type,
			sort,
			idcard,
			fDaypay,
			strStaffID
			);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret=true;
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret=false;
	}
	ReleaseMutex(m_hStaff);
	return ret;
}

bool CDbData::ModifyBook(CString strID, CString strName,CString strCbs,CString strDate,int nBc1,int nBc2, int nSize1,int nSize2,int nKb, double yz,int ys,int bc,double ls,int yzType,int zyType,int rkType,CString strMsg)
{
	WaitForSingleObject(m_hBook, INFINITE);
	USES_CONVERSION;
	bool ret=false;
	try
	{
		m_sql.Format("UPDATE book SET name='%s',cbs='%s',xd_date='%s',bc1='%d',bc2='%d',size1='%d',size2='%d',kb='%d',yz='%f',ys='%d',baoce='%d',ls='%f',yz_type='%d',zy_type='%d',rk_type='%d',msg='%s' WHERE book.bookID='%s'",
			g_Globle.EncodeToUTF8(strName),
			g_Globle.EncodeToUTF8(strCbs),
			strDate,
			nBc1,
			nBc2,
			nSize1,
			nSize2,
			nKb,
			yz,
			ys,
			bc,
			ls,
			yzType,
			zyType,
			rkType,
			g_Globle.EncodeToUTF8(strMsg),
			strID);
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret=true;
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret=false;
	}
	ReleaseMutex(m_hBook); 
	return ret;
}

bool CDbData::ModifyProject(int id,CString strProName,PRO_NUM_TYPE pn_type,PRO_STAFF_TYPE ps_type)
{
	USES_CONVERSION;
	bool ret=false;
	try
	{
		m_sql.Format("UPDATE project SET name='%s',pro_num_type='%d',staff_write='%d' WHERE project.id='%d'",
			g_Globle.EncodeToUTF8(strProName),
			pn_type,
			ps_type,
			id);
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret=true;
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret=false;
	}
	return ret;
}

bool CDbData::RkBook(string strListID)
{
	WaitForSingleObject(m_hBook, INFINITE);
	bool ret=false;
	m_sql = "";
	char *errmsg;
	int result = 0;

	try
	{
		int nFind = strListID.find(';');
		while(nFind>0)
		{
			string strBookID = strListID.substr(0,nFind);
			strListID = strListID.substr(nFind+1);
			nFind = strListID.find(';');
			CString csql;
			csql.Format("UPDATE book SET rk_type='1' WHERE book.bookID='%s';", strBookID.c_str());
			m_sql += csql;
		}
		result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
			ret = true;
	}
	catch (CException* e)
	{
		ret=false;
	}
	
	ReleaseMutex(m_hBook); 
	return ret;
}

bool CDbData::PlDelBook(string strListID)
{
	WaitForSingleObject(m_hBook, INFINITE);
	bool ret=false;
	m_sql = "";
	char *errmsg;
	int result = 0;

	try
	{
		int nFind = strListID.find(';');
		while(nFind>0)
		{
			string strBookID = strListID.substr(0,nFind);
			strListID = strListID.substr(nFind+1);
			nFind = strListID.find(';');
			CString csql;
			csql.Format("UPDATE book SET del='1' WHERE book.bookID='%s';", strBookID.c_str());
			m_sql += csql;
		}
		result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
			ret = true;
	}
	catch (CException* e)
	{
		ret=false;
	}

	ReleaseMutex(m_hBook); 
	return ret;
}

bool CDbData::DelBook(CString strBookID)
{
	WaitForSingleObject(m_hBook, INFINITE);
	USES_CONVERSION;
	bool ret=false;
	
	try
	{
		char *errmsg;
		int result = 0;

		m_sql.Format("UPDATE book SET del='1' WHERE book.bookID='%s';", strBookID);
		sqlite3_stmt *stmt = NULL;//语句句柄
		result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);

	}
	catch (CException* e)
	{
		ret=false;
	}
	ReleaseMutex(m_hBook); 
	return ret;
}

bool CDbData::DelUser(CString strName)
{
	USES_CONVERSION;
	bool ret = false;
	
	try
	{
		m_sql.Format("DELETE FROM user WHERE user.name='%s'", strName);
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (CException* e)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::GetBooks(Json::Value& root,CString strKeyWord,int rkType,EM_DATE_TYPE dateType,int nStart,int nNum)
{
	int xcount = 0;
	USES_CONVERSION;

	CString strTimeBegin;
	CString strTimeNow;
	if (dateType != EM_DATE_TYPE_ALL)
	{
		CTime tm; 
		tm=CTime::GetCurrentTime(); 
		strTimeNow = tm.Format("%Y/%m/%d");
		strTimeBegin = g_Globle.ReturnBeginTime(dateType);
	}

	//获取条数
	try
	{
		
		if (strKeyWord.IsEmpty())
		{
			if(rkType == BOOK_RK_MAX)
			{
				if (dateType != EM_DATE_TYPE_ALL)
					m_sql.Format("SELECT COUNT(*) AS num FROM book WHERE del='0' AND (xd_date BETWEEN '%s' AND  '%s')",strTimeBegin,strTimeNow);
				else
					m_sql.Format("SELECT COUNT(*) AS num FROM book WHERE del='0'");

			}
			else
			{
				if (dateType != EM_DATE_TYPE_ALL)
					m_sql.Format("SELECT COUNT(*) AS num FROM book WHERE book.rk_type='%d' AND del='0' AND (xd_date BETWEEN '%s' AND  '%s')",rkType,strTimeBegin,strTimeNow);
				else
					m_sql.Format("SELECT COUNT(*) AS num FROM book WHERE book.rk_type='%d' AND del='0'",rkType);
			}
		}
		else
		{
			if(rkType == BOOK_RK_MAX)
			{
				if (dateType != EM_DATE_TYPE_ALL)
					m_sql.Format("SELECT COUNT(*) AS num FROM book WHERE book.name like '%%%s%%' AND del='0' AND (xd_date BETWEEN '%s' AND  '%s')",g_Globle.EncodeToUTF8(strKeyWord),strTimeBegin,strTimeNow);
				else
					m_sql.Format("SELECT COUNT(*) AS num FROM book WHERE book.name like '%%%s%%'  AND del='0'",g_Globle.EncodeToUTF8(strKeyWord));
			}
			else
			{
				if (dateType != EM_DATE_TYPE_ALL)
					m_sql.Format("SELECT COUNT(*) AS num FROM book WHERE book.rk_type='%d' AND del='0' AND book.name like '%%%s%%' AND (xd_date BETWEEN '%s' AND  '%s')",rkType,g_Globle.EncodeToUTF8(strKeyWord),strTimeBegin,strTimeNow);
				else
					m_sql.Format("SELECT COUNT(*) AS num FROM book WHERE book.rk_type='%d' AND del='0' AND book.name like '%%%s%%'",rkType,g_Globle.EncodeToUTF8(strKeyWord));
			}
		}
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				xcount = sqlite3_column_int(stmt,0);
			}
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
	}

	try
	{
		
		if (strKeyWord.IsEmpty())
		{
			if(rkType == BOOK_RK_MAX)
			{
				if (dateType == EM_DATE_TYPE_ALL)
					m_sql.Format("SELECT* FROM book WHERE del='0' ORDER BY xd_date ASC LIMIT '%d','%d'",nStart,nNum);
				else
					m_sql.Format("SELECT* FROM book WHERE del='0' AND (xd_date BETWEEN '%s' AND  '%s') ORDER BY xd_date ASC LIMIT '%d','%d'",strTimeBegin,strTimeNow,nStart,nNum);
			}
			else
			{
				if (dateType == EM_DATE_TYPE_ALL)
					m_sql.Format("SELECT* FROM book WHERE book.rk_type='%d' AND del='0' ORDER BY xd_date ASC LIMIT '%d','%d'",rkType,nStart,nNum);
				else
					m_sql.Format("SELECT* FROM book WHERE book.rk_type='%d' AND del='0' AND (xd_date BETWEEN '%s' AND  '%s') ORDER BY xd_date ASC LIMIT '%d','%d'",rkType,strTimeBegin,strTimeNow,nStart,nNum);
			}
		}
		else
		{
			if(rkType == BOOK_RK_MAX)
			{
				if (dateType == EM_DATE_TYPE_ALL)
					m_sql.Format("SELECT* FROM book WHERE book.name like '%%%s%%' AND del='0' ORDER BY xd_date ASC LIMIT '%d','%d'",g_Globle.EncodeToUTF8(strKeyWord),nStart,nNum);
				else
					m_sql.Format("SELECT* FROM book WHERE book.name like '%%%s%%' AND del='0' AND (xd_date BETWEEN '%s' AND  '%s') ORDER BY xd_date ASC LIMIT '%d','%d'",g_Globle.EncodeToUTF8(strKeyWord),strTimeBegin,strTimeNow,nStart,nNum);
			}
			else
			{
				if (dateType == EM_DATE_TYPE_ALL)
					m_sql.Format("SELECT* FROM book WHERE book.rk_type='%d' AND del='0' AND book.name like '%%%s%%' ORDER BY xd_date ASC LIMIT '%d','%d'",rkType,g_Globle.EncodeToUTF8(strKeyWord),nStart,nNum);
				else
					m_sql.Format("SELECT* FROM book WHERE book.rk_type='%d' AND del='0' AND book.name like '%%%s%%' AND (xd_date BETWEEN '%s' AND  '%s') ORDER BY xd_date ASC LIMIT '%d','%d'",rkType,g_Globle.EncodeToUTF8(strKeyWord),strTimeBegin,strTimeNow,nStart,nNum);
			}

		}
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			int count = 0;
			char str[25]={0};
			// 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one;
				one[CMD_BOOKMSG[BOOKMSG_ID]]=(char*)sqlite3_column_text(stmt, 1);
				const char* tmp=(const char*)sqlite3_column_text(stmt, 2);
				one[CMD_BOOKMSG[BOOKMSG_NAME]]=g_Globle.UTF8ToEncode(tmp);
				const char* tmp2=(const char*)sqlite3_column_text(stmt, 3);
				one[CMD_BOOKMSG[BOOKMSG_CBS]]=g_Globle.UTF8ToEncode(tmp2);
				one[CMD_BOOKMSG[BOOKMSG_DATE]] = (char*)sqlite3_column_text(stmt, 4);
				one[CMD_BOOKMSG[BOOKMSG_BC1]] = sqlite3_column_int(stmt,5);
				one[CMD_BOOKMSG[BOOKMSG_BC2]] = sqlite3_column_int(stmt,6);
				one[CMD_BOOKMSG[BOOKMSG_SIZE1]] = sqlite3_column_int(stmt,7);
				one[CMD_BOOKMSG[BOOKMSG_SIZE2]] = sqlite3_column_int(stmt,8);
				one[CMD_BOOKMSG[BOOKMSG_KB]] = sqlite3_column_int(stmt,9);
				one[CMD_BOOKMSG[BOOKMSG_YZ]] = sqlite3_column_double(stmt,10);
				one[CMD_BOOKMSG[BOOKMSG_YS]] = sqlite3_column_int(stmt,11);
				one[CMD_BOOKMSG[BOOKMSG_BC]] = sqlite3_column_int(stmt,12);
				one[CMD_BOOKMSG[BOOKMSG_LS]] = sqlite3_column_double(stmt,13);
				one[CMD_BOOKMSG[BOOKMSG_B_TYPE]] = (BOOK_TYPE)sqlite3_column_int(stmt, 14);
				one[CMD_BOOKMSG[BOOKMSG_ZY_TYPE]] = (ZHEYEPAY_TYPE)sqlite3_column_int(stmt, 15);
				one[CMD_BOOKMSG[BOOKMSG_RK_TYPE]] = (BOOK_RK)sqlite3_column_int(stmt, 16);
				const char* tmp3=(const char*)sqlite3_column_text(stmt, 17);
				if (tmp3 != NULL)
				{
					one[CMD_BOOKMSG[BOOKMSG_MSG]]=g_Globle.UTF8ToEncode(tmp3);
				}
				root[itoa(count,str,10)] = one;
				count++;
			}
			root[CMD_BOOKMSG[BOOKMSG_COUNT]] = count;
		}
		else
			return false;
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		return false;
	}
	root[CMD_BOOKMSG[BOOKMSG_XCOUNT]] = xcount;
	return true;
}

bool CDbData::GetSampleBooks(Json::Value& root,BOOK_RK rkType)
{
	USES_CONVERSION;
	try
	{
		
		if(rkType == BOOK_RK_MAX)
			m_sql.Format("SELECT bookID,name FROM book WHERE del='0' ORDER BY xd_date ASC ");
		else
			m_sql.Format("SELECT bookID,name FROM book WHERE book.rk_type='%d' AND del='0' ORDER BY xd_date ASC ",rkType);

		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			int count = 0;
			char str[125]={0};
			// 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one;
				one[CMD_BOOKMSG[BOOKMSG_ID]]=(char*)sqlite3_column_text(stmt, 0);
				const char* tmp=(const char*)sqlite3_column_text(stmt, 1);
				one[CMD_BOOKMSG[BOOKMSG_NAME]]=g_Globle.UTF8ToEncode(tmp);
		
				root[itoa(count,str,10)] = one;
				count++;
			}
			root[CMD_BOOKMSG[BOOKMSG_COUNT]] = count;
		}
		else
			return false;
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool CDbData::GetUsers(Json::Value& root)
{
	try
	{
		m_sql = "SELECT name,type,time,show_pass,pass FROM user";
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			// 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one;
				CString str;
				str = (char*)sqlite3_column_text(stmt, 0);
				if (str !=L"admin")
				{
					one[CMD_GETUSER[EM_USER_NAME]] = (char*)sqlite3_column_text(stmt, 0);
					one[CMD_GETUSER[EM_USER_TYPE]] = sqlite3_column_int(stmt, 1);
					one[CMD_GETUSER[EM_USER_TIME]] = (char*)sqlite3_column_text(stmt, 2);
					one[CMD_GETUSER[EM_USER_SHOWPASS]] = sqlite3_column_int(stmt, 3);
					one[CMD_GETUSER[EM_USER_PASS]] = (char*)sqlite3_column_text(stmt, 4);
					root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
				}
			}
		}
		else
			return false;
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool CDbData::_JudgeBook(CString strName, Json::Value& root)
{
	bool ret = false;
	bool bExit = false;
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("SELECT name FROM book WHERE book.name='%s' AND book.del='0'",g_Globle.EncodeToUTF8(strName));
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret=true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				bExit=true;
				break;
			}
		}
		sqlite3_finalize(stmt);
		root[CMD_JUDGEBOOK[EM_JUDGE_BOOK_BHAD]] = bExit;
	}
	catch (...)
	{
		ret=false;
	}
	return ret;
}

bool CDbData::_JudgeUser(CString strName, Json::Value& root)
{
	bool ret = false;
	bool bExit = false;
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("SELECT name FROM user WHERE user.name='%s'", strName);
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret = true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				bExit = true;
				break;
			}
			root[CMD_JUDGEUSER[EM_JUDGE_USER_BHAD]] = bExit;
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::bLogin(CString strName, CString strPass, int show_pass, bool& bOk, int& type)
{
	USES_CONVERSION;
	bool ret;
	
	try
	{
		m_sql.Format("SELECT type FROM user WHERE user.name='%s' AND user.pass='%s'", strName,strPass);
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret = true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				bOk = true;
				type = sqlite3_column_int(stmt, 0);
				break;
			}
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}

	if (bOk)
	{
		
		try
		{
			m_sql.Format("UPDATE user SET show_pass='%d' WHERE user.name='%s'", show_pass, strName);
			sqlite3_stmt *stmt = NULL;
			int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
			if (result == SQLITE_OK)
			{
				sqlite3_step(stmt);
			}
			sqlite3_finalize(stmt);
		}
		catch (...)
		{
		}
	}
	return ret;
}

bool CDbData::Login(CString strName,CString strPass,int show_pass,Json::Value& root)
{
	USES_CONVERSION;
	bool bOk = false;
	
	try
	{
		m_sql.Format("SELECT type FROM user WHERE user.name='%s' AND user.pass='%s'", strName,strPass);
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				bOk = true;
				root[CMD_LOGINMSG[EM_LOGINMSG_TYPE]] = sqlite3_column_int(stmt, 0);
				break;
			}
			root[CMD_LOGINMSG[EM_LOGINMSG_NAME]] = strName.GetBuffer();
			root[CMD_LOGINMSG[EM_LOGINMSG_PASS]] = strPass.GetBuffer();
		}
		else
		{
			sqlite3_finalize(stmt);
			return false;
		}
		root[CMD_LOGINMSG[EM_LOGINMSG_LOGIND]] = false;
		root[CMD_LOGINMSG[EM_LOGINMSG_BOK]] = bOk;
	}
	catch (...)
	{
		return false;
	}

	if (bOk)
	{
		
		try
		{
			m_sql.Format("UPDATE user SET show_pass='%d' WHERE user.name='%s'", show_pass, strName);
			sqlite3_stmt *stmt = NULL;
			int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
			if (result == SQLITE_OK)
			{
				sqlite3_step(stmt);
			}
			else
			{
				sqlite3_finalize(stmt);
				return false;
			}
		}
		catch (...)
		{
			return false;
		}
	}
	return true;
}

bool CDbData::CheckPwd(CString strName, CString strPwd)
{
	USES_CONVERSION;
	bool ret=false;
	
	try
	{
		m_sql.Format("SELECT name FROM user WHERE user.name='%s' AND user.pass='%s'",strName,strPwd);
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			// 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				ret = true;
				break;
			}
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::ModifyPwd(CString strName, CString strPwd)
{
	bool ret = false;
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("UPDATE user SET pass='%s' WHERE user.name='%s'",strPwd,strName);
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::InitData()
{
	bool ret = false;
	char sql[MAX_PATH] = { 0 };
	char all_sql[1024 * 10] = {0};
	try
	{
		char *errmsg;
		int result = 0;
		sprintf(sql, "DELETE FROM staff;");
		strcat(all_sql, sql);
		sprintf(sql, "DELETE FROM progress;");
		strcat(all_sql, sql);
		sprintf(sql, "DELETE FROM book;");
		strcat(all_sql, sql);
		sprintf(sql, "UPDATE user SET pass='123456' WHERE user.name='admin';");
		strcat(all_sql, sql);
		sprintf(sql, "DELETE FROM user WHERE type != '2';");
		strcat(all_sql, sql);
		sprintf(sql, "DELETE FROM day_pay;");
		strcat(all_sql, sql);
		sprintf(sql, "DELETE FROM work_cal;");
		strcat(all_sql, sql);
		sprintf(sql, "DELETE FROM project WHERE id>'8';");
		strcat(all_sql, sql);
		sprintf(sql, "UPDATE zheye_number_pay SET a_pay='0',sf_pay='0',td_pay='0';");
		strcat(all_sql, sql);
		sprintf(sql, "DELETE FROM other_number_pay;");
		strcat(all_sql, sql);
		sprintf(sql, "UPDATE dai_number_pay SET a_pay='0',sf_pay='0' ,gr_pay='0';");
		strcat(all_sql, sql);
		sprintf(sql, "UPDATE dianye_number_pay SET w_down='0' ,w_up='0';");
		strcat(all_sql, sql);
		sprintf(sql, "UPDATE common SET LastLoginname='';");
		strcat(all_sql, sql);

		sqlite3_exec(m_sqlite, "begin transaction", 0, 0, NULL);
		result = sqlite3_exec(m_sqlite, all_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
		{
			ret = true;
			sqlite3_exec(m_sqlite, "commit transaction", 0, 0, NULL);
		}
		else
			sqlite3_exec( m_sqlite , "rollback transaction" , 0 , 0 ,NULL);//回滚
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::GetProjectLists(Json::Value& root,PRO_STAFF_TYPE type)
{
	
	USES_CONVERSION;
	try
	{
		if(type == PRO_STAFF_TYPE_MAX)
			m_sql.Format("SELECT id,name,pro_num_type,staff_write,ndex,all_book,pay FROM project WHERE del='0'");
		else
			m_sql.Format("SELECT id,name,pro_num_type,staff_write,ndex,all_book,pay FROM project WHERE del='0' AND staff_write='%d'",PRO_STAFF_TYPE_YES);

		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			int nCount = 0;
			char str[CMD_CHAR_MAX]={0};
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one;
				one[CMD_PROMSG[EM_PROMSG_ID]] = sqlite3_column_int(stmt, 0);
				const char* tmp=(const char*)sqlite3_column_text(stmt, 1);
				one[CMD_PROMSG[EM_PROMSG_NAME]]=g_Globle.UTF8ToEncode(tmp);
				one[CMD_PROMSG[EM_PROMSG_NUM_TYPE]] = (PRO_NUM_TYPE)sqlite3_column_int(stmt, 2);
				one[CMD_PROMSG[EM_PROMSG_BWRITE]] = (PRO_STAFF_TYPE)sqlite3_column_int(stmt, 3);
				one[CMD_PROMSG[EM_PROMSG_NDEX]] = sqlite3_column_int(stmt, 4);
				one[CMD_PROMSG[EM_PROMSG_ALL_BOOK]] = sqlite3_column_int(stmt, 5);
				one[CMD_PROMSG[EM_PROMSG_PAY]] = (char*)sqlite3_column_text(stmt, 6);
				root[itoa(nCount,str,10)]=one;
				nCount++;
			}
			root[CMD_PROMSG[EM_PROMSG_COUNT]]=nCount;
		}
		else
		{
			return false;
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool CDbData::SaveDaiPay(STU_DAI_PAY stu)
{
	USES_CONVERSION;
	bool ret=false;
	m_sql = "";
	char all_sql[1024 * 5] = {0};
	try
	{
		char *errmsg;
		int result = 0;
		CString csql;
		csql.Format("UPDATE dai_number_pay SET a_pay='%s',sf_pay='%s',gr_pay='%s' WHERE id=1;",stu.strA_w,stu.strSf_w,stu.strTd_w);
		m_sql += csql;
		csql.Format("UPDATE dai_number_pay SET a_pay='%s',sf_pay='%s',gr_pay='%s' WHERE id=2;", stu.strA_2,stu.strSf_2, stu.strTd_2);
		m_sql += csql;
		csql.Format("UPDATE dai_number_pay SET a_pay='%s',sf_pay='%s',gr_pay='%s' WHERE id=3;", stu.strA_2_5,stu.strSf_2_5, stu.strTd_2_5);
		m_sql += csql;
		csql.Format("UPDATE dai_number_pay SET a_pay='%s',sf_pay='%s',gr_pay='%s' WHERE id=4;", stu.strA_5_9,stu.strSf_5_9, stu.strTd_5_9);
		m_sql += csql;
		csql.Format("UPDATE dai_number_pay SET a_pay='%s',sf_pay='%s',gr_pay='%s' WHERE id=5;", stu.strA_10,stu.strSf_10, stu.strTd_10);
		m_sql += csql;
		csql.Format("UPDATE dai_number_pay SET a_pay='%s',sf_pay='%s',gr_pay='%s' WHERE id=6;",stu.strA_18, stu.strSf_18, stu.strTd_18);
		m_sql += csql;

		sqlite3_exec(m_sqlite, "begin transaction", 0, 0, NULL);
		result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
		{
			ret = true;
			sqlite3_exec(m_sqlite, "commit transaction", 0, 0, NULL);
		}
		else
			sqlite3_exec( m_sqlite , "rollback transaction" , 0 , 0 ,NULL);//回滚
	}
	catch (CException* e)
	{
		ret=false;
	}
	return ret;
}

bool CDbData::SaveStaffWrite(CString strBookID,int proID,double number)
{
	bool ret = false;
	USES_CONVERSION;
	try
	{
		char *errmsg;
		int result = 0;
		m_sql.Format("REPLACE INTO progress(proID,bookID,number) VALUES('%d','%s','%f');", proID, strBookID,number);
		result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
		{
			ret = true;
		}

	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::_GetDaiPay(Json::Value& root)
{
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("SELECT id,a_pay,sf_pay,gr_pay FROM dai_number_pay");
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				int nID = sqlite3_column_int(stmt, 0);
				switch (nID)
				{
				case DAINUMPAY_TYPE_W:
					{
						
						root[CMD_DAIPAY[EM_DAI_PAY_A_W]]=(char*)sqlite3_column_text(stmt, 1);
						root[CMD_DAIPAY[EM_DAI_PAY_Sf_w]]=(char*)sqlite3_column_text(stmt, 2);
						root[CMD_DAIPAY[EM_DAI_PAY_Td_w]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				case DAINUMPAY_TYPE_2:
					{
						root[CMD_DAIPAY[EM_DAI_PAY_2]]=(char*)sqlite3_column_text(stmt, 1);
						root[CMD_DAIPAY[EM_DAI_PAY_Sf_2]]=(char*)sqlite3_column_text(stmt, 2);
						root[CMD_DAIPAY[EM_DAI_PAY_Td_2]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				case DAINUMPAY_TYPE_2_5:
					{
						root[CMD_DAIPAY[EM_DAI_PAY_2_5]]=(char*)sqlite3_column_text(stmt, 1);
						root[CMD_DAIPAY[EM_DAI_PAY_Sf_2_5]]=(char*)sqlite3_column_text(stmt, 2);
						root[CMD_DAIPAY[EM_DAI_PAY_Td_2_5]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				case DAINUMPAY_TYPE_5_9:
					{
						root[CMD_DAIPAY[EM_DAI_PAY_5_9]]=(char*)sqlite3_column_text(stmt, 1);
						root[CMD_DAIPAY[EM_DAI_PAY_Sf_5_9]]=(char*)sqlite3_column_text(stmt, 2);
						root[CMD_DAIPAY[EM_DAI_PAY_Td_5_9]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				case DAINUMPAY_TYPE_10:
					{
						root[CMD_DAIPAY[EM_DAI_PAY_10]]=(char*)sqlite3_column_text(stmt, 1);
						root[CMD_DAIPAY[EM_DAI_PAY_Sf_10]]=(char*)sqlite3_column_text(stmt, 2);
						root[CMD_DAIPAY[EM_DAI_PAY_Td_10]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				case DAINUMPAY_TYPE_18:
					{
						root[CMD_DAIPAY[EM_DAI_PAY_18]]=(char*)sqlite3_column_text(stmt, 1);
						root[CMD_DAIPAY[EM_DAI_PAY_Sf_18]]=(char*)sqlite3_column_text(stmt, 2);
						root[CMD_DAIPAY[EM_DAI_PAY_Td_18]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				}
			}
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool CDbData::SaveDianyePay(CString strdown,CString strup)
{
	bool ret = false;
	USES_CONVERSION;
	try
	{
		char *errmsg;
		int result = 0;
		m_sql.Format("UPDATE dianye_number_pay SET w_down='%s',w_up='%s' WHERE id=1;", strdown, strup);
		result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
		{
			ret = true;
		}
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::GetDianyePay(CString& strdown,CString& strup)
{
	USES_CONVERSION;
	bool ret = false;
	
	try
	{
		m_sql.Format("SELECT w_down,w_up FROM dianye_number_pay WHERE id='1'");
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				ret = true;
				strdown = (char*)sqlite3_column_text(stmt, 0);
				strup = (char*)sqlite3_column_text(stmt, 1);
			}
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::SaveZheYePay(STU_ZHEYE_PAY stu)
{
	bool ret = false;
	m_sql = "";
	USES_CONVERSION;
	try
	{
		char *errmsg;
		int result = 0;

		CString csql;
		csql.Format("UPDATE zheye_number_pay SET a_pay='%s',sf_pay='%s',td_pay='%s' WHERE id=1;",
			stu.strAQ4,stu.str_sf_Q4,stu.str_td_Q4);
		m_sql += csql;

		csql.Format("UPDATE zheye_number_pay SET a_pay='%s',sf_pay='%s',td_pay='%s' WHERE id=2;",
			stu.strA4,stu.str_sf_4,stu.str_td_4);
		m_sql += csql;

		csql.Format("UPDATE zheye_number_pay SET a_pay='%s',sf_pay='%s',td_pay='%s' WHERE id=3;",
			stu.strAD3,stu.str_sf_D3,stu.str_td_D3);
		m_sql += csql;

		csql.Format("UPDATE zheye_number_pay SET a_pay='%s',sf_pay='%s',td_pay='%s' WHERE id=4;",
			stu.strA3,stu.str_sf_3,stu.str_td_3);
		m_sql += csql;

		csql.Format("UPDATE zheye_number_pay SET a_pay='%s',sf_pay='%s',td_pay='%s' WHERE id=5;",
			stu.strA2,stu.str_sf_2,stu.str_td_2);
		m_sql += csql;

		sqlite3_exec(m_sqlite, "begin transaction", 0, 0, NULL);
		result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
		{
			ret = true;
			sqlite3_exec(m_sqlite, "commit transaction", 0, 0, NULL);
		}
		else
			sqlite3_exec( m_sqlite , "rollback transaction" , 0 , 0 ,NULL);//回滚
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::_GetZheYePay(Json::Value& root)
{
	bool bRet =false;
	
	try
	{
		m_sql.Format("SELECT id,a_pay,sf_pay,td_pay FROM zheye_number_pay");
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			bRet =true;
			// 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				int nID = sqlite3_column_int(stmt, 0);
				switch (nID)
				{
				case ZHEYEPAY_TYPE_Q4:
					{
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_AQ4]] = (char*)sqlite3_column_text(stmt, 1);
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_Q4]] = (char*)sqlite3_column_text(stmt, 2);
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_Q4]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				case ZHEYEPAY_TYPE_4:
					{
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_A4]] = (char*)sqlite3_column_text(stmt, 1);
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_4]] = (char*)sqlite3_column_text(stmt, 2);
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_4]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				case ZHEYEPAY_TYPE_D3:
					{
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_AD3]] = (char*)sqlite3_column_text(stmt, 1);
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_D3]] = (char*)sqlite3_column_text(stmt, 2);
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_D3]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				case ZHEYEPAY_TYPE_3:
					{
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_A3]] = (char*)sqlite3_column_text(stmt, 1);
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_3]] = (char*)sqlite3_column_text(stmt, 2);
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_3]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				case ZHEYEPAY_TYPE_2:
					{
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_A2]] = (char*)sqlite3_column_text(stmt, 1);
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_sf_2]] = (char*)sqlite3_column_text(stmt, 2);
						root[CMD_ZHEYEPAY[EM_ZHEYE_PAY_td_2]] = (char*)sqlite3_column_text(stmt, 3);
						break;
					}
				}
			}
		}
		else
			bRet =false;
		sqlite3_finalize(stmt);
		
	}
	catch (...)
	{
		bRet =false;
	}
	return bRet;
}

bool CDbData::SaveOtherPay(int proID, vector<OTHER_PRO_PAY> vec)
{
	bool ret = false;
	USES_CONVERSION;
	try
	{
		char *errmsg;
		int result = 0;
		int nSize = vec.size();
#if 0
		for (int i = 0; i < nSize;i++)
		{
			char stmp[256] = {0};
			sprintf(stmp, "REPLACE INTO other_number_pay(proID,bookID,pay) VALUES('%d','%s','%s');", proID, vec[i].strBookID, vec[i].strPay);
			strcat(sql, stmp);
		}
		char tmp[256]={0};
		sprintf(tmp,"UPDATE project SET all_book='0',pay='0' WHERE id='%d';",proID);
		strcat(sql, tmp);

		result = sqlite3_exec( m_sqlite, "begin transaction", 0, 0, &errmsg ); //开始一个事务
		result = sqlite3_exec(m_sqlite, sql, NULL, &ret, &errmsg);
		result = sqlite3_exec( m_sqlite, "commit transaction", 0, 0, &errmsg ); //提交事务
		if (result == SQLITE_OK)
		{
			ret = true;
		}
#else
		sqlite3_exec(m_sqlite, "begin transaction", 0, 0, NULL);
		m_sql.Format("REPLACE INTO other_number_pay(proID,bookID,pay) VALUES(?,?,?);");
		sqlite3_stmt *stmt = NULL;
		result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if(result == SQLITE_OK)
		{
			result = SQLITE_DONE;
			for (int i = 0; i < nSize && result==SQLITE_DONE;i++)
			{
				sqlite3_reset(stmt);
				sqlite3_bind_int(stmt,1,proID);
				sqlite3_bind_text(stmt,2,vec[i].strBookID,-1,SQLITE_STATIC);
				sqlite3_bind_text(stmt,3,vec[i].strPay,-1,SQLITE_STATIC);
				result = sqlite3_step(stmt);
			}

			sqlite3_finalize(stmt);
			if(result == SQLITE_DONE)
			{
				char tmp[256]={0};
				m_sql.Format("UPDATE project SET all_book='0',pay='0' WHERE id='%d';",proID);
				result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
				if(result == SQLITE_OK)
				{
					ret = true;
					sqlite3_exec(m_sqlite, "commit transaction", 0, 0, NULL);
				}
				else
					sqlite3_exec( m_sqlite , "rollback transaction" , 0 , 0 ,NULL);//回滚
			}
			else
				sqlite3_exec( m_sqlite , "rollback transaction" , 0 , 0 ,NULL);//回滚
		}
#endif
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::SaveOtherAllBookPay(int proID,CString strPay)
{
	USES_CONVERSION;
	bool ret=false;

	try
	{
		m_sql.Format("DELETE FROM other_number_pay WHERE proID='%d'",proID);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);

	}
	catch (CException* e)
	{
		ret = false;
	}

	try
	{
		m_sql.Format("UPDATE project SET all_book='1',pay='%s' WHERE id='%d'",
			strPay,
			proID
			);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret=true;
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret=false;
	}
	return ret;
}

bool CDbData::_GetOtherPay(Json::Value& root,int proID)
{
	bool ret = false;
	
	try
	{
		m_sql.Format("SELECT bookID,pay FROM other_number_pay WHERE proID=%d", proID);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret = true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one;
				one[CMD_OTHERPAYMSG[EM_OTHER_PAY_MSG_BOOKID]] = (char*)sqlite3_column_text(stmt, 0);
				one[CMD_OTHERPAYMSG[EM_OTHER_PAY_MSG_PAY]] = (char*)sqlite3_column_text(stmt, 1);
				root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
			}
		}
		else
			ret = false;
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::GetYzAndType(CString strBookID, double& yz, int& ys, int& type)
{
	bool ret = false;
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("SELECT yz,ys,yz_type FROM book WHERE bookID='%s'", strBookID);
		sqlite3_stmt *stmt = NULL;//语句句柄
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret = true;
			// 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				yz = sqlite3_column_double(stmt, 0);
				ys = sqlite3_column_int(stmt, 1);
				type = sqlite3_column_int(stmt, 2);
			}
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::GetZyType(CString strBookID, int& zyType)
{
	bool ret = false;
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("SELECT zy_type FROM book WHERE bookID='%s'", strBookID);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret = true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				zyType = sqlite3_column_int(stmt, 0);
			}
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

bool CDbData::GetStaffType(CString strStaffID, int& type)
{
	bool ret = false;
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("SELECT type FROM staff WHERE staffID='%s'", strStaffID);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			ret = true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				type = sqlite3_column_int(stmt, 0);
			}
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}

CString CDbData::GetZyPayFromID(int zyID,int staffType)
{
	CString strRet;
	
	try
	{
		if (staffType == STAFF_TYPE_PT)
		{
			m_sql.Format("SELECT td_pay FROM zheye_number_pay WHERE id='%d'", zyID);
		}
		else if (staffType == STAFF_TYPE_SF)
		{
			m_sql.Format("SELECT sf_pay FROM zheye_number_pay WHERE id='%d'", zyID);
		}
		else if (staffType == STAFF_TYPE_PT_SF)
		{
			m_sql.Format("SELECT a_pay FROM zheye_number_pay WHERE id='%d'", zyID);
		}
		
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				strRet = sqlite3_column_text(stmt, 0);
			}
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
	}
	return strRet;
}

CString CDbData::GetOtherPayFromID(int proID, CString strBookID)
{
	CString strRet;
	
	USES_CONVERSION;
	try
	{
		int all_book=0;
		CString strPay = "";
		m_sql.Format("SELECT all_book,pay FROM project WHERE id='%d'", proID);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				all_book = sqlite3_column_int(stmt, 0);
				strPay = (char*)sqlite3_column_text(stmt, 1);
			}
		}
		sqlite3_finalize(stmt);

		if (all_book == 1)
		{
			strRet = strPay;
		}
		else
		{
			m_sql.Format("SELECT pay FROM other_number_pay WHERE proID='%d' AND bookID='%s'", proID, strBookID);
			int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
			if (result == SQLITE_OK)
			{
				while (sqlite3_step(stmt) == SQLITE_ROW)
				{
					strRet = sqlite3_column_text(stmt, 0);
				}
			}
			sqlite3_finalize(stmt);
		}
	}
	catch (...)
	{
	}
	return strRet;
}

bool CDbData::_GetOnePay(Json::Value& root,CString strStaffID, int proID, CString strBookID)
{
	bool bRet =true;
	CString strRet;
	USES_CONVERSION;
	if (proID == PROJECT_TYPE_JIAODING)
	{
		//首先通过bookID获取印张印数和印张类型
		double yz=0;
		int ys=0,yzType=0;
		if (GetYzAndType(strBookID, yz, ys, yzType))
		{
			//通过strStaff获取职工类型
			int staffType;
			if (GetStaffType(strStaffID, staffType))
			{
				DAINUMPAY_TYPE daiType = DAINUMPAY_TYPE_MAX;
				if (ys<10000 && ys>0)
				{
					if (ys <= 2000)
						daiType = DAINUMPAY_TYPE_2;
					else if (ys >= 2001 && ys <= 5000)
						daiType = DAINUMPAY_TYPE_2_5;
					else if (ys >= 5001 && ys <= 9999)
						daiType = DAINUMPAY_TYPE_5_9;

					if (yzType == BOOK_TYPE_QUAN)
					{
						if (yzType / 2 > 24)
							daiType = DAINUMPAY_TYPE_W;
					}
					else if (yzType == BOOK_TYPE_DUI)
					{
						if (yzType > 24)
							daiType = DAINUMPAY_TYPE_W;
					}
				}
				else if (ys >=10000)
				{
					/*
					1.一本书印数超过10000本，如果全开印张超过10代的，或对开印张超过18代以上的，为18代10印张类型，
					否则为10000以上类型
					*/
					if (yzType == BOOK_TYPE_QUAN)
					{
						if (yz>=10)
							daiType = DAINUMPAY_TYPE_18;
						else
							daiType = DAINUMPAY_TYPE_10;
					}
					else if (yzType == BOOK_TYPE_DUI)
					{
						if (yz>=18)
							daiType = DAINUMPAY_TYPE_18;
						else
							daiType = DAINUMPAY_TYPE_10;
					}
				}

				if (daiType != DAINUMPAY_TYPE_MAX)
				{
					//获取
					
					try
					{
						if (staffType == STAFF_TYPE_SF)
							m_sql.Format("SELECT sf_pay FROM dai_number_pay WHERE id='%d'", daiType);
						else if (staffType == STAFF_TYPE_PT)
							m_sql.Format("SELECT gr_pay FROM dai_number_pay WHERE id='%d'", daiType);
						else if (staffType == STAFF_TYPE_PT_SF)
							m_sql.Format("SELECT a_pay FROM dai_number_pay WHERE id='%d'", daiType);

						sqlite3_stmt *stmt = NULL;
						int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
						if (result == SQLITE_OK)
						{
							while (sqlite3_step(stmt) == SQLITE_ROW)
							{
								strRet = (char*)sqlite3_column_text(stmt, 0);
							}
						}
						sqlite3_finalize(stmt);
					}
					catch (...)
					{
						bRet =false;
					}
				}
			}
		}
	}
	else if (proID == PROJECT_TYPE_ZY)
	{
		//通过bookID获取折页类型
		int zyType;
		if (GetZyType(strBookID,zyType))
		{
			//通过strStaff获取职工类型
			int staffType;
			if (GetStaffType(strStaffID, staffType))
			{
				strRet = GetZyPayFromID(zyType,staffType);
			}
		}
	}
	else if (proID == PROJECT_TYPE_DY)
	{
		//通过bookID获取印数
		double yz=0;
		int ys=0,yzType=0;
		if (GetYzAndType(strBookID, yz, ys, yzType))
		{
			CString strDown,strUp;
			if (GetDianyePay(strDown,strUp))
			{
				if (ys<10000)
					strRet = strDown;
				else
					strRet = strUp;
			}
		}
	}
	else
	{
		strRet = GetOtherPayFromID(proID, strBookID);
	}
	if(bRet)
		root[GETPAYMSG[EM_GET_PAY_PAY]] = strRet.GetBuffer();
	return bRet;
}

bool CDbData::DeleteDayPay(CString strStaffID, CString strDate)
{
	WaitForSingleObject(m_hOnePay, INFINITE); 
	
	bool ret = false;
	
	USES_CONVERSION;
	try
	{
		if (!strDate.IsEmpty())
		{
			m_sql.Format("DELETE FROM day_pay WHERE staffID='%s' AND date='%s'", strStaffID, strDate);
		}
		else
		{
			m_sql.Format("DELETE FROM day_pay WHERE staffID='%s'", strStaffID);
		}
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);

	}
	catch (CException* e)
	{
		ret = false;
	}
	ReleaseMutex(m_hOnePay);
	return ret;
}

bool CDbData::DeleteDayPay(int id)
{
	WaitForSingleObject(m_hOnePay, INFINITE); 
	bool ret = false;
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("DELETE FROM day_pay WHERE id='%d'",id);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);

	}
	catch (CException* e)
	{
		ret = false;
	}
	ReleaseMutex(m_hOnePay);
	return ret;
}

bool CDbData::DeleteDayPay(CString strStaffID,int nProID,CString strBookID, CString strDate)
{
	WaitForSingleObject(m_hOnePay, INFINITE); 
	bool ret = false;
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("DELETE FROM day_pay WHERE staffID='%s' AND proID='%d' AND bookID='%s' AND date='%s'", strStaffID,nProID,strBookID, strDate);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			sqlite3_step(stmt);
			ret = true;
		}
		sqlite3_finalize(stmt);

	}
	catch (CException* e)
	{
		ret = false;
	}
	ReleaseMutex(m_hOnePay);
	return ret;
}

bool CDbData::AddDayPay(CString strStaffID, vector<DAYPAY> vec, CString strDate)
{
	WaitForSingleObject(m_hOnePay, INFINITE); 
	bool ret = false;
	m_sql = "";
	USES_CONVERSION;
	try
	{
		char *errmsg;
		int result = 0;

		int nSize = vec.size();
		for (int i = 0; i < nSize; i++)
		{
			CString csql;

			if (vec[i].type == DAYPAY_TYPE_DEL)
			{
				csql.Format("INSERT INTO day_pay(staffID,pay_type,money,del_msg,date) VALUES('%s','%d','%s','%s','%s');",
					strStaffID, (int)vec[i].type, vec[i].money, g_Globle.EncodeToUTF8(vec[i].strMsg ), strDate);
				m_sql += csql;
			}
			else if (vec[i].type == DAYPAY_TYPE_BZ)//补助
			{
				csql.Format("INSERT INTO day_pay(staffID,pay_type,money,bz_type,bz_msg,date) VALUES('%s','%d','%s','%d','%s','%s');",
					strStaffID, (int)vec[i].type, vec[i].money,(int)vec[i].em_bzType, g_Globle.EncodeToUTF8(vec[i].strMsg ), strDate);
				m_sql += csql;
			}
			else if (vec[i].type == DAYPAY_TYPE_DAY)
			{
				csql.Format("INSERT INTO day_pay(staffID,pay_type,payDay,days,money,date) VALUES('%s','%d','%s','%s','%s','%s');",
					strStaffID, (int)vec[i].type, vec[i].strPayDay, vec[i].strDays,vec[i].money, strDate);
				m_sql += csql;
			}
			else if (vec[i].type == DAYPAY_TYPE_JIJIAN)
			{
				csql.Format("INSERT INTO day_pay(staffID,pay_type,proID,bookID,pay,number,money,date,proName,bookName) VALUES('%s','%d','%d','%s','%s','%.2f','%s','%s','%s','%s');",
					strStaffID, (int)vec[i].type, vec[i].proID, vec[i].strBookID, vec[i].pay, vec[i].number, vec[i].money, strDate,
					g_Globle.EncodeToUTF8(vec[i].strProName),
					g_Globle.EncodeToUTF8(vec[i].strBookName));
				m_sql += csql;
			}
		}

		sqlite3_exec(m_sqlite, "begin transaction", 0, 0, NULL);
		result = sqlite3_exec(m_sqlite, m_sql, NULL, &ret, &errmsg);
		if (result == SQLITE_OK)
		{
			ret = true;
			sqlite3_exec(m_sqlite, "commit transaction", 0, 0, NULL);
		}
		else
			sqlite3_exec( m_sqlite , "rollback transaction" , 0 , 0 ,NULL);//回滚
	}
	catch (...)
	{
		ret = false;
	}
	ReleaseMutex(m_hOnePay);
	return ret;
}

bool CDbData::_GetDayPay(Json::Value& root,CString strStaffID, CString strDate)
{
	bool bret=false;
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("SELECT id,pay_type,proID,bookID,pay,number,money,payDay,days,proName,bookName,del_msg,bz_type,bz_msg FROM day_pay WHERE staffID='%s' AND date='%s'",strStaffID,strDate);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			bret=true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one;
				CString str;
				one[DAYPAYMSG[EM_DAYPAY_MSG_ID]] = sqlite3_column_int(stmt, 0);
				DAYPAY_TYPE type = (DAYPAY_TYPE)sqlite3_column_int(stmt, 1);
				one[DAYPAYMSG[EM_DAYPAY_MSG_TYPE]] = type;
				if (type == DAYPAY_TYPE_DAY)
				{
					one[DAYPAYMSG[EM_DAYPAY_MSG_PAYDAY]] = (char*)sqlite3_column_text(stmt, 7);
					one[DAYPAYMSG[EM_DAYPAY_MSG_DAYS]] = (char*)sqlite3_column_text(stmt, 8);
				}
				else if(type == DAYPAY_TYPE_JIJIAN)
				{
					one[DAYPAYMSG[EM_DAYPAY_MSG_PROID]] = sqlite3_column_int(stmt, 2);
					one[DAYPAYMSG[EM_DAYPAY_MSG_BOOKID]] = (char*)sqlite3_column_text(stmt, 3);
					one[DAYPAYMSG[EM_DAYPAY_MSG_PAY]] = (char*)sqlite3_column_text(stmt, 4);
					one[DAYPAYMSG[EM_DAYPAY_MSG_NUMBER]] = sqlite3_column_double(stmt, 5);
					char* tmp = (char*)sqlite3_column_text(stmt, 9);
					one[DAYPAYMSG[EM_DAYPAY_MSG_PRONAME]] = g_Globle.UTF8ToEncode(tmp);
					char* tmp2 = (char*)sqlite3_column_text(stmt, 10);
					one[DAYPAYMSG[EM_DAYPAY_MSG_BOOKNAME]] = g_Globle.UTF8ToEncode(tmp2);
				}
				else if (type == DAYPAY_TYPE_DEL)
				{
					char* tmp = (char*)sqlite3_column_text(stmt, 11);
					one[DAYPAYMSG[EM_DAYPAY_MSG_DELMSG]] = g_Globle.UTF8ToEncode(tmp);
				}
				else if (type == DAYPAY_TYPE_BZ)
				{
					one[DAYPAYMSG[EM_DAYPAY_MSG_BZTYPE]] =sqlite3_column_int(stmt, 12);
					char* tmp = (char*)sqlite3_column_text(stmt, 13);
					one[DAYPAYMSG[EM_DAYPAY_MSG_BZMSG]] = g_Globle.UTF8ToEncode(tmp);
				}
				one[DAYPAYMSG[EM_DAYPAY_MSG_MONEY]] = (char*)sqlite3_column_text(stmt, 6);	
				
				root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
			}
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		bret=false;
	}
	return bret;
}

bool CDbData::_GetDayPayList(Json::Value& js,Json::Value root)
{
	vector<STAFF_STU> v_staffs;
	CString strDate;
	strDate = root[CMD_GETDAYPAY[EM_GET_DAYPAY_DATE]].asCString();
	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		if (root[CMD_RetType[EM_CMD_RETYPE_VALUE]].isArray())
		{
			Json::Value ones1 = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
			int n1 = ones1.size();
			for (int i=0;i<n1;i++)
			{
				Json::Value one1 = ones1[i];
				STAFF_STU stu;
				stu.strStaffID = one1[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFID]].asCString();
				stu.strname = one1[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFNAME]].asCString();
				v_staffs.push_back(stu);
			}
		}
	}

	bool bret=true;
	USES_CONVERSION;

	try
	{
		sqlite3_exec(m_sqlite, "begin transaction", 0, 0, NULL);
		m_sql.Format("SELECT id,pay_type,proID,bookID,pay,number,money,payDay,days,proName,bookName,del_msg FROM day_pay WHERE staffID=? AND date=?");
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);

		for (int i=0;i<v_staffs.size() && result== SQLITE_OK;i++)
		{
			Json::Value one1;
			one1[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFID]]= v_staffs[i].strStaffID.GetBuffer();
			one1[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFNAME]]= v_staffs[i].strname.GetBuffer();

			sqlite3_reset(stmt);
			sqlite3_bind_text(stmt,1,v_staffs[i].strStaffID,-1,SQLITE_STATIC);
			sqlite3_bind_text(stmt,2,strDate,-1,SQLITE_STATIC);

			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one;
				CString str;
				one[DAYPAYMSG[EM_DAYPAY_MSG_ID]] = sqlite3_column_int(stmt, 0);
				DAYPAY_TYPE type = (DAYPAY_TYPE)sqlite3_column_int(stmt, 1);
				one[DAYPAYMSG[EM_DAYPAY_MSG_TYPE]] = type;
				if (type == DAYPAY_TYPE_DEL)
				{
					char* tmp = (char*)sqlite3_column_text(stmt, 11);
					one[DAYPAYMSG[EM_DAYPAY_MSG_DELMSG]] = g_Globle.UTF8ToEncode(tmp);
				}
				else if (type == DAYPAY_TYPE_DAY)
				{
					one[DAYPAYMSG[EM_DAYPAY_MSG_PAYDAY]] = (char*)sqlite3_column_text(stmt, 7);
					one[DAYPAYMSG[EM_DAYPAY_MSG_DAYS]] = (char*)sqlite3_column_text(stmt, 8);
				}
				else if(type == DAYPAY_TYPE_JIJIAN)
				{
					one[DAYPAYMSG[EM_DAYPAY_MSG_PROID]] = sqlite3_column_int(stmt, 2);
					one[DAYPAYMSG[EM_DAYPAY_MSG_BOOKID]] = (char*)sqlite3_column_text(stmt, 3);
					one[DAYPAYMSG[EM_DAYPAY_MSG_PAY]] = (char*)sqlite3_column_text(stmt, 4);
					one[DAYPAYMSG[EM_DAYPAY_MSG_NUMBER]] = sqlite3_column_double(stmt, 5);
					char* tmp = (char*)sqlite3_column_text(stmt, 9);
					one[DAYPAYMSG[EM_DAYPAY_MSG_PRONAME]] = g_Globle.UTF8ToEncode(tmp);
					char* tmp2 = (char*)sqlite3_column_text(stmt, 10);
					one[DAYPAYMSG[EM_DAYPAY_MSG_BOOKNAME]] = g_Globle.UTF8ToEncode(tmp2);
				}
				one[DAYPAYMSG[EM_DAYPAY_MSG_MONEY]] = (char*)sqlite3_column_text(stmt, 6);	

				one1[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
			}
			js[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one1);
		}
		sqlite3_finalize(stmt);
		sqlite3_exec(m_sqlite, "commit transaction", 0, 0, NULL);
		
		/*
		for (int i=0;i<v_staffs.size();i++)
		{
			Json::Value one1;
			one1[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFID]]=T2A(v_staffs[i].strStaffID);
			one1[CMD_GETDAYPAY[EM_GET_DAYPAY_STAFFNAME]]=T2A(v_staffs[i].strname);

			sprintf(sql, "SELECT id,pay_type,proID,bookID,pay,number,money,payDay,days,proName,bookName,del_msg FROM day_pay WHERE staffID='%s' AND date='%s'",W2A(v_staffs[i].strStaffID),strDate);
			sqlite3_stmt *stmt = NULL;
			int result = sqlite3_prepare_v2(m_sqlite, sql, -1, &stmt, NULL);
			if (result == SQLITE_OK)
			{
				while (sqlite3_step(stmt) == SQLITE_ROW)
				{
					Json::Value one;
					CString str;
					one[DAYPAYMSG[EM_DAYPAY_MSG_ID]] = sqlite3_column_int(stmt, 0);
					DAYPAY_TYPE type = (DAYPAY_TYPE)sqlite3_column_int(stmt, 1);
					one[DAYPAYMSG[EM_DAYPAY_MSG_TYPE]] = type;
					if (type == DAYPAY_TYPE_DEL)
					{
						char* tmp = (char*)sqlite3_column_text(stmt, 11);
						one[DAYPAYMSG[EM_DAYPAY_MSG_DELMSG]] = g_Globle.UTF8ToEncode(tmp);
					}
					else if (type == DAYPAY_TYPE_DAY)
					{
						one[DAYPAYMSG[EM_DAYPAY_MSG_PAYDAY]] = (char*)sqlite3_column_text(stmt, 7);
						one[DAYPAYMSG[EM_DAYPAY_MSG_DAYS]] = (char*)sqlite3_column_text(stmt, 8);
					}
					else if(type == DAYPAY_TYPE_JIJIAN)
					{
						one[DAYPAYMSG[EM_DAYPAY_MSG_PROID]] = sqlite3_column_int(stmt, 2);
						one[DAYPAYMSG[EM_DAYPAY_MSG_BOOKID]] = (char*)sqlite3_column_text(stmt, 3);
						one[DAYPAYMSG[EM_DAYPAY_MSG_PAY]] = (char*)sqlite3_column_text(stmt, 4);
						one[DAYPAYMSG[EM_DAYPAY_MSG_NUMBER]] = sqlite3_column_double(stmt, 5);
						char* tmp = (char*)sqlite3_column_text(stmt, 9);
						one[DAYPAYMSG[EM_DAYPAY_MSG_PRONAME]] = g_Globle.UTF8ToEncode(tmp);
						char* tmp2 = (char*)sqlite3_column_text(stmt, 10);
						one[DAYPAYMSG[EM_DAYPAY_MSG_BOOKNAME]] = g_Globle.UTF8ToEncode(tmp2);
					}
					one[DAYPAYMSG[EM_DAYPAY_MSG_MONEY]] = (char*)sqlite3_column_text(stmt, 6);	

					one1[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
				}
				js[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one1);
			}
			else
			{
				bret = false;
				break;
			}
			sqlite3_finalize(stmt);
		}
		*/
	}
	catch (...)
	{
		bret = false;
	}
	return bret;
}

bool CDbData::_GetMouthPay(Json::Value& js,Json::Value root,DWORD& time)
{
	vector<MONTH_PAY_STAFF> v_staffs;
	if (root.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
	{
		if (root[CMD_RetType[EM_CMD_RETYPE_VALUE]].isArray())
		{
			Json::Value ones1 = root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
			int n1 = ones1.size();
			for (int i=0;i<n1;i++)
			{
				Json::Value one1 = ones1[i];
				MONTH_PAY_STAFF staff;
				staff.strStaffID = one1[MPAYMSG[EM_GET_MPAY_STAFFID]].asCString();
				staff.strStaffName = one1[MPAYMSG[EM_GET_MPAY_STAFFNAME]].asCString();

				if (one1.isMember(CMD_RetType[EM_CMD_RETYPE_VALUE]))
				{
					if (one1[CMD_RetType[EM_CMD_RETYPE_VALUE]].isArray())
					{
						Json::Value ones2 = one1[CMD_RetType[EM_CMD_RETYPE_VALUE]];
						int n2 = ones2.size();
						for (int j=0;j<n2;j++)
						{
							Json::Value one2 = ones2[j];
							MONTHPAY_DAY day;
							day.strDate = one2[MPAYMSG[EM_GET_MPAY_DATE]].asCString();
							day.ndex = one2[MPAYMSG[EM_GET_MPAY_DEX]].asInt();
							staff.vDays.push_back(day);
						}
						v_staffs.push_back(staff);
					}
				}
			}
		}
	}
	else
		return true;
	//////////////////

	bool bret=false;
	
	USES_CONVERSION;
	try
	{
		sqlite3_exec(m_sqlite, "begin transaction", 0, 0, NULL);
		m_sql.Format("SELECT pay_type,money FROM day_pay WHERE staffID=? AND date=?");
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);

		for (int i=0;i<v_staffs.size();i++)
		{
			MONTH_PAY_STAFF staff = v_staffs[i];
			Json::Value one1;
			one1[MPAYMSG[EM_GET_MPAY_STAFFID]]= staff.strStaffID.GetBuffer();
			one1[MPAYMSG[EM_GET_MPAY_STAFFNAME]]= staff.strStaffName.GetBuffer();

			for (auto it = staff.vDays.begin();it!=staff.vDays.end();it++)
			{
				MONTHPAY_DAY day = *it;
				Json::Value one2;
				one2[MPAYMSG[EM_GET_MPAY_DEX]]=day.ndex;

				sqlite3_reset(stmt);
				sqlite3_bind_text(stmt,1,staff.strStaffID,-1,SQLITE_STATIC);
				sqlite3_bind_text(stmt,2,day.strDate,-1,SQLITE_STATIC);

				if (result == SQLITE_OK)
				{
					bret=true;
					while (sqlite3_step(stmt) == SQLITE_ROW)
					{
						Json::Value one3;
						CString str;
						one3[MPAYMSG[EM_GET_MPAY_TYPE]] = sqlite3_column_int(stmt, 0);
						one3[MPAYMSG[EM_GET_MPAY_MONEY]] = (char*)sqlite3_column_text(stmt, 1);
						one2[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one3);
					}
				}
				one1[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one2);
			}
			js[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one1);
		}
		sqlite3_finalize(stmt);
		sqlite3_exec(m_sqlite, "commit transaction", 0, 0, NULL);
	}
	catch (...)
	{
		bret=false;
	}
	return bret;
}

bool CDbData::_GetMouthPay2(Json::Value& js,Json::Value root,DWORD& time)
{
	bool bret=false;
	
	USES_CONVERSION;
	try
	{
		CString strDate;
		DWORD t1=GetTickCount();
		strDate = root[MPAYMSG[EM_GET_MPAY_DATE]].asCString();
		m_sql.Format("SELECT staff.staffID,staff.name,day_pay.pay_type,day_pay.money,day_pay.date FROM staff,day_pay WHERE staff.del = '0' AND staff.staffID = day_pay.staffID AND day_pay.date like '%s%%'",strDate);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			bret=true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one;
				CString str;
				one[MPAYMSG[EM_GET_MPAY_STAFFID]] = (char*)sqlite3_column_text(stmt, 0);

				const char* tmp = (const char*)sqlite3_column_text(stmt, 1);
				one[MPAYMSG[EM_GET_MPAY_STAFFNAME]]=g_Globle.UTF8ToEncode(tmp);

				one[MPAYMSG[EM_GET_MPAY_TYPE]] = sqlite3_column_int(stmt, 2);
				one[MPAYMSG[EM_GET_MPAY_MONEY]] = (char*)sqlite3_column_text(stmt, 3);
				one[MPAYMSG[EM_GET_MPAY_DATE]] = (char*)sqlite3_column_text(stmt, 4);
				js[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
			}
		}

		sqlite3_finalize(stmt);
		DWORD t2=GetTickCount();
		time = t2-t1;
	}
	catch (...)
	{
		bret=false;
	}
	return bret;
}


bool CDbData::GetChartYear(Json::Value& js)
{
	//获取现在年份
	CTime tm=CTime::GetCurrentTime();
	int year = tm.GetYear();

	int ret = SQLITE_ERROR;
	USES_CONVERSION;
	try
	{
		sqlite3_stmt *stmt = NULL;
		char* sql = "SELECT SUM(money) FROM day_pay WHERE pay_type != '2' AND date LIKE ?";
		ret = sqlite3_exec( m_sqlite , "begin transaction" , 0 , 0 ,NULL );
		ret = sqlite3_prepare_v2(m_sqlite, sql, -1, &stmt, NULL);
		for (int i = 0;ret==SQLITE_OK && i<5;i++) 
		{ 
			CString strNowYear,strValue;
			strNowYear.Format("%d",(year-i));
			strValue = strNowYear + "%%";

			ret = sqlite3_bind_text(stmt,1,strValue,-1,SQLITE_STATIC);
			if (ret == SQLITE_OK)
			{
				int step_ret = sqlite3_step(stmt);
				if (step_ret == SQLITE_ERROR)
				{
					ret = step_ret;
				}
				else if (step_ret == SQLITE_ROW)
				{
					Json::Value one;
					one[CHART_YEAR[EM_GET_CHART_YEAR_YEAR]] = strNowYear.GetBuffer();
					one[CHART_YEAR[EM_GET_CHART_YEAR_VALUE]] = sqlite3_column_double(stmt,0);
					js[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
				}
			}
			//重新初始化该sqlite3_stmt对象绑定的变量
			if(stmt)
				sqlite3_reset(stmt);
		}

		if(stmt)
			sqlite3_finalize(stmt);

		if(ret==SQLITE_OK)
		{
			sqlite3_exec( m_sqlite , "commit transaction" , 0 , 0 ,NULL);
			return true;
		}
		else// 如果操作错误,回滚
		{
			sqlite3_exec( m_sqlite , "rollback transaction" , 0 , 0 ,NULL);
			return false;
		}		
	}
	catch (...)
	{
		return false;
	}
}

bool CDbData::GetChartMonth(Json::Value& js,CString strYear)
{
	int ret = SQLITE_ERROR;
	USES_CONVERSION;
	try
	{
		sqlite3_stmt *stmt = NULL;
		char* sql = "SELECT SUM(money) FROM day_pay WHERE pay_type != '2' AND date LIKE ?";
		ret = sqlite3_exec( m_sqlite , "begin transaction" , 0 , 0 ,NULL ); 
		ret = sqlite3_prepare_v2(m_sqlite, sql, -1, &stmt, NULL);
		for (int i = 0;ret==SQLITE_OK && i<12;i++) 
		{ 
			CString strMonth,strValue;
			strMonth.Format("%02d",(i+1));
			strValue.Format("%s/%s%%",strYear,strMonth);
			
			ret = sqlite3_bind_text(stmt,1,strValue,-1,SQLITE_STATIC);
			if (ret == SQLITE_OK)
			{
				int step_ret = sqlite3_step(stmt);
                if (step_ret == SQLITE_ROW)
				{
					Json::Value one;
					one[CHART_MONTH[EM_GET_CHART_MONTH_MONTH]] = strMonth.GetBuffer();
					one[CHART_MONTH[EM_GET_CHART_MONTH_VALUE]] = sqlite3_column_double(stmt,0);
					js[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
				}
			}
			//重新初始化该sqlite3_stmt对象绑定的变量
			if(stmt)
				sqlite3_reset(stmt);
		}
		if(stmt)
			sqlite3_finalize(stmt);

		if(ret==SQLITE_OK)
		{
			sqlite3_exec( m_sqlite , "commit transaction" , 0 , 0 ,NULL);
			return true;
		}
		else// 如果操作错误,回滚
		{
			sqlite3_exec( m_sqlite , "rollback transaction" , 0 , 0 ,NULL);
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
}

bool CDbData::_GetDetails(Json::Value& root,vector<PROJECT_STU> vProIDs,CString strBookID)
{
	USES_CONVERSION;
	int num = vProIDs.size();
	try
	{
		m_sql.Format("SELECT xd_date,ys,ls FROM book WHERE book.bookID =  '%s'",strBookID);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				root[CMD_BOOKMSG[BOOKMSG_DATE]] = (char*)sqlite3_column_text(stmt, 0);
				root[CMD_BOOKMSG[BOOKMSG_YS]] = sqlite3_column_int(stmt,1);
				root[CMD_BOOKMSG[BOOKMSG_LS]] = sqlite3_column_double(stmt,2);
			}
		}
#if 0
		for (int i=0;i<num;i++)
		{
			char sql[MAX_PATH*2];
			sprintf(sql, "SELECT staff.name,staff.staffID,day_pay.number FROM day_pay,staff WHERE day_pay.proID='%d' AND day_pay.bookID='%s' AND day_pay.staffID = staff.staffID",vProIDs[i].nID,strBookID);
			sqlite3_stmt *stmt = NULL;
			int result = sqlite3_prepare_v2(m_sqlite, sql, -1, &stmt, NULL);
			if (result == SQLITE_OK)
			{
				Json::Value one1;
				one1[CMD_DETAILMSG[EM_DETAIL_MSG_PROID]] = vProIDs[i].nID;
				one1[CMD_DETAILMSG[EM_DETAIL_MSG_NDEX]] = vProIDs[i].ndex;
				while (sqlite3_step(stmt) == SQLITE_ROW)
				{
					Json::Value one2;
					const char* tmp = (char*)sqlite3_column_text(stmt, 0);
					one2[CMD_DETAILMSG[EM_DETAIL_MSG_NAME]] = g_Globle.UTF8ToEncode(tmp);
					one2[CMD_DETAILMSG[EM_DETAIL_MSG_IDCARD]] = (char*)sqlite3_column_text(stmt, 1);
					one2[CMD_DETAILMSG[EM_DETAIL_MSG_NUMBER]] = sqlite3_column_int(stmt, 2);
					one1[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one2);
				}
				root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one1);
			}
			else
				return false;
			sqlite3_finalize(stmt);
		}
#else
		sqlite3_exec(m_sqlite, "begin transaction", 0, 0, NULL);
		m_sql.Format("SELECT staff.name,staff.staffID,day_pay.number FROM day_pay,staff WHERE day_pay.proID=? AND day_pay.bookID=? AND day_pay.staffID = staff.staffID");
		result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);

		for (int i=0;i<num && result== SQLITE_OK;i++)
		{
			Json::Value one1;
			one1[CMD_DETAILMSG[EM_DETAIL_MSG_PROID]] = vProIDs[i].nID;
			one1[CMD_DETAILMSG[EM_DETAIL_MSG_NDEX]] = vProIDs[i].ndex;

			sqlite3_reset(stmt);
			sqlite3_bind_int(stmt,1,vProIDs[i].nID);
			sqlite3_bind_text(stmt,2,strBookID,-1,SQLITE_STATIC);

			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				Json::Value one2;
				const char* tmp = (char*)sqlite3_column_text(stmt, 0);
				one2[CMD_DETAILMSG[EM_DETAIL_MSG_NAME]] = g_Globle.UTF8ToEncode(tmp);
				one2[CMD_DETAILMSG[EM_DETAIL_MSG_IDCARD]] = (char*)sqlite3_column_text(stmt, 1);
				one2[CMD_DETAILMSG[EM_DETAIL_MSG_NUMBER]] = sqlite3_column_int(stmt, 2);
				one1[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one2);
			}
			root[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one1);
		}
		sqlite3_finalize(stmt);
		sqlite3_exec(m_sqlite, "commit transaction", 0, 0, NULL);
#endif
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool CDbData::GetStaffWrite(Json::Value& js,CString strBookID,int proID)
{
	double number = 0;
	bool bRet = false;
	
	USES_CONVERSION;
	try
	{
		m_sql.Format("SELECT number FROM progress WHERE proID='%d' AND bookID='%s'",proID,strBookID);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			bRet = true;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
			    number = sqlite3_column_double(stmt, 0);
			}
			js[CMD_RetType[EM_CMD_RETYPE_VALUE]] = number;
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
		bRet = false;
	}
	return bRet;
}

bool CDbData::_GetProgress(Json::Value& js,Json::Value root, CString strBookID)
{
	//先获取印数，和令数
	USES_CONVERSION;
	try
	{
		
		USES_CONVERSION;
		m_sql.Format("SELECT ys,ls FROM book WHERE book.bookID =  '%s'",strBookID);
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);
		if (result == SQLITE_OK)
		{
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				js[CMD_PROGRESSMSG[EM_PROGRESSMSG_YS]] = sqlite3_column_int(stmt,0);
				js[CMD_PROGRESSMSG[EM_PROGRESSMSG_LS]] = sqlite3_column_double(stmt,1);
			}
		}
		sqlite3_finalize(stmt);
	}
	catch (...)
	{
	}

	Json::Value jss=root[CMD_RetType[EM_CMD_RETYPE_VALUE]];
	if (jss.isArray())
	{
		int nSize = jss.size();

#if 0
		for (int i=0;i<nSize;i++)
		{
			
			USES_CONVERSION;
			try
			{
				double number=0;
				Json::Value one;

				int proID = jss[i][CMD_GETPROGRESS[EM_GETPROGRESS_PROID]].asInt();
				int ndex = jss[i][CMD_GETPROGRESS[EM_GETPROGRESS_INDEX]].asInt();
				sprintf(sql, "SELECT number FROM progress WHERE proID='%d' AND bookID='%s'",proID,strBookID);
				sqlite3_stmt *stmt = NULL;
				int result = sqlite3_prepare_v2(m_sqlite, sql, -1, &stmt, NULL);
				if (result == SQLITE_OK)
				{
					while (sqlite3_step(stmt) == SQLITE_ROW)
					{
						number = sqlite3_column_double(stmt, 0);
					}
				}
				else
					return false;

				one[CMD_PROGRESSMSG[EM_PROGRESSMSG_NDEX]] = ndex;
				one[CMD_PROGRESSMSG[EM_PROGRESSMSG_NUMBER]] = number;
				js[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
				sqlite3_finalize(stmt);
			}
			catch (...)
			{
				return false;
			}
		}
#else
		
		sqlite3_exec(m_sqlite, "begin transaction", 0, 0, NULL);
		m_sql.Format("SELECT number FROM progress WHERE proID=? AND bookID=?");
		sqlite3_stmt *stmt = NULL;
		int result = sqlite3_prepare_v2(m_sqlite, m_sql, -1, &stmt, NULL);

		for (int i=0;i<nSize && result== SQLITE_OK;i++)
		{
			double number=0;
			Json::Value one;

			int proID = jss[i][CMD_GETPROGRESS[EM_GETPROGRESS_PROID]].asInt();
			int ndex = jss[i][CMD_GETPROGRESS[EM_GETPROGRESS_INDEX]].asInt();

			sqlite3_reset(stmt);
			sqlite3_bind_int(stmt,1,proID);
			sqlite3_bind_text(stmt,2,strBookID,-1,SQLITE_STATIC);

			if (sqlite3_step(stmt) == SQLITE_ROW)
				number = sqlite3_column_double(stmt, 0);

			one[CMD_PROGRESSMSG[EM_PROGRESSMSG_NDEX]] = ndex;
			one[CMD_PROGRESSMSG[EM_PROGRESSMSG_NUMBER]] = number;
			js[CMD_RetType[EM_CMD_RETYPE_VALUE]].append(one);
			
		}
		sqlite3_finalize(stmt);
		sqlite3_exec(m_sqlite, "commit transaction", 0, 0, NULL);
#endif
	}
	return true;
}