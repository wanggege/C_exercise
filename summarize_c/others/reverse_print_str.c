/**********************************************
* reverse_print_str.c - reverse print a string using recursive
* author: wanggege
* 2011-08-05
************************************************/

#include <stdio.h>

void reverse_print_str(char *str)
{
    if(*str=='\0')
	{
	    return;
	}
	else
	{
	    reverse_print_str(str+1);     //attention:str++ is wrong
	}

	putchar(*str);
}
int main(int argc, char *argv[])
{
    if(argc!=2)
	{
	    printf("please input the string you want\n");
		return 0;
	}

	reverse_print_str(argv[1]);
	putchar('\n');

	return 0;
}
