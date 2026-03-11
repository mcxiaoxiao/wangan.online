# 序言

> Rule 3: Fancy algorithms are slow when n is small, and n is usually small. Fancy algorithms have big constants. Until you know that n is frequently going to be big, don't get fancy. (Even if n does get big, use Rule 2 first.)
> Rule 4: Fancy algorithms are buggier than simple ones, and they're much harder to implement. Use simple algorithms as well as simple data structures.

**来源**：Rob Pike，Unix 先驱、Go 语言创始人，出自 *Notes on Programming in C*（1989）与 *Rob Pike's 5 Rules of Programming*。

---

请原谅我在考研资料中有时融入一些主观表达，但在讨论算法学习与工程实践时，仅靠客观罗列知识，往往难以触及真正重要的问题。

我在中学阶段便主动选择放弃算法竞赛，这不仅是因为我对和人竞争抱有抵触，更是出于对现实与未来的理性考量。在我看来，算法竞赛与小学奥数颇为相似：它擅长在封闭、理想化的题目里，用精巧的技巧追求理论上的最优解，却常常与真实工程场景严重脱节。长期沉浸其中，很容易让人沉迷于花哨的算法、极致的复杂度优化，反而忘掉了工程里最朴素的真理：现实场景中数据规模通常有限，简单、稳定、易维护、不易出错的方案，远比看上去高深的算法更有价值。过度崇拜竞赛思维，本质上是把工程能力窄化为解题技巧，也让编程远离了“解决真实问题”这一初心。

当然，参与竞赛本身无可厚非，只是我更希望表达这样一种观点：**比堆砌复杂度更重要的，是理解问题、权衡取舍、做出真正适合场景的设计**。令我欣慰的是，哈工大的复试并没有把C语言题目设置得过分不切实际、刻意追求复杂，而是更看重基础、逻辑与工程素养。在广阔的计算机世界里，比“更复杂、更巧妙”更有意义的事情，还有太多太多太多。


> Tips：以下题目精选自哈工大SSE课后题、SSE其它中/难题、往年真题，基本可以反映哈工大计算学部复试编程题的实际难度，可以作为复试编程的练习材料，答案仅供参考。**复试编程题判分时若运行失败会基于语义给分，只写了hello world也会给分；代码不允许粘贴但是可以复制到codeblock运行&调试。** 扩展材料：[SSE-C](https://www.nowcoder.com/discuss/353150336095428608) [SSE-改错-1](https://www.nowcoder.com/discuss/353150338465210368) [SSE-改错-2](https://www.nowcoder.com/discuss/353150338620399616) [SSE-改错-3](https://www.nowcoder.com/discuss/353150338934972416)

# 0. 经典的链表
编程题一般不会让大家写，改错题也不会在这里太刁难大家，但是有必要先熟悉一下：
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 定义经典的单向链表节点结构体
typedef struct Node {
    // 数据域：存储整型数据（可替换为char/结构体等）
    int data;
    // 指针域：指向下一个节点
    struct Node *next;
} ListNode, *LinkedList;

// 2. 创建新节点（链表操作的基础工具函数）
ListNode* createNode(int data) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    return node; // 返回值类型为 ListNode*，是一个指向新节点的指针
}

// 3. 初始化链表（创建头节点，空链表）
LinkedList initList() {
    // 头节点：不存储有效数据，仅用于简化操作（经典设计），即有next而没有data
    ListNode *head = createNode(-1); //*head是头节点指针，head->next是第一个有效节点指针
    return head;
}

// 4. 尾插法添加节点（最常用的链表构建方式）
void addNode(LinkedList head, int data) {
    ListNode *newNode = createNode(data);
    ListNode *cur = head;
    // 找到最后一个节点
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}

