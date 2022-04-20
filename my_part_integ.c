#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include "frst_part.h"

int print_to_staple(int mode, int out)
{
    int readed;
    char timed[20];
    int len_timed = 0;

    readed = pop();

    if (mode != 2)
    {
        while (readed != '(')
        {
            out = (out * 256 + (out)?(int)' ':0) * 256 + readed;
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
                    out = (out * 256 + (out)?(int)' ':0) * 256 + readed;
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
    return out;
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

int main_start()
{
    int input;
    int count_open = 0;
    int type_operands = 0;
    int was_input = 0; // отвечает за соблюдение последовательность
    int out_string = 0;

    char operands[12][6] = {"TRUE", "FALSE", "true", "false", "True", "False", "!TRUE", "!FALSE", "!true", "!false", "!True", "!False"};

    push('(');

    scanf("%s", &input);

    while ((char)input != '=' && input != '\n' && input != EOF)
    {
        if ((char)(input / 256) == '&' && (char)(input % 256) == '&')
        {
            if (was_input == 0)
            {
                fprintf(stderr, "unknow input");
                exit(1);
            }
            else
            {
                was_input = 0;
            }
            out_string = print_to_staple(2, out_string);
            push(input);
        }
        else
        {
            if ((char)(input / 256) == '|' && (char)(input % 256) == '|')
            {
                if (was_input == 0)
                {
                    fprintf(stderr, "unknow input");
                    exit(1);
                }
                else
                {
                    was_input = 0;
                }
                out_string = print_to_staple(1, out_string);
                push(input);
            }
            else
            {
                if ((char)(input / 256) == '(' && (char)(input % 256) == '!')
                {
                    if (was_input == 1)
                    {
                        fprintf(stderr, "unknow input");
                        exit(1);
                    }
                    count_open++;
                    out_string = (out_string * 256 + (out_string)?(int)' ':0) * 256 + input;
                }
                else
                {
                    if ((char)(input % 256) == '(')
                    {
                        if (was_input == 1)
                        {
                            fprintf(stderr, "unknow input");
                            exit(1);
                        }
                        count_open++;
                        push(input);
                    }
                    else
                    {
                        if ((char)(input % 256) == ')')
                        {
                            if (was_input == 0)
                            {
                                fprintf(stderr, "er )");
                                exit(1);
                            }
                            else
                            {
                                was_input = 1;
                            }
                            count_open--;
                            out_string = print_to_staple(3, out_string);
                        }
                        else
                        {
                            if ((char)(input % 256) == '!' && input / 256 == 0)
                            {
                                if (was_input == 1)
                                {
                                    fprintf(stderr, "unknow input");
                                    exit(1);
                                }
                                else
                                {
                                    was_input = 0;
                                }
                                out_string = (out_string * 256 + (out_string)?(int)' ':0) * 256 + input;
                            }
                            else
                            {
                                type_operands = in_array(input, operands, 12);
                                if (type_operands)
                                {
                                    if (was_input == 1)
                                    {
                                        fprintf(stderr, "unknow input");
                                        exit(1);
                                    }
                                    else
                                    {
                                        was_input = 1;
                                    }
                                    if (type_operands > 6)
                                    {
                                        out_string = ((out_string * 256 + (out_string)?(int)' ':0) * 256 + (int)'!') * 256 + ((type_operands - 7) % 2)?0:1 + (int)'0';
                                    }
                                    else
                                    {
                                        if (type_operands)
                                        {
                                            out_string = (out_string * 256 + (out_string)?(int)' ':0) * 256 + ((type_operands - 7) % 2)?0:1 + (int)'0';
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

    out_string = print_to_staple(3, out_string);

    out_string = out_string * 256 + (int)'\0';

    if (count_open == 0 && was_input == 1)
    {
        return out_string;
    }
    else
    {
        fprintf(stderr, "err whith '('");
        return -2;
    }
}
