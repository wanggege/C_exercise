/************************
* stack exercise:push and pop
*
*************************/

#include <stdio.h>
#define N 1024

char buff[N];
int top = N;

void push(char n)
{
    if(top > 0)
	{
	    buff[--top] = n;
	}
}

char pop(void)
{
    if(top < N)
	{
	    return buff[top++];
	}
}

int is_emputy(void)
{
    return (top==N);
}

