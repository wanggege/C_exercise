#include <stdio.h>

int main(int argc, const char *argv[])
{
    char *c_ptr;
    char c_array[10] = "helloworld";
    c_ptr = c_array;

    printf("%s\n",c_ptr);
    printf("%s\n",argv[0]);
    return 0;
}
