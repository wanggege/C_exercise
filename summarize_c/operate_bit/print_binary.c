/***************************
* print_binary - print an decimal number's binary
* author :wanggege
* 2011-08-10
*******************************/

#include <stdio.h>
#include <string.h>

void print_binary(int num)
{
    unsigned mask = 0x1;
	int i = 0;

	for(i = 31; i >= 0; i--)
	{
	    printf("%d",(num>>i) & mask);
	}
    putchar('\n');
}

