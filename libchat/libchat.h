#pragma once

#include "libhole.h"
#include <stdint.h>
#include "tinyxml.h"
#include <vector>
#include <string>

#ifdef _DEBUG
#define LCLOG(...) lclog("[DEBUG] ", __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__);
#define LCERR(...) lclog("[ERROR] ", __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__);
#define ISLOG 1
#else
#define LCLOG(...)
#define LCERR(...)
#define ISLOG 0
#endif

void lclog(const char * header, const char * file, const char * func, int pos, const char *fmt, ...);

#include "configloader.h"

// ��ʼ��
bool lc_ini();

// �˳�
bool lc_fini();

// ��ȡ���ص�ַ
std::string lc_get_mac();

// ����guid
std::string lc_newguid(std::string param);

// MD5
std::string lc_md5(const char * str, size_t len);

// ��ȡ����
uint32_t lc_getmstick();

// �����û�
void lc_newuser(std::string name, std::string pwd);

// ���P2P��ȡ��������ַ
bool lc_chekcp2p();

// StunAddress4ת��
std::string lc_get_stunaddr_ip(StunAddress4 addr);

// ����˿�
int lc_randport();
