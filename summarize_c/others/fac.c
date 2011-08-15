/****************************************
* fac.c
* author:wanggege
* 2011-07-05
*******************************************/

#include <stdio.h>
#include <stdlib.h>

long fac(int num)
{
    if(0==num)
	{
	    return 1L;
	}
	else
	{
	    return num*fac(num-1);
	}
}

int main(int argc, char *argv[])
{
    int num;
	
	if(argc!=2)
	{
	    printf("please input a num < 15\n");
        return 0;
	}

    num = atoi(argv[1]);
	printf("%d!=%ld\n",num,fac(num));
	return 0;
}
