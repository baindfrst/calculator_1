#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#define n 20

int stack[n];
int len = 0;

void push(int elem)
{
	if (len > n)
	{
		fprintf(stderr, "overflow error");
		exit(-1);

	}
	stack[len++] = elem;
}

int pop()
{
	if (len < 0)
	{
		fprintf(stderr, "error");
		exit(-1);
	}
	return stack[--len];
} 

void print_stack()
{
	printf("stack print: %d", len);
	for ( int i = 0; i != len + 1; i++)
	{
		if (stack[len] / 256 == 0)
        {
            printf("%c\n", stack[len]);
		}
        else
        {
            printf("%c%c", stack[len] % 256, stack[len] / 256);
        }
	}
	printf("\n");
}