// 5. 遍历链表并打印
void traverseList(LinkedList head) {
    if (head->next == NULL) { // 空链表判断
        printf("链表为空！\n");
        return;
    }
    ListNode *cur = head->next; // 跳过头节点，从第一个有效节点开始
    printf("链表内容：");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// 6. 按位置插入节点（pos从1开始，比如pos=1插入到第一个位置）
int insertNode(LinkedList head, int pos, int data) {
    if (pos < 1) { // 位置合法性判断
        printf("插入位置不合法！\n");
        return 0;
    }
    ListNode *cur = head;
    int curPos = 0;
    // 找到插入位置的前一个节点
    while (cur != NULL && curPos < pos - 1) {
        cur = cur->next;
        curPos++;
    }
    if (cur == NULL) { // 位置超出链表长度
        printf("插入位置超出链表长度！\n");
        return 0;
    }
    // 插入新节点（经典的链表插入逻辑）
    ListNode *newNode = createNode(data);
    newNode->next = cur->next;
    cur->next = newNode;
    return 1;
}

// 7. 按位置删除节点（pos从1开始）
int deleteNode(LinkedList head, int pos) {
    if (pos < 1 || head->next == NULL) {
        printf("删除位置不合法或链表为空！\n");
        return 0;
    }
    ListNode *cur = head;
    int curPos = 0;
    // 找到删除位置的前一个节点
    while (cur != NULL && curPos < pos - 1) {
        cur = cur->next;
        curPos++;
    }
    if (cur == NULL || cur->next == NULL) { // 位置无效
        printf("删除位置超出链表长度！\n");
        return 0;
    }
    // 删除节点（经典的链表删除逻辑）
    ListNode *delNode = cur->next;
    cur->next = delNode->next;
    free(delNode); // 释放内存，避免泄漏
    return 1;
}

// 8. 销毁链表（释放所有节点内存）
void destroyList(LinkedList head) {
    ListNode *cur = head;
    while (cur != NULL) {
        ListNode *temp = cur;
        cur = cur->next;
        free(temp); // free掉的是一个节点指针，不是节点本身
    }
    printf("链表已销毁！\n");
}

// 主函数：演示所有核心操作
int main() {
    // 1. 初始化链表
    LinkedList list = initList();
    
    // 2. 尾插法添加节点
    addNode(list, 10);
    addNode(list, 20);
    addNode(list, 30);
    traverseList(list); // 输出：链表内容：10 20 30 
    
    // 3. 插入节点（在第2个位置插入25）
    insertNode(list, 2, 25);
    traverseList(list); // 输出：链表内容：10 25 20 30 
    
    // 4. 删除节点（删除第3个节点）
    deleteNode(list, 3);
    traverseList(list); // 输出：链表内容：10 25 30 
    
    // 5. 销毁链表
    destroyList(list);
    
    return 0;
}
```

# 1. 输入圆的半径r，计算并输出圆的周长和面积
圆周率取值3.14159.
**输入格式要求："%f" 提示信息："Input r:"**
**输出格式要求："circum = %.2f\n" "area = %.2f\n"**
程序运行示例如下：
Input r:3.5
circum = 21.99
area = 38.48
```c
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

# 2. 字符串排序
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

```c
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

# 3. 计算两个矩阵的乘积
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
```c
#include <stdio.h>

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
}
```

# 4.  百万富翁问题
一个百万富翁遇到一个陌生人，陌生人找他谈了一个换钱的计划。该计划如下：我每天给你10 万元，你第一天给我1 分钱，第二天2 分钱，
第三天4 分钱……
这样交换 30 天后，百万富翁交出了多少钱？陌生人交出了多少钱？（注意一个是万元，一个是分）
输入描述：
该题没有输入
输出描述：
输出两个整数，分别代表百万富翁交出的钱和陌生人交出的钱，富翁交出的钱以万元作单位，陌生人交出的钱以分作单位。
```c
#include <stdio.h>
#include <math.h>
int main() {
	int a, b=0, tmp;
	for (a=1; a<=30; a++) {
		tmp = pow(2, a-1);
		b+=tmp;
	}
	printf("300 %d",b);

	return 0;
}
```

# 5. 最大公约数
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
```c
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

