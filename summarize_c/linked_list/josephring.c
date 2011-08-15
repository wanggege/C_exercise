/*********************************************
* josephring.c - print joseph ring by using linked list
* author :wanggege
* 2011-08-11
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#define PEOPLENUM 5

struct node
{
    int item;
	struct node *next;
};

typedef struct node link;

link *make_node(int item)
{
    link *node = (link *)malloc(sizeof(link));
	if(node==NULL)
	{
	    perror("malloc");
		return NULL;
	}
	
	node->item = item;
	node->next = NULL;
	return node;
}

link *insert_node(link *p, link *node)
{
    if(p==NULL)
	{
	    return node;
	}
	node->next = p;
	p = node;

	return p;
}

void print_link(link *p)
{
    if(p==NULL)
	{
	    printf("linked list is NULL\n");
		return;
	}
    while(p)
	{
	    printf("%d\n",p->item);
		p = p->next;
	}
}

void print_josephring(link *p, int num)
{
    if(p==NULL)
	{
	    printf("linked list is NULL\n");
		return;
	}

    int count = 0;
	int odd = num;
    link *q = p;
	while(odd)
	{
		if(q->item!=0)
	    {
		    if(odd==1)
			{
			    printf("%d is last one\n",q->item);
				return;
			}

		    count++;
            if(count==4)
		    {
		         printf("%d out\n",q->item);
		         q->item = 0;
			     count = 0;
				 odd--;
		    } 
	    }
        q = q->next;
	    if(q==NULL)
	    {
			q = p;
		}
    }
}

int main(int argc, char *argv[])
{
    int i;
	link *head = NULL;
	for(i = PEOPLENUM; i > 0; i--)
	{
	    head = insert_node(head,make_node(i));
	}
    
//	print_link(head);
	print_josephring(head,PEOPLENUM);

	return 0;
}
