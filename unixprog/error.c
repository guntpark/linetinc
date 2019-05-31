#include <errno.h>
#include <stdarg.h>
#include "ourhdr.h"

static void err_doit(int, const char*, va_list);

char *pname = NULL;
/*
 * Nonfatal error related to a system call
 * Print a message and return.
 */
void err_ret (const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    err_doit(1, fmt, ap);
    va_end(ap);
    return;
}
/*
 * Fatal error related to a system call
 * Print a message and terminate.
 */
void err_sys(const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    err_doit(1, fmt, ap);
    va_end(ap);
    exit(1);
}

/*
 * Fatal error related to a system call
 * Print a message, dumpcore, and terminate
 */ 
void err_dump (const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    err_doit(1, fmt, ap);
    va_end(ap);
    abort(); //dump core and terminate
    exit(1); 
}

/*
 * Nonfatal error related to a system call
 * Print a message and return.
 */
void err_msg (const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    err_doit(0, fmt, ap);
    va_end (ap);
    return;
}

/*
 * Fatal error unrelated to a system call
 * Print a message, dumpcore, and terminate
 */ 
void err_quit (const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    err_doit(0, fmt, ap);
    va_end(ap);
    exit(1); 
}

static void 
err_doit(int errnoflag, const char *fmt, va_list ap)
{
    int errno_save;
    char buf[MAXLINE];

    errno_save = errno;
    vsprintf(buf, fmt, ap);
    
    if(errnoflag)
        sprintf(buf+strlen(buf), ": %s", strerror(errno_save));
    
    strcat(buf, "\n");
    
    fflush(stdout);
    
    fputs(buf, stderr);
    
    fflush(NULL);
    
    return;
}