# 6. 找x
输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出-1）。
输入描述：
测试数据有多组，输入n(1<=n<=200)，接着输入n个数，然后输入x。
输出描述：
对于每组输入,请输出结果。
示例1
输入：
2
1 3
0
输出：
-1
示例2
输入:
100
1067 1051 1018 1044 1080 1055 1008 1029 1056 1070 1084 1085 1005 1023 1061 1098 1079 1057 1074 1027 1019 1091 1028 1021 1076 1089 1012 1075 1024 1099 1009 1077 1014 1040 1071 1072 1064 1017 1060 1020 1037 1087 1073 1004 1069 1097 1001 1039 1000 1090 1025 1034 1016 1068 1032 1042 1011 1010 1007 1038 1033 1052 1096 1006 1088 1041 1035 1031 1054 1086 1043 1050 1059 1066 1013 1022 1083 1036 1094 1058 1003 1048 1015 1047 1002 1078 1062 1026 1063 1082 1045 1030 1095 1046 1053 1081 1065 1092 1049 1093
1018
输出:
2

```c
#include <stdio.h>
int main() {
	int a, b, arr[200];
	scanf("%d",&a);
	for (int i=0; i<a; i++) {
		scanf("%d",&arr[i]);
	}
	scanf("%d",&b);

	for (int i=0; i<a; i++) {
		if(arr[i] == b){
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
```


# 7. 字符串链接
描述
不用strcat 函数，自己编写一个字符串链接函数MyStrcat(char dstStr[],charsrcStr[])
输入描述：
两个字符串，字符串由小写字母组成。
输出描述：
链接后的字符串
示例1
输入：
hello world
good morning
输出：
helloworld
goodmorning
```c
#include <stdio.h>

int main() {
	char a, b[100000];
	int tmp = 0;
	while ( (a = getchar()) != EOF) { 
		if (a != ' ') {
			b[tmp] = a;
			tmp++;
		}
		
	}
	printf("%s", b);
	return 0;
}
```


# 8. 结构体数组按指定字段排序
定义如下结构体类型 struct Res，用于描述资源信息：
	```c
	struct Res {
		// 资源编号
		int id;
		// 资源名称（长度不超过9个字符）
		char name[10];
		// 资源访问次数
		int accessCount;
	};
	```
将排序后的结构体数组中的每条数据，按 id name accessCount 的格式输出到标准输出，每行输出一条数据；
输出 n 行数据，每行对应排序后的一条资源信息，格式为：id name accessCount，字段之间用单个空格分隔。

示例 1：

输入

3
1 book 50
2 video 80
3 audio 30

输出

2 video 80
1 book 50
3 audio 30

```c
#include <stdio.h>
#include <string.h>

typedef struct{
    int id;
    char name[10];
    int accessCount;
} Res;

int main() {
    int n;
    scanf("%d", &n);
    Res Resources[n];

    // 输入 n 条数据
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d",
            &Resources[i].id,
            &Resources[i].name,
            &Resources[i].accessCount);
    }

    // 按 accessCount 从大到小排序（冒泡排序）
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (Resources[j].accessCount < Resources[j+1].accessCount) {
                // 交换两个结构体
                Res temp = Resources[j];
                Resources[j] = Resources[j+1];
                Resources[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %s %d\n",
            Resources[i].id,
            Resources[i].name,
            Resources[i].accessCount);
    }

    return 0;
}
```

# 9. 飞船航行
飞船第 1 年航行 0.01 光年，第 2 年 0.03 光年，从第 3 年起每年航行距离是前两年之和。输入年数 n，求 n 年航行的总距离。
若 n 不合法（如 n<1），输出error并终止程序；
合法则用float数组计算并输出总距离。
示例：
I O
1	0.01
2	0.04
3	0.08
0	error
-2	error
```c
int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("error\n");
        return 0; 
    }

    float dist[1000];
    dist[0] = 0.01;
    dist[1] = 0.03;

    for (int i = 2; i < n; i++) {
        dist[i] = dist[i-1] + dist[i-2];
    }

    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += dist[i];
    }

    printf("%f\n", sum);
    return 0;
}
```


