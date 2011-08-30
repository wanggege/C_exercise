#ifndef MSGLINK_H
#define MSGLINK_H

typedef struct UsrData *link_s;

struct UsrData
{
    char usr_id[16];
    char usr_pwd[16];
    int state;
    int login_num;
    link_s next;
};

link_s search(char * usrid);
link_s check_pwd(char * usr_id,char *usr_pwd);
link_s make_node(char *usr_id,char *usr_pwd,int state,int login_num);
void insert(link_s p);
void delete(link_s p);
void traverse(void(*visit)(link_s));

#endif


