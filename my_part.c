#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

void print_to_staple(int mode)
{
    int readed;
    char timed[20];
    int len_timed = 0;

    readed = pop();

    if (mode != 2)
    {
        while (readed != '(')
        {
            if (readed / 256 == 0)
            {
                printf("%c\n", readed);
            }
            else-
            {
                printf("%c%c\n", (char)(readed % 256), (char)(readed / 256));
            }
            readed = pop();
        }
        if (mode == 1)
        {
            push(readed);
        }
    }
    else
    {
        while (readed != '(')
        {
            {
                if (readed == *"||")
                {
                    timed[len_timed++] = readed;
                }
                else
                {
                    if (readed / 256 == 0)
                    {
                        printf("%c\n", readed);
                    }
                    else
                    {
                        printf("%c%c\n", (char)(readed % 256), (char)(readed / 256));
                    }
                    readed = pop();
                }
            }
        }
        push(readed);
        for (int i = 0; i != len_timed; i++)
        {
            push(timed[i]);
        }
    }
}

int in_array(char check, char array[][6], int len)
{
    for (int i = 0; i != len; i++)
    {
        if (check == *array[i])
        {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    int input;
    int count_open = 0;
    int type_operands = 0;

    char operands[12][6] = {"TRUE", "FALSE", "true", "false", "True", "False", "!TRUE", "!FALSE", "!true", "!false", "!True", "!False"};

    push('(');

    scanf("%s", &input);

    while ((char)input != '=' && input != '\n' && input != EOF)
    {
        if ((char)(input / 256) == '&' && (char)(input % 256) == '&')
        {
            print_to_staple(2);
            push(input);
        }
        else
        {
            if ((char)(input / 256) == '|' && (char)(input % 256) == '|')
            {
                print_to_staple(1);
                push(input);
            }
            else
            {
                if ((char)(input / 256) == '(' && (char)(input % 256) == '!')
                {
                    count_open++;
                    push('!');
                    push('(');
                }
                else
                {
                    if ((char)(input % 256) == '(')
                    {
                        count_open++;
                        push(input);
                    }
                    else
                    {
                        if ((char)(input % 256) == ')')
                        {
                            count_open--;
                            print_to_staple(3);
                        }
                        else
                        {
                            if ((char)(input % 256) == '!')
                            {
                                push('!');
                            }
                            else
                            {
                                type_operands = in_array(input, operands, 12);
                                if (type_operands)
                                {
                                    if (type_operands > 6)
                                    {
                                        push('!');
                                        printf("%d\n", ((type_operands - 7) % 2)?0:1);
                                    }
                                    else
                                    {
                                        if (type_operands)
                                        {
                                            printf("%d\n", ((type_operands - 1) % 2)?0:1);
                                        }
                                        else
                                        {
                                            fprintf(stderr, "unknow input");
                                            exit(1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        scanf("%s", &input);
    }

    print_to_staple(3);

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
