/**********************************************************
* delete_substr.c -delete substring in srouce string
* author :wangege
* 2011-08-09
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

void delete_substr(char *src, char * substr)
{
    if(src==NULL || substr==NULL)
	{
	    printf("src or substr is NULL\n");
		exit(0);
	}

	int i,j,k;
	for(i = k = 0; src[i]; i++)
	{
	    for(j = 0; src[i]!=substr[j] && substr[j]!='\0'; j++);
        
		if(substr[j]=='\0')
		{
		    src[k++] = src[i];
		}
	}
	src[k] = '\0';
}

#if 0
int main(int argc, char *argv[])
{
    if(argc!=3)
	{
	    printf("please input two strings\n");
		return 0;
	}

    printf("before delete\n str = %s\n substr = %s\n",argv[1],argv[2]);
	delete_substr(argv[1],argv[2]);
    printf("after delete\n str = %s\n substr = %s\n",argv[1],argv[2]);
   
    return 0;	
}
#endif 
