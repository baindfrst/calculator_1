#include <stdio.h>
#include <string.h>
#include "frst_part.h"

int main()
{  
    int string = main_start();
    printf("%c", (char)string);
    while ((char)string != '\0')
    {
        printf("%c", (char)string % 256);
        string /= 256;
    }
    return 0;
}