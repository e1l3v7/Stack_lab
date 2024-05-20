#include <stdio.h>
#include "stack.h"
#include "lib-input.h"
#include "readline/readline.h"
#include "functions.h"
#include <ctype.h>

int main(void) {
	printf("Введите строку: ");
	char* str = readline("");
	printf("Введите размер стека: ");
	int m;
	if(Scanf(&m)) {
		Stack* s1 = CreateStack(m);
		Stack* s2 = CreateStack(m);
		char* strout = ToInfix(str,s1,s2);
		if(strout)
			printf("%s\n", strout);
		FreeStack(s1);
		FreeStack(s2);
	}
	return 0;
}
