/***************************************************
*delete_repeat_digital.c - delete repeat digital number in an array
*author: wanggege
*2011-08-08
****************************************************/
#include <stdio.h>

void delete_repeat_digital(int *array, int len)
{
    int i = 0;
	int j = 0;
	
	for(i = 0; i < len - 1; i++)
	{
	    for(j = i + 1; j < len; j++)
		{
		    if(array[i]!=-1)
			{
			    if(array[i]==array[j])
				{
				    array[j] = -1;
				}
			}
		}
	}
	 
    for(i = 0; i < len; i++)
	{
	    if(array[i]>0)
		{
	        printf("%d",array[i]);
		}
	}

	putchar('\n');
}

