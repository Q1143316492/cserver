#ifndef _CSERVER_CORE_H_
#define _CSERVER_CORE_H_

class CSocket;

class CServer {
public:
    CSocket *csocket;
    bool  stop;
    pid_t pid;
    pid_t ppid;
};

typedef struct Connection {
    int fd;
    int port;
} Connection;

#endif