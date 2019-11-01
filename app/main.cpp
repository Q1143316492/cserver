#include <bits/stdc++.h>
#include <unistd.h>
#include "cserver_conf.h"
#include "cserver_global.h"
#include "cserver_proc.h"

static void test_base_func()
{
    // ServerConf* serverConf = ServerConf::getInstance();
    // std::cout << serverConf->showAllConf() << std::endl;
    // DEBUG_LOG("test log");
}

int main()
{
    do {
        // 加载全局单例配置加载文件对象
        g_serverConf = ServerConf::getInstance();
        if (g_serverConf == nullptr) {
            CORE_ERR_LOG("config load fail");
            break;
        }

        // 使当前进程成为守护进程
        int ret_deamon = init_deamon();
        if (ret_deamon == 1) {
            INFO_LOG("father process exit");
            break;
        } else if(ret_deamon == -1) {
            ERR_LOG("init_deamon() fail exit()");
            break;
        }
        INFO_LOG("after init_deamon() pid = %d ppid = %d", getpid(), getppid());

        

    } while (false);

    return 0;
}
