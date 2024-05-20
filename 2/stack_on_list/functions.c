#include "stack.h"
#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int getPriority(const char op) {
	if(op=='-' || op=='+')
		return 1;
	else if(op=='*' || op=='/')
		return 2;
	return 0;
}

int isEmpty(const Stack* s) {
	return s->head == NULL;
}

int isSymbol(char symbol) {
	return symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/';
}

char* ToInfix(char* str, Stack* operators, Stack* operands) {
	for (size_t i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			char* a = NULL;
			a = (char*)calloc(2,sizeof(char));
			memcpy(a, str+i, sizeof(char));
			push(operators, a);
			free(a);
		}

		else if (str[i] == ')') {
			while (!isEmpty(operators) && *operators->head->symbols != '(') {
				char* operand1 = (char*)calloc(strlen(operands->head->symbols) + 1, sizeof(char));
				memcpy(operand1, operands->head->symbols, strlen(operands->head->symbols)+1);
				pop(operands);

				char* operand2 = (char*)calloc(strlen(operands->head->symbols) + 1, sizeof(char));
				memcpy(operand2, operands->head->symbols, strlen(operands->head->symbols)+1);
				pop(operands);

				char* op = (char*)calloc(strlen(operators->head->symbols) + 1, sizeof(char));
				memcpy(op, operators->head->symbols, strlen(operators->head->symbols)+1);
				pop(operators);

				char* tmp = (char*)calloc((strlen(operand1) + strlen(operand2) + strlen(op)) + 1, sizeof(char) );
				strcat(tmp, op);
				strcat(tmp, operand2);
				strcat(tmp, operand1);
				push(operands, tmp);

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
			push(operands, a);
			free(a);
		}

		else if(isSymbol(str[i])) {

			while (!isEmpty(operators) && getPriority(str[i]) <= getPriority(*operators->head->symbols)) {
				char* operand1 = (char*)calloc(strlen(operands->head->symbols) + 1, sizeof(char));
				memcpy(operand1, operands->head->symbols, strlen(operands->head->symbols)+1);
				pop(operands);

				char* operand2 = (char*)calloc(strlen(operands->head->symbols) + 1, sizeof(char));
				memcpy(operand2, operands->head->symbols, strlen(operands->head->symbols)+1);
				pop(operands);

				char* op = (char*)calloc(strlen(operators->head->symbols) + 1, sizeof(char));
				memcpy(op, operators->head->symbols, strlen(operators->head->symbols)+1);
				pop(operators);

				char* tmp = (char*)calloc((strlen(operand1) + strlen(operand2) + strlen(op)) + 1, sizeof(char) );
				strcat(tmp, op);
				strcat(tmp, operand2);
				strcat(tmp, operand1);
				push(operands, tmp);

				free(op);
				free(operand1);
				free(operand2);
				free(tmp);
			}
			char* a = NULL;
			a = (char*)calloc(2, sizeof(char));
			memcpy(a, str+i, sizeof(char));
			push(operators, a);
			free(a);
		}
	}

	while (!isEmpty(operators)) {
		char* operand1 = (char*)calloc(strlen(operands->head->symbols) + 1, sizeof(char));
		memcpy(operand1, operands->head->symbols, strlen(operands->head->symbols)+1);
		pop(operands);

		char* operand2 = (char*)calloc(strlen(operands->head->symbols) + 1, sizeof(char));
		memcpy(operand2, operands->head->symbols, strlen(operands->head->symbols)+1);
		pop(operands);

		char* op = (char*)calloc(strlen(operators->head->symbols) + 1, sizeof(char));
		memcpy(op, operators->head->symbols, strlen(operators->head->symbols)+1);
		pop(operators);

		char* tmp = (char*)calloc((strlen(operand1) + strlen(operand2) + strlen(op)) + 1, sizeof(char) );
		strcat(tmp, op);
		strcat(tmp, operand2);
		strcat(tmp, operand1);
		push(operands, tmp);

		free(op);
		free(operand1);
		free(operand2);
		free(tmp);
	}
	return operands->head->symbols;
}

