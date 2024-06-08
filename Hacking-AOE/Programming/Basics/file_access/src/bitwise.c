#include <stdio.h>
int main()
{
    int i, bit_a, bit_b;
    printf("BITWISE OPERATOR | \n");

    for (i=0;i<4;i++)
    {
        bit_a = (i & 2) / 2;
        bit_b = i & 1;
        printf("%d | %d = %d\n", bit_a, bit_b , bit_a | bit_b);
    }
    printf("\n");

    printf("BITWISE AND OPERATOR & \n");

    for (i=0;i<4;i++)
    {
        bit_a = (i & 2) / 2;
        bit_b = i & 1;
        printf("%d & %d = %d\n", bit_a,bit_b , bit_a & bit_b);
    }
    return 0;
     
}