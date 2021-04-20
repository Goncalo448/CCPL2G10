/**
 * @file Função que diz respeito ao parser
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include "parser.h"
#include "stack.h"


/**
 * \brief Esta função faz o parse do input.
 *
 * @param line O input que foi lido ao qual vai ser aplicado o parse.
 * 
 * 
 */


#define max(x,y)	((x) > (y)) ? (x) : (y)

#define min(x,y)    ((x) < (y)) ? (x) : (y)


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
			DATA x = POP(s);
			double vx = get_double(x);
			PUSH_TYPE(s, vx, DOUBLE);
		}
		else if (strcmp(token, "c") == 0)
		{
			DATA x = POP(s);
			char vx = get_double(x);
			PUSH_TYPE(s, vx, CHAR);
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
		}/*
		else if(strcmp(token, "0") == 0)
		{

		}*/
		else if(strcmp(token, "=") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			double vx = get_double(x);
			double vy = get_double(y);
			if(vx == vy){
				PUSH_TYPE(s, 1, LONG);
			}else{
				PUSH_TYPE(s, 0, LONG);
			}
		}
		else if(strcmp(token, "<") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			double vx = get_double(x);
			double vy = get_double(y);
			if(vy < vx){
				PUSH_TYPE(s, 1, LONG);
			}else{
				PUSH_TYPE(s, 0, LONG);
			}
		}
		else if(strcmp(token, ">") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			double vx = get_double(x);
			double vy = get_double(y);
			if(vy > vx){
				PUSH_TYPE(s, 1, LONG);
			}else{
				PUSH_TYPE(s, 0, LONG);
			}
		}
		else if(strcmp(token, "!") == 0)
		{
			DATA x = POP(s);
			double vx = get_double(x);
			if(vx == 0){
				PUSH_TYPE(s, 1, LONG);
			}else{
				PUSH_TYPE(s, 0, LONG);
			}
		}
		else if(strcmp(token, "e&") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			double vx = get_double(x);
			double vy = get_double(y);
			if(vx && vy){
				PUSH_LONG(s, max(vx,vy));
			}else{
				PUSH_TYPE(s, 0, LONG);
			}
		}
		else if(strcmp(token, "e|") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			double vx = get_double(x);
			double vy = get_double(y);
			if(vx == 0 && vy == 0){
				PUSH_TYPE(s, 0, LONG);
			}else if(vx == 0){
				PUSH(s, y);
			}else if(vy == 0){
				PUSH(s, x);
			}else{
				TYPE ret_t = min(x.type, y.type);
				PUSH_TYPE(s, min(vx,vy), ret_t);
			}
		}
		else if(strcmp(token, "e<") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			double vx = get_double(x);
			double vy = get_double(y);
			if(vy < vx){
				PUSH_TYPE(s, vy, DOUBLE);
			}else{
				PUSH_TYPE(s, vx, DOUBLE);
			}
		}
		else if(strcmp(token, "e>") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			double vx = get_double(x);
			double vy = get_double(y);
			if(vy > vx){
				PUSH_TYPE(s, vy, DOUBLE);
			}else{
				PUSH_TYPE(s, vx, DOUBLE);
			}
		}
		else if(strcmp(token, "?") == 0)
		{
			DATA x = POP(s);
			DATA y = POP(s);
			DATA z = POP(s);
			double vz = get_double(z);
			if(vz){
				PUSH(s, y);
			}else{
				PUSH(s, x);
			}
		}
		else if(strcmp(token, "A") == 0)
		{
			PUSH_TYPE(s, 10, LONG);
		}
		else if(strcmp(token, "B") == 0)
		{
			PUSH_TYPE(s, 11, LONG);
		}
		else if(strcmp(token, "C") == 0)
		{
			PUSH_TYPE(s, 12, LONG);
		}
		else if(strcmp(token, "D") == 0)
		{
			PUSH_TYPE(s, 13, LONG);
		}
		else if(strcmp(token, "E") == 0)
		{
			PUSH_TYPE(s, 14, LONG);
		}
		else if(strcmp(token, "F") == 0)
		{
			PUSH_TYPE(s, 15, LONG);
		}
		else if(strcmp(token, "N") == 0)
		{
			PUSH_STRING(s, "\n");
		}
		else if(strcmp(token, "S") == 0)
		{
			PUSH_STRING(s, " ");
		}
		else if(strcmp(token, "X") == 0)
		{
			PUSH_TYPE(s, 0, LONG);
		}
		else if(strcmp(token, "Y") == 0)
		{
			PUSH_TYPE(s, 1, LONG);
		}
		else if(strcmp(token, "Z") == 0)
		{
			PUSH_TYPE(s, 2, LONG);
		}
	}
	printStack(s);
}
