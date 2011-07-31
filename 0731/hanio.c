#include <stdio.h>

void hanio(char a,char b, char c,int n);

int main(int argc, const char *argv[])
{
    hanio('A','B','C',3);
    return 0;
}

void hanio(char a,char b, char c,int n)
{
    if (n==1) 
    {
        printf("%c------>%c\n",a,c);
        return;
    }

    hanio(a,c,b,n-1);
    printf("%c------>%c\n",a,c);
    hanio(b,a,c,n-1);

}