# 10. 字符串连接
输入一个字符串 `a`（长度不超过 10 个字符），将 `a` 逆置得到字符串 `b`，然后将 `b` 连接到 `a` 的末尾，输出拼接后的新字符串。

**注意**：
- 需定义 `char a[21]` 作为存储数组，因为：
  - 输入字符串 `a` 最多 10 个字符，加上结束符 `'\0'` 共 11 个字节；
  - 逆置后的字符串 `b` 最多 10 个字符，加上结束符 `'\0'` 共 11 个字节；
  - 拼接后总长度为 20 个有效字符 + 1 个结束符，共 21 个字节。



```c
#include <stdio.h>
#include <string.h>

int main() {
    // 按题目要求定义足够大的数组
    char a[21] = {0};
    char b[11] = {0};

    // 输入字符串 a
    scanf("%10s", a);

    int len = strlen(a);

    // 逆置 a 得到 b
    for (int i = 0; i < len; i++) {
        b[i] = a[len - 1 - i];
    }
    // 给 b 加上字符串结束符
    b[len] = '\0';

    // 将 b 连接到 a 的后面
    strcat(a, b);

    // 输出结果
    printf("%s\n", a);

    return 0;
}
```

示例：
| 输入 | 输出 |
|------|------|
| `abc` | `abccba` |
| `hello` | `helloolleh` |
| `a` | `aa` |




# 11. 素数判断、sqrt、mod

输入一个整数 \(n\)，找出所有**小于等于 \(n\)** 的正整数 \(x\)，使其满足以下全部条件：

1. \(x\) 是一个素数（质数）
2. \(x\) 除以 4 的余数为 1
3. \(x\) 除以 5 的余数为 1
4. \(x\) 除以 7 的余数为 3
5. \(x\) 除以 9 的余数为 4

输出所有满足条件的 \(x\)。


示例：
| 输入 \(n\) | 输出 | 说明 |
| :--- | :--- | :--- |
| 1000 | 661 | \(t=0\) 时，\(x=661\)，是素数。 |



```c
#include <stdio.h>
#include <math.h>

// 判断素数：返回1表示是素数，返回0表示不是
int isPrime(int x) {
    if (x <= 1) return 0;          // 小于等于1不是素数
    
    int sqrt_x = (int)sqrt(x);
    for (int i = 2; i <= sqrt_x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

// 判断是否满足所有余数条件：返回1表示满足，0表示不满足
int checkMod(int x) {
    // 条件1：x%4 == 1
    if (x % 4 != 1) return 0;
    // 条件2：x%5 == 1
    if (x % 5 != 1) return 0;
    // 条件3：x%7 == 3
    if (x % 7 != 3) return 0;
    // 条件4：x%9 == 4
    if (x % 9 != 4) return 0;
    // 所有条件都满足
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int x = 1; x <= n; x++) {
        if (checkMod(x) && isPrime(x)) {
            printf("%d\n", x);
        }
    }

    return 0;
}
```
# 12. 交换最大最小数
输入一个数n，然后输入n个数值各不相同，调换数组中最大和最小的两个数，然后输出。
输入描述：
测试数据有多组，输入n(1<=n<=20)，接着输入n个数。
输出描述：
对于每组输入,输出交换后的结果。
示例1
输入：
2
1 3
输出：
3 1

```c
#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    int arr[a];
    for (int i=0; i<a; i++) {
        scanf("%d",&arr[i]);
        arr[i];
    }

    int max=0,min=100000,maxidx=0,minidx=0;

    for (int i=0; i<a; i++) {
        if (arr[i]>max) {
            max=arr[i];
            maxidx=i;
        }
        if (arr[i]<min) {
            min=arr[i];
            minidx=i;
        }
    }

    arr[maxidx] = min;
    arr[minidx] = max;

    for (int i=0; i<a; i++) {
        printf("%d ",arr[i]);
    }

    return 0;
}
```

# 13. 完数
求1-n内的完数，所谓的完数是这样的数，它的所有因子相加等于它自身，比如6有3个因子1,2,3,1+2+3=6，那么6是完数。即完数是等于其所有因子（除了它自己）相加和的数。
输入描述：
    测试数据有多组，输入n，n数据范围不大。
