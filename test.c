#include <stdio.h>

int main(int argc, char *argv[])
{
    char binary[32];
    int byte = 0;
    int tmp = 127;
    int i;

    for (i = 0; i < 32; i++) 
    {
        binary[i] = (tmp>>i)&&1;
    }

 
    for (i = 0; i < 4; i++) 
    {
        printf("%d",binary[byte+i]);
    }

    printf("\n");

    return 0;
}
