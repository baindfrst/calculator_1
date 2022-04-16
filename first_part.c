#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int from_char_int(int input)
{
    int ret = 0;
    int flag_minus = 0;
    int sumbol_weight = 256;
    while (input != 0)
    {
        if ('-' == (char)input)
        {
            input /= sumbol_weight;
            flag_minus = 1;
        }
        ret *= 10;
        ret += (char)(input % sumbol_weight ) - (char)'0';
        input /= sumbol_weight;
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

int check_input(char input) // 0 - (, -1 - унарные, -2 - унарный минус, 1 - бинарные ниж поряд, 2 - бинар выс поряд, 3 - ), -3 - простое число, -4 - ошибка 
{
    int staple[2] = {'(', ')'};
    int unar_operators[4] = {'&','|','!','~'}; //пока нет операторов && и || так как я не понял как их тут ввести
    int binar_operators_scnd[3] = {'/', '*', '%'};
    int binar_operators_frst[2] = {'+', '-'};

    for (int i = 0; i != 3; i++)
    {
        if (input == binar_operators_scnd[i])
        {
            return 2;
        }
        if (input == binar_operators_frst[i/2])
        {
            return 1;
        }
    }

    if (input == staple[0])
    {
        return 0;
    }

    if (input == staple[1])
    {
        return 3;
    }

    for (int i = 0; i != 4; i++)
    {
        if (input == unar_operators[i])
        {
            return -1;
        }
    }

    input = from_char_int(input);

    if (input < 0)
    {
        return -2;
    }
    else
    {
        return -3;
    }
    return -4;
}

void print_to_staple(int mode)
{
    char readed;
    char timed[20];
    int len_timed = 0;

    readed = pop();

    if (mode != 2)
    {
        while (readed != '(');
        {
            printf("%c\n", readed);
            readed = pop();
        }
        if (mode == 1)
        {
            push('(');
        }
    }
    else
    {
        while (readed != '(')
        {
            {
                if (readed == '+' || readed == '-')
                {
                    timed[len_timed++] = readed;
                }
                else
                {
                    printf("%c\n", readed);
                    readed = pop();
                }
            }
        }
        push('(');
        for (int i = 0; i != len_timed; i++)
        {
            push(timed[i]);
        }
    }
}

int main()
{
    int input;
    int input_class;
    int count_open = 0;
    scanf("%s", &input);

    while (input != '=' && input != '\n' && input != EOF)
    {
        input_class = check_input(input);
        printf("%c, %d test\n", input, input_class);
        if (input_class == -4) // вывод ошибки
        {
            fprintf(stderr, "unknow input");
            return -2;
        }
        if (input_class < 1) // унарные операции, открывающая скобка и числа
        {
            if (input_class == -2) // отрицательное число
            {
                push('-');
                printf("%d\n", -1 * from_char_int(input));
            }
            else
            {
                if (input_class == -3) // простое число
                {
                    printf("%d\n", from_char_int(input));
                }
                else
                {
                    push(input);
                    if (input_class == 0) // если ввелась открывающая точка
                    {
                        count_open++;
                    }
                }
            }
        }
        else
        {
            print_to_staple(input_class); // вывод операций до открывающей скобки
            if (input_class != 3) // ввод нынешней операции, если ввели не закрывабщую скобку, иначе уменьшаем количество открывабщих скобок на 1
            {
                push(input);
            }
            else
            {
                count_open--; 
            }
        }
        scanf("%s", &input);
    }

    printf("end\n");

    if (count_open == 0)
    {
        return 0;
    }
    else
    {
        fprintf(stderr, "err whith '('");
        return -2;
    }
}