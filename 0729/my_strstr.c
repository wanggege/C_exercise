#include <stdio.h>
char * my_strstr(char *src, char *find);

int main(int argc, char *argv[])
{
    char *src = argv[1];
    char *find = argv[2];
    
    printf("%s\n",my_strstr(src,find)) ;
    return 0;
}

char * my_strstr(char *src, char *find)
{
    int count = 0;
    char *result = src;

    while(*src != '\0')
    {
        while(*src==*find)
        {
            find++;
            src++;
            if(*find=='\0')
            {
                return result+count;
            }

        }
        
        src++;
        count++;
    }

    return NULL;

}
