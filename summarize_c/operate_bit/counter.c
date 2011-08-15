/************
* counter.c - count how many 1s in num
* author:wanggege
* 2011-08-10
***********/

#include <stdio.h>

int counter(unsigned int num)
{
    int count = 0;
	unsigned mask = 0x01;
	int i = 0;

	for(i = 0; i < 32; i++)
	{
	    if((num>>i)&mask)
		{
		    count++;
		}

	}

	return count;
}

