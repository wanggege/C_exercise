#include <stdio.h>

int main(int argc, const char *argv[])
{
    char * str = "hello!";
    char * ptr = str;

 //   printf("%s\n",ptr);

    while(*ptr!='\0')
    {
        printf("%c",*ptr);
        ptr++;
    }
    printf("\n");

    ptr--;
    while(ptr>=str)
    {
        printf("%c",*ptr);
        ptr--;
    }

    printf("\n");
    return 0;
}
