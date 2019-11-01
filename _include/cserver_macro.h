#ifndef _CSERVER_MACRO_H_
#define _CSERVER_MACRO_H_

#include "cserver_func_base.h"

// conf

#define DEFAULT_CONFKV_PATH "conf/core.conf"
#define MAX_CONF_LINE_SIZE  500

// log

#define DEFAULT_LOG_PATH "logs/"
#define MAX_LOG_MSG_SIZE 128

#define NO_BUG_LOG_CORE_ERR          5    //严重错误 【error】
#define NO_BUG_LOG_ERR               4    //错误 【error】
#define NO_BUG_LOG_WARN              3    //警告 【warn】
#define NO_BUG_LOG_NOTICE            2    //注意 【notice】
#define NO_BUG_LOG_INFO              1    //信息 【info】
#define NO_BUG_LOG_DEBUG             0    //调试 【debug】

#define STR_NO_BUG_LOG_CORE_ERR      "CORE_ERR"
#define STR_NO_BUG_LOG_ERR           "ERR"      //错误 【error】
#define STR_NO_BUG_LOG_WARN          "WARN"     //警告 【warn】
#define STR_NO_BUG_LOG_NOTICE        "NOTICE"   //注意 【notice】
#define STR_NO_BUG_LOG_INFO          "INFO"     //信息 【info】
#define STR_NO_BUG_LOG_DEBUG         "DEBUG"    //调试 【debug】

#define DEBUG_LOG(args...)      print_log(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_DEBUG    , args)
#define INFO_LOG(args...)       print_log(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_INFO     , args)
#define NOTICE_LOG(args...)     print_log(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_NOTICE   , args)
#define WARN_LOG(args...)       print_log(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_WARN     , args)
#define ERR_LOG(args...)        print_log(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_ERR      , args)
#define CORE_ERR_LOG(args...)   print_log(__FILE__, __FUNCTION__, __LINE__, STR_NO_BUG_LOG_CORE_ERR , args)

// proc

#define SERVER_MASTER "cserver_master"
#define SERVER_WORKER "cserver_worker"

// process type master or worker
#define PROC_TYPE_UNDEFINE  0
#define MASTER_PROCESS      1
#define WORKER_PROCESS      2


#endif