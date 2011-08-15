/******************************************************
* itoa.c - converts integer to str which initial  
* reverse - reversr a string
* author: wanggeg
* 2011-08-09
************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX 10

void reverse(char * c_array)
{
    int arraylen = strlen(c_array);
	int i,j;
	char c;

	for(i = 0, j = arraylen-1; i < j; i++, j--)
	{
	    c = c_array[i];
		c_array[i] = c_array[j];
		c_array[j] = c;
	}
}
void itoa(int num, char str[])
{
    int i = 0;
    int signal = 1;

	if(num < 0)
	{
	    signal = -1;
		num = -num;
	}

	while(num)
	{
	    str[i++] = num % 10 + '0';
		num /= 10;
	}

	if(signal < 0)
	{
	    str[i++] = '-';
	}

	str[i] = '\0';
	reverse(str);
}

#if 0
int main(int argc, char *argv[])
{
    char str[MAX];
    int num = 4500;
	itoa(num, str);
	printf("%s\n",str);
	return 0;

}
#endif
