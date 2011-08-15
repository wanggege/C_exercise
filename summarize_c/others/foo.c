/*********************************************************
* foo.c -converts a num which is decimal to base
* author:wanggege
* 2011-08-08
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100

void foo(int num, int base)
{
    int i = 0;
	int tmp;
    char c_array[MAXLEN];
    
	while(num)
	{
	    tmp = num % base;

	    if(tmp > 9)
		{
		    c_array[i++] = tmp - 10 + 'A'; 
		}
		else
		{
		    c_array[i++] = tmp + '0';
		}

		num /= base;
	}

    --i;
	for(; i >= 0; i--)
	{
	    printf("%c",c_array[i]);
	}
	putchar('\n');
}

