#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "creat_link.h"
#include "msg_link.h"

#define ONLINE       1                //在线的符号
#define BUF_SIZE     200              //一个客户信息的大小 
#define LOGIN        0                //注册的符号
#define REGISTER     1                //登录的符号
#define PRIVATE      2                //私聊的符号
#define GROUP        3                //群聊的符号
#define CAT_ONLINE   5

extern link_s head;
void print(link_s p)
{
    printf("%s\n",p->usr_id);
    printf("%s\n",p->usr_pwd);
    printf("%d\n",p->state);
    printf("%d\n",p->login_num);
}

/**********************************************************
 函 数 名：creak_link
 功    能：将存放用户文件中的已经注册的用户读出并创建链表
 说    明：参数：空   返回值：空
***********************************************************/
void creat_link (void)
{
    char read_buf[BUF_SIZE];
    struct UsrData have_usr;           //存放读出的用户信息的结构体
    link_s source_p;

    FILE *fptr;
    if((fptr = fopen("./usrmsg.txt","a+"))==NULL)
    {
        perror("fopen fail");
	exit(1);
    }

    fseek(fptr, 0, SEEK_SET);          //设置文件属性使从文件开始读取数据       
    while((fgets(read_buf, sizeof(read_buf), fptr))!=NULL)
    {
        memcpy (&have_usr,read_buf,sizeof(have_usr));
        source_p = make_node (have_usr.usr_id,have_usr.usr_pwd,have_usr.state,have_usr.login_num);
	insert(source_p);              //将用户信息创建链表
	memset(&read_buf, 0, sizeof(read_buf));
    }

   fclose(fptr);
}

/*********************************************************
函数名：log_in
功  能：验证用户登录的消息内容，将正确的用户信息写入用户
        文件中，并将该用户加入用户链表中
参  数：information服务器接受的信息
返回值：成功返回 1 失败返回 0
********************************************************/
char log_in(char *information)
{
    char result;                   //数据分析结果
    link_s search_p;               //查找节点的返回值
    link_s newusr;
    struct UsrData rev_usr; 

    int wfd;
    if((wfd = open("./usrmsg.txt",O_RDWR|O_CREAT|O_APPEND,0777))<0)
    {
        perror("open fail");
	exit(1);
    }
    lseek(wfd, 0, SEEK_END);       //设置文件属性使写时以追加的方式写
    
    memset(&rev_usr.usr_id, 0,sizeof(rev_usr.usr_id));
    memset(&rev_usr.usr_pwd, 0,sizeof(rev_usr.usr_pwd));
    memcpy(&rev_usr,information,sizeof(rev_usr));
    
    //查找用户链表看该用户是否已经注册如果没有就进行注册
    if((search_p = search(rev_usr.usr_id))==NULL)
    {
        write(wfd,(char *)&rev_usr,sizeof(rev_usr));   //将用户信息写如                                                           存放用户信息的文件
	write(wfd,"\n",1);
        newusr = make_node (rev_usr.usr_id,rev_usr.usr_pwd,rev_usr.state,rev_usr.login_num);
	insert(newusr);                    //将新注册的用户插入用户链表

	result = '1';                      //注册成功
    }
    else
    {
        result = '0';                      //该用户已经注册
    }

    return result;
}

/********************************************************
 函 数 名：register_usr
 功    能：解析用户登录信息
 参    数：information:用户登录信息 socket_fd:用户对应的套接字
 返 回 值：返回登录的结果符号
*********************************************************/
char register_usr(char * information,int socket_fd)
{
    char result;
    struct UsrData rev_usr;
    link_s check_p;

    //对存放用户信息的结构体清零
    memset(&rev_usr.usr_id, 0,sizeof(rev_usr.usr_id));
    memset(&rev_usr.usr_pwd, 0,sizeof(rev_usr.usr_pwd));
    memcpy(&rev_usr, information, sizeof(rev_usr));
   // traverse(print);
    
    //核对用户密码是否正确
    if((check_p=check_pwd(rev_usr.usr_id,rev_usr.usr_pwd)))
    {
        if(check_p->login_num == 0)          //用户还未登录
	{
            check_p->state = ONLINE;         //将用户状态改为在线
	    check_p->login_num = socket_fd;  //设置登录号码
	    result = '1';                    //登录成功
	}
	else
	{
	    result = '2';                    //该用户已经在线
	}
    }
    else
    {
        result = '0';                       //该用户不存在
    }

    return result;
    
}

/**************************************************************
  函 数 名：analyse_log
  功    能：解析用户登录或者注册信息
  参    数：msg:用户信息 socket_fd:用户使用的套接字
            chat_fd ：保存聊天记录的文件描述符
  返 回 值：解析结果
****************************************************************/
char analyse_log(char * msg,int socket_fd,int chatfd)
{
    char  sign;                                 //返回给客户端的信息符号
    struct UsrData rev_usr;
    struct UsrMsg  rev_msg;
    char send_msg[BUF_SIZE];

    memset(&send_msg, 0, sizeof(send_msg));
    memcpy(&rev_usr, msg, sizeof(rev_usr));

    //用户的状态是注册，进行注册
    if(rev_usr.state == LOGIN)
    {
        sign = log_in(msg);
	write(socket_fd,&sign,1);              //返回注册结果
    }

    //用户的状态是登录，进行登录
    if(rev_usr.state == REGISTER)
    {
        sign = register_usr(msg, socket_fd);
	write(socket_fd,&sign,1);            //返回登录结果
    }

    //用户请求群发消息
    if(rev_usr.state == GROUP)
    {
        //对用户要求群发的信息进行封装
        memcpy(&rev_msg, msg, sizeof(rev_msg));
        memset(&send_msg, 0, sizeof(send_msg));
        strcat(send_msg,rev_msg.my_id);
        strcat(send_msg,":");
        strcat(send_msg,rev_msg.msg);
       
	link_s p;
	//找出在新用户将封装好的信息发送
	for(p=head; p; p=p->next)
	{
	    if((p->login_num!=0)&&(p->login_num!=socket_fd))
	    {
	        write(p->login_num,send_msg,sizeof(send_msg));
	    }
	}

	write(chatfd, send_msg, sizeof(send_msg));    //保存消息记录
	write(chatfd, "\n", 1);
    }

    //用户请求私聊
    if(rev_usr.state == PRIVATE)
    {
        //封装私聊信息
        memcpy(&rev_msg, msg, sizeof(rev_msg));
        memset(&send_msg, 0, sizeof(send_msg));
        strcat(send_msg,rev_msg.my_id);
        strcat(send_msg,":");
        strcat(send_msg,rev_msg.msg);
        
	link_s p;
	//找出用户要发送信息的对象，发送信息
	for(p=head; p; p=p->next)
	{
	    if((strcmp(p->usr_id,rev_msg.to_id) == 0)&&(p->login_num!=0))
	    {
	        write(p->login_num,send_msg,sizeof(send_msg));
	    }
	}
	
	write(chatfd, send_msg, sizeof(send_msg));//保存聊天记录
	write(chatfd, "\n", 1);
    }

    //用户请求查看在线用户
    if(rev_usr.state == CAT_ONLINE)
    {
        memset(&send_msg, 0, sizeof(send_msg));
        
	link_s p;
        for(p=head; p; p=p->next)
	{
	    if(p->login_num!=0)
	    {
		strcat(send_msg, p->usr_id);
		strcat(send_msg, "&&");
	    }
	}

	write(socket_fd, send_msg, sizeof(send_msg));
    }
}
