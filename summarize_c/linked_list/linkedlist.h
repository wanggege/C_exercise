#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node *link;
struct node
{
    int item;
	link next;
};

link make_node(int item);
void free_node(link p);
link search(int key);
void insert(link p);
void delete_node(link p);
void traverse(void (*visit)(link));
void destory(void);
void push(link p);
link pop(void);

#endif