输出描述：
    对于每组输入,请输出1-n内所有的完数。如有案例输出有多个数字，用空格隔开，输出最后不要有多余的空格。
示例1
输入：
6
输出：
6

```c
#include <stdio.h>

int isw(int in){
    int ans = 0;
    for (int i=1; i<in; i++) {
        if (in%i==0) {
            ans+=i;
        }
    }
    if (ans == in) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int sum;
    scanf("%d",&sum);
    for (int i=6; i<=sum; i++) {
        if (isw(i)) {
            printf("%d ",i);
        }
    }
    return 0;
}
```

14. 字符串去特定字符
描述
输入字符串s和字符c，要求去掉s中所有的c字符，并输出结果。
输入描述：
测试数据有多组，每组输入字符串s和字符c。
输出描述：
对于每组输入,输出去除c字符后的结果。
示例1
输入：
heallo
a
输出：
hello

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    char c;

    while (scanf("%s %c", s, &c) == 2) {
        int len = strlen(s);
        int idx = 0;

        for (int i = 0; i < len; i++) {
            if (s[i] != c) {
                s[idx++] = s[i];
            }
        }

        s[idx] = '\0';

        printf("%s\n", s);
    }

    return 0;
}

```

15. 判断三角形类型
给定三角形的三条边，a,b,c。判断该三角形类型。
输入描述：
测试数据有多组，每组输入三角形的三条边。
输出描述：
对于每组输入,输出直角三角形、锐角三角形、或是钝角三角形。
示例1
输入：
3 4 5
输出：
直角三角形
```c
/* @note 核心逻辑：根据勾股定理判断三边关系，再用 **勾股定理拓展规则** 判断钝角or锐角 */
#include <stdio.h>

