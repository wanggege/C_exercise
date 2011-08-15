#include <stdio.h>

char * mystrcat(char *s1, char *s2)
{
    if(s1==NULL || s2==NULL)
	{
	    printf("s1 or s2 is NULL\n");
		return NULL;
	}

    char *tmp = s1;
	while(*s1!='\0')
	{
	    s1++;
	}

	while(*s1=*s2)
	{
	    s1++;
		s2++;
	}

	return tmp;
}

int main(int argc, char *argv[])
{
    if(argc!=3)
	{
	    printf("input two string\n");
		return 0;
	}

	printf("after cat the string is %s\n",mystrcat(argv[1],argv[2]));
	return 0;
}
