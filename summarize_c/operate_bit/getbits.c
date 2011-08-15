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

int main(int argc, char *argv[])
{
    if((argc!=4) || (atoi(argv[2])>31) || (atoi(argv[3])>31))
	{
	    printf("input error,please input two numbers littler than 31\n");
		return 0;
	}

	getbits(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
	return 0;
}
