#include <stdio.h>
int count_nine(int num);

int main(int argc, const char *argv[])
{
    printf("total nine = %d\n",count_nine(100));

    return 0;
}

int count_nine(int num)
{
    int i;
    int tmp;
    int count = 0;

    for (i = 0; i < num; i++) 
    {
        tmp = i;
        while(tmp)
        {
            if(tmp%10==9)
            {
                count++;
            }

            tmp = tmp / 10;
        }
    }

    return count;
}
