/**
 * @file Função que diz respeito ao parser
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"
#include "stack.h"

/**
 * \brief Esta função faz o parse do input.
 *
 * @param line O input que foi lido ao qual vai ser aplicado o parse.
 * 
 * 
 */

void parse(char *input)
{

	char *delims = " \t\n";
	long a;
	STACK *s = createStack();

	for (char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims))
	{
		char *resto;
		a = strtol(token, &resto, 10);
		if (strlen(resto) == 0)
		{
			PUSH_LONG(s, a);
		}
		else if (strcmp(token, "+") == 0)
		{
			if (hasType(profundidade(s,1), LONG) && hasType(profundidade(s, 2), LONG))
			{
				long x = POP_LONG(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y+x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), DOUBLE)){
				long x = POP_LONG(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, y+x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), CHAR)){
				long x = POP_LONG(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, y+x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), DOUBLE)){
				double x = POP_DOUBLE(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, y+x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), LONG)){
				double x = POP_DOUBLE(s);
				long y = POP_LONG(s);
				PUSH_DOUBLE(s, y+x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), CHAR)){
				double x = POP_DOUBLE(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, y+x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), CHAR)){
				char x = POP_CHAR(s);
				char y = POP_CHAR(s);
				PUSH_CHAR(s, y+x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), LONG)){
				char x = POP_CHAR(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y+x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), DOUBLE)){
				char x = POP_CHAR(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, y+x);
			}
		}
		else if (strcmp(token, "-") == 0)
		{
			if (hasType(profundidade(s,1), LONG) && hasType(profundidade(s, 2), LONG))
			{
				long x = POP_LONG(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y-x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), DOUBLE)){
				long x = POP_LONG(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, y-x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), CHAR)){
				long x = POP_LONG(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, y-x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), DOUBLE)){
				double x = POP_DOUBLE(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s,y-x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), LONG)){
				double x = POP_DOUBLE(s);
				long y = POP_LONG(s);
				PUSH_DOUBLE(s, y-x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), CHAR)){
				double x = POP_DOUBLE(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, y-x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), CHAR)){
				char x = POP_CHAR(s);
				char y = POP_CHAR(s);
				PUSH_CHAR(s, y-x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), LONG)){
				char x = POP_CHAR(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y-x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), DOUBLE)){
				char x = POP_CHAR(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, y-x);
			}
		}
		else if (strcmp(token, "*") == 0)
		{
			if (hasType(profundidade(s,1), LONG) && hasType(profundidade(s, 2), LONG))
			{
				long x = POP_LONG(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y*x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), DOUBLE)){
				long x = POP_LONG(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, y*x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), CHAR)){
				long x = POP_LONG(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, y*x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), DOUBLE)){
				double x = POP_DOUBLE(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s,y*x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), LONG)){
				double x = POP_DOUBLE(s);
				long y = POP_LONG(s);
				PUSH_DOUBLE(s, y*x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), CHAR)){
				double x = POP_DOUBLE(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, y*x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), CHAR)){
				char x = POP_CHAR(s);
				char y = POP_CHAR(s);
				PUSH_CHAR(s, y*x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), LONG)){
				char x = POP_CHAR(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y*x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), DOUBLE)){
				char x = POP_CHAR(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, y*x);
			}
		}
		else if (strcmp(token, "/") == 0)
		{
			if (hasType(profundidade(s,1), LONG) && hasType(profundidade(s, 2), LONG))
			{
				long x = POP_LONG(s);
				long y = POP_LONG(s);
				double z = y/x;
				PUSH_DOUBLE(s, z);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), DOUBLE)){
				long x = POP_LONG(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, y/x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), CHAR)){
				long x = POP_LONG(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, y/x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), DOUBLE)){
				double x = POP_DOUBLE(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s,y/x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), LONG)){
				double x = POP_DOUBLE(s);
				long y = POP_LONG(s);
				PUSH_DOUBLE(s, y/x);
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), CHAR)){
				double x = POP_DOUBLE(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, y/x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), CHAR)){
				char x = POP_CHAR(s);
				char y = POP_CHAR(s);
				PUSH_CHAR(s, y/x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), LONG)){
				char x = POP_CHAR(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y/x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), DOUBLE)){
				char x = POP_CHAR(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, y/x);
			}
		}
		else if (strcmp(token, "(") == 0)
		{
			if(hasType(TOP(s), LONG)){
				long x = POP_LONG(s);
				PUSH_LONG(s, x--);
			}else if(hasType(TOP(s), DOUBLE)){
				double x = POP_DOUBLE(s);
				PUSH_DOUBLE(s, x--);
			}else if(hasType(TOP(s), CHAR)){
				char x = POP_CHAR(s);
				PUSH_CHAR(s, x--);
			}
		}
		else if (strcmp(token, ")") == 0)
		{
			if(hasType(TOP(s), LONG)){
				long x = POP_LONG(s);
				PUSH_LONG(s, x++);
			}else if(hasType(TOP(s), DOUBLE)){
				double x = POP_DOUBLE(s);
				PUSH_DOUBLE(s, x++);
			}else if(hasType(TOP(s), CHAR)){
				char x = POP_CHAR(s);
				PUSH_CHAR(s, x++);
			}
		}
		else if (strcmp(token, "%") == 0)
		{
			if (hasType(profundidade(s,1), LONG) && hasType(profundidade(s, 2), LONG)){
				long x = POP_LONG(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y%x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), CHAR)){
				long x = POP_LONG(s);
				char y = POP_CHAR(s);
				long z = y%x;
				PUSH_LONG(s, z);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), CHAR)){
				char x = POP_CHAR(s);
				char y = POP_CHAR(s);
				long z = y%x;
				PUSH_LONG(s, z);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), LONG)){
				char x = POP_CHAR(s);
				long y = POP_LONG(s);
				long z = y%x;
				PUSH_LONG(s, z);
			}
		}
		else if (strcmp(token, "#") == 0)
		{
			if (hasType(profundidade(s,1), LONG) && hasType(profundidade(s, 2), LONG))
			{
				long x = POP_LONG(s);
				long y = POP_LONG(s);
				PUSH_DOUBLE(s, pow(y,x));
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), DOUBLE)){
				long x = POP_LONG(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, pow(y,x));
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), CHAR)){
				long x = POP_LONG(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, pow(y,x));
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), DOUBLE)){
				double x = POP_DOUBLE(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s,pow(y,x));
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), LONG)){
				double x = POP_DOUBLE(s);
				long y = POP_LONG(s);
				PUSH_DOUBLE(s, pow(y,x));
			}else if(hasType(profundidade(s,1), DOUBLE) && hasType(profundidade(s,2), CHAR)){
				double x = POP_DOUBLE(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, pow(y,x));
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), CHAR)){
				char x = POP_CHAR(s);
				char y = POP_CHAR(s);
				PUSH_DOUBLE(s, pow(y,x));
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), LONG)){
				char x = POP_CHAR(s);
				long y = POP_LONG(s);
				PUSH_DOUBLE(s, pow(y,x));
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), DOUBLE)){
				char x = POP_CHAR(s);
				double y = POP_DOUBLE(s);
				PUSH_DOUBLE(s, pow(y,x));
			}
		}
		else if (strcmp(token, "&") == 0)
		{
			if (hasType(profundidade(s,1), LONG) && hasType(profundidade(s, 2), LONG))
			{
				long x = POP_LONG(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y&x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), CHAR)){
				long x = POP_LONG(s);
				char y = POP_CHAR(s);
				PUSH_LONG(s, y&x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), CHAR)){
				char x = POP_CHAR(s);
				char y = POP_CHAR(s);
				PUSH_LONG(s, y&x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), LONG)){
				char x = POP_CHAR(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y&x);
			}
		}
		else if (strcmp(token, "|") == 0)
		{
			if (hasType(profundidade(s,1), LONG) && hasType(profundidade(s, 2), LONG))
			{
				long x = POP_LONG(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y|x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), CHAR)){
				long x = POP_LONG(s);
				char y = POP_CHAR(s);
				PUSH_LONG(s, y|x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), CHAR)){
				char x = POP_CHAR(s);
				char y = POP_CHAR(s);
				PUSH_LONG(s, y|x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), LONG)){
				char x = POP_CHAR(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y|x);
			}
		}
		else if (strcmp(token, "^") == 0)
		{
			if (hasType(profundidade(s,1), LONG) && hasType(profundidade(s, 2), LONG))
			{
				long x = POP_LONG(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y^x);
			}else if(hasType(profundidade(s,1), LONG) && hasType(profundidade(s,2), CHAR)){
				long x = POP_LONG(s);
				char y = POP_CHAR(s);
				PUSH_LONG(s, y^x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), CHAR)){
				char x = POP_CHAR(s);
				char y = POP_CHAR(s);
				PUSH_LONG(s, y^x);
			}else if(hasType(profundidade(s,1), CHAR) && hasType(profundidade(s,2), LONG)){
				char x = POP_CHAR(s);
				long y = POP_LONG(s);
				PUSH_LONG(s, y^x);
			}
		}
		else if (strcmp(token, "~") == 0)
		{
			if(hasType(TOP(s), LONG)){
				long x = POP_LONG(s);
				PUSH_LONG(s, ~x);
			}else if(hasType(TOP(s), CHAR)){
				char x = POP_CHAR(s);
				PUSH_CHAR(s, ~x);
			}
		}/*
		else if (strcmp(token, "l") == 0)
		{
			char str[50];
			fgets(str, sizeof(str), stdin);
			PUSH_STRING(s, str);
		}*/
		else if (strcmp(token, "i") == 0)
		{
			if(hasType(TOP(s), DOUBLE)){
				double x = POP_DOUBLE(s);
				long y = x;
				PUSH_LONG(s, y);
			}else if(hasType(TOP(s), CHAR)){
				char x = POP_CHAR(s);
				long y = x;
				PUSH_LONG(s, y);
			}
		}
		else if (strcmp(token, "f") == 0)
		{
			if(hasType(TOP(s), LONG)){
				long x = POP_LONG(s);
				double y = x;
				PUSH_DOUBLE(s, y);
			}else if(hasType(TOP(s), CHAR)){
				char x = POP_CHAR(s);
				double y = x;
				PUSH_DOUBLE(s, y);
			}
		}
		else if (strcmp(token, "c") == 0)
		{
			if(hasType(TOP(s), LONG)){
				long x = POP_LONG(s);
				char y = x;
				PUSH_CHAR(s, y);
			}else if(hasType(TOP(s), DOUBLE)){
				double x = POP_DOUBLE(s);
				char y = x;
				PUSH_CHAR(s, y);
			}
		}/*
		else if (strcmp(token, "s") == 0)
		{
			// fazer depois
		}*/
		else if(strcmp(token, "_") == 0)
		{
			DATA x = TOP(s);
			POP(s);
			PUSH(s, x);
			PUSH(s, x);
		}
		else if (strcmp(token, ";") == 0)
		{
			POP(s);
		}
		else if (strcmp(token, "\\") == 0)
		{
			DATA x = TOP(s);
			POP(s);
			DATA y = TOP(s);
			POP(s);
			PUSH(s, x);
			PUSH(s, y);
		}
		else if (strcmp(token, "@") == 0)
		{
			DATA x = TOP(s);
			POP(s);
			DATA y = TOP(s);
			POP(s);
			DATA z = TOP(s);
			POP(s);
			PUSH(s, y);
			PUSH(s, x);
			PUSH(s, z);
		}
		else if (strcmp(token, "$") == 0)
		{
			long x = POP_LONG(s);
			PUSH(s, profundidade(s, x+1));
		}
	}
	printStack(s);
}
