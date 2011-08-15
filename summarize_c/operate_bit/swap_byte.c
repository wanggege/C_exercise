/***************************
* print_binary - swap unsigned short number's hign 8 byte and low 8 byte 
* author :wanggege
* 2011-08-10
*******************************/

#include <stdio.h>
#include <string.h>

void print_binary(int num)
{
    unsigned mask = 0x1;
	int i = 0;

	for(i = 15; i >= 0; i--)
	{
	    printf("%d",(num>>i) & mask);
	}
    putchar('\n');
}

unsigned short swap_byte(unsigned short num)
{
    return (num>>8)|(num<<8);
}

int main(int argc, char *argv[])
{
    if(argc!=2)
	{
	    printf("input an num\n");
		return 0;
	}

    printf("before swap\n");
    print_binary(atoi(argv[1]));
    printf("after swap\n");
	print_binary(swap_byte(atoi(argv[1])));

	return 0;
}
