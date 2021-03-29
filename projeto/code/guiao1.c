/**
 * @file Ficheiro principal
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "parser.h"
#include "stack.h"

/**
 * \brief Esta é a função principal do programa.
 *
 * Descrição detalhada:
 * Aplica a função parse ao input.
 *
 * @returns O valor 0
 */

int main(){

	char input[10000];

	assert(fgets(input, 10000, stdin) != NULL);
	assert(input[strlen(input) - 1] == '\n');

	parse(input);

	return 0;
}

//gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O *.c -lm