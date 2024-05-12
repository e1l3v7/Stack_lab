#include <stdio.h>
#include "stack.h"
#include "lib-input.h"
#include "readline/readline.h"
#include <ctype.h>

int main(void)
{

	printf("Введите строку: ");
	char* str=readline(">");
	str=string_transformation(str);
	printf("Введите размер стека: ");
	int size;
	Scanf(&size);
	Stack* s=CreateStack(size);
	char* strout=ToInfix(&s,str);
	PrintStr(strout);
	FreeStack(&s);
}
