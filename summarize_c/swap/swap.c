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

