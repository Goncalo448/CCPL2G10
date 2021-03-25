#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#define limit 10240


STACK createStack(){
	STACK s;
	s.num = 0;
	return s;
}



long TOP(STACK s){
	long x;
	x = s.array[s.num - 1];
	return x;
}


void printStack(STACK s){
	for(int i = 0; i < s.num; i++){
		printf("%ld", s.array[i]);
	}
	printf("\n");
}


