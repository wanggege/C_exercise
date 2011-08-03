#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int num;
    char name[20];
    struct student *next;
};

typedef struct student STU;
STU *creat_link(int n);
void print_link(STU *p);
int count_node(STU *p);
STU *insert_node(STU *p);
STU *delete_node(STU *head, int num);

int main(int argc, const char *argv[])
{
    int n = 5;
    STU *head = NULL;
    
    head = creat_link(n);
    print_link(head);

//    head = insert_node(head);
//    print_link(head);

   head = delete_node(head, 5);
   print_link(head);

   free(head); 
   return 0;
}

STU *creat_link(int n)
{
    int i;
    STU *head = NULL;
    STU *p = NULL;
    head = p = malloc(sizeof(STU));
    if(p==NULL)
    {
        perror("creat");
        exit(0);
    }

    p->num = 1;
    strcpy(p->name,"student");
    p->next = NULL;

    for (i = 1; i < n; i++) 
    {
        p->next = malloc(sizeof(STU));
        if(p->next==NULL)
        {
            perror("creat");
            exit(0);
        }

        p->next->num = i + 1;
        strcpy(p->next->name,"student");
        p->next->next = NULL;
        p = p->next;
    }

    return head;
}

void print_link(STU *p)
{
    if(p==NULL)
    {
        printf("linked list is empty\n");
        return;
    }

    while(p)
    {
        printf("num = %d\n",p->num);
        printf("name = %s\n",p->name);

        p = p->next;
    }
}

int count_node(STU *p)
{
    int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }

    return count;
}

STU *insert_node(STU *p)
{
    STU * head = p;
    STU * p1 = NULL;
    p1 = malloc(sizeof(STU));

    if(NULL==p1)
    {
        perror("insert malloc");
        exit(0);
    }

    printf("please input an number\n");
    scanf("%d",&p1->num);
    printf("please input your name\n");
    scanf("%s",p1->name);
    p1->next = NULL;

    if(p==NULL)
    {
        return p1;
    }

    if((p1->num) < (p->num))
    {
        p1->next = head;
       // head = p1;
      //  return head;
        return p1;
    }

    while(p->next)
    {
        if((p->next->num) > (p1->num))
        {
            break;
        }

        p = p->next;
    }

    p1->next = p->next;
    p->next = p1;

    return head;
}


STU *delete_node(STU *p, int num)
{
    STU *head = p;
    STU *tmp = NULL;

    if(p->num == num)
    {
       head = p->next;
       free(p);
       return head;
    }

    for(p = head; p->next; p=p->next)
    {
        if(p->next->num==num)
        {
            tmp = p->next;
            p->next = p->next->next;
            free(tmp);
            return head;//若将return放外面则查找尾节点出现断错误
        }
    }   

    if(p->next==NULL)
    {
        printf("no number match\n");
        return head;
    }

   // return head;
}
