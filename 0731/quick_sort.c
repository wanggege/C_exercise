#include <stdio.h>
void quick_sort(int *array, int start, int end);

int main(int argc, const char *argv[])
{
    int i;
    int array[10] = {1,3,2,5,4,6,8,7,9,0};

    quick_sort(array, 0, 9);
    for(i=0; i<10; i++)
    {
        printf("%4d",array[i]);
    }
    putchar('\n');
    return 0;
}

void quick_sort(int *array, int start, int end)
{
    int i = start;
    int j = end;
    int tmp = 0;
    int mid = array[(start+end)/2];

    while(i<=j)
    {
        while((array[i]<mid)&&(i<end)) i++;
        while((array[j]>mid)&&(j>start)) j--;
        
        if(i<=j)
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }

    }

    if(i<end)
    {
        quick_sort(array,i,end);
    }

    if(j>start)
    {
        quick_sort(array,start,j);
    }
}
