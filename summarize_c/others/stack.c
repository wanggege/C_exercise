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

int main(int argc, char *argv[])
{
    char *s = "helloworld";
	while(*s!='\0')
	{
	    push(*s);
		s++;
	}

    while(is_emputy()!=1)
	{
        putchar(pop());
	}
	putchar('\n');
	return 0;
}
