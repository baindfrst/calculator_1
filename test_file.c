#include <stdio.h>
#include <string.h>

int main()
{  
    int a;
    scanf("%5s", &a);
    while (a != '=')
    {
        printf("%5s", a);
        scanf("%5s", &a);
    }

    return 0;
}