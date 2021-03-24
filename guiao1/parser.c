#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

void parse(char *input){

	char *delims = "\t\n";

	for(char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims)){
		char *sobra;
		long a = strtol(token, &sobra, 10);
		if(strlen(sobra) == 0){
			printf("INT: %ld\n", a);
		}else{
			double b = strtod(token, &sobra);
			if(strlen(sobra) == 0){
				printf("DOUBLE: %lf\n", b);
			}else{
				printf("%s\n", token);
			}
		}
	}
}

