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

STACK createStack(){
	STACK s;
	s.num = 0;
	return s;
}

/**
 * \brief Esta função pega no valor que está no topo da STACK.
 */

long TOP(STACK s){
	long x;
	x = s.array[s.num - 1];
	return x;
}

/**
 * \brief Esta função imprime a STACK.
 */
void printStack(STACK s){
	for(int i = 0; i < s.num; i++){
		printf("%ld", s.array[i]);
	}
	printf("\n");
}


