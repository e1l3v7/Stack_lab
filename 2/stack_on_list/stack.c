#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

int pop(Stack* s) {
	if(!isEmpty(s)) {
		StackElem* temp = s->head;
		s->head = s->head->next;
		if(temp->symbols != NULL)
			free(temp->symbols);
		if(temp != NULL)
			free(temp);
		return 1;
	}
	else {
		return 0;
	}
}

void FreeStack(Stack* s) {
	if(!isEmpty(s)) {
		while(s->head->next != NULL) {
			StackElem* temp = s->head;
			s->head = s->head->next;
			free(temp->symbols);
			free(temp);
		}
		if(s->head->symbols)
			free(s->head->symbols);
		free(s->head);
	}
}

StackElem* CreateStackElem(StackElem* sel, char* symbols) {
	StackElem* se = (StackElem*)calloc(1,sizeof(StackElem));
	se->next = sel;
	se->symbols = (char*)calloc(strlen(symbols) + 1, sizeof(char));
	memcpy(se->symbols, symbols, strlen(symbols));
	return se;
}

Stack* CreateStack() {
	Stack* s = (Stack*)calloc(1,sizeof(Stack));
	s->head = NULL;
	return s;
}

int push(Stack* s,char* symbols) {
	StackElem* new_elem = NULL;
	new_elem = CreateStackElem(s->head, symbols);
	if(new_elem) {
		s->head = new_elem;
		return 1;
	}
	else {
		return 0;
	}
}

