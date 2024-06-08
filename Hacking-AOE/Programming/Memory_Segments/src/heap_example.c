#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HEAP MEMORY ALLOCATION AND DEALLOCATION
int main(int argc, char** argv)
{
    int mem_size;
    int* int_ptr;
    char* char_ptr;

    if (argc < 2)
    {
        mem_size = 50; //DEFAULT SIZE
    }
    else
    {
        mem_size = atoi(argv[1]);
    }

    // ALLOCATING MEMORY TO CHAR_PTR
    char_ptr = (char*) malloc(mem_size * sizeof(char));
    if (char_ptr == NULL)
    {
        fprintf(stderr, "Eror : could not allocate heap memory!\n");
        exit(-1);
    }
    printf("\t[+] allocating memory at %p for char_ptr of size %d\n", char_ptr, mem_size);
    strcpy(char_ptr, "Memory!");

    // ALLOCATING MEMORY TO INT_PTR
    int_ptr = (int*) malloc(12 * sizeof(int));
    if (int_ptr == NULL)
    {
        fprintf(stderr, "Error : could not allocate heap memory!\n");
        exit(-1);
    }
    *int_ptr = 31337;
    printf("\t[+] allocating memory at %p for int_ptr and value is %d\n", int_ptr, *int_ptr);

    printf("\t[-] freeing char_ptr's heap memory...\n");
    free(char_ptr);
    printf("\t[-] freeing int_ptr's heap memory...\n");
    free(int_ptr);

    char* ptr = (char*) malloc(15 * sizeof(char));
    if (ptr == NULL)
    {
        fprintf(stderr, "Error : could not allocate heap memory!\n");
        exit(-1);
    }
    strcpy(ptr, "new memory");
    printf("\t[+] reallocating another 15 bytes for char_ptr\n");
    printf("char_ptr (%p) --> '%s'\n", ptr, ptr);

    // FREE MEMORY
    printf("\t[-] freeing char_ptr's heap memory...\n");
    free(ptr);

    return 0;
    
}