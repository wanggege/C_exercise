#include <stdlib.h>
#include <stdio.h>
#define P_NUM 4

int riffle(int (*p)[13])
{
    int flag[52] = {0};
	int num = 52;
	int tmp;
	int *q = (int *)p;     

	srand(time(NULL));
	while(num > 0)
	{
	    tmp = rand() % 52;
		if(flag[tmp] == 1)
		{
		    continue;
		}
		else
		{
		    flag[tmp] = 1;
			*q = tmp;
			q++;
			num--;
		}
	}

	return 0;
}

void print_num(int (*p)[13])
{
    int *q = (int *)p;
	int i = 0;
	for(i = 0; i < 52; i++)
	{
	    printf("%d\n",*q);
		q++;
	}
}

int perflop(int (*p)[13], int p_num)
{
    int *q = (int *)p;
	int person[P_NUM][13];
	int i = 0;
	int j = 0;
	for(i = 0; i < 4; i++)
	{
	    for(j = 0; j < 13; j++)
		{
		    person[i][j] = *q;
			q++;
		}
	}

	return 0;
}

int main(void)
{    
    int p[4][13];
    riffle(p);
	print(p);
	perflop(p,P_NUM);

	return 0;

}
