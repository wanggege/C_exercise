#include <stdio.h>
#include <stdlib.h>
void get_binary(unsigned int input);

int main(int argc, const char *argv[])
{
    if(argc!=2)
    {
        printf("input error,please intput an number");
    }
    
    get_binary(atoi(argv[1]));

    return 0;
}

void get_binary(unsigned int input)
{
    int tmp;
    unsigned int mask = 0xf;
    int i;
    for (i = 28; i >= 0;) 
    {
        tmp = (input>>i)&mask;
        if(tmp<10)
        {
            printf("%d",tmp);
        }
        else
        {
            printf("%c",tmp-10+'a');
        }

        i = i - 4;
    }
        
    printf("\n");

}


