#ifndef CREATLINK_H
#define CREATLINK_H

#define MAXLINE 20
typedef struct UsrMsg * msg_p;

struct UsrMsg
{
    char my_id[16];
    char to_id[16];
    int  state;
    char msg[MAXLINE];
};

void creat_link(void);
char analyse_log(char * str, int socket_fd, int chatfd);
char log_in(char * information);

#endif
