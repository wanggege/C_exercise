#include <stdio.h>
void invert_print_str(char * str);

int main(int argc, const char *argv[])
{
    char * str="helloworld!";

    invert_print_str(str);
    putchar('\n');
    return 0;
}

void invert_print_str(char * str)
{

/*    if(*str)
    {
        invert_print_str(str++);
    }
    else
    {
        return;
    }   */
    if(*str=='\0')
    {
        return;
    }

    invert_print_str(str+1);  //str++ is wrong

    putchar(*str);
}
