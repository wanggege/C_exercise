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

