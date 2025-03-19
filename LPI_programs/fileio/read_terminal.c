/*read contents from terminal using the same system calls used to read from files */
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_READ 20
char buffer[MAX_READ+1];
/*bytes_read always contains one byte extra when you type in the terminal because newline is also
included*/
int main()
{
    mode_t filemode = S_IRUSR;
    ssize_t bytes_read = read(STDIN_FILENO, buffer, MAX_READ);
    printf("bytes read = %ld\n", bytes_read);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    return 0;
}