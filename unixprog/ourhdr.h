#ifndef __ourhdr_h
#define __ourhdr_h

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void Sigfunc(int); //for signal handler
 

void err_ret (const char *fmt, ...);
void err_sys(const char *fmt, ...);
#endif /*__ourhdr_h*/
