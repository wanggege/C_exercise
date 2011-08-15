/******************************************
* myround.c - Rounding a decimal
* author :wanggege
* 2011-08-05
*******************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double myround(double x)
{
    double y;

	if((x - floor(x)) < (0.5))
	{
	    printf("%f floor is %f\n",x,floor(x));
	}
	else
	{
	    printf("%f ceil is %f\n",x,ceil(x));
		y = ceil(x);
	}

	return y;
}

int main(int argc, char *argv[])
{
    double x;

	if(argc!=2)
	{
	    printf("please input a double number\n");
		return 0;
	}

	x = atoi(argv[1]);
	printf("After round %f is %f\n",x,myround(x));

	return 0;
}
