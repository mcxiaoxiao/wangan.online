#include <stdio.h>

int main()
{
    double n = 1;
    double sum = 0;
    for(int i = 0; i < 64; i++)
    {
        sum += n;
        n *= 2;
    }

    printf("%e\t%e",sum,sum/1.42e8);
    return 0;
}
