#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*

int Setting(char password[]);
功能：设置密码
参数：passWord，存放密码数组，大小为20个字符;
返回值：设置成功返回1，设置失败返回0。

*/

int Setting(char password[])
{
    int flag = 0;
    puts("Please input password with 8 characters:");
    gets(password);
    if(strlen(password)!=8) return 0;

    puts("Please input again:");
    char *a = (char*)malloc(sizeof(char)*22);
    gets(a);
    if(strcmp(a,password) == 0) return 1;

    return flag;
}

int main(void)
{
    char psw[22];
    int flag = Setting(psw);
    if(flag) printf("Successfully set password:%s\n",psw);
    else printf("Failure!\n");
    return 0;
}
