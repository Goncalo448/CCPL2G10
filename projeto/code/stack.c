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
 
STACK *createStack()
{
	STACK *s = (STACK *)malloc(sizeof(STACK));
	assert(s != NULL);
	s->num = 0;
	s->size = 50;
	s->array = (DATA *)calloc(s->size, sizeof(DATA));
	return s;
}


int hasType(DATA x, int mask)
{
	return (x.type & mask) != 0;
}


void PUSH(STACK *s, DATA x)
{
	if (s->size == s->num)
	{
		s->size += 50;
		s->array = (DATA *)realloc(s->array, s->size * sizeof(DATA));
	}
	s->array[s->num] = x;
	s->num += 1;
}

DATA POP(STACK *s){
	s->num--;
	return s->array[s->num];
}

/**
 * \brief Esta função pega no valor que está no topo da STACK.
 */

DATA TOP(STACK *s)
{
	return s->array[s->num-1];
}

DATA profundidade(STACK *s, int x){
	return s->array[s->num-x];
}


int isEmpty(STACK *s){

	return s->num == 0;
}

/**
 * \brief Esta função imprime a STACK.
 */
void printStack(STACK *s)
{

	for (int i = 0; i < s->num; i++)
	{
		DATA x = s->array[i];
		TYPE tipo = x.type;
		switch (tipo)
		{
		case LONG:
			printf(" ""%ld", x.LONG);
			break;
		case DOUBLE:
			printf(" ""%g", x.DOUBLE);
			break;
		case CHAR:
			printf(" ""%c", x.CHAR);
			break;
		case STRING:
			printf(" ""%s", x.STRING);
			break;
		}
	}
	printf("\n");
}


#define STACK_OPERATION(_type, _name)        \
	void PUSH_##_name(STACK *s, _type val){  \
		DATA elemento;                       \
		elemento.type = _name;               \
		elemento._name = val;                \
		PUSH(s, elemento);                   \
	}                                        \
	_type POP_##_name(STACK *s){             \
		DATA elemento = POP(s);              \
		assert(elemento.type == _name);      \
		return elemento._name;               \
	}


STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
