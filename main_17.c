#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "frst_part.h"
#define N 15

int main() 
{
    
   
    int i = 0; int a, flag = 0, b; int result;
    //strochka = res_f_Koli; - по-моему так не получится, если хочешь передать строку, 
    //как результат твоей функции, то я хз как
    //char strochka[11] = {'0', ' ', '1', ' ', '|', '|', ' ', '0', ' ', '&', '&', '\0'}; //это тупой ввод
    int strochka = main_start(); 
    int c;
    int count = 0;
    //while (((c = getchar())!= '=') && (c != '\n')  && (c != EOF))  {
        //strochka[count] = c;
        //count++;
    //}
    //strochka[count] = '\0';
    
    
    
    while ((char)(strochka % 256) != '\0') //пока не конец строки
    {
       printf("%c", (char)(strochka % 256));
       if ((char)(strochka % 256 != ' ') && (flag == 0))
       {
           if ((char)(strochka % 256) == '1' || (char)(strochka % 256) == '0') 
           {
            push((char)(strochka % 256) - '0'); //кладём операнд в стек - сразу как цифру
            i++;
            flag = 1;
           }
           else {
               if ((char)(strochka % 256) == '!')
               {
                   a = pop();
                   push(!a);
                   flag = 1;
                   i++;
               }
               else {
                   if ((char)(strochka % 256) == '&')
                   {
                      if ((char)(strochka / 256 % 256) == '&') 
                      {
                     
                         b = pop();
                         //printf ("%d %s \n", b, " это b");
                         a = pop();
                         //printf ("%d %s \n", a, " это a");
                         printf ("%d %s \n", a&&b, " это a&&b");
                         push(a&&b);
                         flag = 1;
                         i+=2;
                         
                      }
                      else {
                         fprintf (stderr, "ne korectno 1\n");
                         exit(1); 
                        }
                   }
                  else {
                      if ((char)(strochka % 256) == '|')
                      {
                         if ((char)(strochka / 256 % 256) == '|') 
                         {
                             
                             b = pop();
                             //printf ("%d %s \n", b, " это b");
                             a = pop();
                             //printf ("%d %s \n", a, " это a");
                             printf ("%d %s \n", a||b, " это a||b");
                             push(a||b);
                             flag = 1;
                             i+=2;
                         
                         }
                         else {
                             fprintf (stderr, "ne korectno 2\n");
                             exit(1);
                            }
                       }
                    }
                   
               }
           }
       }
       else 
       {
           if ((char)(strochka % 256) == ' ')
           {
               i++;
               flag = 0;
           }
           else {
               fprintf (stderr, "ne korectno 3\n");
               exit(1);
           }
       }
    }
    result = pop ();
    printf ("%d %s\n", result, " это результат");
    return result;
    
}