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
 * \brief Esta macro calcula o maior entre dois valores
 */

#define max(x,y)	((x) > (y)) ? (x) : (y)

/**
 * \brief Esta macro calcula o menor entre dois valores
 */

#define min(x,y)    ((x) < (y)) ? (x) : (y)

/**
 * \brief Esta função retorna um inteiro que indica qual o tipo de operações o programa vai executar
 * 
 * @returns O valor que indica qual o tipo de operações
 */

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
	}else if(strcmp(token, "=") == 0 || strcmp(token, "<") == 0 || strcmp(token, ">") == 0 || strcmp(token, "!") == 0 || strcmp(token, "e&") == 0 || strcmp(token, "e|") == 0 || strcmp(token, "e<") == 0 || strcmp(token, "e>") == 0 || strcmp(token, "?") == 0){
		return 6;
	}

	return 0;
}

/**
 * \brief Esta função faz o parse do input.
 *
 * @param line O input que foi lido ao qual vai ser aplicado o parse.
 */

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
		else if(token_type == 6)
		{
			LOGICA(s, token);
		}
		else if(token_type == 4)
		{
			VARIAVEIS(s, letras, token);
		}
	}
	printStack(s);
}
