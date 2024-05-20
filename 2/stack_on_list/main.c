#include <stdio.h>
#include "stack.h"
#include "lib-input.h"
#include "functions.h"
#include <ctype.h>
#include <stdlib.h>

int main(void) {
  printf("Введите строку: ");
  Stack* operators = CreateStack();
  Stack* operands = CreateStack();
  char* str = readline("");
  char* strout=ToInfix(str, operators, operands);
  printf("\n%s\n",strout);
  FreeStack(operators);
  free(operators);
  FreeStack(operands);
  free(operands);
  return 0;
}
