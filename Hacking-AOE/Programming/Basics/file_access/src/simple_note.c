#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
// defines requests are arguments like flag descriptor flags etc

#include <unistd.h>
//The <sys/stat. h> header defines the structure of the data returned by the functions fstat(), lstat(), and stat(). File serial number and device ID taken together uniquely identify the file within the system.

void usage(char* prog_name, char* filename)
{
    printf("Usage : %s < data to add to %s >\n", prog_name, filename);
    exit(0);
}

void fatal(char*);
void *ec_malloc(unsigned int);

int main(int argc, char** argv)
{
    int fd; // FILE DESCRIPTOR
    char* buffer;
    char* datafile;
    buffer = (char* ) ec_malloc(100);
    datafile = (char* ) ec_malloc(20);
    strcpy(datafile, "/tmp/notes");

    if (argc < 2)
    {
        usage(argv[0] , datafile);
    }
    strcpy(buffer, argv[1]);
    printf("[DEBUG] at %p, we have \' %s \' \n", buffer,buffer);
    printf("[DEBUG] at %p, we have \' %s \' \n", datafile,datafile);

    strncat(buffer,"\n",1);

    // FILE ACCESS
    fd = open(datafile, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR|S_IWUSR);
    if (fd == -1)
    {
        fatal("in main() while opening file!\n");
    }
    printf("the file descriptor is %d\n", fd);
    //WRITING DATA
    if (write(fd, buffer, strlen(buffer)) == -1)
    {
        fatal("in main() while writing to file!\n");
    }
    // CLOSING FILE
    if (close(fd) == -1)
    {
        fatal("in main() while closing file!\n");
    }

    // MEM DEALLOC
    free(buffer);
    free(datafile);
    return 0;
}

void fatal(char* msg)
{
    char error_message[100];
    strcpy(error_message, "[!!] Fatal error ");
    strncat(error_message, msg, 83); // beware of buffer injection here !!!
    perror(error_message);
    exit(-1);
}

void *ec_malloc(unsigned int size)
{
    void* ptr;
    ptr = malloc(size);
    if (ptr == NULL)
    {
        fatal("in ec_malloc() during MEMALLOC!\n");
    }
    return ptr;

}
