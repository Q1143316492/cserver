#ifndef _CSERVER_GLOBAL_H_
#define _CSERVER_GLOBAL_H_

class ServerConf;
class CMemeryPools;
class CServer;
class CSocket;

extern ServerConf* g_serverConf;

extern CMemeryPools* g_memeryPools;

extern CServer* g_cserver;

extern CSocket* g_csocket;

extern int  g_os_argc;
extern int  g_arg_len;
extern char **g_os_argv;
extern char **g_os_old_argv;

extern int  g_env_len;
extern char **g_env_mem;

#endif