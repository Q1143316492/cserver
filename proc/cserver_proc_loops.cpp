#include "cserver_proc.h"

void mainWorkProcessLoops()
{
    int proc_count = g_serverConf->getIntConf(CHILD_PROCESS_NUMBER);
    if (proc_count == ERROR_CONF_VALUE) {
        proc_count = 0;
    }
    if (proc_count < MIN_CHILD_PROC_LIMIT || proc_count > MAX_CHILD_PROC_LIMIT) {
        proc_count = 0;
    }
    INFO_LOG("father process pid = %d", getpid());
    for (size_t i = 1; i <= proc_count; i++ ) {
        int ret = fork();
        if (ret == -1) {
            ERR_LOG("mainWorkProcessLoops fork() fail");
        } else if (ret == 0) {
            // child
            setproctitle(g_os_old_argv, SERVER_WORKER);
            childWorkProcessLoops();
        } else {
            // father
            INFO_LOG("create child process pid = %d", ret);
            
        }
    }
    fatherWorkProcessLoops();
}

void fatherWorkProcessLoops()
{
    sleep(60);
    // while (true) ;
}

void childWorkProcessLoops()
{
    
}