#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int getPriority(char op) {
	if(op == '-' || op == '+')
		return 1;
	else if(op == '*' || op == '/')
		return 2;
	return 0;
}

int isFull(Stack* s) {
	return s->head == s->max_size;
}

int isEmpty(Stack* s) {
	return s->head == 0;
}

int isSymbol(char symbol) {
	return symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/';
}


char* ToInfix(char* str, Stack* operators, Stack* operands) {
	int fl = 0;
	for (size_t i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			char* a = NULL;
			a = (char*)calloc(2,sizeof(char));
			memcpy(a, str+i, sizeof(char));
			fl = push(operators, a);
			if(fl) {
				printf("Недостаточный размер стека\n");
				free(a);
				return NULL;
			}
			free(a);
		}

		else if (str[i] == ')') {
			while (!isEmpty(operators) && *operators->elems[operators->head - 1].symbols != '(') {
				char* operand1 = (char*)calloc(strlen(operands->elems[operands->head - 1].symbols) + 1, sizeof(char));
				memcpy(operand1, operands->elems[operands->head - 1].symbols, strlen(operands->elems[operands->head - 1].symbols));
				pop(operands);

				char* operand2 = (char*)calloc(strlen(operands->elems[operands->head - 1].symbols) + 1, sizeof(char));
				memcpy(operand2, operands->elems[operands->head - 1].symbols, strlen(operands->elems[operands->head - 1].symbols));
				pop(operands);

				char* op = (char*)calloc(strlen(operators->elems[operators->head - 1].symbols) + 1, sizeof(char));
				memcpy(op, operators->elems[operators->head - 1].symbols, strlen(operators->elems[operators->head - 1].symbols));
				pop(operators);

				char* tmp = (char*)calloc((strlen(operand1) + strlen(operand2) + strlen(op)) + 1, sizeof(char) );
				strcat(tmp, op);
				strcat(tmp, operand2);
				strcat(tmp, operand1);
				fl = push(operands, tmp);
				if(fl) {	
					printf("Недостаточный размер стека\n");
					free(op);
					free(operand1);
					free(operand2);
					free(tmp);
					return NULL;
				}
				free(op);
				free(operand1);
				free(operand2);
				free(tmp);
			}
			pop(operators);
		}

		else if (isalpha(str[i]) || isdigit(str[i])) {
			char* a = NULL;
			a = (char*)calloc(2, sizeof(char));
			memcpy(a, str+i, sizeof(char));
			fl = push(operands, a);
			if(fl) {
				printf("Недостаточный размер стека\n");
				free(a);
				return NULL;
			}
			free(a);
		}

		else if(isSymbol(str[i])) {

			while (!isEmpty(operators) && getPriority(str[i]) <= getPriority(*operators->elems[operators->head - 1].symbols)) {
				 char* operand1 = (char*)calloc(strlen(operands->elems[operands->head - 1].symbols) + 1, sizeof(char));
				memcpy(operand1, operands->elems[operands->head - 1].symbols, strlen(operands->elems[operands->head].symbols)+1);
				pop(operands);

				char* operand2 = (char*)calloc(strlen(operands->elems[operands->head - 1].symbols) + 1, sizeof(char));
				memcpy(operand2, operands->elems[operands->head].symbols, strlen(operands->elems[operands->head].symbols)+1);
				pop(operands);

				char* op = (char*)calloc(strlen(operators->elems[operators->head - 1].symbols) + 1, sizeof(char));
				memcpy(op, operators->elems[operators->head].symbols, strlen(operators->elems[operators->head].symbols)+1);
				pop(operators);

				char* tmp = (char*)calloc((strlen(operand1) + strlen(operand2) + strlen(op)) + 1, sizeof(char) );
				strcat(tmp, op);
				strcat(tmp, operand2);
				strcat(tmp, operand1);
				fl = push(operands, tmp);
				if(fl) {
					printf("Недостаточный размер стека\n");
					free(operand1);
					free(operand2);
					free(op);
					free(tmp);
					return NULL;
				}
				free(op);
				free(operand1);
				free(operand2);
				free(tmp);
			}
			char* a = NULL;
			a = (char*)calloc(2, sizeof(char));
			memcpy(a, str+i, sizeof(char));
			fl = push(operators, a);
			if(fl) {
				printf("Недостаточный размер стека\n");
				free(a);
				return NULL;
			}
			free(a);
		}
	}

	while (!isEmpty(operators)) {
		char* operand1 = (char*)calloc(strlen(operands->elems[operands->head - 1].symbols) + 1, sizeof(char));
		memcpy(operand1, operands->elems[operands->head - 1].symbols, strlen(operands->elems[operands->head - 1].symbols));
		pop(operands);

		char* operand2 = (char*)calloc(strlen(operands->elems[operands->head - 1].symbols) + 1, sizeof(char));
		memcpy(operand2, operands->elems[operands->head - 1].symbols, strlen(operands->elems[operands->head - 1].symbols));
		pop(operands);

		char* op = (char*)calloc(strlen(operators->elems[operators->head - 1].symbols) + 1, sizeof(char));
		memcpy(op, operators->elems[operators->head - 1].symbols, strlen(operators->elems[operators->head - 1].symbols));
		pop(operators);

		char* tmp = (char*)calloc((strlen(operand1) + strlen(operand2) + strlen(op)) + 1, sizeof(char) );
		strcat(tmp, op);
		strcat(tmp, operand2);
		strcat(tmp, operand1);
		fl = push(operands, tmp);
		if(fl) {
			printf("Недостаточный размер стека\n");
			free(operand1);
			free(operand2);
			free(op);
			free(tmp);
			return NULL;
		}
		free(op);
		free(operand1);
		free(operand2);
		free(tmp);
	}
	return operands->elems[operands->head - 1].symbols;
}
