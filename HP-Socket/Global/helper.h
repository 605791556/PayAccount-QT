#pragma once

#include <string>
#include "SocketInterface.h"

using std::string;

#define USER_INFO_MSG			(WM_USER + 100)
#define MAX_LOG_RECORD_LENGTH	1000

enum LINK_TYPE
{
	LINK_TYPE_CLIENT,//客户端连接
	LINK_TYPE_DOG,//看门狗
	LINK_TYPE_UNKNOW,//陌生连接
	LINK_TYPE_MAX
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

	std::string user;
	std::string name;
	int  nPort;
	LINK_TYPE em_LinkType;

	TPkgInfo(bool header = true, int len = sizeof(TPkgHeader)) : is_header(header), length(len) {}
	void Reset() {is_header = true, length = sizeof(TPkgHeader);}
	~TPkgInfo() {}
};