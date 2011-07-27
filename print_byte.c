#include <stdio.h>
#include <stdlib.h>

int get_binary(int test, int start, int end);
void print_binary(int num);

int main(int argc, const char *argv[])
{
    if(argc!=4)
    {
        printf("input error,please intput four number");
    }

    int test = atoi(argv[1]);
    int start = atoi(argv[2]);
    int end = atoi(argv[3]);

    print_binary(get_binary(test,start,end));
    return 0;
}

int get_binary(int test, int start, int end)
{
    int mask = 0;

    return ((test>>start)&((~mask)>>(32-end)));
}

void print_binary(int num)
{
     int binary[32];
     int i;
    
    for (i = 0; i < 32; i++) 
    {
        binary[i] =(num >> i) & 1;
    }

    for (i = 0; i < 4; i++) 
    {
        printf("%d",binary[i]);
    }

    printf("\n");
}






