#include <stdio.h>

int main() {

    FILE *file;
    
    char fname[20];
    char lname[20];
    char password[20];
    int studentID;
    int mobile;
    
    
    printf("------REGISTER PAGE-----\n");
    
    printf("First name: ");
    scanf("%s", &fname);
    
    printf("Lastname: ");
    scanf("%s", &lname);
    
    printf("StudentID: ");
    scanf("%d", &studentID);
    
    printf("password: ");
    scanf("%s", &password);
    
    printf("Mobile phone: ");
    scanf("%d", &mobile);
   
    file = fopen("user.txt", "a+");
    fprintf(file, "%d %s %s %s %d\n", studentID, fname, lname, password, mobile);
    
    fclose(file);
    
    printf("注册成功！\n");
    return 0;   
}
