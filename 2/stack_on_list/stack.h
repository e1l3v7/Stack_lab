#ifndef STACK_H
#define STACK_H

typedef struct {
	void* next;
	char* symbols;
} StackElem;

typedef struct {
	StackElem* head;
} Stack;

StackElem* CreateStackElem(StackElem* sel, char* symbols);
int push(Stack* s,char* symbols);
int pop(Stack* s);
void FreeStack(Stack* head);
Stack* CreateStack();

#endif
