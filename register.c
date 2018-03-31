#include <stdio.h>

int main() {

    FILE *file;
    
    char fname[20];
    char lname[20];
    char password[20];
    int manid;
    int count;
    int cpid;
    
    
    printf("------REGISTER PAGE-----\n");
    
    printf("姓: ");
    scanf("%s", &fname);
    
    printf("名: ");
    scanf("%s", &lname);

    printf("manid: ");
    scanf("%d", &manid);

    printf("密码: ");
    scanf("%s", &password);

    printf("请输入充值金额: ");
    scanf("%d", &count);
    
    printf("彩票有以下编号: ");
    
    for(int i = 0;i < 10;i++)
    {
        cpid=i;
        printf("%d,",cpid);

    }

    
   
    file = fopen("user.txt", "a+");
    fprintf(file, "%s %s %d %s %d\n",fname, lname, manid, password, count );
    
    fclose(file);
    
    printf("\n注册成功！\n");
    return 0;   
}
