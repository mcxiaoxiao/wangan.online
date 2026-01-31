#include<stdio.h>
#include<math.h>

int main(void)
{
//    // 判断闰年
//    int year = 0;
//    scanf("%d", &year);
//    int flag = year%4==0 && year%100!=0 || year%400==0 ? 1 : 0;
//    if(flag) printf("run");
//    else printf("NO");

    //大小写 转化 打印ASCII码
    char ch;
    scanf("%c",&ch);
    if(ch>='A'&&ch<='Z')
    {
        ch+=0x20;
        printf("%c-->%d-->%X",ch,ch,ch);
    }
    else if(ch>='a'&&ch<='z')
    {
        ch-=0x20;
        printf("%c-->%d-->%X",ch,ch,ch);
    }
    else printf("%c-->%d-->%X",ch,ch,ch);
    return 0;
}
