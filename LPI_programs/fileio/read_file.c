#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

#define MAX_READ 20
char buffer[MAX_READ+1];

int main()
{
    mode_t filemode = S_IRUSR | S_IWUSR;
    int fd = open("created_file.txt", O_RDONLY, filemode);
    ssize_t bytes_read = read(fd, buffer, MAX_READ);
    printf("bytes read = %ld\n", bytes_read);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    return 0;
}