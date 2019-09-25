#pragma once
#include <QObject>
#include "SocketInterface.h"

#define USER_INFO_MSG			(WM_USER + 100)
#define MAX_LOG_RECORD_LENGTH	1000

enum LINK_TYPE
{
	LINK_TYPE_CLIENT,//客户端连接
	LINK_TYPE_DOG,//看门狗
	LINK_TYPE_UNKNOW,//陌生连接
	LINK_TYPE_MAX
};

struct info_msg
{
	LPCTSTR name;
	CONNID connID;
	LPCTSTR evt;
	int contentLength;
	LPCTSTR content;

	static info_msg* Construct(CONNID dwConnID, LPCTSTR lpszEvent, int iContentLength = 0, LPCTSTR lpszContent = nullptr, LPCTSTR lpszName = nullptr);
	static void Destruct(info_msg* pMsg);

private:
	info_msg(CONNID dwConnID, LPCTSTR lpszEvent, int iContentLength = 0, LPCTSTR lpszContent = nullptr, LPCTSTR lpszName = nullptr);
	~info_msg();
};

struct TPkgHeader 
{
	DWORD seq;
	LINK_TYPE em_LinkType;
	int body_len;

	TPkgHeader()
	{
		em_LinkType = LINK_TYPE_UNKNOW;
	}
};

struct TPkgBody 
{
	char name[30];
	short age;
	char desc[1];
};

struct TPkgInfo
{
	bool is_header;
	int length;

	QString user;
	QString name;
	int  nPort;
	LINK_TYPE em_LinkType;

	TPkgInfo(bool header = true, int len = sizeof(TPkgHeader)) : is_header(header), length(len) {}
	void Reset() {is_header = true, length = sizeof(TPkgHeader);}
	~TPkgInfo() {}
};