#include <stdio.h>
int my_strcmp(char *s1, char *s2);

int main(int argc, char *argv[])
{
    int result;
    result = my_strcmp(argv[1],argv[2]);

    if(result>0)
    {
        printf("s1 is bigger\n");
    }
    else if(result<0)
        {
            printf("s1 is smaller\n");
        }
        else
        {
            printf("equal\n");
        }

    return 0;
}

int my_strcmp(char *s1, char *s2)
{
    while((*s1==*s2)&&(*s1!='\0'))
    {
        s1++;
        s2++;
    }

    return *s1-*s2;
}
