#ifndef STACK_H
#define STACK_H

typedef struct
{
	int head;
	char* symbols;
	int max_size;
} Stack;

Stack* CreateStack(int size);
int push(Stack** s,char symbol);
int pop(Stack** s);
void FreeStack(Stack** s);

#endif
