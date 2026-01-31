#include<stdio.h>
#include<string.h>
#define N 201
void sortStr(char a[][N], int n);
int main(void)
{
    int i, j, k;
    char str[N];
    char str_spit[N][N];
    int lenth_str;
    int count;
    int flag;
    gets(str);
    lenth_str = strlen(str);

    j = 0;
    k = 0;
    count = 0;
    for(i = 0; i < lenth_str; i ++)
    {
        if(str[i] == ' ')
        {
            str_spit[k][j] = '\0';
            k++;
            count ++;
            flag = 0;
            // 处理多个空格
            while(str[i] == ' ')
            {
                i++;
                flag = 1;
            }
            if(flag) i --;
            j = 0;
        }
        else
        {
            str_spit[k][j++] = str[i];
        }
    }
    // 处理str的‘\0’
    if(i != 0)
    {
        str_spit[k][j] = '\0';
        k++;
        count ++;
    }
    printf("num:%d\n",count);
    sortStr(str_spit,k);
    for(i = 0; i < k; i ++)
    {
        puts(str_spit[i]);
    }
    return 0;
}

void sortStr(char a[][N], int n)
{
    char temp[N];
    int i, j;
    for(int i = 0; i < n; i ++)
    {
        for(j = n-1; j > i; j --)
        {
            if(strcmp(a[j],a[j-1])>0)
            {
                memset(temp,0,sizeof(temp));
                strcpy(temp,a[j]);
                strcpy(a[j],a[j-1]);
                strcpy(a[j-1],temp);
            }
        }
    }
}


/*
*对字符串进行 ‘ ’ 划分并排序
*空格
*/
