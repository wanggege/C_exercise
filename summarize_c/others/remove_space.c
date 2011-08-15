/*****************************************************
* remove_space.c - remove redundant space in string,save one space between two word
* author: wanggege
* 2011-08-08
*****************************************************/

#include <stdio.h>

void remove_space(char *array)
{
     int state = 0;
	 printf("<<");
	 while(*array)
	 {
	     if((*array==' ')&&(state==0))
		 {
		     array++;
		 }
         else if((*array==' ') && (state ==1))
		     {
		         putchar(*array);
			     state = 0;
		     }
			 else
			 {
		         putchar(*array); 
		         state = 1;
			 }

		 array++; 
	 }
   
     printf(">>\n");
}

int main(int argc, char *argv[])
{
    char *str = "  123   23 312  45  ";
	remove_space(str);

	return 0;
}
