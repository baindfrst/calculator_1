#include <stdio.h>
#include <string.h>

int main()
{  
    int a;
    scanf("%s", &a);
    printf("%c\n", a);
    printf("%d\n", a);
    printf("%d\n", a == '-');
    a = a - (int)'0';
    printf("%d\n", a == 3);

    return 0;
}