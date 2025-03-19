/* create API was used in earlier UNIX implementations. now it is obsolete because 
open() is more feature rich providing finer control to the user */

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

int main()
{
        mode_t access_mode = S_IRUSR | S_IWUSR;
        int fd = creat("created_file.txt", access_mode);
        printf("file descriptor = %d\n", fd);
        if (fd == -1) /* file creation failed */
                printf("errno = %d\n", errno);

        return 0;
}
