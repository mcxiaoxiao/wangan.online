# 序言

> Rule 3: Fancy algorithms are slow when n is small, and n is usually small. Fancy algorithms have big constants. Until you know that n is frequently going to be big, don't get fancy. (Even if n does get big, use Rule 2 first.)
> Rule 4: Fancy algorithms are buggier than simple ones, and they're much harder to implement. Use simple algorithms as well as simple data structures.

**来源**：Rob Pike，Unix 先驱、Go 语言创始人，出自 *Notes on Programming in C*（1989）与 *Rob Pike's 5 Rules of Programming*。

---

请原谅我在考研资料中有时融入一些主观表达，但在讨论算法学习与工程实践时，仅靠客观罗列知识，往往难以触及真正重要的问题。



我在中学阶段便主动选择放弃算法竞赛，这不仅是因为我对和人竞争抱有抵触，更是出于对现实与未来的理性考量。在我看来，算法竞赛与小学奥数颇为相似：它擅长在封闭、理想化的题目里，用精巧的技巧追求理论上的最优解，却常常与真实工程场景严重脱节。过于重视这些东西容易让人沉迷于花哨的算法、极致的复杂度优化，反而忘掉了工程里最朴素的真理：现实场景中数据规模通常有限，简单、稳定、易维护、不易出错的方案，远比看上去高深的算法更有价值。过度崇拜竞赛思维，本质上是把工程能力窄化为解题技巧，也让编程远离了“解决真实问题”这一初心。



当然，参与竞赛本身无可厚非，只是我更希望表达这样一种观点：**比堆砌复杂度更重要的，是理解问题、权衡取舍、做出真正适合场景的设计**。令我欣慰的是，哈工大的复试并没有把C语言题目设置得过分不切实际、刻意追求复杂，而是更看重基础、逻辑与工程素养。在广阔的计算机世界里，比“更复杂、更巧妙”更有意义的事情，还有太多太多太多。



