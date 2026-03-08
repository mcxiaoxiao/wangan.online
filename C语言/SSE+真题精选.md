> Tips：以下题目精选自哈工大SSE课后题、SSE其它中难题、往年真题，基本可以反映哈工大计算学部复试编程题的实际难度，可以作为复试编程的练习材料，答案仅供参考。**复试编程题判分时若运行失败会基于语义给分，只写了hello world也会给分；代码不允许粘贴但是可以复制到codeblock运行&调试。**

1. 输入圆的半径r，计算并输出圆的周长和面积
圆周率取值3.14159.
**输入格式要求："%f" 提示信息："Input r:"**
**输出格式要求："circum = %.2f\n" "area = %.2f\n"**
程序运行示例如下：
Input r:3.5
circum = 21.99
area = 38.48
	```
	#include <stdio.h>
	#define pie 3.14159
	int main()
	{
		float a, area, circum;
		printf("Input r:");
		scanf("%f",&a);
		circum=2*pie*a;
		area=pie*a*a;
		printf("circum = %.2f\narea = %.2f\n",circum,area);
		return 0;
	}

	```

2. 字符串排序
输入一个字符串，长度小于等于200，然后将输出按字符顺序升序排序后的字符串。
输入描述：
测试数据有多组，输入字符串。
输出描述：
对于每组输入,输出处理后的结果。
示例1
输入：
bacd
输出：
abcd

	```
	#include<stdio.h>
	#include<string.h>
	//插入排序
	void sort1(char input[], int len) {
		int i, j, min_idx;
		char temp;
		for (i = 0; i < len - 1; i++) {
			min_idx = i;
			for (j = i + 1; j < len; j++) {
				if (input[j] < input[min_idx]) {
					min_idx = j;
				}
			}
			temp = input[min_idx];
			input[min_idx] = input[i];
			input[i] = temp;
		}
	}

	//冒泡排序
	void sort2(char input[], int len) {
		int i, j;
		char tmp;
		for (i = 0; i < len - 1; i++) {
			for (j = 0; j < len - 1 - i; j++) {
				tmp = input[j];
				if (input[j] > input[j + 1]) {
					input[j] = input[j + 1];
					input[j + 1] = tmp;
				}
			}
		}
	}


	int main() {
		char input[200];

		while (scanf("%s",&input) != EOF) {
			int len = strlen(input);
		
			sort1(input,len);
			printf("%s",input);

			// sort2(input,len);
			// printf("%s",input);
		}
		return 0;
	}

	```

3. 计算两个矩阵的乘积
计算两个矩阵的乘积，第一个是2*3,第二个是3*2
输入描述：
输入为两个矩阵，其中一个为2*3的矩阵，另一个为3*2的矩阵
输出描述：
一个2*2的矩阵（每一个数字后都跟一个空格）
示例1
输入：
1 2 3
3 4 5
6 7
8 9
10 11
输出：
52 58
100 112
	```#include <stdio.h>

	int main() {
		int a[2][3], b[3][2], c[2][2];
		int i,j;
		for (i=0;i<2;i++){
			for(j=0;j<3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for (i=0;i<3;i++){
			for(j=0;j<2;j++){
				scanf("%d",&b[i][j]);
			}
		}
		
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				int sum;
				sum = a[i][0]*b[0][j] + a[i][1]*b[1][j] + a[i][2]*b[2][j];
				printf("%d ",sum);
			}
			printf("\n");
		}

		return 0;
	}```

4.  百万富翁问题
一个百万富翁遇到一个陌生人，陌生人找他谈了一个换钱的计划。该计划如下：我每天给你10 万元，你第一天给我1 分钱，第二天2 分钱，
第三天4 分钱……
这样交换 30 天后，百万富翁交出了多少钱？陌生人交出了多少钱？（注意一个是万元，一个是分）
输入描述：
该题没有输入
输出描述：
输出两个整数，分别代表百万富翁交出的钱和陌生人交出的钱，富翁交出的钱以万元作单位，陌生人交出的钱以分作单位。
	```#include <stdio.h>
	#include <math.h>
	int main() {
		int a, b=0, tmp;
		for (a=1; a<=30; a++) {
			tmp = pow(2, a-1);
			b+=tmp;
		}
		printf("300 %d",b);

		return 0;
	}```

5. 最大公约数
描述
输入两个正整数，求其最大公约数。
输入描述：
测试数据有多组，每组输入两个正整数。
输出描述：
对于每组输入,请输出其最大公约数。
示例1
输入：
49 14
输出：
7
	```
	#include <stdio.h>

	int main() {
		int a, b, tmp;
		scanf("%d %d",&a,&b);
		while (a != b && a != 0 && b != 0) {
			if(a>b){
				a = a % b;
			}
			else {
				b = b % a;
			}
		}
		tmp = (a >= b) ? a : b;
		printf("%d",tmp);
		return 0;
	}
	```