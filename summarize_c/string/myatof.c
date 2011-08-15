/*********************************************
* myatof.c - converts the initial portion of string to pointed to by str to float
* author :wanggege
* 2011-08-10
**************************************************/

#include <stdio.h>

float myatof(char *str)
{
    if(str==NULL)
	{
	    printf("str is NULL\n");
		return 0.0;
	}

    float number = 0.0;
	float demical_digit = 1.0;
	float signal = 1.0;
	int tmp = 0;

	if(*str=='-')
	{
	    signal = -1.0;
		str++;
	}

	while(*str>='0' && *str<='9' && *str!='\0')
	{
	    tmp = *str - '0';
		number = number * 10.0 + tmp;
		str++;
	}

	if(*str=='.')
	{
	    str++;
	}
	
	while(*str>='0' && *str<='9' && *str!='\0')
	{
	    tmp = *str - '0';
		number = number * 10.0 + tmp;
		str++;
		demical_digit *= 10.0;
	}

    if(signal>0)
	{
	    return number/demical_digit;
	}
	else
	{
	    return signal*number/demical_digit;
	}

}

int main(int argc, char *argv[])
{
    if(argc!=2)
	{
	    printf("please input a number string\n");
		return 0;
	}

	printf("%f\n",myatof(argv[1]));
}
