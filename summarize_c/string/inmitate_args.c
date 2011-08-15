/********************************************************
*inmitate_args.c - inmitate argc and argv's function
*author :wanggege
*2011-08-08
**********************************************************/

#include <stdio.h>
#define MAX 10

char args[44] = "./a.out hello world 123";
int argc = 0;
char *argv[MAX];

void inmitate_args(void)
{
    int state = 0;
	int i = 0;

    argv[0] = args;
    while(args[i])
	{
	    if(args[i] != ' ' && state == 0)
		{
		    argv[argc++] = args + i;
			state = 1;
		}

		if(args[i]==' ' && state == 1)
		{
		    args[i] = '\0';
			state = 0;
		}

		i++;

	}

	printf("argc = %d\n",argc);
	for(i = 0; i < argc; i++)
	{
	    printf("argv[%d] = %s\n",i, argv[i]);
	}

}

#if 0
int main()
{
    inmitate_args();
	return 0;
}
#endif
