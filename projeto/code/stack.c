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


void CONVERTE_INT(STACK *s){
	DATA x = POP(s);
	long vx = get_double(x);
	PUSH_TYPE(s, vx, LONG);
}

void CONVERTE_FLOAT(STACK *s){
	DATA x = POP(s);
	double vx = get_double(x);
	PUSH_TYPE(s, vx, DOUBLE);
}

void CONVERTE_CHAR(STACK *s){
	DATA x = POP(s);
	char vx = get_double(x);
	PUSH_TYPE(s, vx, CHAR);
}

void CONVERSAO(STACK *s, const char *token){
	if(strcmp(token, "i") == 0){
		CONVERTE_INT(s);
	}else if(strcmp(token, "f") == 0){
		CONVERTE_FLOAT(s);
	}else if(strcmp(token, "c") == 0){
		CONVERTE_CHAR(s);
	}
}


void PUSH_PROFUNDIDADE(STACK *s, int x, DATA y){
	s->num = x;
	s->array[s->num++] = y;
}


STACK *create_letter_array(){
	
	STACK *letras = (STACK *)malloc(sizeof(STACK));
	letras->num = 0;
	letras->size = 26;
	letras->array = (DATA *)calloc(letras->size, sizeof(DATA));

	PUSH_LONG(letras, 10);
	PUSH_LONG(letras, 11);
	PUSH_LONG(letras, 12);
	PUSH_LONG(letras, 13);
	PUSH_LONG(letras, 14);
	PUSH_LONG(letras, 15);

	letras->num = 13;
	double n = '\n';
	PUSH_TYPE(letras, n, CHAR);

	letras->num = 18;
	double s = ' ';
	PUSH_TYPE(letras, s, CHAR);

	letras->num = 23;
	double x = 0;
	PUSH_TYPE(letras, x, LONG);

	letras->num = 24;
	double y = 1;
	PUSH_TYPE(letras, y, LONG);

	letras->num = 25;
	double z = 2;
	PUSH_TYPE(letras, z, LONG);

	return letras;
}


void VARIAVEIS(STACK *s, STACK *letras, const char *token){

	if(strcmp(token, "A") == 0){
		DATA x = letras->array[0];
		PUSH(s, x);
	}else if(strcmp(token, "B") == 0){
		DATA x = letras->array[1];
		PUSH(s, x);
	}else if(strcmp(token, "C") == 0){
		DATA x = letras->array[2];
		PUSH(s, x);
	}else if(strcmp(token, "D") == 0){
		DATA x = letras->array[3];
		PUSH(s, x);
	}else if(strcmp(token, "E") == 0){
		DATA x = letras->array[4];
		PUSH(s, x);
	}else if(strcmp(token, "F") == 0){
		DATA x = letras->array[5];
		PUSH(s, x);
	}else if(strcmp(token, "N") == 0){
		DATA x = letras->array[13];
		PUSH(s, x);
	}else if(strcmp(token, "S") == 0){
		DATA x = letras->array[18];
		PUSH(s, x);
	}else if(strcmp(token, "X") == 0){
		DATA x = letras->array[23];
		PUSH(s, x);
	}else if(strcmp(token, "Y") == 0){
		DATA x = letras->array[24];
		PUSH(s, x);
	}else if(strcmp(token, "Z") == 0){
		DATA x = letras->array[25];
		PUSH(s, x);
	}else if(strcmp(token, "G") == 0){
		DATA x = letras->array[6];
		PUSH(s, x);
	}else if(strcmp(token, "H") == 0){
		DATA x = letras->array[7];
		PUSH(s, x);
	}else if(strcmp(token, "I") == 0){
		DATA x = letras->array[8];
		PUSH(s, x);
	}else if(strcmp(token, "J") == 0){
		DATA x = letras->array[9];
		PUSH(s, x);
	}else if(strcmp(token, "K") == 0){
		DATA x = letras->array[10];
		PUSH(s, x);
	}else if(strcmp(token, "L") == 0){
		DATA x = letras->array[11];
		PUSH(s, x);
	}else if(strcmp(token, "M") == 0){
		DATA x = letras->array[12];
		PUSH(s, x);
	}else if(strcmp(token, "O") == 0){
		DATA x = letras->array[14];
		PUSH(s, x);
	}else if(strcmp(token, "P") == 0){
		DATA x = letras->array[15];
		PUSH(s, x);
	}else if(strcmp(token, "Q") == 0){
		DATA x = letras->array[16];
		PUSH(s, x);
	}else if(strcmp(token, "R") == 0){
		DATA x = letras->array[17];
		PUSH(s, x);
	}else if(strcmp(token, "T") == 0){
		DATA x = letras->array[19];
		PUSH(s, x);
	}else if(strcmp(token, "U") == 0){
		DATA x = letras->array[20];
		PUSH(s, x);
	}else if(strcmp(token, "V") == 0){
		DATA x = letras->array[21];
		PUSH(s, x);
	}else if(strcmp(token, "W") == 0){
		DATA x = letras->array[22];
		PUSH(s, x);
	}else if(strcmp(token, ":A") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 0, x);
	}else if(strcmp(token, ":B") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 1, x);
	}else if(strcmp(token, ":C") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 2, x);
	}else if(strcmp(token, ":D") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 3, x);
	}else if(strcmp(token, ":E") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 4, x);
	}else if(strcmp(token, ":F") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 5, x);
	}else if(strcmp(token, ":G") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 6, x);
	}else if(strcmp(token, ":H") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 7, x);
	}else if(strcmp(token, ":I") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 8, x);
	}else if(strcmp(token, ":J") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 9, x);
	}else if(strcmp(token, ":K") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 10, x);
	}else if(strcmp(token, ":L") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 11, x);
	}else if(strcmp(token, ":M") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 12, x);
	}else if(strcmp(token, ":N") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 13, x);
	}else if(strcmp(token, ":O") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 14, x);
	}else if(strcmp(token, ":P") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 15, x);
	}else if(strcmp(token, ":Q") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 16, x);
	}else if(strcmp(token, ":R") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 17, x);
	}else if(strcmp(token, ":S") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 18, x);
	}else if(strcmp(token, ":T") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 19, x);
	}else if(strcmp(token, ":U") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 20, x);
	}else if(strcmp(token, ":V") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 21, x);
	}else if(strcmp(token, ":W") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 22, x);
	}else if(strcmp(token, ":X") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 23, x);
	}else if(strcmp(token, ":Y") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 24, x);
	}else if(strcmp(token, ":Z") == 0){
		DATA x = POP(s);
		PUSH_PROFUNDIDADE(letras, 25, x);
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
