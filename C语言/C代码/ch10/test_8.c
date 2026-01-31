#include<stdio.h>

void swap(char *a, char *b)
{
    char temp[10];
    strcpy(temp, a);
    strcpy(a,b);
    strcpy(b,temp);

}
void sort(char a[][10])
{
    for(int i = 0; i < 4; i ++)
    {
        for(int j = i + 1; j < 5; j ++)
        {
            if(strcmp(a[i],a[j]) > 0) swap(a[i],a[j]);
        }
    }
}

int main(void)
{
    char s[5][10];
    for(int i = 0; i < 5; i ++)
        gets(s[i]);
    sort(s);

    puts(s[0]);
    return 0;
}
