#include <stdio.h>
#include "linkedlist.h" 

void print_item(link p)
{
    printf("%d\n",p->item);
}

int main(int argc, char *argv[])
{
    link p = make_node(10);
	insert(p);
    p = make_node(5);
	insert(p);
    p = make_node(90);
	insert(p);
	p = search(5);
	delete_node(p);
	free_node(p);

	traverse(print_item);
	destory();

	p = make_node(100);
	push(p);
	p = make_node(200);
	push(p);
	p = make_node(250);
	push(p);

	while(p = pop())
	{
	    print_item(p);
		free_node(p);
	}

	return 0;
}
