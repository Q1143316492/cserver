#ifndef _CSERVER_FUNC_BASE_H_
#define _CSERVER_FUNC_BASE_H_

#include <bits/stdc++.h>
#include <stdarg.h>
#include "cserver_macro.h"
#include "cserver_easy_tools.h"

// logs

void print_log(const char* file, const char* func, int line, const char* level, const char* fmt, ...);

void write_log_to_file(const char* file, const char* func, int line, const char* level, const char* buf);

#endif