#ifndef FUCNTIONS_H
#define FUCNTIONS_H
#include "stack.h"

char* ToInfix(char* str, Stack* operators, Stack* operands);
int isFull(Stack* s);
int isEmpty(Stack* s);
int isSymbol(char symbol);
int getPriority(char op);


#endif

