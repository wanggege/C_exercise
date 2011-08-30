/******************************************************
  函 数 名：analyse_msg
  功    能：解析用户发送的信息并按类进行封装
  参    数：sendfd:用户使用的套接字
            msg_buf:用户信息储存缓冲区
            chatfd: 聊天记录保存文件描述符
  返 回 值：空
 *****************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "analyse_msg.h"

#define STATESIZE   16
#define PRIVATE     2
#define GROUP       3
#define CAT_ONLINE  5

extern char ownerid[16];                     //用户id

void analyse_msg(int sendfd, char * msgbuf,FILE *chatfd)
{
    struct send_msg send_node;
    msg_p send_p;
    char statebuf[STATESIZE];               //用户请求的服务类型      

    memset(&statebuf, 0, sizeof(statebuf));
    fscanf(stdin, "%s", statebuf);

    //如果用户选择私聊，按提示输入对方id以及消息，对消息进行封装并发送
    if(((strncmp(statebuf, "private", 7))==0)||((strncmp(statebuf, "2", 1))==0))
    {
	memset(&send_node.my_id, 0, sizeof(send_node.my_id));
	strncpy(send_node.my_id, ownerid, sizeof(ownerid));
	memset(&send_node.to_id, 0, sizeof(send_node.to_id));
        printf("请输入您朋友的id\n");
	fscanf(stdin, "%s", send_node.to_id);
	printf("输入信息\n");
	memset(&send_node.msg, 0, sizeof(send_node.msg));
	fscanf(stdin, "%s", send_node.msg);
	send_node.state = PRIVATE;

	write(sendfd,(char *)&send_node, sizeof(send_node));  //发送消息
	write(chatfd,(char *)&send_node, sizeof(send_node));  //保存记录
	write(chatfd, "\n", 1);

    }
    
    //用户选择群来，以群聊形式封装消息，并发送
    if(((strncmp(statebuf, "gro/", 4))==0)||((strncmp(statebuf, "3", 1))==0))
    {
	memset(&send_node.my_id, 0, sizeof(send_node.my_id));
	strncpy(send_node.my_id, ownerid, sizeof(ownerid));
	memset(&send_node.to_id, 0, sizeof(send_node.to_id));
	printf("输入信息\n");
	memset(&send_node.msg, 0, sizeof(send_node.msg));
	fscanf(stdin, "%s", send_node.msg);
	send_node.state = GROUP;

	write(sendfd,(char *)&send_node, sizeof(send_node));
	write(chatfd,(char *)&send_node, sizeof(send_node));
	write(chatfd, "\n", 1);
    }

    //用户选择查看在线用户
    if(((strncmp(statebuf, "cat_online", 10))==0)||((strncmp(statebuf, "5", 1))==0))
    {
	memset(&send_node.my_id, 0, sizeof(send_node.my_id));
	strncpy(send_node.my_id, ownerid, sizeof(ownerid));
	memset(&send_node.to_id, 0, sizeof(send_node.to_id));
//	printf("输入信息\n");
	memset(&send_node.msg, 0, sizeof(send_node.msg));
//	fscanf(stdin, "%s", send_node.msg);
	send_node.state = CAT_ONLINE;

	write(sendfd,(char *)&send_node, sizeof(send_node));
//	write(chatfd,(char *)&send_node, sizeof(send_node));
//	write(chatfd, "\n", 1);
    }

}


