#ifndef _CSERVER_PROC_H_
#define _CSERVER_PROC_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "cserver_macro.h"
#include "cserver_global.h"

int init_deamon();

void setproctitle(char *const *argv, const char *title);

void mainWorkProcessLoops();

void fatherWorkProcessLoops();

void childWorkProcessLoops();

#endif