> Tips：以下题目精选自哈工大SSE课后题、SSE其它中/难题、往年真题，基本可以反映哈工大计算学部复试编程题的实际难度，可以作为复试编程的练习材料，答案仅供参考。**复试编程题只能用标准 C 语言编程，不可用 C++ 特殊语法，所有变量必须在第一条可执行语句之前定义。判分时若运行失败会基于语义给分，只写了hello world也会给分；代码不允许粘贴但是可以复制到codeblock运行&调试。** 扩展材料：[SSE-C](https://www.nowcoder.com/discuss/353150336095428608) [SSE-改错-1](https://www.nowcoder.com/discuss/353150338465210368) [SSE-改错-2](https://www.nowcoder.com/discuss/353150338620399616) [SSE-改错-3](https://www.nowcoder.com/discuss/353150338934972416)

# 0. 经典的链表
编程题一般不会让大家写，改错题也不会在这里太刁难大家，但是有必要先熟悉一下：
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 定义经典的单向链表节点结构体
typedef struct Node {
    // ======================
    // 数据域：存放节点的有效数据
    // ======================
    int data;               // 存储当前节点的数据（可以是int、char、结构体等）

    // ======================
    // 指针域：指向 下一个节点
    // ======================
    struct Node *next;      // 指针变量，存放下一个节点的地址
                            // 作用：把多个节点串成一条链表
}
// ======================
// 给结构体起两个别名（超级重要！）
// ======================
ListNode,                    // 别名1：ListNode = struct Node
                             // 表示：一个链表节点（实体）

*LinkedList;                 // 别名2：LinkedList = struct Node*
                             // 表示：指向链表节点的指针（头指针）

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
    //由于linkedlist是指向链表节点的指针，所以返回头节点指针head
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

# 14. 字符串去特定字符
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

# 15. 判断三角形类型
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

# 16.  求最大值
描述
输入10个整数，要求输出其中的最大值。
输入描述：
测试数据有多组，每组10个整数。
输出描述：
对于每组输入,请输出其最大值（有回车）。
示例1
输入：
10 22 23 152 65 79 85 96 32 1
输出：
max=152

```c
#include <stdio.h>

int main() {
    int max=-100000,tmp;
    for (int i=0; i<10; i++) {
        scanf("%d",&tmp);
        if(tmp>max) max = tmp;
    }
    
    printf("max=%d",max);
    
    return 0;
}
```

# 17. 百鸡问题
   用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的mini鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。

输入描述：
    测试数据有多组，输入n。
输出描述：
    对于每组输入,请输出x,y,z所有可行解，按照x，y，z依次增大的顺序输出。
示例1
输入：
40
输出：
x=0,y=0,z=100
x=0,y=1,z=99
x=0,y=2,z=98
x=1,y=0,z=99

```c
#include <stdio.h>
int main() {
    //这道题有点意思的地方就是解决mini鸡1/3元每只的问题：
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int x = 0; x <= 3 * n / 15; x++)
            for (int y = 0; y <= (3 * n - 15 * x) / 9; y++) {
                int z = 100 - x - y;
                if (z >= 0 && (x * 15 + y * 9 + z) <= 3 * n)
                    printf("x=%d,y=%d,z=%d\n", x, y, z);
            }
    }
    return 0;
}
```

# 18. 众数
描述
输入20个数，每个数都在1-10之间，求1-10中的众数（众数就是出现次数最多的数，如果存在一样多次数的众数，则输出权值较小的那一个）。
输入描述：
测试数据有多组，每组输入20个1-10之间的数。
输出描述：
对于每组输入,请输出1-10中的众数。
示例1
输入：
5 1 5 10 3 5 3 4 8 6 8 3 6 5 10 7 10 2 6 2 
输出：
5

```c
#include <stdio.h>

int main() {
    int arr[21]={0}, tmp, maxidx=0;
    for (int i=0; i<20; i++) {
       scanf("%d",&tmp);
       arr[tmp]++;
    }
    for (int i=0; i<20; i++) {
        if (arr[i]>arr[maxidx]) {
            maxidx = i;
        }
    }

    printf("%d",maxidx);
    return 0;
}

```

# 19.  数字阶梯求和
描述
给定a和n，计算a+aa+aaa+a...a(n个a)的和。
输入描述：
测试数据有多组，输入a，n（1<=a<=9,1<=n<=100）。
输出描述：
对于每组输入,请输出结果。
示例1
输入：
1 10
输出：
1234567900

```c
#include <stdio.h>
#include <string.h>

// 功能：两个字符串形式的大数相加，结果存到 res 里
// a：第一个大数  b：第二个大数  res：存储相加结果
void add_str(char *a, char *b, char *res)
{
    int lenA = strlen(a);        // 取a的长度
    int lenB = strlen(b);        // 取b的长度
    int maxLen = lenA > lenB ? lenA : lenB; // 取较长的那个长度
    int jinwei = 0;              // 进位，初始为0
    int i;

    // 从低位（最后一位）开始逐位相加
    for (i = 0; i < maxLen; i++)
    {
        // 取a当前位数字，没有则补0
        int digitA = (i < lenA) ? (a[lenA - 1 - i] - '0') : 0;
        // 取b当前位数字，没有则补0
        int digitB = (i < lenB) ? (b[lenB - 1 - i] - '0') : 0;

        // 当前位总和 = a位 + b位 + 进位
        int sum = digitA + digitB + jinwei;

        res[i] = sum % 10 + '0'; // 当前位结果
        jinwei = sum / 10;       // 新的进位
    }

    // 如果最后还有进位，直接加到结果里，jinwei是int需要加char的‘0’
    if (jinwei > 0)
        res[i++] = jinwei + '0';

    res[i] = '\0'; // 字符串结束符

    // 反转字符串，得到正确顺序
    int left = 0, right = i - 1;
    while (left < right)
    {
        char t = res[left];
        res[left] = res[right];
        res[right] = t;
        left++;
        right--;
    }
}

int main()
{
    int a, n;
    // 循环输入多组 a 和 n
    while (scanf("%d %d", &a, &n) != EOF)
    {
        char ans[10000] = "0";   // 最终结果，初始为0
        char temp[10000];        // 存放每一项：a, aa, aaa...
        char next[10000];        // 临时存放加法结果

        // 循环累加：a + aa + aaa + ... + n个a
        for (int i = 1; i <= n; i++)
        {
            // 生成 i 个 a 组成的字符串，例如 i=3,a=2 → "222"
            for (int j = 0; j < i; j++)
                temp[j] = a + '0';
            temp[i] = '\0'; // 字符串结束

            // 累加：ans = ans + temp
            add_str(ans, temp, next);
            strcpy(ans, next); // 把结果复制回 ans，** strcpy 是字符串复制函数，返回值为目标字符串的指针所以不可以 ans = strcpy(ans, next);**
        }

        printf("%s\n", ans); // 输出最终答案
    }
    return 0;
}
```


# 20. 结构体按字典序排序

主要是strcmp函数的使用，strcmp函数是比较两个字符串的函数，返回值为int类型，当第一个字符串大于第二个字符串时返回一个大于0的数，当第一个字符串小于第二个字符串时返回一个小于0的数，当两个字符串相等时返回0。

请使用如下定义的 `Worker` 结构体存储员工信息：
```c
typedef struct{
    char name[20];   // 员工姓名
    int score[3];    // 三门课程成绩
    float sum;       // 三门课总分
    float aver;      // 三门课平均分
    int num;         // 缺席次数
}Worker;
```

编写一个 C 语言程序，完成以下功能：
1.  从键盘输入 **n 个员工**的完整信息（需提供输入示例）。
2.  筛选出同时满足以下两个条件的员工：
    -   三门课的平均成绩 **≥ 85 分**
    -   缺席次数 **≤ 2 次**
3.  将筛选出的员工，按照**姓名的字典序逆序**排列后输出。



```c
#include <stdio.h>
#include <string.h>

// 定义员工结构体
typedef struct {
    char name[20];
    int score[3];
    float sum;
    float aver;
    int num;  // 缺席次数
} Worker;

int main() {
    int n, i, j;
    printf("请输入员工人数 n：");
    scanf("%d", &n);
    getchar();  // 吸收换行符

    Worker workers[n];  // 定义员工数组

    // 1. 输入员工信息
    for (i = 0; i < n; i++) {
        printf("\n请输入第 %d 个员工的信息：\n", i + 1);
        printf("姓名：");
        gets(workers[i].name); //gets函数可以读取姓名里的空格，回车（换行） 就停止，会把回车丢掉，不会存进字符串里
        printf("三门课成绩（用空格分隔）：");
        scanf("%d %d %d", &workers[i].score[0], &workers[i].score[1], &workers[i].score[2]);
        printf("缺席次数：");
        scanf("%d", &workers[i].num);
        getchar();  // 吸收换行符

        // 计算总分和平均分
        workers[i].sum = workers[i].score[0] + workers[i].score[1] + workers[i].score[2];
        workers[i].aver = workers[i].sum / 3.0;
    }

    // 2. 筛选满足条件的员工（平均分≥85 且 缺席次数≤2）
    Worker qualified[n];
    int count = 0;
    for (i = 0; i < n; i++) {
        if (workers[i].aver >= 85 && workers[i].num <= 2) {
            qualified[count++] = workers[i];
        }
    }

    // 3. 按姓名字典序逆序排序（冒泡排序）
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - 1 - i; j++) {
            // strcmp(a,b) > 0 表示 a 字典序在 b 之后，逆序则交换
            if (strcmp(qualified[j].name, qualified[j+1].name) < 0) {
                Worker temp = qualified[j];
                qualified[j] = qualified[j+1];
                qualified[j+1] = temp;
            }
        }
    }

    // 4. 输出结果
    printf("\n满足条件的员工信息（按姓名逆序）：\n");
    printf("----------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n", "姓名", "总分", "平均分", "缺席次数");
    printf("----------------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("%-20s %-10.0f %-10.2f %-10d\n",
               qualified[i].name,
               qualified[i].sum,
               qualified[i].aver,
               qualified[i].num);
    }

    return 0;
}
```

不知道有strcmp也没关系：


```c
// 自己写字典序比较！
int mystrcmp(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}

```

# 21. 采购三种肥料

### 一、题目复述📝
已知有红、黄、紫三种肥料，价格分别为**80元/袋、50元/袋、35元/袋**。
输入经费 \(n\)（\(1000 < n < 2000\)），输出满足以下**任一条件**的所有购买方案：
1.  紫色肥料袋数是黄色肥料袋数的 \(1/3\)（即 \(purple = yellow/3\)，且 \(yellow\) 必须是3的倍数）
2.  黄色肥料袋数是红色肥料袋数的 \(2\) 倍（即 \(yellow = 2 \times red\)）

要求：按**红、黄、紫**的顺序输出每种方案的袋数，且总花费不超过输入经费 \(n\)。


```c
#include <stdio.h>

int main() {
    int red, yellow, purple, budget;
    // 正确读取经费
    scanf("%d", &budget);

    // 遍历所有可能的购买数量
    for (red = 0; red <= budget / 80; red++) {
        for (yellow = 0; yellow <= budget / 50; yellow++) {
            for (purple = 0; purple <= budget / 35; purple++) {
                // 总花费不超过预算 + 满足任一条件
                int total = 80 * red + 50 * yellow + 35 * purple;
                if (total <= budget && 
                    ((purple * 3 == yellow) || (yellow == 2 * red))) {
                    printf("%d %d %d\n", red, yellow, purple);
                }
            }
        }
    }
    return 0;
}
```

# 22. 字母串输入复制排序

输入一行由空格分隔的英文句子（单词之间用空格隔开，总长度不超过 200），要求：
统计句子中的单词总数
将所有单词按照字母表降序排列
先输出单词数量，再分行输出排序后的单词

输入：

i have a dream
输出：

num: 4
i
have
dream
a

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[201], tmp[201], words[201][201];
    int i = 0, j = 0, k = 0;
    gets(s);
    
    while (s[i] != '\0') {
        if (s[i] == ' ') {
            words[j][k] = '\0';
            j++;
            k = 0;
            i++;
        } else {
            words[j][k] = s[i];
            i++;
            k++;
        }
    }

    words[j][k] = '\0';


    printf("num:%d\n", j + 1);


    for (i = 0; i < j+1; i++) {
        for (k = 0; k < j - i; k++) {
            if (strcmp(words[k], words[k + 1]) < 0) {//strcmp(a,b)返回a-b的差值
                strcpy(tmp, words[k + 1]);//strcpy(a,b)将b复制到a
                strcpy(words[k + 1], words[k]);
                strcpy(words[k], tmp);
            }
        }
    }

    // 输出
    for (i = 0; i <= j; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
```

# 23. 孪生素数

编写一个 C 语言程序，实现以下功能：

素数是只能被 1 和自身整除的大于 1 的正整数；孪生素数是指相差为 2 的两个素数（例如 3 与 5、41 与 43）。

输入：

从键盘输入区间的上下限（格式为 %d,%d），提示信息为 "Please input lower limit and upper bound:\n"，且输入区间上下限均大于 2，为合理区间，无需处理异常情况。
处理：找出指定闭区间内的所有孪生素数对，并统计孪生素数对的总数。

输出：

按格式 (%d,%d)\n 逐行输出每一对孪生素数。
最后按格式 "Total = %d" 输出孪生素数对的总数。

限制：

不能使用指针、结构体、共用体、文件、goto、枚举类型。
必须用标准 C 语言编程，所有变量需在第一条可执行语句之前定义。
严格遵循给定的输入输出格式。

```c
#include <stdio.h>
#include <math.h>

// 判断是否为素数的函数
int isPrime(int x) {
    if (x <= 1) return 0;
    int sqrt_x = (int)sqrt(x);
    for (int i = 2; i <= sqrt_x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int left, right, tmp = -100, count = 0;
    
    // 输入提示
    printf("Please input lower limit and upper bound:\n");
    // 按格式读取输入
    scanf("%d,%d", &left, &right);
    
    int i;
    for (i = left; i <= right; i++) {
        if (isPrime(i)) {
            // 检查是否与上一个素数构成孪生素数
            if (tmp == i - 2) {
                printf("(%d,%d)\n", tmp, i);
                count++;
            }
            tmp = i;
        }
    }
    
    // 输出总数
    printf("Total = %d", count);
    return 0;
}
```

# 24. 凯撒密码加密字符串

编写一个 C 语言程序，实现凯撒密码加密功能：
加密规则：将英文字母按字母表顺序向后移动固定位数m（示例中m=3），超出字母范围则循环（如x→a、y→b、z→c，大写同理）。

函数要求：
函数原型：int Caesar(char c[], int m)

功能：若字符串包含非英文字母（包括空格、数字等），返回0；否则将所有字母后移m位加密，返回1。

输入输出：

输入提示："Input a string:"

输入方式：用gets()读取字符串（长度 < 100，仅含英文字母或非法字符）

输出方式：用puts()输出结果

异常处理：若输入含非英文字母，输出"Input error!\n"

限制条件：

禁止使用指针、结构体、共用体、文件、goto、枚举类型
必须用标准 C 语言，所有变量在第一条可执行语句前定义
严格遵循输入输出格式



```c
#include <stdio.h>
#include <string.h>

// 按题目要求实现Caesar函数
int Caesar(char c[], int m) {
    int i = 0;
    // 先检查是否有非英文字母
    while (c[i] != '\0') {
        if (!((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))) {
            return 0;
        }
        i++;
    }
    // 加密处理
    i = 0;
    while (c[i] != '\0') {
        if (c[i] >= 'a' && c[i] <= 'z') {
            c[i] = (c[i] - 'a' + m) % 26 + 'a';
        } else if (c[i] >= 'A' && c[i] <= 'Z') {
            c[i] = (c[i] - 'A' + m) % 26 + 'A';
        }
        i++;
    }
    return 1;
}

int main() {
    char str[101];
    int result;
    int m = 3; // 题目示例中偏移量为3

    printf("Input a string:");
    gets(str); // 按题目要求使用gets

    result = Caesar(str, m);
    if (result == 0) {
        printf("Input error!\n");
    } else {
        puts(str);
    }

    return 0;
}
```

# 25. 字典计数

从键盘输入一个 int 型整数，编写程序判断该整数共有几位，并输出包含各个数字的个数。例如：输入整数 16644，该整数共有 5 位，其中有 1 个 1，2 个 6，2 个 4。

注意事项

不能使用指针、结构体、共用体、文件、goto、枚举类型进行编程



输入输出格式要和给定格式完全一致

输入输出要求

输入提示信息：Please enter the number:\n

输出格式：

第一行：%d:%d bits\n（输入整数：位数 bits）
后续行：按数字从小到大顺序，输出%d:%d\n（数字：出现次数），仅输出出现次数 > 0 的数字

```c
#include <stdio.h>

int main() {
    int num, n, len = 0;
    int cnt[10] = {0};
    int i;

    printf("Please enter the number:\n");
    scanf("%d", &num);

    n = num;
    if (n < 0) n = -n;

    while (n > 0) {
        cnt[n % 10]++;
        len++;
        n /= 10;
    }

    printf("%d:%d bits\n", num, len);

    for (i = 0; i < 10; i++) {
        if (cnt[i] > 0)
            printf("%d:%d\n", i, cnt[i]);
    }

    return 0;
}
```


# 26. 设置密码程序

用户密码设置模拟程序：编写函数 int Setting(char password[]);，实现以下功能：
让用户先输入一串长度为 8 的密码：
若输入密码长度不是 8 → 密码设置失败，函数返回 0
若长度为 8 → 让用户再输入一次密码进行确认


两次输入对比：
两次密码相同 → 设置成功，函数返回 1，密码存入password数组
两次密码不同 → 设置失败，函数返回 0
主程序调用该函数，根据返回值输出对应提示信息


函数说明
功能：设置密码
参数：password，存放密码的数组，大小为 20 个字符
返回值：成功返回 1，失败返回 0

注意事项
禁止使用指针、结构体、共用体、文件、goto、枚举类型
标准 C 语言，无 C++ 语法，所有变量必须在第一条可执行语句前定义


输入输出要求

输入提示：
Please input password with 8 characters:\n
Please input again:\n
输入格式：%s

输出格式：
成功：Successfully set password:%s\n
失败：Failure!%s\n


```c
#include <stdio.h>
#include <string.h>

int Setting(char password[]);

int main() {
    char pwd[20];
    int result;
    result = Setting(pwd);
    if (result == 1)
        printf("Successfully set password:%s\n", pwd);
    else
        printf("Failure!%s\n", pwd);
    return 0;
}

int Setting(char password[]) {
    char confirm[20];
    printf("Please input password with 8 characters:\n");
    scanf("%s", password);
    if (strlen(password) != 8)
        return 0;
    printf("Please input again:\n");
    scanf("%s", confirm);
    if (strlen(confirm) != 8)
        return 0;
    if (strcmp(password, confirm) == 0)
        return 1;
    else
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

# D 发贺卡


- 有 `n` 个同学排成一排，每人有一个分数 `rate[i]`。
- 需满足两个条件：
  1. 每个同学至少 1 张贺卡；
  2. 相邻同学中，**分数更高的人** 获得的贺卡数至少比分数更低的人多 1 张。
- 目标：计算总共需要的**最少贺卡总数**。


原代码错误片段：
```c
for (i = 0; i < n; i++)
{
    if(i > 0 && rate[i] > rate[i - 1])
        rate[i] = rate[i - 1] + 1;
    else if(i==0)
        rate[i] = 1;
}
```

**主要问题**：
1.  **变量名冲突**：用存储分数的 `rate` 数组直接存储贺卡数，会覆盖原始分数数据，导致后续比较错误。
2.  **遍历方向单一**：只从左到右遍历，无法处理「右侧分数更高」的情况（例如序列 `[1, 2, 1]`，左到右会得到 `[1, 2, 1]`，但实际应满足 `[1, 2, 1]` 是对的，但如果是 `[3, 2, 1]`，左到右会得到 `[1, 1, 1]`，违反了「分数高的贺卡更多」的规则）。
3.  **逻辑不完整**：`else if(i==0)` 只处理了第一个元素，其余元素在不满足 `rate[i] > rate[i-1]` 时没有被赋值为 1，会导致未初始化的脏数据。
4.  **未计算总和**：代码只给每个位置赋值，没有累加得到最终的贺卡总数。


**修正后代码（C语言）**：
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *rate = (int*)malloc(n * sizeof(int));
    int *cards = (int*)malloc(n * sizeof(int)); // 单独用数组存贺卡数

    // 输入分数
    for (int i = 0; i < n; i++) {
        scanf("%d", &rate[i]);
        cards[i] = 1; // 每个同学至少1张贺卡
    }

    // 左到右遍历
    for (int i = 1; i < n; i++) {
        if (rate[i] > rate[i-1]) {
            cards[i] = cards[i-1] + 1;
        }
    }

    // 右到左遍历
    for (int i = n-2; i >= 0; i--) {
        if (rate[i] > rate[i+1] && cards[i] <= cards[i+1]) {
            cards[i] = cards[i+1] + 1;
        }
    }

    // 计算总和
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += cards[i];
    }

    printf("%d\n", total);

    free(rate);
    free(cards);
    return 0;
}
```

# E 链表排序


实现一个简单的学生管理系统，学生信息包含学号（`id`）和成绩（`score`），用单链表存储。要求对链表按成绩**升序**排序（使用简单选择排序），以下代码存在指针操作相关的错误，请找出并改正。

**学生链表结构定义**：
```c
typedef struct Student {
    int id;
    int score;
    struct Student *next;
} Stu;
```

**错误代码（待修改）**：
```c
// 按score升序排序链表（选择排序）
void sortStu(Stu *head) {
    Stu *p, *q, *min;
    p = head->next;
    while (p != NULL) {
        min = p;
        q = p->next;
        while (q != NULL) {
            if (q->score < min->score) {
                min = q; // 找到分数更小的节点
            }
            q = q->next;
        }
        // 交换p和min节点的数据（错误写法，不改变指针指向，仅交换数据域）
        int temp_score = p->score;
        p->score = min->score;
        min->score = temp_score;
        
        int temp_id = p->id;
        p->id = min->id;
        min->id = temp_id;
        
        p = p->next;
    }
}
```

1.  **违背链表操作设计思想**：直接交换节点数据域（`score`、`id`），而非调整指针指向来交换节点位置。这在实际链表操作中是不规范的，且当节点数据域复杂时会导致效率极低、代码冗余。
2.  **指针边界处理缺失**：若链表为空或仅有一个节点时，代码仍会执行排序逻辑，虽结果正确但无意义，且未做边界判断。
3.  **未考虑前驱节点指针**：若要交换链表中两个节点的位置，必须修改其前驱节点的`next`指针，当前代码完全未处理这一关键指针操作，导致无法真正调整节点在链表中的顺序。

```c
// 按score升序排序链表（选择排序，指针交换版）
void sortStu(Stu *head) {
    if (head == NULL || head->next == NULL) {
        return; // 空链表或仅一个节点，无需排序
    }

    Stu *p, *q, *min, *p_prev, *min_prev, *temp;
    p = head->next;
    p_prev = head; // p的前驱节点

    while (p != NULL) {
        min = p;
        min_prev = p_prev; // min的前驱节点
        q = p->next;
        Stu *q_prev = p; // q的前驱节点

        // 遍历找到剩余链表中score最小的节点及其前驱
        while (q != NULL) {
            if (q->score < min->score) {
                min = q;
                min_prev = q_prev;
            }
            q_prev = q;
            q = q->next;
        }

        // 若min不是当前p节点，交换p和min的位置（指针操作）
        if (min != p) {
            // 断开min节点
            min_prev->next = min->next;
            // 插入min到p之前
            p_prev->next = min;
            min->next = p;

            // 更新p和p_prev，避免断链
            temp = p;
            p = min;
            min = temp;
        }

        // 指针后移
        p_prev = p;
        p = p->next;
    }
}
```


# F n!

实现一个函数，计算正整数 `n` 的阶乘 `n!`（规定 `0! = 1`），以下代码存在多处错误，请找出并改正。

**错误代码（待修改）**：
```c
#include <stdio.h>

// 计算n的阶乘
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i++; // 错误1：循环变量i自增两次
    }
    return result;
}

