/*Functions for parsing numeric command line arguments */
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>

#include "get_num.h"

static void gnFail(const char* fname, const char* msg, const char* arg,
                    const char* name)
{
    fprintf(stderr, "%s error", fname);
    if (name!=NULL)
        fprintf(stderr, "(in %s)", name);
    fprintf(stderr, " : %s\n", msg);
    if (arg!=NULL && *arg!='\0')
        fprintf(stderr, "       offending text : %s\n",arg);

    exit(EXIT_FAILURE);
}

static long getNum(const char* fname, const char* arg, int flags, const char* name)
{
    long res;
    char* endptr;
    int base;
    
    if ((arg == NULL) || (*arg=='\0'))
    {
        gnFail(fname, "null or empty string", arg, name);
    }
    base = (flags & GN_ANY_BASE) ? 0 : (flags & GN_BASE_8) ? 8 : (flags & GN_BASE_16) ? 16 : 10;
    errno = 0;
    res = strtol(arg, &endptr, base);
    if (*endptr!='\0')
        gnFail(fname, "non-numeric characters",arg, name);
    if ((flags & GN_NONNEG) && res < 0)
    {
        gnFail(fname, "negative value not allowed!", arg, name);
    }
    if ((flags & GN_GT_O) && res <= 0)
        gnFail(fname , "value must be > 0", arg, name);
    return res;
}

long getLong(const char* arg, int flags, const char* name)
{
    return getNum("getLong", arg, flags, name);
}

int getInt(const char* arg, int flags, const char* name)
{
    long res;
    res = getNum("getInt", arg, flags, name);
    if (res > INT_MAX || res < INT_MIN)
        gnFail("getInt", "integer out of range", arg, name);
    return (int) res;
}
