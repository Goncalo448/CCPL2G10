#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"
#include "stack.h"

void parse(char *input){

	char *delims = " \t\n";
	long a;
	STACK s = createStack();

	for(char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims)){
		char *resto;
		a = strtol(token, &resto, 10);
		if(strlen(resto) == 0){
			PUSH(s, a);
		}else if(strcmp(token, "+") == 0){
			long x = TOP(s);
			POP(s);
			long y = TOP(s);
			POP(s);
			PUSH(s, y+x);
		}else if(strcmp(token, "-") == 0){
			long x = TOP(s);
			POP(s);
			long y = TOP(s);
			POP(s);
 			PUSH(s, y-x);
		}else if(strcmp(token, "*") == 0){
			long x = TOP(s);
			POP(s);
			long y = TOP(s);
			POP(s);
			PUSH(s, y*x);
		}else if(strcmp(token, "/") == 0){
			long x = TOP(s);
			POP(s);
			long y = TOP(s);
			POP(s);
			PUSH(s, y/x);
		}else if(strcmp(token, "(") == 0){
			long x = TOP(s);
			x = x - 1;
			POP(s);
			PUSH(s, x);
		}else if(strcmp(token, ")" == 0)){
			long x = TOP(s);
			POP(s);
			PUSH(s, x++);
		}else if(strcmp(token, "%") == 0){
			long x = TOP(s);
			POP(s);
			long y = TOP(s);
			POP(s);
			PUSH(s, y%x);
		}else if(strcmp(token, "#") == 0){
			long x = TOP(s);
			POP(s);
			long y = TOP(s);
			POP(s);
			PUSH(s, pow(y,x));
		}else if(strcmp(token, "&") == 0){
			long x = TOP(s);
			POP(s);
			long y = TOP(s);
			POP(s);
			PUSH(s, y&x);
		}else if(strcmp(token, "|") == 0){
			long x = TOP(s);
			POP(s);
			long y = TOP(s);
			POP(s);
			PUSH(s, y|x);
		}else if(strcmp(token, "^") == 0){
			long x = TOP(s);
			POP(s);
			long y = TOP(s);
			POP(s);
			PUSH(s, y^x);
		}else if(strcmp(token, "~") == 0){
			long x = TOP(s);
			POP(s);
			PUSH(s, ~x);
		}
	}

	printStack(s);
}

