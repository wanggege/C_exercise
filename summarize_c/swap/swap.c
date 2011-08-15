/**************************************************
*swap.c - swap two number by using pointer and ^
* author :wanggege
*2011-08-08
***********************************************/

#include <stdio.h>

void swap1(int *a,int *b)
{
    int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap2(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main(int argc, char *argv[])
{
    int a = 3; 
	int b = 4;

	printf("before swap a = %d, b = %d\n",a,b);
	swap1(&a,&b);
	printf("after swap1 a = %d, b = %d\n",a,b);
	swap1(&a,&b);
	printf("after swap2 a = %d, b = %d\n",a,b);

	return 0;
}
