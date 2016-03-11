#pragma once

#include "libhole.h"
#include <stdint.h>
#include "tinyxml.h"
#include <vector>
#include <string>
#include <deque> 
#include <algorithm> 

#ifdef _DEBUG
#define LCLOG(...) lclog("[DEBUG] ", __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__);
#define LCERR(...) lclog("[ERROR] ", __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__);
#define ISLOG 1
#else
#define LCLOG(...)
#define LCERR(...)
#define ISLOG 0
#endif

// ��Ϣ����󳤶�
#define LC_MAX_MSG_LEN 512

// des buff
#define LC_DES_BUFF_LEN 8

// RPC��ʱʱ��
#define LC_MAX_RPC_TIME 10

// ͬ����Ϣ���ͼ��ʱ��
#define LC_SYNC_TIME 60

// ���������ͼ��ʱ��
#define LC_HB_TIME 1

// ��Ϣ���ط����ʱ��
#define LC_RESEND_TIME 1

typedef void(*lc_on_recv_chat)(const char * acc, const char * words);

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
int lc_randtryport();

// 16����ת��
int lc_atoi16(const std::string & str);
std::string lc_itoa16(uint32_t number);

// des
std::string lc_des(const std::string & strkey, const std::string & s_text);
std::string lc_undes(const std::string & strkey, const std::string & s_text);

// sleep
void lc_sleep(int32_t millionseconds);

// token
std::vector<std::string> lc_token(const std::string & str, const std::string & token);

// combine
std::string lc_combine(const std::vector<std::string> & strvec, const std::string & token);

// ������Ϣ
std::string lc_send(const std::string & ip, int port, const std::string & msg);

// �ظ���Ϣ
void lc_resp(const std::string & ip, int port, const std::string & msgid, const std::string & msg);

// ����udp��Ϣ
void lc_send_udp(const std::string & ip, int port, const std::string & msg);

// ������Ϣ
bool lc_recv(const std::string & msgid, std::string & ret);

// ������Ϣ
std::string lc_rpc(const std::string & ip, int port, const std::string & cmd, const std::string & msg);

// ������Ϣ
void lc_process();

// ��Ϣ�ص�
void lc_msg_process(const std::string & ip, int port, const std::string & msg);

// ��ȡ����
CConfigLoader::STConfig::STFriendList::STFriend lc_get_friend(const std::string & acc);
void lc_set_friend(const CConfigLoader::STConfig::STFriendList::STFriend & f);
bool lc_is_friend(const std::string & acc);
CConfigLoader::STConfig::STFriendList::STFriend lc_get_friend_by_name(const std::string & name);
void lc_set_friend_skey(const std::string & acc, const std::string & key);

// ���ɺ���֮���key
std::string lc_make_friend_key(const std::string & acc);

// �����������
bool lc_rpc_add(const std::string & ip, int port, const std::string & acc, const std::string & key);
void lc_on_rpc_add(const std::string & ip, int port, const std::string & msgid, const std::string & msg);

// ����
bool lc_rpc_chat(const std::string & ip, int port, const std::string & acc, const std::string & words);
void lc_on_rpc_chat(const std::string & ip, int port, const std::string & msgid, const std::string & msg);

// ��������ص�
void lc_set_chat_cb(lc_on_recv_chat cb);

// ͬ����Ϣ
void lc_send_sync(const std::string & ip, int port, const std::string & acc);
void lc_recv_sync(const std::string & ip, int port, const std::string & msg);
