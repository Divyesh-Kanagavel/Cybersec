#ifndef LDRI_HDR_H
#define LDRI_HDR_H

#include <sys/types.h> /* Type definition used by many programs */
#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Prototypes of commonly used library functions */
#include <unistd.h> /* prototypes for many system calls */
#include <errno.h> /* Declares errno and many error constants */
#include <string.h> /* string manipulation library */

#include "get_num.h"
#include "error_functions.h"

typedef enum {FALSE, TRUE} Boolean;

#define min(m,n) ((m) < (n) ? (m) : (n))
#define max(m,n) ((m) > (n) ? (m) : (n))




#endif
