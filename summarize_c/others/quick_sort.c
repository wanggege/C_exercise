/*******************************************************
* sort.c - sort the int array from littler to bigger by using quick way
* author:wanggege
*2011-08-08
***************************************************/

#include <stdio.h>
#define MAX 10

void quick_sort(int *int_array, int start, int end)
{
    int i = start;
	int j = end;
	int tmp;
	int mid = int_array[(start+end)/2];

    while(i<=j)
    {
	    while((int_array[i]<mid)&&(i<end)) i++;
	    while((int_array[j]>mid)&&(j>start)) j--;

		for(; i <= j; i++, j--)
		{
		    tmp = int_array[i];
            int_array[i] = int_array[j];
			int_array[j] = tmp;
		}
	}

	if(i < end)
	{
	    quick_sort(int_array,i,end);
	}

	if(j > start)
	{
	    quick_sort(int_array,start,j);
	}

}

int main(int argc, char *argv[])
{
    int i;
    int int_array[MAX] = {2,1,4,6,3,5,7,8,9,0};
	quick_sort(int_array,0,MAX-1);
    for(i = 0; i < MAX; i++)
	{
	    printf("%d",int_array[i]);
	}
  
	putchar('\n');
    
	return 0;
}
