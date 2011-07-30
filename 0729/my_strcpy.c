#include <stdio.h>

char * my_strcpy(char *dest, char *src);

int main(int argc, const char *argv[])
{
    char *src = argv[1];
    char dest[10];

    printf("%s\n",my_strcpy(dest,src));
    return 0;
}

char * my_strcpy(char *dest, char *src)
{
    char * tmp = dest;
   
    while(*dest=*src)
    {
        dest++;
        src++;
    }

    return tmp;
}
