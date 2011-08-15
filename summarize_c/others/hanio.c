/*********************************************************
* hanio.c - print order of hanio tower
* author :wanggege
* 2011-08-09
***********************************************************/

#include <stdio.h>

void hanio(int n, char a, char b, char c)
{
    if(1==n)
	{
	    printf("%c------------>%c\n",a,c);
		return;
	}

	hanio(n-1,a,c,b);
	printf("%c------------>%c\n",a,c);
	hanio(n-1,b,a,c);
}
