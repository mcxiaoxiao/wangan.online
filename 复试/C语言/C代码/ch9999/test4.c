#include<stdio.h>
#include<string.h>
int w[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char p[12] = "10x98765432";

int IsTrue(char *s)
{
    int sum = 0;
    for(int i = 0; i < 17; i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            int a = s[i]-'0';
            sum += a*w[i];
        }
        else
        {
            return 0;
        }
    }
    sum %= 11;
    if(s[17] == p[sum]) return 1;
    return 0;
}

int main(void)
{
    int n = 0;
    scanf("%d",&n);
    getchar();
    char a[n][20];
    char *b[n];
    int flag = 0;
    int j = 0;
    for(int i = 0; i < n; i ++)
    {
        puts("INPUT");
        gets(a[i]);
        if(IsTrue(a[i])) flag ++;
        else
        {
            b[j] = a[i];
            j ++;
        }
    }

    if(flag == n) puts("All pass!");
    else
    {
        for(int k = 0; k < j; k ++) puts(b[k]);
    }
    return 0;
}
