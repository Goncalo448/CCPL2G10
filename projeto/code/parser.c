#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"
#include "stack.h"

void parse(char *input){

	char *delims = "\t\n";
	long a;
	STACK s = createStack();

	for(char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims)){
		char *resto;
		a = strtol(token, &resto, 10);
		if(strlen(resto) == 0){
			s = PUSH(s, a);
		}else if(strcmp(token, "+")){
			long x = TOP(s);
			s = POP(s);
			long y = TOP(s);
			s = POP(s);
			s = PUSH(s, x+y);
		}else if(strcmp(token, "-")){
			long x = TOP(s);
			s = POP(s);
			long y = TOP(s);
			s = POP(s);
 			s = PUSH(s, x-y);
		}else if(strcmp(token, "*")){
			long x = TOP(s);
			s = POP(s);
			long y = TOP(s);
			s = POP(s);
			s = PUSH(s, x*y);
		}else if(strcmp(token, "/")){
			long x = TOP(s);
			s = POP(s);
			long y = TOP(s);
			s = POP(s);
			s = PUSH(s, x/y);
		}else if(strcmp(token, "(")){
			long x = TOP(s);
			s = POP(s);
			s = PUSH(s, x--);
		}else if(strcmp(token, ")")){
			long x = TOP(s);
			s = POP(s);
			s = PUSH(s, x++);
		}else if(strcmp(token, "%")){
			long x = TOP(s);
			s = POP(s);
			long y = TOP(s);
			s = POP(s);
			s = PUSH(s, x%y);
		}else if(strcmp(token, "#")){
			long x = TOP(s);
			s = POP(s);
			long y = TOP(s);
			s = POP(s);
			s = PUSH(s, pow(x,y));
		}/*else if(strcmp(token, "&")){
			PUSH(s, &);
		}else if(strcmp(token, "|")){

		}else if(strcmp(token, "^")){

		}else if(strcmp(token, "~")){

		}*/
	}

	printStack(s);
}

