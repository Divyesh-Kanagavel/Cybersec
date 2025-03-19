/*the kernel keeps track of the current position at the file available through its descriptor
through lseek you can move to different locations through an offset argument and from a given location
given by the whence argument. SEEK_CUR, SEEK_SET, SEEK_END. */

/*cannot apply lseek to all types of files . terminals, pipes, FIFOs, sockets are not permitted
and return error with errno set to ESPIPE. */

#include <sys/stat.h>


