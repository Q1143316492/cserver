#include <bits/stdc++.h>
#include "cserver_conf.h"
#include "cserver_global.h"

int main()
{
    do {
        ServerConf* serverConf = ServerConf::getInstance();
        std::cout << serverConf->showAllConf() << std::endl;

    } while (false);

    return 0;
}
