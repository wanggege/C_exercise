/**********************************************************
  函 数 名：server
  作    者：王阁阁/欧美良
  功    能：用select实现简单的服务器功能
  日    期：2010-09-23
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "msg_link.h"
#include "creat_link.h"
#include "wrap.h"

#define MYPORT 8000     //客户端套接字的端口号

#define BACKLOG 25      // 一次可以链接的客户端最大数

#define BUF_SIZE 200   //接受消息内容的最大数

#define MAXNAME  26    //客户端名字最大长度

#define OK 1           //套接字属性

void print_node(link_s p)
{
    printf("%s\n",p->usr_id);
    printf("%s\n",p->usr_pwd);
    printf("%d\n",p->state);
    printf("%d\n",p->login_num);
}

int fd_A[BACKLOG];     //当前接受链接的苦户标志数组
int conn_amount ;       //当前链接的客户数目

int main(int argc,char *argv[])
{
    int sock_fd, new_fd;               //要监听的套接字和新链接的套接字
    struct sockaddr_in server_addr;    //服务器地址信息
    struct sockaddr_in client_addr;    //客户端地址信息
    socklen_t sin_size;                //存放客户端地址信息的结构体长度
    int ret;                           //监听的可读文件描述符的变化个数
    char msg_buf[BUF_SIZE];
    char node_buf[BUF_SIZE];
    int rev_byte;
    struct UsrData rev_usr;             //客户信息链表节点
    int opt = OK;                       //改变socket属性的选项
    int sign;                           //登录时服务器返回的信号
    int chatfd;
    int i;
    
    //打开已有用户信息文件，创建链表
    creat_link();
    //traverse(print_node);
    
    chatfd = open("./chatrecord.txt", O_RDWR|O_CREAT|O_APPEND,0777);
    if(chatfd < 0)
    {
        perr_exit("open record fail");
    }

    //建立一个服务器监听套接字
    sock_fd = Socket(AF_INET, SOCK_STREAM, 0);

    //改变socket选项，使创建端口号相同但IP地址不同的多个sokcet描述符
    setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

    //初始化服务器地址信息的结构体
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;      
    server_addr.sin_port = htons(MYPORT);    
    server_addr.sin_addr.s_addr = INADDR_ANY; 

    //将监听的套接字与本机绑定
    Bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    //监听套接字
    Listen(sock_fd, BACKLOG);

    printf("listen port %d\n", MYPORT);

    fd_set fdsr;                             //SELECT监听的可读文件描述符集
    int maxsock;                             //SELECT监听的文件描述符最大数
    struct timeval tv;

    conn_amount = 1;
    sin_size = sizeof(client_addr);
    maxsock = sock_fd;                       //初始化当前最大的文件描述符
    while (1) 
    {
        FD_ZERO(&fdsr);                    //初始化SELECT监听的文件描述符集
        FD_SET(sock_fd, &fdsr);            //将服务器的套接字加入SELECT监听                                              的文件描述符集中

        tv.tv_sec = 30;                     //SELECT监听的最长时间
        tv.tv_usec = 0;

        for (i = 1; i < BACKLOG; i++) 
	{
            if (fd_A[i] != 0) 
	    {
                FD_SET(fd_A[i], &fdsr);
            }
        }

	//检查select监听的文件描述符中是否变化，根据其变化进行不同的处理
        ret = select(maxsock + 1, &fdsr, NULL, NULL, &tv);
        if (ret < 0) 
	{
            perror("select");
            break;
        } else if (ret == 0) 
	  {
            printf("timeout\n");
            continue;
          }

        //将刚建立链接的套接字加入SELECT监听的可读文件描述符集中
        for (i = 1; i < conn_amount; i++) 
	{
            if (FD_ISSET(fd_A[i], &fdsr)) 
	    {
		if((rev_byte = read(fd_A[i], node_buf,200))<=0)
		{
		    printf("client[%d] close\n",i);
		    close(fd_A[i]);
		    FD_CLR(fd_A[i], &fdsr);
		    fd_A[i] = 0;
		}

                //traverse(print_node);
		analyse_log(node_buf,fd_A[i],chatfd);
            }
        }

        //检查SELECT监听的可读文件描述符集中的变化是否由新客户请求链接引起
        if (FD_ISSET(sock_fd, &fdsr)) 
	{
            new_fd = Accept(sock_fd, (struct sockaddr *)&client_addr, &sin_size);

            // 将新链接的客户套接字加入客户队列
            if (conn_amount < BACKLOG) 
	    {
	        
                fd_A[conn_amount] = new_fd;
                printf("new connection client[%d] %s:%d\n", conn_amount,
                        inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
		conn_amount++;
		if (new_fd > maxsock)
		{
                    maxsock = new_fd;
		}

		memset(node_buf, 0, sizeof(node_buf));
		if((rev_byte = read(new_fd, node_buf, sizeof(node_buf)))<0)
		{
		    perr_exit("read fail");
		}
                
		//对用户的消息进行解析
		analyse_log(node_buf,new_fd,chatfd);
                //traverse(print_node);
               
            }
            else 
	    {
                printf("max connections arrive, exit\n");
                send(new_fd, "bye", 4, 0);
                close(new_fd);
                break;
            }
        }
    }

}
