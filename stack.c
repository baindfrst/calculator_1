#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#define n 20

char stack[n];
int len = 0;

void push(char elem)
{
	if (len > n)
	{
		fprintf(stderr, "overflow error");
		exit(-1);

	}
	stack[len++] = elem;
}

char pop()
{
	if (len < 0)
	{
		fprintf(stderr, "error");
		exit(-1);
	}
	return stack[--len];
} 
