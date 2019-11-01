#ifndef _CSERVER_MACRO_H_
#define _CSERVER_MACRO_H_

// conf

#define DEFAULT_CONFKV_PATH "conf/core.conf"
#define MAX_CONF_LINE_SIZE  500

// log

#define DEFAULT_LOG_PATH "log/"
#define MAX_LOG_MSG_SIZE 128

#define DEBUG_LOG(args...)      g_log->printLog(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_DEBUG    , args)
#define INFO_LOG(args...)       g_log->printLog(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_INFO     , args)
#define NOTICE_LOG(args...)     g_log->printLog(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_NOTICE   , args)
#define WARN_LOG(args...)       g_log->printLog(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_WARN     , args)
#define ERR_LOG(args...)        g_log->printLog(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_ERR      , args)
#define CORE_ERR_LOG(args...)   g_log->printLog(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_CORE_ERR , args)




#endif