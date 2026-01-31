#include <stdio.h>

#define pane_num 64   //方格数

void grains_total(); //计算米粒函数声明

int main()
{
    grains_total();

    return 0;
}

void grains_total()
{
   int count = 0;  //记录方格数
   double total = 0; //记录米粒总数
   double current = 0.5; //记录当前方格的米粒数

   printf("pane_num    current        total\n");

   while (count < pane_num)
   {
        count = count + 1;
        current = current * 2;
        total = total + current;
        printf("%5d %15.4f %12.2f\n", count, current, total); //每计算一个方格的米粒数便打印出来。其中15.4e中15表示空白字段数，.4表示取的小数的有效位数。
   }
}
