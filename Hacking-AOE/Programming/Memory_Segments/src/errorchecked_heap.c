#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* errorchecked_malloc(unsigned int size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        fprintf(stderr, "ERROR:could not allocate required memory!\n");
        exit(-1);
    }
    return ptr;
}

int main()
{
    int mem_size = 50;
    // MEM ALLOC
    char* char_ptr = (char*) errorchecked_malloc(mem_size);
    printf("\t[+] allocating memory at %p for char_ptr of size %d\n", char_ptr, mem_size);
    strcpy(char_ptr, "error checked memory example!");
    printf("content at %p is %s\n", char_ptr, char_ptr);

    // MEM DEALLOC
    free(char_ptr);
    printf("\t[-] memory freed!\n");
    return 0;
}
