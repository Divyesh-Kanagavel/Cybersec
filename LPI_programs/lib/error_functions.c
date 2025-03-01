#include <stdarg.h> // for variable argument lists
#include "error_functions.h"
#include "tlpi_hdr.h"
#include "ename.c.inc" // contains error name ENUMS

#ifdef __GNUC__
__attribute__ ((noreturn))
#endif

static void terminate(Boolean useExit3)
{
    char *s;
    /*Dump core if EF_DUMPCORE is defined and return a non empty string
      otherwise call exit() or _exit() depending on the boolean value useExit3 */
    s = getenv("EF_DUMPCORE");
    if ((s!=NULL) && (*s!='\0'))
        abort();
    else if (useExit3)
        exit(EXIT_FAILURE);
    else
        _exit(EXIT_FAILURE);
}

static void outputError(Boolean useErr, int err,
                         Boolean flushStdOut, const char* format, va_list ap)
{
    #define BUFSIZE 500
    char buf[BUFSIZE], usrMsg[BUFSIZE], errText[BUFSIZE];
    vsnprintf(usrMsg, BUFSIZE, format, ap);

    if (useErr)
    {
        snprintf(errText, BUFSIZE, "[%s %s]",(err > 0 && err <= MAX_ENAME) ?
                                             ename[err] : "?UNKNOWN?", 
                                             strerror(err));
    }
    else
    {
        snprintf(errText, BUFSIZE, ":");
    }

    snprintf(buf, BUFSIZE, "ERROR%s %s\n", errText, usrMsg);

    if (flushStdOut)
    {
        fflush(stdout);
    }
    fputs(buf, stderr);
    fflush(stderr);

}
// flush the errorMsg to stderr
void errMsg(const char* format, ...)
{
    va_list argList;
    int savedErrno;
    savedErrno = errno;
    va_start(argList, format);
    outputError(TRUE, errno, TRUE, format, argList);
    va_end(argList);
    errno = savedErrno;
}
// to terminate the process after flushing error message to stderr
void errExit(const char *format, ...)
{
	va_list argList;
	va_start(argList, format);
	outputError(TRUE, errno, TRUE, format, argList);
	va_end(argList);
	terminate(TRUE);
}
// to terminate the process without flushing the stdout buffer
void err_exit(const char* format, ...)
{
	va_list argList;
	va_start(argList, format);
	outputError(TRUE, errno, FALSE, format, argList);
	va_end(argList);
	terminate(FALSE);
}

// to terminate using a err number instead of the global errno
// useful in certain cases like POSIX thread, where errno is not used generally
// due to it being generated from a function MACRO

void errExitEN(int errnum, const char* format, ...)
{
	va_list argList;
	va_start(argList, format);
	outputError(TRUE, errnum, TRUE, format, argList);
	va_end(argList);
	terminate(TRUE);
}

void fatal(const char *format, ...)
{
	va_list argList;
	va_start(argList, format);
	outputError(FALSE, 0, TRUE, format, argList);
	va_end(argList);
	terminate(TRUE); 
}



void usageErr(const char* format, ...)
{
	va_list argList;
    fflush(stdout); /*flush out pending stdout*/
    fprintf(stderr, "Usage : ");
    va_start(argList, format);
    vfprintf(stderr, format, argList);
    va_end(argList);
    fflush(stderr);
    exit(EXIT_FAILURE);
}

void cmdLineErr(const char* format, ...)
{
    va_list argList;
    fflush(stdout);
    fprintf(stderr, "Command line usage error : ");
    va_start(argList, format);
    vfprintf(stderr, format, argList);
    va_end(argList);
    fflush(stderr);
    exit(EXIT_FAILURE);
}



