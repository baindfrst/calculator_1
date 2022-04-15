#include <stdio.h>
#include <string.h>

int charint(int input)
{
    int ret = 0;
    int flag_minus = 0;
    while (input != 0)
    {
        if ('-' == (char)input)
        {
            input /= 256;
            flag_minus = 1;
        }
        ret *= 10;
        ret += (char)(input % 256 ) - (char)'0';
        input /= 256;
        printf("%d, %d\n", ret, input);
    }
    if (flag_minus)
    {
        return -ret;
    }
    else
    {
        return ret;
    }
}

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