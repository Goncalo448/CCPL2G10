/**
 * @file Ficheiro que contém a STACK
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
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
	s->num++;
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


#define max(x,y)	((x) > (y)) ? (x) : (y)


void SOMA(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	double vx = get_double(x);
	double vy = get_double(y);
	PUSH_TYPE(s, vy+vx, ret_t);
}


void SUBTRACAO(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	double vx = get_double(x);
	double vy = get_double(y);
	PUSH_TYPE(s, vy-vx, ret_t);
}


void MULTIPLICACAO(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	double vx = get_double(x);
	double vy = get_double(y);
	PUSH_TYPE(s, vy*vx, ret_t);
}


void DIVISAO(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	double vx = get_double(x);
	double vy = get_double(y);
	PUSH_TYPE(s, vy/vx, ret_t);
}


void ARITMETICA(STACK *s, const char *token){
	if(strcmp(token, "+") == 0){
		SOMA(s);
	}else if(strcmp(token, "-") == 0){
		SUBTRACAO(s);
	}else if(strcmp(token, "*") == 0){
		MULTIPLICACAO(s);
	}else if(strcmp(token, "/") == 0){
		DIVISAO(s);
	}
}


void DECREMENT(STACK *s){
	DATA x = POP(s);
	TYPE ret_t = x.type;
	double vx = get_double(x);
	PUSH_TYPE(s, vx-1, ret_t);
}

void INCREMENT(STACK *s){
	DATA x = POP(s);
	TYPE ret_t = x.type;
	double vx = get_double(x);
	PUSH_TYPE(s, vx+1, ret_t);
}

void MODULO(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	long vx = get_double(x);
	long vy = get_double(y);
	PUSH_TYPE(s, vy%vx, ret_t);
}

void EXPOENTE(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	double vx = get_double(x);
	double vy = get_double(y);
	PUSH_TYPE(s, pow(vy, vx), DOUBLE);
}

void MAT(STACK *s, const char *token){
	if(strcmp(token, "(") == 0){
		DECREMENT(s);
	}else if(strcmp(token, ")") == 0){
		INCREMENT(s);
	}else if(strcmp(token, "%") == 0){
		MODULO(s);
	}else if(strcmp(token, "#") == 0){
		EXPOENTE(s);
	}
}

void AND(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	long vx = get_double(x);
	long vy = get_double(y);
	PUSH_TYPE(s, vx&vy, ret_t);
}

void OR(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	long vx = get_double(x);
	long vy = get_double(y);
	PUSH_TYPE(s, vx|vy, ret_t);
}

void XOR(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	long vx = get_double(x);
	long vy = get_double(y);
	PUSH_TYPE(s, vx^vy, ret_t);
}

void NOT(STACK *s){
	DATA x = POP(s);
	TYPE ret_t = x.type;
	long vx = get_double(x);
	PUSH_TYPE(s, ~vx, ret_t);
}

void BITWISE(STACK *s, const char *token){
	if(strcmp(token, "&")==0){
		AND(s);
	} else if(strcmp(token, "|")==0){
		OR(s);
	} else if(strcmp(token, "^")==0){
		XOR(s);
	} else if(strcmp(token, "~")==0){
		NOT(s);
	}
}

/**
 * \brief Esta função imprime a STACK.
 */
void printStack(STACK *s)
{
#define SEP ""
	for (int i = 0; i < s->num; i++)
	{
		DATA x = s->array[i];
		TYPE tipo = x.type;
		switch (tipo)
		{
		case LONG:
			printf(SEP"%ld", x.LONG);
			break;
		case DOUBLE:
			printf(SEP"%g", x.DOUBLE);
			break;
		case CHAR:
			printf(SEP"%c", x.CHAR);
			break;
		case STRING:
			printf(SEP"%s", x.STRING);
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


void PUSH_TYPE(STACK *s, double val, TYPE t){
	DATA elemento;
	elemento.type = t;
	switch(elemento.type){
		case LONG:
			elemento.LONG = val;
			break;
		case DOUBLE:
			elemento.DOUBLE = val;
			break;
		case CHAR: 
			elemento.CHAR = val;
			break;
		default:
			assert(0 && "tou a tentar fazer push de double para algo que não é um numero");
			break;
	}
	PUSH(s, elemento);
}

double get_double(DATA elemento){
	switch(elemento.type){
		case LONG:
			return elemento.LONG;
			break;
		case DOUBLE:
			return elemento.DOUBLE;
			break;
		case CHAR: 
			return elemento.CHAR;
			break;
		case STRING:
			return atof(elemento.STRING);
		default:
			assert(0 && "tou a tentar converter um DATA noutra coisa qualquer");
			break;
	}
}


STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
