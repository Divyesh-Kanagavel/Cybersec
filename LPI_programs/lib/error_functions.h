#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

void errMsg(const char* format, ...); /* args : format string and variable arguments */

#ifdef __GNUC__
/* putting in these macros make sure the compiling the programs with gcc -Wall
 * do not throw the non-return warning for non-void return functions. if there is an early exit from non-void functions like main and there is no returnStatus, the compiler understands that NORETURN has been defined for error handling functions */
#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void errExit(const char *format, ...) NORETURN;
void err_exit(const char *format, ...) NORETURN;
void errExitEN(int errnum, const char *format, ...) NORETURN ;
void fatal(const char *format, ...) NORETURN ;
void usageErr(const char *format, ...) NORETURN ;
void cmdLineErr(const char *format, ...) NORETURN ;




#endif

