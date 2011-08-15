/*******************************************
* is_leap_year.c  - judge a year is a leap year or not
* athour:wanggege
* 2011-08-05
*******************************************/

#include<stdio.h>
#define YES 1
#define NO 0

int is_leap_year(int year)
{
    if(((year % 4 == 0)&&(year % 100 != 0)) || (year % 400==0))
    {
        return YES;
    }
    else
    {
        return NO;
    }
}

#if 0
int main(int argc, char *argv[])
{
    int year;

	if(argc!=2)
	{
	    printf("please input year\n");
		return 0;
	}

	year = atoi(argv[1]);
	if(is_leap_year(year))
	{
	    printf("%d is leap year\n",year);
	}
	else
	{
	    printf("%d is not leap year\n",year);
	}

	return 0;

}
#endif
