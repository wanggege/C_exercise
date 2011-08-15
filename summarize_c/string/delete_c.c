/**********************************************************
* delete_c.c - delete c in string
* author:wangege
* 2011-08-09
*************************************************************/

#include <stdio.h>
#include <stdlib.h>

void delete_c(char *str, char c)
{
    if(str==NULL)
	{
	    printf("str is NULL\n");
		exit(0);
	}

    int i = 0;
	int j = 0;

	while(str[i])
	{
	    if(str[i]!=c)
		{
		    str[j++] = str[i];   
		}
		i++;
//		j++;      wrong,i and j change the same time,and i = j
	}

	str[j] = '\0';
}

#if 0
int main(int argc, char *argv[])
{
    char str[] = "helloworld";
	char c = 'o';
	delete_c(str,c);
	printf("%s\n",str);
	return 0;
}
#endif
