#pragma once

#include "libhole.h"
#include <stdint.h>

// ��ʼ��
void lc_ini();

// ��ȡ���ص�ַ
std::string lc_get_mac();

// ����guid
std::string lc_newguid(std::string param);

// MD5
std::string lc_md5(const char * str, size_t len);

// ��ȡ����
uint32_t lc_getmstick();
