#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "parser.h"

int main(){

	char input[10000];

	assert(fgets(input, 10000, stdin) != NULL);
	assert(input[strlen(input) - 1] == '\n');

	parse(input);

	return 0;
}