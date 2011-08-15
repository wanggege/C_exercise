/*
* mystrcpy.c - copy src to dest
* author:wanggege
* 2011-08-09
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char * mystrcpy(char *dest, char *src)
{
    if(src==NULL)
	{
	    printf("src is NULL\n");
		return NULL;
	}

    char * tmp = dest;

	while(*dest=*src)
	{
	    dest++;
		src++;
	}
	return tmp;
}

#if 0
int main(int argc, char *argv[])
{
    if(argc!=2)
	{
	    printf("please input a string\n");
		return 0;
	}

	char dest[MAX];
	printf("dest = %s\n",mystrcpy(dest,argv[1]));
	return 0;
}
#endif
