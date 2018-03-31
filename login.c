#include <stdio.h>
#include <string.h>

int main() {
    
    FILE *file;
    
    int studentID;
    char password[20];
    
    int id;
    char fname[20];
    char lname[20];
    char pass[20];
    char mobile[20];
    
    int c = 0;
    int d = 0;
    
    printf("------LOGIN PAGE-----\n");
    
    printf("StudentID: ");
    scanf("%d", &studentID);
    
    printf("Password: ");
    scanf("%s", &password);
    
    
    file = fopen("user.txt", "r");
    
    // READ FILE
    while(1) {
        
        int stop = fscanf(file, "%d %s %s %s %s", &id, &fname, &lname, &pass, &mobile);
        if(stop == EOF) {
            break;
        }
        
        // CHECK LOGIN
        if(id == studentID) {
                c = 0;
            if(strcmp(pass, password) == 0) {
                printf("欢迎 '%s' 登录！", &lname);
                
                d = 0;
                break;
            } else {
                d = 1;
            }
        } else {
            c = 1;
        }

    }
    
    if(c) {
        printf("用户名错误！");
    }
    if(d) {
        printf("密码错误！");
    }
    printf("\n");
    return 0;
}
