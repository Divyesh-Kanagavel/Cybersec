#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib/tlpi_hdr.h"
int main()
{
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        errExit("open");
    /*by default, the open system call assigns the lowest unassigned 
      file descriptor */
    printf("%d\n", fd);
    return 0;
}
