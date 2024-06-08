#include <stdio.h>
#include <stdlib.h>
int global_var;
int global_var_init = 4;

void function()
{
    int stack_var;
    printf("The address of stack_var in function() is %p\n", &stack_var);
}

int main()
{
    int stack_var;
    static int static_var;
    static int static_var_init = 5;

    int *heap_var = (int *) malloc(6);
    // data segment
    printf("the address of static_var_init is %p\n", &static_var_init);
    printf("the address of global_var_init is %p\n", &global_var_init);

    // bss segment
    printf("the address of static_var is %p\n", &static_var);
    printf("the address of global_var is %p\n", &global_var);

    // heap segment
    printf("The address of heap_var is %p\n", heap_var);

    //stack segment
    printf("The address of stack_var in main() is %p\n", &stack_var);
    function();
    return 0;
}