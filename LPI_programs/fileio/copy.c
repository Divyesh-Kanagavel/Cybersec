#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/tlpi_hdr.h"

#ifndef BUF_SIZE 
#define BUF_SIZE 1024
#endif

int 
main
(
int argc, 
char** argv
)
{
    int inputFd, outputFd, openFlags;
    mode_t file_perms; // file permissions
    ssize_t numread;
    char buf[BUF_SIZE];

    if (argc != 3 || strcmp(argv[1], "--help")==0)
        usageErr("%s old-file - new-file\n", argv[0]);
    inputFd = open(argv[1], O_RDONLY);
    if (inputFd == -1)
        errExit("opening file %s", argv[1]);

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    outputFd = open(argv[2], openFlags, file_perms);

    /* transfer bytes of data from input file to output file */
    /* numread could be BUF_SIZE or something smaller , the while loop keeps running till we EOF is encountered and numread bytes are copied to output file*/
    while((numread = read(inputFd, buf, BUF_SIZE)) > 0)
    {
        if ((write(outputFd, buf, numread)!=numread))
            fatal("could not write buffer");

    }
    if (numread == -1)
        errExit("read");
    if (close(inputFd) == -1)
        errExit("close input file");
    if (close(outputFd) == -1)
        errExit("close output file");

    exit(EXIT_SUCCESS);
}
