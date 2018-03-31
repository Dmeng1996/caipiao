#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 100
struct user
{
int user_id;
char user_name[19];//最大18位
char password[13];//最大13位
char like[255];
char sign[255];
};

/*
* 验证用户名长度是否合法
*/
int length_user_name(char *p)
{
int l;
l=strlen(p);
if(l>18||l<1)
{
   return 0;
}
else
   return l;
}

/*
* 判断用户名是否有效
*/
int valid_user_name(char *p)
{
int i=0;
int len = strlen(p);
if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <='Z')) //判断首字符是不是字母
{
   for(i = 0; i < len; i++)
   {
    if(!(p[i] == '_' || (p[i] >= 'a' && p[i] <= 'z') || (p[i] >= 'A' && p[i] <='Z')
     ||(p[i] >='0' && p[i] <= '9'))) //判断后面字符是否有效
     return 0;

   }
   return 1;
}
else
   return 0;

}

/*
* 判断用户名是否有效
*/
int is_username_valid(char *p)
{
if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <='Z'))
{
   p++;
   while(*p)
   {
    if(!(isalpha(*p) || *p == '_' || isdigit(*p)))
     return 0;
    p++;
   }

   return 1;
}
else
{
   return 0;
}
}

/*
* 密码长度有效性验证
*/
int length_password(char *p)
{
int len;
len = strlen(p);
if(len<6||len>12)
{
   return 0;
}
else
   return len;
}

/*
* 密码的有效性验证
*/
int is_password_valid(char *p)
{
int i=0;

for(;*p != '\0'; p++)
{
   if(!( (*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <='Z')
    ||(*p >='0' && *p <= '9'))) //判断字符是否有效
    return 0;
}
return 1;
}

int two_password_valid(char *p1,char*p2)
{
if(strcmp(p1,p2)==0)
   return 1;
else
   return 0;
}

/*
* 完成注册功能
*/
int user_register(struct user *ptr_user,int size)
{
char password[13];
char repassword[13];
if(size==N)
{
   puts("注册人数以满!");
   return 0;
}
printf("请输入注册姓名:");
fflush(stdin);
gets(ptr_user[size].user_name);
if(!(length_user_name(ptr_user[size].user_name)&&valid_user_name(ptr_user[size].user_name)))
{
   printf("您输入的姓名无效,用户名在1-18之间,首字符为字母,后面必须为字母,数字或下划线!!!");
   return 0;
}

printf("请输入注册密码:");
fflush(stdin);
gets(password);
printf("请再次输入注册密码:");
fflush(stdin);
gets(repassword);
if(!two_password_valid(password,repassword))
{
   printf("\n两次输入的密码不一致!");
   return 0;
}
else
{
   strcpy(ptr_user[size].password,password);
}

if(!(length_password(ptr_user[size].password)&&is_password_valid(ptr_user[size].password)))
{
   printf("您输入的密码无效,密码应在6-12之间,密码只能包含字母和数字!!!");
   return 0;
}

printf("请输入您的爱好:");
fflush(stdin);
gets(ptr_user[size].like);
printf("请输入您的个性签名:");
fflush(stdin);
gets(ptr_user[size].sign);
printf("您的编号为:%d,这将是您的登陆帐号.",ptr_user[size].user_id=10000+size);
return 1;
}

/*
* 如果登陆成功则返回第i+1个用户的信息,否则返回0
*/
int is_my_user(struct user *p,int size)
{
int i;
int zhanghu;
char mima[15];
printf("请输入您的帐号: ");
scanf("%d",&zhanghu);
fflush(stdin);
printf("请输入您的密码: ");
gets(mima);
for(i=0;i<size;i++)
{
   if((zhanghu == p[i].user_id)&&(strcmp(mima,p[i].password)==0))
   {

    return i + 1;
   }
}
return 0;
}

void display_user(struct user u)
{
printf("\n你的帐号是:%d",u.user_id);
printf("\n你注册姓名是:%s",u.user_name);
printf("\n你的爱好:%s",u.like);
printf("\n你的个性签名:%s",u.sign);
}

void update_password(struct user *ptr_user,int size)
{
char mima1[13],mima2[13];
int i = is_my_user(ptr_user,size);
if(i)
{
   i--;
}
else
{
   printf("\n帐号密码不存在!");
   return;
}

printf("请输入新密码: ");
scanf("%s",mima1);
printf("请再次输入新密码: ");
scanf("%s",mima2);

if(two_password_valid(mima1,mima2) && length_password(mima1) && is_password_valid(mima1))
{
   strcpy(ptr_user[i].password,mima1);//完成新旧密码的调换
   printf("\n您的的密码修改成功!");
}
else
   printf("\n您的密码修改失败!");

}

//显示菜单
int show_menu()
{
int choice;
printf("\n1.注册");
printf("\n2.登陆");
printf("\n3.修改密码");
printf("\n4.退出");
printf("\n请选择1-4\n");
scanf("%d",&choice);

return choice;
}

int main()
{
struct user our_users[N];
int count = 0;
int current_user;
while(1)
{
   switch(show_menu())
   {
    case 1:
     if(user_register(our_users,count))
     {
      count++;
      printf("\n注册成功!");
     }
     break;
     //注册
    case 2:
     if((current_user = is_my_user(our_users,count)))
     {
      printf("\n登陆成功!");
      display_user(our_users[current_user - 1]);
     }
     else
      printf("\n登陆失败!");
      break;
     //登陆
    case 3:
     update_password(our_users,count);
      break;
     //修改密码
    case 4:
     exit(1);
     break;
     //退出
    default:
     printf("请正确输入");
   }
}
return 0;
} 