/**********************************************
* mystrcmp.c - compares two string s1 and s2,returns an integer less than greater or equal to zero.
* author: wanggege
* 2011-08-08
**********************************************/
#include <stdio.h>
#include <stdlib.h>

int mystrcmp(char *s1, char *s2)
{
    if(s1==NULL||s2==NULL)
	{
	    printf("input error\n");
		exit(0);
	}

    while((*s1==*s2)&&(*s1!='\0'))
	{
	    s1++;
		s2++;
	}

	return *s1-*s2;
}

#if 0
int main(int argc, char * argv[])
{
    if(argc!=3)
	{
	    printf("please input two string\n");
		return 0;
	}

	printf("%d\n", mystrcmp(argv[1],argv[2]));

	return 0;

}
#endif
