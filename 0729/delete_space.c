#include <stdio.h>

void delete_null(void);
char str[128] = "./a.out    100        200";

int main(void)
{
    int i;

    delete_null();
//    printf("%s\n",str);
    return 0;
}

void delete_null(void)
{
    int i = 0;
    int state = 1;

    while(str[i])
    {

        if(str[i] != ' ')
        {
            if(state==1)
            {
                printf("%c",str[i]);
                state = 0;
            
            }
            else
            {
                printf("%c",str[i]);
            }
        }
/*        if((state==1)&&(str[i]!=' '))
        {
            printf("%c",str[i]);
            state = 0;
           
        } */

//        if((state==1)&&(str[i]==' '))
  //      {
    //        i++;
      //  }

        if(str[i]==' ')
        {
            if(state==0)
            {
                printf("%c",str[i]);
                i++;
                state = 1;
            }
            else
            {
                i++;
            }
        }
       /* if((state==0)&&(str[i]!=' '))
        {
            printf("%c",str[i]);
        }*/

       // if((state==0)&&(str[i]==' '))
       // {
         //   printf("%c",str[i]);
           // i++;
          //  state = 1;
      //  }  
        i++;
    }
    
    putchar('\n');
}
