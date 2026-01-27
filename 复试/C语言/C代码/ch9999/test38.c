#include<stdio.h>
#include<string.h>
#define N 100
void MyStrcat(char dstStr[],char srcStr[]);
int main(void)
{
    char a[N] = "i like ";
    char b[N] = "c program";
    MyStrcat(a,b);
    printf("%s\n",a);
    return 0;
}

void MyStrcat(char dstStr[],char srcStr[])
{
    int i;
    int len_dst, len_src;
    len_dst = strlen(dstStr);
    len_src = strlen(srcStr);
    i = 0;
    while(i < len_src)
    {
        dstStr[len_dst++] = srcStr[i++];
    }
    dstStr[len_dst]='\0';
}
