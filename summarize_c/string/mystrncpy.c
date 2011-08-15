/*********************************************************
* mystrncpy.c - copy nbyte from src to dest
* author :wanggege
* 2011-08-09
**********************************************************/

#include <stdio.h>
#include <string.h>

char *mystrncpy(char *dest, char *src, int nbyte)
{
    if(nbyte==0||src==NULL)
	{
	    printf("please input correct number or string\n");
		return NULL;
	}

    char * tmp = dest;

	while((nbyte)&&(*dest=*src))
	{
	    dest++;
		src++;
		nbyte--;
	}

	*dest = '\0';
	return tmp;
}

int main(int argc, char *argv[])
{
    if(argc!=3)
	{
	    printf("please input a string and a number\n");
		return 0;
	}
    
	char dest[100];
	printf("src = %s\n dest = %s\n",argv[1],mystrncpy(dest,argv[1],atoi(argv[2])));
	return 0;
}
