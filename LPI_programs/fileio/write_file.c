/* write a file from C using the appropriate wrapper function for sys call */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define BUF_SIZE 20

int main()
{
    char buffer[BUF_SIZE];
    int fd = open("write_file.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    strncpy(buffer, "Hello world!\n", 13);
    ssize_t num_bytes_written = write(fd, buffer, 13);
    printf("%ld\n", num_bytes_written);
    if (close(fd) == -1)
        exit(1);
    return 0;

}