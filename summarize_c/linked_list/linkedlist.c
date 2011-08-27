#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>

static link head = NULL;
link head_t = NULL;

link make_node(int item)
{
    link p = (link)malloc(sizeof(link));
	if(p==NULL)
	{
	    perror("malloc");
		return NULL;
	}

	p->item = item;
	p->next = NULL;

	return p;
}

void free_node(link p)
{
    free(p);
}

link search(int key)
{
    link p;
	for(p = head; p; p = p->next)
	{
	    if(p->item == key)
		{
		    return p;
		}
	}

	return NULL;
}

void insert(link p)
{
    p->next = head;
	head = p;
}

void insert_t(link p)
{
    p->next = head_t;
	head = p;
}

void delete_node(link p)
{
    if(p==head)
	{
	    head = head->next;
		return;
	}

	link pre;
	for(pre = head; pre; pre = pre->next)
	{
	    if(pre->next == p)
		{
		    pre->next = p->next;
			return;
		}
	}
}

void traverse(void (*visit)(link))
{
    link p;
	for(p = head; p; p = p->next)
	{
	    visit(p);
	}
}

void destory(void)
{
    link q, p = head;
	head = NULL;

    while(p)
	{
	    q = p; 
		free_node(q);
		p = p->next;
	}
}

void push(link p)
{
    insert(p);
}

link pop(void)
{
    if(head == NULL)
	{
	    return NULL;
	}
	else
	{
        link p = head;
	    head = head->next;
	    return p;
	}
}


