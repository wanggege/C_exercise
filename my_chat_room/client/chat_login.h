#ifndef CHATLOGIN_H
#define CHATLOGIN_H

typedef struct login_node * link_c;

//消息发送和接受的结构体形式
struct login_node
{
    char usr_id[16];
    char usr_pwd[16];
    int state;
    int login_num;
};

void print_star(void);
void chat_login(int sockfd,link_c p);

#endif
