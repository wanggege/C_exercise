#include <stdio.h>
int foo(int a, char ch)
{
    printf("%d\n%c\n",a,ch);
}

int too(int a, char ch)
{
    printf("%d\n%c\n",a,ch);
}
int main(void)
{
    int (*p[10])(int, char) = {foo,too};
	int i = 0;
	while(p[i]!=NULL)
	{
	    p[i](i,'a'+i);
		i++;
	}

	return 0;
}
