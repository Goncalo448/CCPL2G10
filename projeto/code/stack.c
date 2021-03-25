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


STACK PUSH(STACK s, long n){
	s.array[s.num] = n;
	s.num++;
	return s;
}

STACK POP(STACK s){
	s.num--;
	return s;
}


long TOP(STACK s){
	long x;
	x = s.array[s.num];
	return x;
}


void printStack(STACK s){

	int i;

	for(i = 0; i < s.num; i++){
		printf("%ld", s.array[i]);
	}
	printf("\n");
}


