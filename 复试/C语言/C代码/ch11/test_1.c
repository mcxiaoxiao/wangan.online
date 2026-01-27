#include<stdio.h>
#include<string.h>
void swap(char* a, char *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}
void sort(char *ptr[],int n)
{
    for(int i = 0; i < n - 1; i ++)
    {

        for(int j = i + 1; j < n; j ++)
        {
            if(strcmp(ptr[j],ptr[i])<0)
            {
                char* temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}
int main(void)
{

    int n = 0;
    scanf("%d",&n);
    getchar();
    char name[5][10];
    char* ptr[5];
    for(int i = 0; i < n; i ++)
    {
        ptr[i] = name[i];
        gets(name[i]);
    }
    sort(ptr,n);
    for(int i = 0; i < n; i ++)
    {
        puts(ptr[i]);
    }
    return 0;
}