int main() {
    int n;
    printf("请输入一个正整数：");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("输入错误！n不能为负数。\n");
        return 0;
    }
    
    long long res = factorial(n);
    printf("%d! = %lld\n", n, res);
    return 0;
}
```

1. 循环变量自增错误
- **错误位置**：`result = result * i++;`
- **原因**：`for` 循环中已经对 `i` 执行 `i++`，循环体内又执行 `i++`，导致 `i` 每次循环自增2次，跳过部分乘数，计算结果错误。
- **示例**：计算 `3!` 时，循环实际只执行 `i=1` 和 `i=3`，得到 `1*1*3=3`，而正确结果应为 `6`。

2. 边界值 `n=0` 未正确处理
- **错误表现**：原代码中 `factorial` 函数在 `n=0` 时，`for` 循环不执行，`result` 保持为 `1`，这一点结果正确，但代码逻辑未显式体现 `0! = 1` 的规定，且 `main` 函数未对 `n=0` 做友好提示，易让使用者误解。
- **补充问题**：未对 `n` 过大导致的**数据溢出**做提示（如 `n>20` 时 `long long` 类型会溢出），存在潜在错误。

```c
#include <stdio.h>

// 计算n的阶乘，n为非负整数
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // 0! = 1, 1! = 1
    }
    long long result = 1;
    for (int i = 2; i <= n; i++) { // 从2开始乘，优化计算
        result = result * i; // 修正：移除i++，避免重复自增
    }
    return result;
}

