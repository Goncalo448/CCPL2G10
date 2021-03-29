/**
 * @file Ficheiro que contém a STACK
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#define limit 10240

/**
 * \brief Esta função cria uma STACK.
 *
 * @returns Retorna uma STACK
 */

STACK *createStack(){
	STACK *s = (STACK *) malloc(sizeof(STACK));
	assert(s != NULL);
	s->num = 0;
	s->size = 50;
	s->array = (DATA *) calloc(s->size, sizeof(DATA));
	return s;
}


int hasType(DATA x, int mask){
	return (x.type & mask) != 0;
}


STACK PUSH(STACK *s, DATA x){
	if(s->size == s->num){
		s->size += 50;
		s->array = (DATA *) realloc(s->array, s->size * sizeof(DATA));
	}
	s->array[s->num] = x;
	s->num += 1;

	return s->array[s->num];
}


STACK POP(STACK *s){
	return s->array[s->num--];
}


/**
 * \brief Esta função pega no valor que está no topo da STACK.
 */

DATA TOP(STACK *s){
	return  s->array[s->num];
}

/**
 * \brief Esta função imprime a STACK.
 */
void printStack(STACK *s){
	
	for(int i; i < s->num; i++){
		DATA x = s->array[i];
		TYPE tipo = x.type;
		switch(tipo){
			case LONG:
				printf("%ld ", x.LONG);
				break;
			case DOUBLE:
				printf("%lf ", x.DOUBLE);
				break;
			case CHAR:
				printf("%c ", x.CHAR);
				break;
			case STRING:
				printf("%s ", x.STRING);
				break;
		}
	}
	printf("\n");
}


