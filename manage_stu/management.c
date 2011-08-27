#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int num;
	char name[20];
	struct student * next;
}STU;

void memu(void)
{
    printf("****************学生管理系统******************\n");
	printf("请选择操作\n");
	printf("1 : 打印所用已有学生信息\n");
	printf("2 : 添加新学生信息\n");
	printf("3 : 删除学生信息\n");
	printf("4 : 保存修改\n");
	printf("5 : 退出系统\n");
    printf("**********************************************\n");
}

STU *read_data(void)
{
    STU *head = NULL;
	STU *p = NULL;
	int num;
	char name[20];

	FILE *fp = fopen("./message.txt","r");
	if(NULL==fp)
	{
	    perror("open em.");
		exit(0);
	}

	if(fscanf(fp, "%d%s", &num,name) == EOF)
	{
	    return NULL;
	}

	head = p = (STU *)malloc(sizeof(STU));
	if(NULL == head)
	{
	    perror("malloc");
		exit(0);
	}
	head->num = num;
	strncpy(head->name,name,19);
	head->next = NULL;

	while(fscanf(fp,"%d%s",&num,name) != EOF)
	{
	    p->next = (STU *)malloc(sizeof(STU));
	    if(NULL == p->next)
	    {
	        perror("malloc");
		    exit(0);
	    }
	    p->next->num = num;
	    strncpy(p->next->name,name,19);
	    p->next->next = NULL;

		p = p->next;
	}

	return head;
}

void print_node(STU *p)
{
    if(NULL == p)
	{
	    printf("the node is empty\n");
	    return;
	}

	while(p)
	{
	    printf("%d   %s\n",p->num,p->name);
		p = p->next;
	}

}

STU *add_node(STU *head)
{
    STU *p = head;
	STU *new;
	new = (STU *)malloc(sizeof(STU));
	if(NULL == new)
	{
	    perror("malloc");
        exit(0);
    }

	printf("please input the student number\n");
	scanf("%d",&(new->num));
	printf("please input the student name\n");
	scanf("%s",new->name);
	getchar();
	new->next = NULL;

	if(NULL==p)
	{
	    return new;
	}

	if((new->num) < (head->num))
	{
	    new->next = head;
		return new;
	}

	while(p->next)
	{
	    if((p->next->num) > (new->num))
		{
		    break;
		}

		p = p->next;
	}

	new->next = p->next;
	p->next = new;

	return head;
}

STU *delete_node(STU *head)
{
    STU *p = head;
	STU *delete_p = NULL;
	int delete_num;
	
	printf("please input the number which you want to delete\n");
	scanf("%d",&delete_num);
	getchar();

    if(head->num==delete_num)
	{
	    delete_p = head;
	    head = head->next;
		free(delete_p);
		return head;
	}

	while(p->next)
	{
	   if(p->next->num == delete_num)
	   {
	       delete_p = p->next;
		   p->next = p->next->next;
		   free(delete_p);
		   return head;
	   }

	   p = p->next;
	}

//	return head;
}

void save_link(STU *head)
{
   FILE *fp = fopen("./message.txt","w");
   if(NULL == fp)
   {
       perror("save open");
	   exit(0);
   }

   STU *p = head;
//   if( )

   while(p)
   {
       fprintf(fp, "%d  %s\n", p->num,p->name);
	   p = p->next;
   }
}

int main(int argc, const char *argv[])
{
	char choice = 0;
	int flag = 1;
    STU *head = NULL;
	head = read_data();

    while(flag!=0)
	{
	    memu();
	    choice = getchar();
		getchar();

		switch(choice)
		{
		    case '1': print_node(head);  break;
			case '2': head = add_node(head); break;
			case '3': head = delete_node(head); break;
			case '4': save_link(head); break;
			case '5': flag = 0; printf("thank you for using~!\n");break;
			default : printf("Sorry, no this function~!\n"); break;
		}
	}

	return 0;
}
