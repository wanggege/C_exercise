/***********************
* link.c - linked list practice
* author: wanggege
* 2011-08-11
*************************/

#include <stdio.h>
#include <stdlib.h>

struct student
{
    unsigned ID;
	char name[30];
	struct student *next;
};

typedef struct student STU;

STU *creat_link(int n)
{
    STU *head = NULL;
	STU *current = (STU *)malloc(sizeof(STU));
	head = current;
	if(current==NULL)
	{
	    perror("malloc");
		return NULL;
	}

	printf("please input students' message:ID,name\n");
	scanf("%d",&current->ID);
	scanf("%s",current->name);
	current->next = NULL;

	while(n>1)
	{
        current->next = (STU *)malloc(sizeof(STU));
	    if(current->next==NULL)
	    {
	        perror("malloc");
		    return NULL;
	    }

	    scanf("%d",&current->next->ID);
	    scanf("%s",current->next->name);
	    current->next->next = NULL;
		current = current->next;
		n--;
	}

	return head;
}

void print_link(STU *p)
{
    if(p==NULL)
	{
	    printf("linked list is NULL\n");
		return;
	}

    while(p)
	{
	    printf("%d   %s\n",p->ID,p->name);
		p = p->next;
	}
}

int count_node(STU *p)
{
    int count = 0;
	if(p==NULL)
	{
	    printf("linked list is NULL\n");
		return 0;
	}

	while(p)
	{
	    p = p->next;
		count++;
	}
	return count;
}
 
STU *insert_node(STU *head, STU *info)
{
    if(head==NULL || info==NULL)
	{
	    printf("head or info is NULL\n");
		return NULL;
	}

	STU *current = head;
    STU *former;

    if((info->ID) <= (current->ID))
	{
	    info->next = current;
		return info;
	}
	while(current->next)
	{
	//    former = current; 
	    if((current->next->ID) > (info->ID))
		{
		   // info->next = former->next;
           // former->next = info;
		   //	return head;
		    break;
		}

		current = current->next;
	}
    info->next = current->next;
	current->next = info;
 
	return head;
}

int main(int agrc, char *argv[])
{
    int nodenum = 3;
	STU *head = creat_link(nodenum);
	print_link(head);
//	printf("before insert node linked list's node is %d\n",count_node(head));
	STU *node = (STU *)malloc(sizeof(STU));
	printf("please input the node which you want to insert message:ID,name\n");
	scanf("%d",&node->ID);
	scanf("%s",node->name);
	head = insert_node(head,node);
//	printf("after insert node linked list's node is %d\n",count_node(head));
    printf("after insert linked list:\n");
	print_link(head);
	return 0;
}