int main() {
    int n;
    printf("请输入一个非负整数（推荐n≤20，避免溢出）：");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("输入错误！n不能为负数。\n");
        return 0;
    }
    
    // 溢出提示
    if (n > 20) {
        printf("警告：n>20时，结果会超出long long类型范围，可能导致数据错误。\n");
    }
    
    long long res = factorial(n);
    printf("%d! = %lld\n", n, res);
    return 0;
}
```


# G 质因数分解


下面是一段**有错误**的C语言代码，功能是对输入的整数进行质因数分解（如输入`100`，输出`100=2*2*5*5`），请找出并改正其中的错误。

```c
#include <stdio.h>

int main() {
    int n, i;
    printf("请输入一个整数：");
    scanf("%d", &n);
    
    printf("%d=", n);
    for (i = 2; i < n; i++) {
        while (n % i == 0) {
            printf("%d*", i);
            n = n / i;
        }
    }
    return 0;
}
```

1. **循环边界错误**：`for (i = 2; i < n; i++)` 会漏掉最后一个质因子。例如当`n`最终变为质数时（如`100`分解到最后剩`5`），循环条件`i < n`不成立，导致最后一个质因子未输出。
2. **多余的乘号**：每次分解都输出`%d*`，会在末尾多一个`*`（如`100=2*2*5*5*`）。
3. **未处理特殊情况**：当输入`n=1`或`n=0`时，程序没有输出任何结果。

```c
#include <stdio.h>

