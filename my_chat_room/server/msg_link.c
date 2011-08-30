#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "msg_link.h"

link_s head = NULL;                   //链表头

/*******************************************************
  函 数 名：make_node
  功    能：制造链表节点
  参    数：节点信息
  返 回 值：节点指针
 *******************************************************/
link_s make_node(char * usr_id,char *usr_pwd,int state,int login_num)
{
    link_s p = (link_s)malloc(sizeof *p);
    if(p==NULL)
    {
        printf("malloc fail\n");
	exit(1);
    }

    memset(&(p->usr_id), 0, sizeof(p->usr_id));
    memcpy(p->usr_id,usr_id,strlen(usr_id));
    memcpy(p->usr_pwd,usr_pwd,strlen(usr_pwd));
    p->state = state;
    p->login_num = login_num;
  //  printf("%s\n",p->usr_id);

    return p;
}

void insert(link_s p)
{
    p->next = head;
    head = p;
}

link_s check_pwd(char * usr_id,char * usr_pwd)
{
    link_s p;

    for(p=head; p; p=p->next)
    {
        if((strcmp(p->usr_id,usr_id)==0)&&(strcmp(p->usr_pwd,usr_pwd)==0))
	{
            return p;	    
	}
    }

    return NULL;
}

void delete(link_s p)
{
    link_s pre;
    
    if(p==head)
    {
        head = p->next;
	return;
    }

    for(pre=head; pre; pre=pre->next)
    {
        if(pre->next==p)
	{
	    pre->next = p->next;
	    return;
	}
    }
}

void traverse (void (*visit)(link_s))
{
    link_s p;

    for(p=head; p; p=p->next)
    {
        visit(p);
    }
}

link_s search(char * id)
{
    link_s p;

    for(p=head; p; p=p->next)
    {
        if(strcmp(p->usr_id,id)==0)
	{
	    return p;
	}
    }

    return NULL;
}
