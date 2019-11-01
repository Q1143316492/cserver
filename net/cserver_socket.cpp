#include "cserver_socket.h"

bool CSocket::init_server()
{
    std::string strPort = g_serverConf->getStrConf("port");
    std::vector<std::string> vecPort = Tools::splitString(strPort, ';');
    if (vecPort.size() == 0) {
        WARN_LOG("without out port to listen in config");
        return false;
    }
    return cserver_listen(vecPort);
}

bool CSocket::cserver_listen(std::vector<std::string> ports)
{
    for (size_t i = 0; i < ports.size(); i++ ) {
        INFO_LOG("ports %s", ports[i].c_str());
    }
}