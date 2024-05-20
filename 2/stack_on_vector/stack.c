#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include <string.h>
int push(Stack* s,char* symbols) {
	if(!isFull(s)) {
		s->elems[s->head].symbols = (char*)calloc(strlen(symbols) + 1, sizeof(char));
		memcpy(s->elems[s->head].symbols, symbols, strlen(symbols)*sizeof(char));
		s->head += 1;
		return 0;
	}
	else {
		return 1;
	}
}
int pop(Stack* s) {
	if(!isEmpty(s)) {
		StackElem* tmp = s->elems + s->head - 1;
		s->head -= 1;
		free(tmp->symbols);
		return 0;
	}
	else {
		return 1;	
	}
}
Stack* CreateStack(int size) {
	Stack* s = (Stack*)calloc(1,sizeof(Stack));
	s->head = 0;
	s->max_size=size;
	s->elems = (StackElem*)calloc(size, sizeof(StackElem));
	return s;
}
void FreeStack(Stack* s) {
	while(!isEmpty(s)) {
		free(s->elems[s->head - 1].symbols);
		s->head -= 1;
	}
	free(s->elems);
	free(s);
}
