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
			if (hasType(TOP(s), LONG))
			{
				long x = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}

			if (hasType(TOP(s), LONG))
			{
				long y = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double y = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}

			if (hasType(y + x, LONG))
			{
				PUSH_LONG(s, y + x);
			}
			else
			{
				PUSH_DOUBLE(s, y + x);
			}
		}
		else if (strcmp(token, "-") == 0)
		{
			if (hasType(TOP(s), LONG))
			{
				long x = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}
			if (hasType(TOP(s), LONG))
			{
				long y = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double y = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}
			if (hasType(y - x, LONG))
			{
				PUSH_LONG(s, y - x);
			}
			else
			{
				PUSH_DOUBLE(s, y - x);
			}
		}
		else if (strcmp(token, "*") == 0)
		{
			if (hasType(TOP(s), LONG))
			{
				long x = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}

			if (hasType(TOP(s), LONG))
			{
				long y = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double y = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}

			if (hasType(x * y, LONG))
			{
				PUSH_LONG(s, x * y);
			}
			else
			{
				PUSH_DOUBLE(s, x * y);
			}
		}
		else if (strcmp(token, "/") == 0)
		{
			if (hasType(TOP(s), LONG))
			{
				long x = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}

			if (hasType(TOP(s), LONG))
			{
				long y = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double y = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}

			if (hasType(y / x, LONG))
			{
				PUSH_LONG(s, y / x);
			}
			else
			{
				PUSH_DOUBLE(s, y / x);
			}
		}
		else if (strcmp(token, "(") == 0)
		{
			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long x = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char x = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}

			if (hasType(x--, LONG))
			{
				PUSH_LONG(s, x--);
			}
			else if (hasType(x--, CHAR))
			{
				PUSH_CHAR(s, x--);
			}
			else
			{
				PUSH_DOUBLE(s, x--);
			}
		}
		else if (strcmp(token, ")") == 0)
		{
			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long x = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char x = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}

			if (hasType(x++, LONG))
			{
				PUSH_LONG(s, x++);
			}
			else if (hasType(x++, CHAR))
			{
				PUSH_CHAR(s, x++);
			}
			else
			{
				PUSH_DOUBLE(s, x++);
			}
		}
		else if (strcmp(token, "%") == 0)
		{
			if (hasType(TOP(s), LONG))
			{
				long x = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}

			if (hasType(TOP(s), LONG))
			{
				long y = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double y = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}

			if (hasType(y % x, LONG))
			{
				PUSH_LONG(s, y % x);
			}
			else
			{
				PUSH_DOUBLE(s, y % x);
			}
		}
		else if (strcmp(token, "#") == 0)
		{
			if (hasType(TOP(s), LONG))
			{
				long x = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}
			if (hasType(TOP(s), LONG))
			{
				long y = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double y = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Operação inválida\n");
				break;
			}
			PUSH_DOUBLE(s, pow(x, y));
		}
		else if (strcmp(token, "&") == 0)
		{
			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long x = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char x = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}

			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long y = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char y = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double y = TOP_DOUBLE(s);
				POP(s);
			}
			PUSH_LONG(s, x & y);
		}
		else if (strcmp(token, "|") == 0)
		{
			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long x = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char x = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}

			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long y = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char y = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double y = TOP_DOUBLE(s);
				POP(s);
			}
			PUSH_LONG(s, x | y);
		}
		else if (strcmp(token, "^") == 0)
		{
			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long x = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char x = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}

			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long y = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char y = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double y = TOP_DOUBLE(s);
				POP(s);
			}
			PUSH_LONG(s, x ^ y);
		}
		else if (strcmp(token, "~") == 0)
		{
			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long x = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char x = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}
			PUSH_LONG(s, ~x);
		}
		else if (strcmp(token, "l") == 0)
		{
			char p[50];
			fgets(p, 50, stdin);
			PUSH_STRING(s, p);
		}
		else if (strcmp(token, "i") == 0)
		{
			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long x = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char x = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}
			long y = x;
			PUSH_LONG(s, y);
		}
		else if (strcmp(token, "f") == 0)
		{
			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long x = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char x = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}
			double y = x;
			PUSH_LONG(s, y);
		}
		else if (strcmp(token, "c") == 0)
		{
			if (hasType(TOP(s), INTEGER))
			{
				if (hasType(TOP(s), LONG))
				{
					long x = TOP_LONG(s);
					POP(s);
				}
				else
				{
					char x = TOP_CHAR(s);
					POP(s);
				}
			}
			else
			{
				double x = TOP_DOUBLE(s);
				POP(s);
			}
			char y = x;
			PUSH_LONG(s, y);
		}
		else if (strcmp(token, "s") == 0)
		{
			// fazer depois
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
		}/*
		else if (strcmp(token, "$") == 0)
		{
			if (hasType(TOP(s), LONG))
			{
				long n = TOP_LONG(s);
				POP(s);
			}
			else if (hasType(TOP(s), DOUBLE))
			{
				double n = TOP_DOUBLE(s);
				POP(s);
			}
			else
			{
				printf("Tipo inválido\n");
				break;
			}

			while (n > 0)
			{
			}
		}*/
	}
	printStack(s);
}
