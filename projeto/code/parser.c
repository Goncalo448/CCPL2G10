/**
 * @file Função que diz respeito ao parser
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "parser.h"
#include "stack.h"


#define max(x,y)	((x) > (y)) ? (x) : (y) 


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
	double a;
	STACK *s = createStack();

	for (char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims))
	{
		char *resto;
		a = strtol(token, &resto, 10);
		if (strlen(resto) == 0)
		{
			PUSH_LONG(s, a);
			continue;
		}
		a = strtod(token, &resto);
		if (strlen(resto) == 0)
		{
			PUSH_DOUBLE(s, a);
			continue;
		}
		if (strcmp(token, "+") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			TYPE ret_t = max(x.type, y.type);
			double vx = get_double(x);
			double vy = get_double(y);
			PUSH_TYPE(s, vy+vx, ret_t);
		}
		else if (strcmp(token, "-") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			TYPE ret_t = max(x.type, y.type);
			double vx = get_double(x);
			double vy = get_double(y);
			PUSH_TYPE(s, vy-vx, ret_t);
		}
		else if (strcmp(token, "*") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			TYPE ret_t = max(x.type, y.type);
			double vx = get_double(x);
			double vy = get_double(y);
			PUSH_TYPE(s, vy*vx, ret_t);
		}
		else if (strcmp(token, "/") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			TYPE ret_t = max(x.type, y.type);
			double vx = get_double(x);
			double vy = get_double(y);
			PUSH_TYPE(s, vy/vx, ret_t);
		}
		else if (strcmp(token, "(") == 0)
		{
			DATA x = POP(s);
			TYPE ret_t = x.type;
			double vx = get_double(x);
			PUSH_TYPE(s, vx-1, ret_t);
		}
		else if (strcmp(token, ")") == 0)
		{
			DATA x = POP(s);
			TYPE ret_t = x.type;
			double vx = get_double(x);
			PUSH_TYPE(s, vx+1, ret_t);
		}
		else if (strcmp(token, "%") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			TYPE ret_t = max(x.type, y.type);
			long vx = get_double(x);
			long vy = get_double(y);
			PUSH_TYPE(s, vy%vx, ret_t);
		}
		else if (strcmp(token, "#") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			double vx = get_double(x);
			double vy = get_double(y);
			PUSH_TYPE(s, pow(vy, vx), DOUBLE);
		}
		else if (strcmp(token, "&") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			TYPE ret_t = max(x.type, y.type);
			long vx = get_double(x);
			long vy = get_double(y);
			PUSH_TYPE(s, vx&vy, ret_t);
		}
		else if (strcmp(token, "|") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			TYPE ret_t = max(x.type, y.type);
			long vx = get_double(x);
			long vy = get_double(y);
			PUSH_TYPE(s, vx|vy, ret_t);
		}
		else if (strcmp(token, "^") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			TYPE ret_t = max(x.type, y.type);
			long vx = get_double(x);
			long vy = get_double(y);
			PUSH_TYPE(s, vx^vy, ret_t);
		}
		else if (strcmp(token, "~") == 0)
		{
			DATA x = POP(s);
			TYPE ret_t = x.type;
			long vx = get_double(x);
			PUSH_TYPE(s, ~vx, ret_t);
		}
		else if (strcmp(token, "l") == 0)
		{
			char str[10000];
			assert(fgets(str, sizeof(str), stdin) != NULL);
			PUSH_STRING(s, strdup(str));
		}
		else if (strcmp(token, "i") == 0)
		{
			DATA x = POP(s);
			long vx = get_double(x);
			PUSH_TYPE(s, vx, LONG);
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
		}
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
