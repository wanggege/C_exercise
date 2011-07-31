#include <stdio.h>

void delete_same(int *array, int len);

int main(int argc, const char *argv[])
{
    int i;
    int array[10] = {1,2,4,1,3,6,4,8,8,3};
    printf("source:");
    for (i = 0; i < 10; i++) 
    {
        printf("%4d",array[i]);
    }
    putchar('\n');

    delete_same(array,10);
    return 0;
}

void delete_same(int *array, int len)
{
    int i;
    int j;

    for (i = 0; i < len-1; i++) 
    {
        if(array[i]!=-1)
        {
            for (j = i+1; j < len; j++) 
            {
                if(array[i]==array[j])
                {
                    array[j] = -1;
                 
                }
            }
        }
    }

    printf("result:");
    for (i = 0; i < 10; i++) 
    {
        if(array[i]!=-1)
        {
            printf("%4d",array[i]);
        }
    }
    putchar('\n');
}
