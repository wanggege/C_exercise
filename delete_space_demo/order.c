#include <stdio.h>

void order(int *array, int array_len);
int main(int argc, const char *argv[])
{
    int array[10] = {3,4,5,2,6,1,7,9,8,0};

    order(array, 10);
    return 0;
}

void order(int *array, int array_len)
{
    int i,j;
    int tmp;
    
    for (i = 0; i < array_len-1; i++) 
    {
         for (j = 0; j < (array_len-1-i); j++) 
         {
             if(array[j]>array[j+1])
             {
                 tmp = array[j];
                 array[j] = array[j+1];
                 array[j+1] = tmp;
             }
         }
    }

    for (i = 0; i < 10; i++) 
    {
        printf("%4d",array[i]);
    }

    putchar('\n');
}