int main() {
    int n, i;
    printf("请输入一个整数：");
    scanf("%d", &n);
    
    printf("%d=", n);
    int first = 1; // 标记是否是第一个因子
    for (i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            if (!first) {
                printf("*");
            }
            printf("%d", i);
            first = 0;
            n = n / i;
        }
    }
    // 处理最后一个大于1的质因子
    if (n > 1) {
        if (!first) {
            printf("*");
        }
        printf("%d", n);
    }
    printf("\n");
    return 0;
}
```

# H 击鼓传花

**题目描述**：
小明班级共有 **n** 名同学围成一圈，小明编号为0，其他同学依次编号为1、2、……、n-1。游戏规则：花**只能传给相邻**的左右两名同学。

初始时花在小明手中，一共传递 **m** 次。
要求：计算**恰好传递m次后，花重新回到小明手中的方法总数**。

给定一段存在错误的C语言代码，请找出并修正代码中的错误，使其能够正确输出结果。

**典型输入输出示例**：
输入：3 3 （3名同学，传递3次）
输出：2


状态定义：dp[i][j] 表示传了 i 次后，花在第 j 个同学手里的方法数。
初始状态：dp[0][0] = 1（0 次传递时，花在小明（0 号）手里，只有 1 种方法），其余 dp[0][j] = 0。
状态转移：
对于第 i 次传递，第 j 个同学的花只能来自左边 (j-1+n)%n 或右边 (j+1)%n 的同学：
dp[i][j] = dp[i-1][(j-1+n)%n] + dp[i-1][(j+1)%n];
结果：dp[m][0] 即为传 m 次后回到小明手里的方法数。

```c
#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    printf("请输入同学总数n和传递次数m：");
    scanf("%d %d", &n, &m);

    // 动态规划数组：dp[i][j] 表示传i次后到第j个同学的方法数
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;  // 初始状态：0次传递，花在小明(0号)手里

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            // 环形边界处理：(j-1+n)%n 避免负数，(j+1)%n 处理最后一个同学
            dp[i][j] = dp[i-1][(j-1 + n) % n] + dp[i-1][(j+1) % n];
        }
    }

    printf("传%d次后回到小明手里的方法数为：%d\n", m, dp[m][0]);
    return 0;
}
```
常见错误点分析（改错题核心）

1. **边界处理错误**
   - 错误写法：`dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];`
   - 问题：当 `j=0` 时 `j-1=-1`，当 `j=n-1` 时 `j+1=n`，数组越界。
   - 修正：使用 `(j-1+n)%n` 和 `(j+1)%n` 处理环形边界。

2. **初始状态错误**
   - 错误写法：`dp[0][j] = 1` 或 `dp[1][0] = 1`
   - 问题：初始状态应为 0 次传递时花在小明手里，即 `dp[0][0] = 1`，其余为 0。

3. **循环次数错误**
   - 错误写法：`for (int i = 0; i < m; i++)`
   - 问题：循环次数不足，导致只计算了 `m-1` 次传递。
   - 修正：循环应从 `1` 到 `m`，共 `m` 次传递。

4. **数组维度理解错误**
   - 错误写法：将 `dp[i][j]` 理解为第 `i` 个同学传 `j` 次，导致状态转移逻辑完全颠倒。
   - 修正：明确 `i` 为传递次数，`j` 为当前持有花的同学编号。

# I 超大数取模算末尾

输入一个整数 \(n\)（\(0 < n \le 1000000\)），计算并输出 \(1! + 2! + \dots + n!\) 的**末6位**（记为 \(s\)）：
- 若 \(s\) 不足6位，直接输出（不含前导0，如末6位为`001234`则输出`1234`）。
- 若 \(n\) 不满足范围，输出 `"Input error!"`。
- 已知：从25开始及以后的所有数的阶乘末6位均为0。

下面的程序存在错误，请修改正确：

```c
#include <stdio.h>
#define MOD = 1000000;
long Func(int n);
int main()
{
    int n;
    long s;
    scanf("%d", &n);
    if (n > 0 || n <= 1000000){
        s = Func(n);
        printf("%ld\n", s);
    }
    else
    {
        printf("Input error!\n");
    }
    return 0;
}
//函数功能：计算1!2!+...+n!的末六位数
long Factsum(int n)
{
    int i;
    long s = 0, f = 1;
    for (i = 1; i <= n; i++){
        f = f * i;
        s = s + f;
    }
    return s % MOD;
}
```



---


```c
#include <stdio.h>
#define MOD 1000000  // 修正宏定义语法

