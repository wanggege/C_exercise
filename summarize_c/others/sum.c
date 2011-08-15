/**********************************************
* sum.c - sum number
* author:wanggege
* 2011-07-05
***********************************************/

#include<stdio.h>
#include<stdlib.h>

int sum(int n)
{
    if(0==n)
	{
	    return 0;
	}

	return n + sum(n-1);
}

int main(int argc, char *argv[])
{
    int num;

	if(argc!=2)
	{
	    printf("please input a number\n");
		return 0;
	}
    
	num = atoi(argv[1]);
	printf("1+2+...+%d=%d\n",num,sum(num));
	return 0;
}
