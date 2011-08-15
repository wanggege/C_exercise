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

int main(int argc, char *argv[])
{
    if(argc!=2)
	{
	    printf("please input a num\n");
		return 0;
	}

	printf("The number you input contains %d 1s\n",counter(atoi(argv[1])));
	return 0;
}