long Factsum(int n);  // 修正函数声明名

int main()
{
    int n;
    long s;
    scanf("%d", &n);
    // 修正范围判断逻辑
    if (n > 0 && n <= 1000000) {
        s = Factsum(n);
        printf("%ld\n", s);
    } else {
        printf("Input error!\n");
    }
    return 0;
}

// 函数功能：计算1!+2!+...+n!的末六位数
long Factsum(int n)
{
    int i;
    long s = 0, f = 1;
    for (i = 1; i <= n; i++) {
        f = (f * i) % MOD;  // 每步取模防止溢出
        s = (s + f) % MOD;   // 累加和也取模
        if (i >= 25) break;  // 25及以后阶乘末6位为0，提前终止
    }
    return s % MOD;
}
```

| 错误类型               | 原代码                          | 修正后代码                          |
|------------------------|---------------------------------|-------------------------------------|
| 宏定义语法错误         | `#define MOD = 1000000;`        | `#define MOD 1000000`               |
| 函数名不匹配           | `Func` vs `Factsum`             | 统一为 `Factsum`                    |
| 范围判断逻辑错误       | `n > 0 || n <= 1e6`             | `n > 0 && n <= 1e6`                 |
| 阶乘溢出与效率问题     | 直接计算阶乘累加                | 每步取模 + 25后提前终止循环         |

