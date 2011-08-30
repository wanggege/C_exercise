/*******************************************************
  函 数 名：client
  功    能：用select实现基本的客户端功能
  作    者：王阁阁/欧美良
  日    期：2010-09-23
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "chat_login.h"
#include "analyse_msg.h"

#define SERVERPORT     8000          /* 服务器端口号 */
#define MAX_NAMESIZE   16            /* 用户名最大长度 */
#define MAX_DATASIZE   256           /* 消息最大长度 */
#define STDIN          0             /* 标准输入文件描述符 */

int main(int agrc, char *agrv[])
{
     struct send_msg send_node;
     msg_p send_p;
    char chat_to[MAX_NAMESIZE];          /* 聊天对象的名字 */ 
    char chat_to_id[32];                 /* 聊天对象的名字+我的名字 */ 
    int sockfd;
    int recvbytes;
    struct login_node send_usr;
    link_c login_p;
    char recv_buf[MAX_DATASIZE];       /* 接收消息缓冲区 */
    char *recv_p;                      /* 私聊时寻找"："的指针*/

    char name[MAX_NAMESIZE];           /* 定义用户名 */
    char send_str[MAX_DATASIZE], send_buf[MAX_DATASIZE]; /* 消息发送缓冲区 */
    struct sockaddr_in serv_addr;      /*Ineternet套接字地址结构 */
    fd_set rfd_set, wfd_set, efd_set;  /* r-读 w-写 e-异常描述符集 */
    FILE *fd;

    if ((fd = fopen("./msgrecord.txt", "a+")) == NULL)
    {
        perror("open");
        exit(1);
    }

    struct timeval timeout;          /* 本次select的超时结束时间 */
    int ret;                         /* 与server连接的结果 */

    /* 打开本机一个网络端口 */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    /* 初始化sockaddr */
    bzero(&serv_addr, sizeof(struct sockaddr_in));       /* 全部清0 */
    serv_addr.sin_family = AF_INET;                      /* IP地址类型 */
    serv_addr.sin_port = htons(SERVERPORT);              /* 主机端口号->网                                                          络端口号 */
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  /* IP转换：点分十                                                        进制->long网络地址*/
    
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("connect");
        exit(1);
    }

    /* sockfd设为非阻塞 */
    fcntl(sockfd, F_SETFD, O_NONBLOCK);
    
    /*解析用户登录，注册信息*/
    chat_login(sockfd,login_p);
    
    /*打印操作格式*/
    run_form();
    
    while (1)
    {
        FD_ZERO(&rfd_set); /* 将select()监视的读的文件描述符集清除 */
        FD_ZERO(&wfd_set); /* 将select()监视的写的文件描述符集清除 */
        FD_ZERO(&rfd_set); /* 将select()监视的异常的文件描述符集清除 */
        
        /* 将标准输入文件描述符加到select监视的读文件描述符集中 */
        FD_SET(STDIN, &rfd_set);
        
        /* 将新建的文件描述符加到select监视的读文件描述符集中 */
        FD_SET(sockfd, &rfd_set);
        
        /* 将新建的文件描述符加到select监视的异常文件描述符集中 */
        FD_SET(sockfd, &efd_set);
        
        timeout.tv_sec = 10;    /* 被监视窗口等待的秒数 */
        timeout.tv_usec = 10;   /* 被监视窗口等待的微秒数 */
        
        /* 等待*.set改变，成功返回改变的个数 */
        ret = select(sockfd + 1, &rfd_set, &wfd_set, &efd_set, &timeout);
        if (ret == 0)
        {
            continue;
        }
        if (ret < 0)
        {
            perror("select error: ");
            exit(-1);
        }

        /* 判断是否已将STDIN文件描述符添加到select的读文件描述符集中 */
        if (FD_ISSET(STDIN, &rfd_set))
        {  
          //对发送的消息进行封装并发送
	  analyse_msg(sockfd, send_buf, fd);
        }
        
        /* 判断是否已将新建描述符添加到select监视的读的文件描述符集合中 */
        if (FD_ISSET(sockfd, &rfd_set))
        {
            //接受消息并打印
	    memset(recv_buf, 0, sizeof(recv_buf));
            recvbytes = read(sockfd, recv_buf, MAX_DATASIZE);
            if (recvbytes == 0)
            {
                close(sockfd);
                exit(0);
            }
            recv_buf[recvbytes] = '\0';
            
            printf("%s\n", recv_buf);
        }
        
        /* 判断是否已将新建的描述符添加到select监视的异常文件描述符集中 */
        if (FD_ISSET(sockfd, &efd_set))
        {
            close(sockfd);
            fclose(fd);
            exit(0);
        }
    }
}
