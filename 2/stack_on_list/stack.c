#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

int pop(Stack** s)
{
	if((*s)->head->next!=NULL)
	{
		StackElem* temp = (*s)->head;
		*head = (*s)->head->next;
		free(temp);
		return 1;
	}
	else
	{
		return 0;
	}
}

void FreeStack(Stack** s)
{
	while((*s)->head->next!=NULL)
	{
		StackElem* temp = (*s)->head;
		(*s)->head = (*s)->head->next;
		free(temp);
	}
	free((*s)->head);
}

StackElem* CreateStackElem(StackElem* sel)
{
	StackElem* se = (StackElem*)malloc(sizeof(StackElem));
	se->next=sel;
	return se;
}

Stack* CreateStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->head = NULL;
	return s;
}

int push(Stack** s, char symbol)
{
	StackElem* new_elem=NULL;
	new_elem=CreateStackElem((*s)->head);
	if(new_elem!=NULL)
	{
		new_elem->symbol=symbol;
		(*s)->head=se;
		return 1;
	}
	else
	{
		return 0;
	}
}
