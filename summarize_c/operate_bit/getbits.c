/*************************************************
* getbits.c - print n binary bite from p
* author -wanggege
* 2011-08-10
***************************************************/

#include <stdio.h>

void getbits(unsigned num, int p, int n)
{
    unsigned mask = 1;
    int i;
	for(i = (p+n-1); i >= p; i--)
	{
	    printf("%d",(num>>i) & mask);
	}

	putchar('\n');
}

