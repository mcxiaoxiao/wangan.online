#include <stdio.h>

int main(void)
{
    char s[7]= {'H','e','l','l','o','\0','!'};
    puts(s); // Hello

    char* p = s;
    p[0] = 'A';
    puts(p);
    return 0;
}
