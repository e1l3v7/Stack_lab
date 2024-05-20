#ifndef FUCNTIONS_H
#define FUCNTIONS_H
#include "stack.h"

char* ToInfix(char* str, Stack* operators, Stack* operands);
int isFull(const Stack* s);
int isEmpty(const Stack* s);
int isSymbol(const char symbol);
int getPriority(const char op);

#endif