# J 删除重复元素

给定一个长度不超过100的一维整型数组，要求删除所有**在当前元素之后出现过重复值**的元素，直到数组中无重复元素，且保持剩余元素的相对顺序不变，最后输出处理后的数组。

下面的程序存在错误，请修改正确：

```c
#include <stdio.h>
#define N = 100;
void SearchRepeatedNum(int a[], int n);
int main(){
    int a[N], n, i;
    printf("请输入数组中元素个数\n");
    scanf("%d", &n);
    printf("请输入各个元素\n");
    for (i = 0; i < n; i++);
        scanf("%d", a[i]);
    SearchRepeatedNum(a[], n);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
void SearchRepeatedNum(int a[], int n){
    int i, j, k;
    for (i = 0; i < n; i++){
        for (j = n - 1; j > i; j--){
            if (a[i] = a[j]){
                for (k = i; k < n; k++)
                    a[k] = a[k + 1];
                n--;
            }
        }
    }
}
```



```c
#include <stdio.h>
#define N 100

void SearchRepeatedNum(int a[], int *n);

int main() {
    int a[N], n, i;
    printf("请输入数组中元素个数\n");
    scanf("%d", &n);
    printf("请输入各个元素\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    SearchRepeatedNum(a, &n); // 数组传参不需要a[]，n需要取地址才能修改原数组长度n
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

void SearchRepeatedNum(int a[], int *n) {
    int i, j, k;
    for (i = 0; i < *n; i++) {
        for (j = *n - 1; j > i; j--) {
            if (a[i] == a[j]) {
                // 从j位置开始覆盖删除
                for (k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];
                (*n)--; // 数组长度减1
            }
        }
    }
}
```

| 错误类型               | 原代码片段                          | 修正后代码                          |
|------------------------|-------------------------------------|-------------------------------------|
| 宏定义语法错误         | `#define N = 100;`                  | `#define N 100`                     |
| `for` 循环**多余分号**      | `for (i=0; i<n; i++);`              | `for (i=0; i<n; i++)`               |
| `scanf` 参数错误        | `scanf("%d", a[i]);`                | `scanf("%d", &a[i]);`               |
| 函数调用语法错误        | `SearchRepeatedNum(a[], n);`        | `SearchRepeatedNum(a, &n);`         |
| 比较运算符错误          | `if (a[i] = a[j])`                  | `if (a[i] == a[j])`                 |
| 数组删除逻辑错误        | `for(k=i; k<n; k++) a[k]=a[k+1];`   | `for(k=j; k<*n-1; k++) a[k]=a[k+1];`|
| 值传递无法修改数组长度  | `void SearchRepeatedNum(int a[], int n)` | `void SearchRepeatedNum(int a[], int *n)` |

# K 升序与降序


程序功能：从键盘读入某门课程的成绩（以负数结束输入），根据用户输入的选项排序：输入 1 按升序，输入 2 按降序，最后输出排序结果。程序存在多处隐蔽错误，需在不改变程序原有意图、不修改输入输出格式的前提下，修正所有错误。
注意事项
仅修改错误语句，正确语句不改动
必须全部改正、运行正确才得分，部分正确不得分
不得改变程序原有逻辑和输入输出格式

```c
#include <stdio.h>
#include <stdlib.h>
#define N 20

int ReadScore(int score[]);
void PrintScore(int score[], int n);
// ==================== 错误  ====================
// 原写法：int *compare(int a,int b)
// 错误：这是声明返回int*的函数，不是函数指针
// 正确：int (*compare)(int a,int b)
void SelectionSort(int score[], int n, int *compare(int a, int b));
// ===============================================
void Swap(int *x, int *y);
int Ascending(int a, int b);
int Descending(int a, int b);

int main(){
    int score[N],n;
    int order;
    n = ReadScore(score);
    printf("Total students are %d\n",n);
    printf("Enter 1 to sort in ascending order\n");
    printf("Enter 2 to sort in descending order\n");
    scanf("%d",&order);
    if(order == 1){
        SelectionSort(score, n, Ascending);
        printf("Data items in asending order\n");

    }
    // ==================== 错误  ====================
    // else 没有大括号{}，下面printf不属于else，永远会输出
    // 正确：else { ... }
    else
        SelectionSort(score, n, Descending);
        printf("Data items in descending order\n");
    // ===============================================
    PrintScore(score, n);
    return 0;
}

/*读入成绩以负数结束,返回实际输入的成绩个数*/
int ReadScore(int score[]){
    int i=-1;
    printf("Input score:\n");
    do{
        i++;
        // ==================== 错误  ====================
        // scanf必须取地址！score[i] → &score[i]
        scanf("%d",score[i]);
        // ===============================================
    }while(score[i]>=0);
    return i;
}

void PrintScore(int score[], int n){
    int i;
    for(i=0; i<n; i++)
        printf("%4d",score[i]);
    printf("\n");
}

void SelectionSort(int score[], int n, int *compare(int a, int b)){
    int i, j, k;
    for(i=0; i<n-1;i++){
        k = i;
        for(j = i+1; j< n; j++){
            // ==================== 错误 5 ====================
            // 比较对象写错：应该是score[j] 和 score[k]
            // 原代码写了score[i]，排序逻辑完全错误
            if((*compare)(score[i],score[k]))
            // 正确：if((*compare)(score[j],score[k]))
            // ===============================================
                k = j;
        }
        if(k!= i)
            // ==================== 错误 6 ====================
            // Swap需要传地址！应该是 &score[i], &score[k]
            Swap(score[i],score[k]);
            // ===============================================
    }
}

int Ascending(int a, int b){
    return a < b;
}

int Descending(int a, int b){
    return a > b;
}

void Swap(int *x, int *y){
    // ==================== 错误 7 ====================
    // int *temp 是野指针，没有指向有效空间，程序崩溃
    // 正确：int temp;
    int *temp;
    *temp = *x;
    *x = *y;
    *y = *temp;
    // ===============================================
}
```


