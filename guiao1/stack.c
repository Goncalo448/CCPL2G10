#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define limit 10240


typedef struct{
	long array[limit];
	int num;
}STACK;


STACK createStack(){
	STACK s;
	s.num = 0;
	return s;
}


STACK PUSH(STACK s, int n){
	s.num += 1;
	s.array[s.num] = n;
	return s;
}

STACK POP(STACK s){
	s.num -= 1;
	s.array[s.num];
	return s;
}


void printStack(STACK s){

	int i;

	printf("Stack: ");
	for(i = 1; i <= s.num; i++){
		printf("%ld ", s.array[i]);
	}
	printf("\n");
}


int main(){

	STACK a = createStack();

	PUSH(a, 8l);
	PUSH(a, 92l);
	PUSH(a, 45l);

	printStack(a);

	return 0;
}
