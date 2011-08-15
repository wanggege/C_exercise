/****************
*mystrlen - calculates the length of src
* author:wanggege
* 2011-08-09
*******************************/

#include <stdio.h>

int mystrlen(char *src)
{
    if(src==NULL)
	{
	    printf("src is NULL\n");
		return 0;
	}

    int len = 0;
	while(*src)
	{
	    src++;
		len++;
	}

	return len;
}

#if 0
int main(int argc, char *argv[])
{
    if(argc!=2)
	{
	    printf("please input the string you want to know it's len\n");
		return 0;
	}

	printf("the string's len  which you input is %d\n",mystrlen(argv[1]));
	return 0;
}
#endif
