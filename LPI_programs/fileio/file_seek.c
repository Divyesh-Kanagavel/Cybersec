#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctypes.h>
#include <stdio.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
        size_t len;
        off_t offset;
        char* buf;
        int ap, j, fd;
        ssize_t numRead, numWritten;

        /* check if correct number of arguments are passed / --help is asked */
        if ((argc < 3) || (strcmp(argv[1], "--help")==0))
        {
            usageErr("%s file : {r<length>|R<length>|w<str>|s<offset>}...\n", argv[1]);
        }
        fd = open(argv[1], O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH) /*rw-rw-rw*/
        if (fd==-1)
        {
                errExit("open");
        }

        

        return 0;
}
