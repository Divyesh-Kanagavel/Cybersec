#ifndef GET_NUM_H
#define GET_NUM_H
/*we do not use built-in functions like atoi atol or strtol
 to perform some basic checking on numeric arguments!*/

#include "tlpi_hdr.h"

#define GN_NONNEG 01 // Value must be non-negative i.e val >= 0
#define GN_GT_O 02 // Value must be positive i.e val > 0

#define GN_ANY_BASE 0100 // By default integers are decimal, can use any base
#define GN_BASE_8 0200 // Value is expressed in octal
#define GN_BASE_16 0400 // Value is expressed in hexadecimal

int getInt(const char* arg, int flags, const char* name);

long getLong(const char* arg,int flags, const char* name);

#endif
