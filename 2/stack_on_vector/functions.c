#include "stack.h"
#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getPriority(char oper)
{
	if (oper == '-' || oper == '+')
		return 1;
	else if (oper == '*' || oper == '/')
		return 2;
	return 0;
}

int isFull(Stack* s)
{
	if(s->head==s->max_size)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int isEmpty(Stack* s)
{
	if(s->head==0)
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
	for(int i=1;i<strlen(str)+1;i++)
	{
		str1[i]=str[i-1];
	}
	str1[strlen(str)+1]=')';
	return str1;
}
void PrintStr(char* str)
{
	for(int i=strlen(str)-1;i>=0;i--)
	{
		printf("%c",str[i]);
	}
}
char* ToInfix(Stack** s,char* str)
{
	char* strout=(char*)malloc(strlen(str)*sizeof(char));
	int flag=0;
	int j=0;
	for(int i = 0; i < strlen(str)+2; i++)
	{
		if (isalpha(str[i]) || isdigit(str[i]))
		{
			strout[j] = str[i];
			j+=1;
		}
		else if( str[i] == '(')
		{
			flag=push(s, str[i]);
			if(flag==1)
			{
				break;
			}
		}
		else if(str[i]==')')
		{
			while((*s)->symbols[(*s)->head-1] != '(')
			{
				strout[j] = (*s)->symbols[(*s)->head-1];
				j++;
				pop(s);
			}
			pop(s);
		}
		else if(isSymbol(str[i]))
		{
			while (getPriority(str[i])< getPriority((*s)->symbols[(*s)->head-1]))
			{
				strout[j] = (*s)->symbols[(*s)->head-1];
				pop(s);
				j+=1;
			}
			flag=push(s,str[i]);
			if(flag==1)
			{
				break;
			}
		}
	}
	if(flag==0)
	{
		return strout;
	}
	else
	{
		printf("Недостаточный размер стека");
		return NULL;
	}
	
}
