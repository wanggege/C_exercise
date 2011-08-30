#include <stdio.h>

void delete_null(char *src);

int main(int argc, char *argv[])
{
    char input_buff[100];
    printf("input the string you want to delete space\n");
    gets(input_buff);

    delete_null(input_buff);
    return 0;
}

void delete_null(char * str)
{
    int i = 0;
    int state = 1;

    while(str[i])
    {
        if(str[i]!=' ')
	{
	    printf("%c",str[i]);
	    state = 0;
	}

	if((state==0)&&(str[i])==' ')
	{
	    printf("%c",str[i]);
	    state = 1;
	}
        i++;
    }
    
    putchar('\n');
}
