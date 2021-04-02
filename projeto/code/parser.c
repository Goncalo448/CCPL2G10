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
			PUSH(s, a);
		}
		else if (strcmp(token, "+") == 0)
		{
			if(hasType(TOP(s), NUMBER)){
				if(hasType(TOP(s), INTEGER)){
					if(hasType(TOP(s), LONG)){
						long x = TOP(s);
						POP(s);
					}else{
						char x = TOP(s);
						POP(s);
					}
				}else{
					double x = TOP(s);
					POP(s);
				}
			}else{
				break;
			}
			if(hasType(TOP(s), NUMBER)){
				if(hasType(TOP(s), INTEGER)){
					if(hasType(TOP(s), LONG)){
						long y = TOP(s);
						POP(s);
					}else{
						char y = TOP(s);
						POP(s);
					}
				}else{
					double y = TOP(s);
					POP(s);
				}
			}else{
				break;
			}
			if(hasType(x+y, NUMBER)){
				if(hasType(x+y, INTEGER)){
					if(hasType(x+y, LONG)){
						PUSH_LONG(s, x+y);
					}else{
						PUSH_CHAR(s, x+y);
					}
				}else{
					PUSH_DOUBLE(s, x+y);
				}
			}else{
				break;
			}
		}
		else if (strcmp(token, "-") == 0)
		{
			DATA x = TOP(s);
			POP(s);
			DATA y = TOP(s);
			POP(s);
			if(hasType(x+y, LONG)){
				PUSH_LONG(s, x+y);
			}else if(hasType(z, DOUBLE)){
				PUSH_DOUBLE(s, x+y);
			}else{
				printf("Invalid operation\n");
			}
		}
		else if (strcmp(token, "*") == 0)
		{
			DATA x = TOP(s);
			POP(s);
			DATA y = TOP(s);
			POP(s);
			PUSH(s, y * x);
		}
		else if (strcmp(token, "/") == 0)
		{
			DATA x = TOP(s);
			POP(s);
			DATA y = TOP(s);
			POP(s);
			PUSH(s, y / x);
		}
		else if (strcmp(token, "(") == 0)
		{
			DATA x = TOP(s);
			x--;
			POP(s);
			PUSH(s, x);
		}
		else if (strcmp(token, ")") == 0)
		{
			DATA x = TOP(s);
			x++;
			POP(s);
			PUSH(s, x);
		}
		else if (strcmp(token, '%') == 0)
		{
			DATA x = TOP(s);
			POP(s);
			DATA y = TOP(s);
			POP(s);
			PUSH(s, y % x);
		}
		else if (strcmp(token, "#") == 0)
		{
			double x.DOUBLE = TOP(s);
			POP(s);
			double a = (double)x;
			DATA y = TOP(s);
			POP(s);
			double b = (double)y;
			double k = pow(a, b);
			x = (DATA)k;
			PUSH(s, x);
		}
		else if (strcmp(token, "&") == 0)
		{
			DATA x = TOP(s);
			POP(s);
			DATA y = TOP(s);
			POP(s);
			PUSH(s, y & x);
		}
		else if (strcmp(token, "|") == 0)
		{
			DATA x = TOP(s);
			POP(s);
			DATA y = TOP(s);
			POP(s);
			PUSH(s, y | x);
		}
		else if (strcmp(token, "^") == 0)
		{
			DATA x = TOP(s);
			POP(s);
			DATA y = TOP(s);
			POP(s);
			PUSH(s, y ^ x);
		}
		else if (strcmp(token, "~") == 0)
		{
			DATA x = TOP(s);
			POP(s);
			PUSH(s, ~x);
		}
		else if (strcmp(token, "l") == 0)
		{
			char p[50];
			fgets(p, 50, stdin);
			PUSH(s, p);
		}
		else if (strcmp(token, "i") == 0)
		{
			DATA k = TOP(s);
			POP(s);
			k = (int)k;
			PUSH(s, k);
		}
		else if (strcmp(token, "f") == 0)
		{
			DATA k = TOP(s);
			POP(s);
			k = (float)k;
			PUSH(s, k);
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
			DATA n = TOP(s); // n é a posição que vamos buscar
			POP(s);
			n = (int)n;
			while (n-1 > 0){
				POP(s);
				n--;
			}

		}
	}
	printStack(s);
}
