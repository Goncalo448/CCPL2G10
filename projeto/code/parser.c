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

int verifica_token(char const *token){

	if(strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0){
		return 1;
	}else if(strcmp(token, "(") == 0 || strcmp(token, ")") == 0 || strcmp(token, "%") == 0 || strcmp(token, "#") == 0){
		return 2;
	}else if(strcmp(token, "&") == 0 || strcmp(token, "|") == 0 || strcmp(token, "^") == 0 || strcmp(token, "~") == 0){
		return 3;
	}else if(strcmp(token, "A") == 0 || strcmp(token, "B") == 0 || strcmp(token, "C") == 0 || strcmp(token, "D") == 0 || strcmp(token, "E") == 0 || strcmp(token, "F") == 0 || strcmp(token, "G") == 0 || strcmp(token, "H") == 0 || strcmp(token, "I") == 0 || strcmp(token, "J") == 0 || strcmp(token, "K") == 0 || strcmp(token, "L") == 0 || strcmp(token, "M") == 0 || strcmp(token, "N") == 0 || strcmp(token, "O") == 0 || strcmp(token, "P") == 0 || strcmp(token, "Q") == 0 || strcmp(token, "R") == 0 || strcmp(token, "S") == 0 || strcmp(token, "T") == 0 || strcmp(token, "U") == 0 || strcmp(token, "V") == 0 || strcmp(token, "W") == 0 || strcmp(token, "X") == 0 || strcmp(token, "Y") == 0 || strcmp(token, "Z") == 0 || strcmp(token, ":A") == 0 || strcmp(token, ":B") == 0 || strcmp(token, ":C") == 0 || strcmp(token, ":D") == 0 || strcmp(token, ":E") == 0 || strcmp(token, ":F") == 0 || strcmp(token, ":G") == 0 || strcmp(token, ":H") == 0 || strcmp(token, ":I") == 0 || strcmp(token, ":J") == 0 || strcmp(token, ":K") == 0 || strcmp(token, ":L") == 0 || strcmp(token, ":M") == 0 || strcmp(token, ":N") == 0 || strcmp(token, ":O") == 0 || strcmp(token, ":P") == 0 || strcmp(token, ":Q") == 0 || strcmp(token, ":R") == 0 || strcmp(token, ":S") == 0 || strcmp(token, ":T") == 0 || strcmp(token, ":U") == 0 || strcmp(token, ":V") == 0 || strcmp(token, ":W") == 0 || strcmp(token, ":X") == 0 || strcmp(token, ":Y") == 0 || strcmp(token, ":Z") == 0){
		return 4;
	}else if(strcmp(token, "_") == 0 || strcmp(token, ";") == 0 || strcmp(token, "\\") == 0 || strcmp(token, "@") == 0 || strcmp(token, "$") == 0){
		return 5;
	}

	return 0;
}


void parse(char *input)
{

	char *delims = " \t\n";
	double a;
	STACK *s = createStack();
	STACK *letras = create_letter_array();

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
		
		int token_type = verifica_token(token);
		if (token_type == 1)
		{
			ARITMETICA(s, token);
		}
		else if (token_type == 2)
		{
			MAT(s, token);
		}
		else if (token_type == 3)
		{
			BITWISE(s, token);
		}
  		else if (strcmp(token, "l") == 0)
		{
			char str[10000];
			assert(fgets(str, sizeof(str), stdin) != NULL);
			PUSH_STRING(s, strdup(str));
		}
		else if (strcmp(token, "i") == 0 || strcmp(token, "f") == 0 || strcmp(token, "c") == 0)
		{
			CONVERSAO(s, token);
		}
		else if(token_type == 5)
		{
			COMANDOS_STACK(s, token);
		}
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
				PUSH_TYPE(s, max(vx,vy), DOUBLE);
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
		}else if(token_type == 4){
			VARIAVEIS(s, letras, token);
		}
	}
	printStack(s);
}
