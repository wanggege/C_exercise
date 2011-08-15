/***************************************************
* countnine.c - count how many nines in 0~num
* author: wanggege
* 2011-08-08
****************************************************/
#include <stdio.h>

int countnine(int num)
{
    int total = 0;
	int tmp = 0;
	int i;
	
	for(i = 1; i <= num; i++)
	{
	    tmp = i;

		while(tmp)
	    {
		    if(9==(tmp%10))
		    {
		        total++;
		    }

		    tmp /= 10;
	    }

	}
	return total;
}

