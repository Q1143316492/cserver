#ifndef _CSERVER_SOCKET_H_
#define _CSERVER_SOCKET_H_

#include <bits/stdc++.h>

#include "cserver_conf.h"
#include "cserver_global.h"
#include "cserver_easy_tools.h"

class CSocket {
public:
    bool init_server();

    bool cserver_listen(std::vector<std::string> ports);
private:

};

#endif