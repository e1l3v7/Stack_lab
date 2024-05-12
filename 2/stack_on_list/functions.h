#ifndef FUCNTIONS_H
#define FUCNTIONS_H
#include "stack.h"

char* string_transformation(char* str);
char* ToInfix(Stack** s,char* str);
int isFull(Stack* s);
int isEmpty(Stack* s);
int isSymbol(char symbol);
int getPriority(char op);
void PrintStr(char* str);

#endif