修正：
```c
#include <stdio.h>
#include <stdlib.h>
#define N 20

int ReadScore(int score[]);
void PrintScore(int score[], int n);
void SelectionSort(int score[], int n, int (*compare)(int a, int b));
void Swap(int *x, int *y);
int Ascending(int a, int b);
int Descending(int a, int b);

int main(){
    int score[N],n;
    int order;
    n = ReadScore(score);
    printf("Total students are %d\n",n);
    printf("Enter 1 to sort in ascending order\n");
    printf("Enter 2 to sort in descending order\n");
    scanf("%d",&order);
    if(order == 1){
        SelectionSort(score, n, Ascending);
        printf("Data items in ascending order\n");
    }
    else{
        SelectionSort(score, n, Descending);
        printf("Data items in descending order\n");
    }
    PrintScore(score, n);
    return 0;
}

/*读入成绩以负数结束,返回实际输入的成绩个数*/
int ReadScore(int score[]){
    int i=-1;
    printf("Input score:\n");
    do{
        i++;
        scanf("%d",&score[i]);
    }while(score[i]>=0);
    return i;
}

void PrintScore(int score[], int n){
    int i;
    for(i=0; i<n; i++)
        printf("%4d",score[i]);
    printf("\n");
}

void SelectionSort(int score[], int n, int (*compare)(int a, int b)){
    int i, j, k;
    for(i=0; i<n-1;i++){
        k = i;
        for(j = i+1; j< n; j++){
            if((*compare)(score[j],score[k]))
                k = j;
        }
        if(k!= i)
            Swap(&score[i],&score[k]);
    }
}

int Ascending(int a, int b){
    return a < b;
}

int Descending(int a, int b){
    return a > b;
}

void Swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
```


# L 链表录成绩

创建动态链表并打印链表内容。
从键盘读入学生的学号（long型）和分数（float型）
当输入的学号为0时，表示链表创建结束
最终将读入的学生学号和成绩打印输出
程序存在多处隐蔽错误，需在不改变程序原有意图、不修改输入输出格式的前提下，修正所有错误。


```c

#include <stdio.h>
// 错误1：缺少<stdlib.h>，malloc/free无法使用
struct node{
    long num;
    float score;
    struct node *next;
};

int main(){
    struct node *head, *p, *q;

    head = (struct node*)malloc(sizeof(struct node));
    p = (struct node*)malloc(sizeof(struct node));
    q = p;

    head->next = p;
    // 错误2：scanf必须传地址，p->num和p->score是变量，要加&
    scanf("%ld%f", p->num, p->score);

    while (p->num != 0){
        q = (struct node*)malloc(sizeof(struct node));
        p->next = q;
        // 错误3：循环内应该给新节点q赋值，而不是给p赋值，导致数据覆盖
        scanf("%ld%f", p->num, p->score);
    }
    // 错误4：尾节点p->next未置空，遍历会越界
    p->next = NULL;  // 需补充

    p = head->next;
    do{
        printf("%ld%.2f", p->num, p->score);
        p = p->next;
    }
    // 错误5：条件写反，p->next==NULL只会执行一次循环
    while (p->next == NULL);  // 应改为while(p != NULL)

    // 错误6：仅释放最后一个节点，内存泄漏，需遍历释放所有节点
    free(p);
    return 0;
}

```

修正：

```c
#include <stdio.h>
#include <stdlib.h>  // 错误1：补充malloc/free所需头文件

struct node{
    long num;
    float score;
    struct node *next;
};

int main(){
    struct node *head = NULL, *p = NULL, *q = NULL;
    long num;
    float score;

    // 第一次输入
    printf("请输入学号和分数（学号为0结束）：\n");
    scanf("%ld%f", &num, &score);  // 先读取数据，再分配节点

    while(num != 0){
        // 分配新节点
        q = (struct node*)malloc(sizeof(struct node));
        q->num = num;
        q->score = score;
        q->next = NULL;  // 新节点尾指针置空

        if(head == NULL){
            head = q;  // 第一个节点作为头节点
            p = q;
        }else{
            p->next = q;  // 链接到链表尾部
            p = q;        // 移动尾指针
        }

        // 读取下一组数据
        scanf("%ld%f", &num, &score);
    }

    // 遍历打印链表
    p = head;
    printf("\n链表内容：\n");
    while(p != NULL){  // 错误5：修正遍历条件，直到空指针结束
        printf("%ld%.2f ", p->num, p->score);
        p = p->next;
    }
    printf("\n");

    // 错误6：完整释放所有节点内存
    p = head;
    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }

    return 0;
}
```

# M 