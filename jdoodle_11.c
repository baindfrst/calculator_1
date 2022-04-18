#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    
   
    int N; int i = 0; int a, a_new, flag, b;
    N = strlen("1 0 &&"); //наше выражение в постфиксном формате, в виде строчки res_f_Koli
    char strochka[6] = "1 0 &&"; 
    
    while (strochka [i]) //пока не конец строки
    {
       if ((strochka[i] != ' ') && (flag = 0))
       {
           if (strochka[i] == '1' || strochka[i] == '0') 
           {
            push ((int)strochka [i++]); //кладём операнд в стек
            flag = 1;
           }
           else {
               if (strochka[i] == '!')
               {
                   a = pop() - (int)'0';
                   a_new = !a;
                   push (a_new);
                   flag = 1;
                   i++;
               }
               else {
                   if (strochka [i] == '&')
                      if (strochka [i + 1] == '&') 
                      {
                         b = pop () - (int)'0';
                         a = pop () - (int)'0';
                         a_new = a && b;
                         push (a_new);
                         flag = 1;
                         i+=2;
                         
                      }
                      else {
                         fprintf (stderr, "ne korectno 1\n");
                         exit(1); //потому что Коля сказал..., мудак
                   }
                  else {
                      if (strochka [i] == '|')
                         if (strochka [i + 1] == '|') 
                         {
                             b = pop () - (int)'0';
                             a = pop () - (int)'0';
                             a_new = a || b;
                             push (a_new);
                             flag = 1;
                             i+=2;
                         
                         }
                         else {
                             fprintf (stderr, "ne korectno 2\n");
                             exit(1); //потому что Коля сказал..., мудак
                            }
                    }
                   
               }
           }
       }
       else 
       {
           if (strochka[i] == ' ')
           {
               i++;
               flag = 0;
           }
           else fprintf (stderr, "ne korectno 3\n");
       }
    }
    pop (a);
    return a;
    
}