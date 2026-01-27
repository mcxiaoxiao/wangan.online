#include<stdio.h>
int main()
{
//    //maix
//    printf("man\twoman\tchildren\n");
//    int i, j;
//    for(i = 0; i <=30; i++)
//        for(j = 0; j <= 30-i; j++)
//            if(3*i+2*j+30-i-j==50) printf("%d\t%d\t%d\n",i,j,30-i-j);
//

//    //鸡兔同笼
//    for(int i = 0;i <= 98; i++)
//    {
//        if(2*i+4*(98-i)==386)printf("%d\t%d",i,98-i);
//    }

//    // 百元百鸡
//    for(int i = 0; i <= 20; i++)
//        for(int j = 0; j <= 100-i; j+=3)
//            if(5*i+j/3+3*(100-i-j) == 100)printf("%d\t%d\t%d\n",i,100-i-j,j);

//    int count = 0;
//    for(int i = 1; i <= 10; i++)
//        for(int j = 1; j <=20 - i; j ++)
//            if(i+j!=50&&10*i+5*j+(50-i-j)==100)
//            {
//                count++;
//                printf("%d\t%d\t%d\n",i,j,50-i-j);
//            }
//    printf("count=%d",count);


//    // 9x9 乘法表
//    for(int i = 1; i <=9; i ++)
//    {
//        for(int j = 1; j<=9; j++)
//            if(i<=j)printf("%d\t",i*j);
//            else printf("\t");
//        puts("");
//    }

//    // 换钱
//    float a = 0.01,sum=0.01;
//    for(int i = 1; i<30;i++)
//    {
//        a*=2;
//        sum+=a;
//    }
//    printf("%f=%f",sum/10000,10.0*30);

    for(int i = 31; i < 100; i ++)
    {
        int term = i * i;
        if(term > 1100)
        {
            int b0 = term % 10;
            int b1 = term/10%10;
            int b2 = term/100%10;
            int b3 = term/1000;
            if(b0 == b1 && b2==b3 && b0+b1*10 != b2+b3*10) printf("%d\t%d\n",term,i);
        }
    }
    return 0;
}
