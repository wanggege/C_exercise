#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "chat_login.h"

#define CHOOSESIZE      10
#define PASSWARD        16
#define STDIN           0
#define STDOUT          1
#define LOGIN           0
#define REGISTER        1

char ownerid[16];                    //用户id

/******************************************************
函 数 名：print_star
功    能：打印边框
******************************************************/
void print_star(void)
{
    printf("%s\n","***************************************************");
}

/*******************************************************
函 数 名：chat_login
功    能：用户登录，注册处理
参    数：sockfd:用户使用的套接字 login_p:结构体指针
*******************************************************/
void chat_login(int sockfd,link_c login_p)
{
    char choose_buf[CHOOSESIZE];               //用户登录或者注册选项缓冲区
    char passward[PASSWARD];                   //密码存放缓冲区
    char result;                               //处理结果
    int nbyte;

    login_p = (link_c)malloc(sizeof(*login_p));
    if(login_p == NULL)
    {
        printf("malloc fail,try again\n");
	exit(1);
    }

    print_star();
    printf("          welcome to happy paradise chatroom        \n");
    printf("          0.login(注册)\n          1.register(登录)\n          2.exit(退出)\n");
    print_star();

    printf("请输入你的服务选项\n");
    if((nbyte = read(STDIN, choose_buf, sizeof(choose_buf))) < 0)
    {
        perror("read in");
	exit(1);
    }

    choose_buf[nbyte] = '\0';

   // printf("%d\n",sizeof(choose_buf));
   // printf("%d\n",sizeof("login"));

     if(((strncmp(choose_buf,"login",5))==0)||((strncmp(choose_buf,"0",1))==0))
    {
        login:
             memset(&login_p->usr_id, 0, sizeof(login_p->usr_id));
             printf("请输入 1~16 id号\n");
	     fscanf(stdin ,"%s", login_p->usr_id);

        login_pwd:
                 memset(&login_p->usr_pwd, 0, sizeof(login_p->usr_pwd));
	         printf("请输入 1~16 密码\n");
		 fscanf(stdin, "%s", passward);
	         printf("请再次输入您的密码\n");
		 fscanf(stdin, "%s", login_p->usr_pwd);
		 if((strncmp(login_p->usr_pwd, passward, sizeof(passward)))!=0)
		 {
		     printf("两次输入的密码不相同，再试一次\n");
		     goto login_pwd;
		 }

		 login_p->state = LOGIN;
		 login_p->login_num = 0;

		 write(sockfd, (char *)login_p, sizeof(*login_p));
		 read(sockfd, &result, 1);

		 switch(result)
		 {
		     case '1':
		           printf("注册成功请登录\n");
			   goto registe;
	             case '0':
			   printf("该用户id已被注册，请重新注册\n");
			   goto login;

		 }

    }

    if(((strncmp(choose_buf, "register", 8))==0)||((strncmp(choose_buf, "1",1))==0)) 
    {
        registe:
              memset(&login_p->usr_id, 0, sizeof(login_p->usr_id));
              printf("请输入您的id\n");
	      fscanf(stdin ,"%s", login_p->usr_id);
	      
              memset(&login_p->usr_pwd, 0, sizeof(login_p->usr_pwd));
	      printf("请输入您的密码\n");
	      fscanf(stdin, "%s", login_p->usr_pwd);

	      login_p->state = REGISTER;
	      login_p->login_num = 0;

	      write(sockfd, (char *)login_p, sizeof(*login_p));
	      read(sockfd, &result, 1);

	      switch(result)
	      {
	          case '1':
		        printf("登录成功，感谢您的使用，请按提示操作\n");
			strncpy(ownerid, login_p->usr_id, sizeof(login_p->usr_id));
			break;
	          case '2':
			printf("该用户已登录，请登录其他用户\n");
			goto registe;
		  case '0':
			printf("密码错误\n");
			goto registe;
	      }
    }
    
    if(((strncmp(choose_buf,"exit",4))==0)||((strncmp(choose_buf,"2",1))==0))
    {
        exit(1);
    }

}
