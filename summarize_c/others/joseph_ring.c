/******************************************************
* josephring.c - print who out and last one in josephring game
* author : wanggege
* 2011-08-08
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#define OUT 5

void josephring(int peoplenum)
{
   int i;
   int count = 0;
   int peopleodd = peoplenum;
   int josephring[peoplenum];
  
   for(i = 0; i < peoplenum; i++)
   {
       josephring[i] = i + 1;
   }

   i = 0;
   while(peopleodd)
   {
       if(josephring[i])
	   {
	       if(peopleodd==1)
		   {
		       printf("last one: %d\n",josephring[i]);
			   return;
		   }

	       count++;
		   if(OUT==count)
		   {
		       count = 0;
			   printf("%d out\n",josephring[i]);
			   josephring[i] = 0;
			   peopleodd--;
		   }
	   }

	   i++;
	   i = i % peoplenum;

   }

}

