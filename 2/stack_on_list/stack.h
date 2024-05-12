#ifndef STACK_H
#define STACK_H

typedef struct
{
	void* next;
	char symbol;
} StackElem;

typedef struct
{
	StackElem* head;
} Stack;

StackElem* CreateStackElem();
int push(Stack** head,char symbol);
int pop(Stack** head);
void PrintStr(char* str);
void FreeStack(Stack** head);
bool isEmpty(Stack* s);

#endif
