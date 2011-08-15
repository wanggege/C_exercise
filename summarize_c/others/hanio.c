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

int main(int argc, char *argv[])
{
    char a = 'A';
    char b = 'B';
    char c = 'C';

	int n = 3;
	hanio(n,a,b,c);

	return 0;
}