// 交换两个数的函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    
    int a, b, c;

    // 循环读取多组输入，直到文件结束
    while (scanf("%d %d %d", &a, &b, &c) == 3) {
        // 第一步：对三边从小到大排序
        // 确保 a <= b <= c
        if (a > b) swap(&a, &b);
        if (a > c) swap(&a, &c);
        if (b > c) swap(&b, &c);
        
        // 计算平方，避免溢出用 long 类型
        long x2 = (long)a * a;
        long y2 = (long)b * b;
        long z2 = (long)c * c;
        
        // 判断三角形类型
        if (x2 + y2 == z2) {
            printf("直角三角形\n");
        } else if (x2 + y2 > z2) {
            printf("锐角三角形\n");
        } else {
            printf("钝角三角形\n");
        }
    }
    return 0;
}
```



# A 两数相加
哈工大计算学部复试机试2024改错题，来自[Leetcode 2](https://leetcode.cn/problems/add-two-numbers)，以下代码是正确的：
```c
/**
 * @brief 两数相加（LeetCode 第2题）
 * @param l1 第一个逆序存储数字的链表（如 1->2->3 表示 321）
 * @param l2 第二个逆序存储数字的链表（如 9->9 表示 99）
 * @return 两数之和的逆序链表（如 321+99=420 → 0->2->4）
 * @note 核心逻辑：模拟竖式加法，逐位相加并处理进位
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL, *tail = NULL; // head:结果链表头指针 tail:结果链表尾指针
    int carry = 0; // 进位值（0或1，因为两个个位数相加最大为9+9+1=19）

    // 循环条件：只要l1/l2有一个未遍历完，就继续计算
    while (l1 || l2) {
        // 取当前位的值，链表遍历完则取0（避免空指针访问）
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry; // 当前位总和 = l1位 + l2位 + 上一位进位

        // 初始化结果链表（第一次进入循环时）
        if (!head) {
            head = tail = malloc(sizeof(struct ListNode)); // 分配头、尾节点内存
            tail->val = sum % 10; // 取余数作为当前位结果（如19%10=9）
            tail->next = NULL;    // 尾节点next置空
        } else {
            // 非首次循环：在结果链表尾部追加新节点
            tail->next = malloc(sizeof(struct ListNode)); // 分配新节点内存
            tail->next->val = sum % 10;                   // 赋值当前位结果
            tail = tail->next;                            // 尾指针后移
            tail->next = NULL;                            // 新尾节点next置空
        }

        carry = (int) (sum / 10); // 更新进位（如19/10=1，09/10=0）
        // 链表指针后移（已遍历完的链表不再移动）
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }

    // 处理最后剩余的进位（如999+999=1998，最后进位1需要单独加节点）
    if (carry > 0) {
        tail->next = malloc(sizeof(struct ListNode)); // 分配进位节点
        tail->next->val = carry;                      // 赋值进位值
        tail->next->next = NULL;                      // next置空
    }

    return head; // 返回结果链表头指针
}
```
# B GCD辗转相除求最大公约数
```c
#include<stdio.h>
int Gdc(int a,int b);

int main()
{
    int a,b,x;
    scanf("%d,%d",a,b);
    x=Gdc(a,b);
    if(x<0)
        printf("Input Error!\n");
    printf("%d\n",x);
    return 0;
}

int Gdc(int a,int b)
{
    if(a<=0||b<=0)
        return -1;
    while(a!=b);
    {
        if(a>b)
            return a-b;
        else if(b>a)
            return b-a;
        else
            return a;
    }
}
```
修正：
```c
#include<stdio.h>
int Gdc(int a,int b);

int main()
{
    int a,b,x;
    scanf("%d,%d", &a, &b);  // 修正1：添加取地址符
    x=Gdc(a,b);
    if(x<0)
        printf("Input Error!\n");
    else
        printf("%d\n",x);  // 修正4：仅输入合法时输出结果
    return 0;
}

int Gdc(int a,int b)
{
    if(a<=0||b<=0)
        return -1;
    while(a!=b)  // 修正2：删除 while 后的分号
    {
        if(a>b)
            a = a - b;  // 修正3：更新变量而非直接返回
        else
            b = b - a;
    }
    return a;  // 循环结束时 a==b，即为最大公约数
}
```


# C 数组最大最小数换位
```c
#include<stdio.h>
#define ARR_SIZE 10
void MaxMinExchange(int a[],n)
{
    int maxValue,minValue,maxPos,minPos;
    int i,temp;
    maxValue=a[0];
    minValue=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>maxValue)
        {
            maxValue=a[i];
            maxPos=i;
        }
        if(a[i]<minValue)
        {
            minValue=a[i];
            minPos=i;
        }
    }
    temp=a[maxPos];
    a[maxPos]=a[minPos];
    a[minPos]=temp;
}
int main()
{
    int a[ARR_SIZE],i,n;
    printf("Input n(n<=10):");
    scanf("%d",&n);
    printf("Input %d Numbers:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    MaxMinExchange(a[],n);
    printf("After MaxMinExchange:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
```
修正：
```c
#include<stdio.h>
#define ARR_SIZE 10

// 修正1：补充参数n的类型
void MaxMinExchange(int a[], int n)
{
    int maxValue, minValue, maxPos, minPos;
    int i, temp;
    maxValue = a[0];
    minValue = a[0];
    maxPos = 0;  // 修正2：初始化位置变量
    minPos = 0;  // 修正2：初始化位置变量

    for (i = 0; i < n; i++)
    {
        if (a[i] > maxValue)
        {
            maxValue = a[i];
            maxPos = i;
        }
        if (a[i] < minValue)
        {
            minValue = a[i];
            minPos = i;
        }
    }

    // 交换最大值和最小值的位置
    temp = a[maxPos];
    a[maxPos] = a[minPos];
    a[minPos] = temp;
}

int main()
{
    int a[ARR_SIZE], i, n;
    printf("Input n(n<=10):");
    scanf("%d", &n);
    printf("Input %d Numbers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    MaxMinExchange(a, n);  // 修正3：函数调用时数组名直接传参，去掉 []

    printf("After MaxMinExchange:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
```

