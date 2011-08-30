#ifndef ANALYSEMSG_H
#define ANALYSEMSG_H

#define MAXLINE 20
typedef struct send_msg * msg_p;

struct send_msg
{
    char my_id[16];
    char to_id[16];
    int state;
    char msg[MAXLINE];
};

void analyse_msg(int sendfd, char *msgbuf, FILE * chatfd);

#endif
