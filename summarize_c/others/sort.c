/*******************************************************
* sort.c - sort the int array from littler to bigger by using bubble sort
* author:wanggege
*2011-08-08
***************************************************/

#include <stdio.h>
#define MAX 10

void sort(int *int_array, int len)
{
    int i;
	int j;
	int tmp;

	for(i = 0; i < len; i++)
	{
	    for(j = i + 1; j < len; j++)
		{
		    if(int_array[i] > int_array[j])
			{
			    tmp = int_array[i];
				int_array[i] = int_array[j];
				int_array[j] = tmp;
			}
		}
	}

	for(i = 0; i < len; i++)
	{
	    printf("%d",int_array[i]);
	}

	putchar('\n');
}

#if 0
int main(int argc, char *argv[])
{
    int int_array[MAX] = {2,1,4,6,3,5,7,8,9,0};
	sort(int_array,MAX);

	return 0;
}
#endif
