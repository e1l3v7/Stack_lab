#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
int push(Stack** s,char symbol)
{
	if(!isFull(*s))
	{
		(*s)->symbols[(*s)->head] = symbol;
		(*s)->head += 1;
		return 0;
	}
	else
	{
		return 1;
	}
}
int pop(Stack** s)
{
	if(!isEmpty(*s))
	{
		(*s)->head-=1;
		return 0;
	}
	else
	{
		return 1;	
	}
}
Stack* CreateStack(int size)
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->head = 0;
	s->max_size=size;
	s->symbols = (char*)malloc(size*sizeof(char));
	return s;
}

void FreeStack(Stack** s)
{
	free((*s)->symbols);
	free(*s);
}
