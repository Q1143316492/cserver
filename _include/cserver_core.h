#ifndef _CSERVER_CORE_H_
#define _CSERVER_CORE_H_

#include "cserver_socket.h"

typedef struct CServer {
    CSocket *csocket;
    pid_t pid;
    pid_t ppid;
} CServer;

#endif