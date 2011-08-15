/************
* mystrstr.c - finds the first occurence of the substring dest in the string  src
* author:wanggege
* 2011-08-10
*****************/

#include <stdio.h>

char *mystrstr(char *src, char *dest)
{
    if(src==NULL || dest==NULL)
	{
	    printf("src or dest is NULL\n");
		return NULL;
	}

	char *tmp_src = src;
	char *tmp_dest = dest;

	while(*tmp_src!='\0')
	{   
	    src = tmp_src;
	    dest = tmp_dest;

	    while(*dest!='\0' && *dest==*src)
		{
		    dest++;
			src++;
		}

		if(*dest=='\0')
		{
		    return tmp_src;
		}

		tmp_src++;
	}
}

int main(int argc, char *argv[])
{
    if(argc!=3)
	{
	    printf("please input two strings\n");
		return 0;
	}

	if(mystrstr(argv[1],argv[2]))
	{
	    printf("%s\n",mystrstr(argv[1],argv[2]));
	}
	else
	{
	    printf("not find\n");
	}
	return 0;
}
