#include <bits/stdc++.h>
#include <unistd.h>
#include "cserver_conf.h"
#include "cserver_global.h"
#include "cserver_memery.h"
#include "cserver_proc.h"
#include "cserver_core.h"

static void moveArgv()
{
    for (int i = 0; i < g_os_argc; i++ ) {
        g_arg_len += strlen(g_os_argv[i]) + 1;
    }
    char *new_argv = new char[g_arg_len];
    char *ptmp = new_argv;
    for (int i = 0; i < g_os_argc; i++ ) {
        int size = strlen(g_os_argv[i]) + 1;
        strcpy(ptmp, g_os_argv[i]);
        ptmp += size;
    }
    g_os_argv = (char **)new_argv;
}

static void moveGlobalEnviron()
{
    for (int i = 0; environ[i]; i++ ) {
        g_env_len += strlen(environ[i]) + 1;
    }
    char *new_env_mem = new char[g_env_len];
    char *ptmp = new_env_mem;
    for (int i = 0; environ[i]; i++) {
        size_t size = strlen(environ[i]) + 1;
        strcpy(ptmp, environ[i]);
        environ[i] = ptmp;
        ptmp += size;
    }
}

static void test_base_func()
{
    ServerConf* serverConf = ServerConf::getInstance();
    std::cout << serverConf->showAllConf() << std::endl;
    DEBUG_LOG("test log");
}

ServerConf* g_serverConf = nullptr;

CMemeryPools* g_memeryPools = nullptr;

CServer* g_cserver = nullptr;

int g_os_argc = 0;
int g_arg_len = 0;
char **g_os_argv = nullptr;
char **g_os_old_argv = nullptr;

int g_env_len = 0;
char **g_env_mem = nullptr;


int main(int argc, char *const *argv)
{
    do {
        // 加载全局单例配置加载文件对象
        g_serverConf = ServerConf::getInstance();
        if (g_serverConf == nullptr) {
            CORE_ERR_LOG("config load fail");
            break;
        }
        INFO_LOG("core config init success");

        // 内存池，暂未实现
        g_memeryPools = CMemeryPools::getInstance();
        if (g_memeryPools == nullptr) {
            CORE_ERR_LOG("memery pools load fail");
            break;
        }
        INFO_LOG("memery pools init success");

        // 使当前进程成为守护进程
        int ret_deamon = init_deamon();
        if (ret_deamon == 1) {
            break;
        } else if(ret_deamon == -1) {
            ERR_LOG("init_deamon() fail exit()");
            break;
        }
        
        // 进程变量迁移，设置进程标题
        g_os_argc = argc;
        g_os_argv = (char**) argv;
        g_os_old_argv = (char**) argv;
        moveArgv();
        moveGlobalEnviron();
        setproctitle(argv, SERVER_MASTER);

        g_cserver = new CServer();
        if (g_cserver == nullptr) {
            CORE_ERR_LOG("server init fail");
            break;
        }
        g_cserver->pid  = getpid();
        g_cserver->ppid = getppid();
        g_cserver->stop = false;
        mainWorkProcessLoops();

    } while (false);

    return 0;
}
