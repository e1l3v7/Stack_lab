#include <stdio.h>
#include "lib-input.h"
void Scanf(int* a)
{
	while(scanf("%d",a) != 1)
	{
		printf("введен символ, а не число, повторите ввод\n");
		scanf("%*[^\n]");
	}
}
