/************************************************
* myatoi.c -converts the initial portion of the string pointed to by str to   int
* author :wanggege
* 2011-08-10
*************************************************/

#include <stdio.h>

int myatoi(char *str)
{
    if(str==NULL)
	{
	    printf("string is NULL\n");
		return 0;
	}

	int number = 0;
//	int base = 0;
	int signal = 1;
	int digital = 0;

	if(*str=='-')
    {
	    signal = -1;
		str++;
	}

	while(*str>='0' && *str <='9' && *str!='\0')
	{
	    digital = *str - '0';
		number = number * 10 + digital;
//		base = number * 10;
		str++;
	}

	if(signal<0)
	{
	    return -number;
	}
	else
	{
	    return number;
	}
}

int main(int argc, char *argv[])
{
    if(argc!=2)
	{
	    printf("please input an number string\n");
		return 0;
	}
    printf("%d\n",myatoi(argv[1]));
	return 0;
}
