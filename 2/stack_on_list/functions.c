#include "stack.h"
#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getPriority(char op)
{
	if(op=='-' || op=='+')
		return 1;
	else if(op=='*' || op=='/')
		return 2;
	return 0;
}
void PrintStr(char* str)
{
	for(int i=strlen(str)-1;i>=0;i--)
	{
		printf("%c",str[i]);
	}
}
int isEmpty(Stack* s)
{
	if(s->head==NULL)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int isSymbol(char symbol)
{
	if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char* string_transformation(char* str)
{
	char* str1=malloc((strlen(str)+2)*sizeof(char));
	str1[0]='(';
	strcat(str1,str);
	strcat(str1,')');
	return str1;
}

char* ToInfix(Stack** s,char* str)
{
	char* strout=(char*)malloc(strlen(str)*sizeof(char));
	int j=0;
	int fl=1;
	for(int i = 0; i < strlen(str)+2; i++)
	{
		if (isalpha(str[i]) || isdigit(str[i]))
		{
			strout[j] = str[i];
			j+=1;
		}
		else if(str[i] == '(')
		{
			fl=push(s, str[i]);
			if(fl=0)
			{
				printf("Ошибка");
				return NULL;
			}
		}
		else if(str[i]==')')
		{
			while((*s)->head->symbol != '(')
			{
				strout[j] = (*head)->symbol;
				j++;
				fl=pop(s);
				if(fl=0)
				{
					printf("Ошибка");
					return NULL;
				}
			}
			fl=pop(s);
			if(fl=0)
			{
				printf("Ошибка");
				return NULL;
			}
		}
		else if(isSymbol(str[i]))
		{
			while (getPriority(str[i])< getPriority((*s)->head->symbol))
			{
				strout[j] = (*s)->head->symbol;
				fl=pop(s);
				if(fl=0)
				{
					printf("Ошибка");
					return NULL;
				}
				j+=1;
			}
			fl=push(s,str[i]);
			if(fl=0)
			{
				printf("Ошибка");
				return NULL;
			}
		}
	}
	return strout;
}
