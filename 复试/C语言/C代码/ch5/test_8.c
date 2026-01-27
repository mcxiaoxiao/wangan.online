#include<stdio.h>

int main(void)
{

//    //判断字符
//    char ch = getchar();
//    if(ch >= '1' && ch <= '9') puts("NUMBER");
//    else if(ch >= 'A' && ch <= 'Z') puts(" Big character!");
//    else if(ch >= 'a' && ch <= 'z') puts("small character!");
//    else if(ch == ' ') puts("space");
//    else puts("OTHERS");

    // 判断月份天数
    int y = 0, m = 0;
    scanf("%d%d",&y, &m);

    int flag = (y%4==0&&y%100!=0||y%400==0)?1:0;

    switch(m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("DATS:31");
        break;
    case 2:
        printf("%d",flag?29:28);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("30");
        break;
    default:puts("wrong");
    }
    return 0;
}
