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
    int i;

    for (i = 31; i >= 0; i--) 
    {
        printf("%c", (((input>>i)&1)>0)?'1':'0');
    }
    
    printf("\n");

}


