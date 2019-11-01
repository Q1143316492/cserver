#ifndef _CSERVER_FUNC_BASE_H_
#define _CSERVER_FUNC_BASE_H_

#include "cserver_macro.h"
// logs

void print_log(const char*file, const char* func, int line, const char* level, const char* fmt, ...);

void write_log_to_file(const char*file, const char* func, int line, const char* level, const char* buf);

#endif