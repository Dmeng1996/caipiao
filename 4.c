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

int show_menu()
{
int choice;
printf("\n1.购买");
printf("\n2.修改");
printf("\n3.查询");
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
      printf("\n购买成功!");
     }
     break;
     //注册
    case 2:
     if((current_user = is_my_user(our_users,count)))
     {
      printf("\n修改成功!");
      display_user(our_users[current_user - 1]);
     }
     else
      printf("\n修改失败!");
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