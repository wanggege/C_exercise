#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node *link;
extern link head_t;
struct node
{
    int item;
	link next;
};

link make_node(int item);
void free_node(link p);
link search(int key);
void insert(link p);
void insert_t(link p);
void delete_node(link p);
void traverse(void (*visit)(link));
void destory(void);
void push(link p);
link pop(void);

#endif
