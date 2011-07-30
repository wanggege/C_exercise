#include <stdio.h>

void parse(void);
char str[128] = "./a.out  100   200";
int argc = 0;
char * argv[16];

int main(void)
{
    int i;

    parse();
    printf("argc = %d\n",argc);
    for (i = 0; i < argc; i++) 
    {
        printf("argv[%d] = %s\n",i, argv[i]);
    }
}

void parse(void)
{
    int i = 0;
    int state = 0;

    while(str[i])
    {
        if((state==0)&&(str[i]!=' '))
        {
            argv[argc++] = str + i;
            state = 1;
        }

        if((state==1)&&(str[i]==' '))
        {
            state = 0;
            str[i] = '\0';
        }

        i++;
    }
    
}
