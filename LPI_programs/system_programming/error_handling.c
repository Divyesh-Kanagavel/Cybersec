#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
int main()
{

                errno = 0; // to reset errno value set due to previous syscalls 
		int fd = open("", O_RDONLY);
		// ideal way to handle errors
		if (fd == -1) // failure in file opening
	           {
			   printf("errno = %d\n", errno);
			   perror("opening file");
			   exit(EXIT_FAILURE);
		   }
		return 0;
}
