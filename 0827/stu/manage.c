#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student
{
    int ID;
	char name[20];
	int score;
	struct student *next;
}STU;

STU *head = NULL;

void menu(void)
{
    printf("************************************************\n");
	printf("   welcome you to use student mansge system\n");
	printf("   please choice function number\n");
	printf("   1.print student'ID\n");
	printf("   2.print student'name\n");
	printf("   3.print student'score\n");
	printf("   4.exit\n");
	printf("*************************************************\n");
}

STU * creat_node(void)
{
   STU *p = (STU *)malloc(sizeof(STU));
   if(p==NULL)
   {
       perror("malloc");
	   exit(0);
   }

   char buffer[20];
   memset(buffer,0,sizeof(buffer));
   printf("please input the student's ID\n"); 
   fgets(buffer,20,stdin);
   buffer[strlen(buffer) - 1] = '\0';
   p->ID = atoi(buffer);
   
   memset(buffer,0,sizeof(buffer));
   printf("please input the student's name\n"); 
   fgets(buffer,20,stdin);
   buffer[strlen(buffer) - 1] = '\0';
   strncpy(p->name,buffer,strlen(buffer));
   
   memset(buffer,0,sizeof(buffer));
   printf("please input the student's score\n"); 
   fgets(buffer,20,stdin);
   buffer[strlen(buffer) - 1] = '\0';
   p->score = atoi(buffer);
   p->next = NULL;

   return p;
}

STU *insert_node(STU *p)
{
    STU *q = head;

    if(p==NULL)
	{
	    printf("insert node is NULL\n");
		return NULL;
	}
	
	if(head==NULL)
	{
	    head = p;
		return p;
	}
	if(head->ID > p->ID)
	{
	    p->next = head;
		head = p;
		return p;
	}
}

int p_name(STU *p)
{
    printf("student %s\n",p->name);
	return 0;
}

int p_ID(STU *p)
{
    printf("ID %d\n",p->ID);
	return 0;
}

int p_score(STU *p)
{
    printf("score %d\n",p->score);
	return 0;
}

int main(void)
{
    char choice;
	char buff[10];
	int(*q)(STU *p);
    STU *p = creat_node();
	int flag = 1;
	while(flag!=0)
	{
        menu();
	    fgets(buff,sizeof(buff),stdin);
	    buff[strlen(buff)-1] = '\0';
	    choice = buff[0];
	
        switch(choice)
        {
            case '1':q = p_ID;
		             q(p);
				     break;
            case '2':q = p_name;
		             q(p);
			     	 break;
            case '3':q = p_score;
		            q(p);
			    	 break;
           case '4':flag = 0;
		            printf("thank you for using\n");
				    break;
	       default:printf("sorry no this function\n");
		            break;
    	} 
	}

// 	insert_node(p);

	return 0;
}
