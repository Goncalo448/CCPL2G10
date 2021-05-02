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

/**
 * \brief Esta função verifica se um dado elemento da stack é de um certo tipo
 *
 * @returns Retorna 1 ou 0
 */

int hasType(DATA x, int mask)
{
	return (x.type & mask) != 0;
}

/**
 * \brief Esta função coloca um dado elemento no topo da stack
 */

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

/**
 * \brief Esta função apaga o topo da stack
 *
 * @returns Retorna um DATA
 */

DATA POP(STACK *s){
	s->num--;
	return s->array[s->num];
}

/**
 * \brief Esta função retorna o valor que está no topo da STACK.
 * 
 * @returns Retorna um DATA
 */

DATA TOP(STACK *s)
{
	return s->array[s->num-1];
}

/**
 * \brief Esta função retorna o valor que se encontra numa dada profundidade da stack
 * 
 * @returns Retorna um DATA
 */

DATA profundidade(STACK *s, int x){
	return s->array[s->num-x];
}

/**
 * \brief Esta função verifica se a stack está vazia
 * 
 * @returns Retorna um int
 */

int isEmpty(STACK *s){

	return s->num == 0;
}

/**
 * \brief Esta macro calcula o maior entre dois valores
 */

#define max(x,y)	((x) > (y)) ? (x) : (y)

/**
 * \brief Esta função soma os dois valores que estão no topo da stack e coloca o resultado no topo da stack
 */

void SOMA(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	double vx = get_double(x);
	double vy = get_double(y);
	PUSH_TYPE(s, vy+vx, ret_t);
}

/**
 * \brief Esta função subtrai os dois valores que estão no topo da stack e coloca o resultado no topo da stack
 */

void SUBTRACAO(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	double vx = get_double(x);
	double vy = get_double(y);
	PUSH_TYPE(s, vy-vx, ret_t);
}

/**
 * \brief Esta função multiplica os dois valores que estão no topo da stack e coloca o resultado no topo da stack
 */

void MULTIPLICACAO(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	double vx = get_double(x);
	double vy = get_double(y);
	PUSH_TYPE(s, vy*vx, ret_t);
}

/**
 * \brief Esta função divide os dois valores que estão no topo da stack e coloca o resultado no topo da stack
 */

void DIVISAO(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	double vx = get_double(x);
	double vy = get_double(y);
	PUSH_TYPE(s, vy/vx, ret_t);
}

/**
 * \brief Esta função vai executar uma operação aritmetica conforme o sinal que esteja no token
 */

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

/**
 * \brief Esta função decrementa o valor que está no topo da stack
 */

void DECREMENT(STACK *s){
	DATA x = POP(s);
	TYPE ret_t = x.type;
	double vx = get_double(x);
	PUSH_TYPE(s, vx-1, ret_t);
}

/**
 * \brief Esta função decrementa o valor que está no topo da stack
 */

void INCREMENT(STACK *s){
	DATA x = POP(s);
	TYPE ret_t = x.type;
	double vx = get_double(x);
	PUSH_TYPE(s, vx+1, ret_t);
}

/**
 * \brief Esta função calcula o resto da divisao dos dois valores do topo da stack
 */

void MODULO(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	long vx = get_double(x);
	long vy = get_double(y);
	PUSH_TYPE(s, vy%vx, ret_t);
}

/**
 * \brief Esta função calcula o topo da stack elevado ao segundo elemento da stack
 */

void EXPOENTE(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	double vx = get_double(x);
	double vy = get_double(y);
	PUSH_TYPE(s, pow(vy, vx), DOUBLE);
}

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

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

/**
 * \brief Esta função compara os bits de cada elemento da stack
 */

void AND(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	long vx = get_double(x);
	long vy = get_double(y);
	PUSH_TYPE(s, vx&vy, ret_t);
}

/**
 * \brief Esta função compara os bits de cada elemento da stack
 */

void OR(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	long vx = get_double(x);
	long vy = get_double(y);
	PUSH_TYPE(s, vx|vy, ret_t);
}

/**
 * \brief Esta função compara os bits de cada elemento da stack
 */

void XOR(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	TYPE ret_t = max(x.type, y.type);
	long vx = get_double(x);
	long vy = get_double(y);
	PUSH_TYPE(s, vx^vy, ret_t);
}

/**
 * \brief Esta função compara os bits de cada elemento da stack
 */

void NOT(STACK *s){
	DATA x = POP(s);
	TYPE ret_t = x.type;
	long vx = get_double(x);
	PUSH_TYPE(s, ~vx, ret_t);
}

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

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
 * \brief Esta função converte o topo da stack num inteiro
 */

void CONVERTE_INT(STACK *s){
	DATA x = POP(s);
	long vx = get_double(x);
	PUSH_TYPE(s, vx, LONG);
}

/**
 * \brief Esta função converte o topo da stack num float
 */

void CONVERTE_FLOAT(STACK *s){
	DATA x = POP(s);
	double vx = get_double(x);
	PUSH_TYPE(s, vx, DOUBLE);
}

/**
 * \brief Esta função converte o topo da stack num char
 */

void CONVERTE_CHAR(STACK *s){
	DATA x = POP(s);
	char vx = get_double(x);
	PUSH_TYPE(s, vx, CHAR);
}

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

void CONVERSAO(STACK *s, const char *token){
	if(strcmp(token, "i") == 0){
		CONVERTE_INT(s);
	}else if(strcmp(token, "f") == 0){
		CONVERTE_FLOAT(s);
	}else if(strcmp(token, "c") == 0){
		CONVERTE_CHAR(s);
	}
}

/**
 * \brief Esta função coloca um elemento numa determinada profundidade da stack
 */

void PUSH_PROFUNDIDADE(STACK *s, int x, DATA y){
	s->num = x;
	s->array[s->num++] = y;
}

/**
 * \brief Esta função cria uma STACK de letras em que algumas delas têm valores predefinidos.
 *
 * @returns Retorna uma STACK de letras
 */

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

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */


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
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 0, x);
	}else if(strcmp(token, ":B") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 1, x);
	}else if(strcmp(token, ":C") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 2, x);
	}else if(strcmp(token, ":D") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 3, x);
	}else if(strcmp(token, ":E") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 4, x);
	}else if(strcmp(token, ":F") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 5, x);
	}else if(strcmp(token, ":G") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 6, x);
	}else if(strcmp(token, ":H") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 7, x);
	}else if(strcmp(token, ":I") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 8, x);
	}else if(strcmp(token, ":J") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 9, x);
	}else if(strcmp(token, ":K") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 10, x);
	}else if(strcmp(token, ":L") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 11, x);
	}else if(strcmp(token, ":M") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 12, x);
	}else if(strcmp(token, ":N") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 13, x);
	}else if(strcmp(token, ":O") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 14, x);
	}else if(strcmp(token, ":P") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 15, x);
	}else if(strcmp(token, ":Q") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 16, x);
	}else if(strcmp(token, ":R") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 17, x);
	}else if(strcmp(token, ":S") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 18, x);
	}else if(strcmp(token, ":T") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 19, x);
	}else if(strcmp(token, ":U") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 20, x);
	}else if(strcmp(token, ":V") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 21, x);
	}else if(strcmp(token, ":W") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 22, x);
	}else if(strcmp(token, ":X") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 23, x);
	}else if(strcmp(token, ":Y") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 24, x);
	}else if(strcmp(token, ":Z") == 0){
		DATA x = TOP(s);
		PUSH_PROFUNDIDADE(letras, 25, x);
	}
}

/**
 * \brief Esta função duplica o valor do top da stack
 */

void DUPLICA(STACK *s){

	DATA x = TOP(s);
	POP(s);
	PUSH(s, x);
	PUSH(s, x);
}

/**
 * \brief Esta função troca os dois valores que estão no topo da stack
 */

void TROCA(STACK *s){

	DATA x = TOP(s);
	POP(s);
	DATA y = TOP(s);
	POP(s);
	PUSH(s, x);
	PUSH(s, y);
}

/**
 * \brief Esta função roda os três elemento que estão no topo da stack
 */

void RODA_ELEMENTOS(STACK *s){

	DATA x = TOP(s);
	POP(s);
	DATA y = TOP(s);
	POP(s);
	DATA z = TOP(s);
	POP(s);
	PUSH(s, y);
	PUSH(s, x);
	PUSH(s, z);
}

/**
 * \brief Esta função coloca o elemento que se encontra numa determinada posiçao no topo da stack
 */

void N_ESIMO_ELEMENTO(STACK *s){

	long x = POP_LONG(s);
	PUSH(s, profundidade(s, x+1));
}

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

void COMANDOS_STACK(STACK *s, const char *token){

	if(strcmp(token, "_") == 0){
		DUPLICA(s);
	}else if(strcmp(token, ";") == 0){
		POP(s);
	}else if(strcmp(token, "\\") == 0){
		TROCA(s);
	}else if(strcmp(token, "@") == 0){
		RODA_ELEMENTOS(s);
	}else if(strcmp(token, "$") == 0){
		N_ESIMO_ELEMENTO(s);
	}
}

/**
 * \brief Esta função verifica se os dois elementos do topo da stack sao iguais e coloca no topo da stack 0 ou 1 conforme o valor logico
 */ 

void IGUAL(STACK *s){

	DATA x = POP(s);
	DATA y = POP(s);
	double vx = get_double(x);
	double vy = get_double(y);
	if(vx == vy){
		PUSH_TYPE(s, 1, LONG);
	}else{
		PUSH_TYPE(s, 0, LONG);
	}
}

/**
 * \brief Esta função verifica se o segundo elemento da stack e menor do que primeiro elemento da stack e coloca no topo da stack 0 ou 1 conforme o valor logico
 */

void MENOR(STACK *s){

	DATA x = POP(s);
	DATA y = POP(s);
	double vx = get_double(x);
	double vy = get_double(y);
	if(vy < vx){
		PUSH_TYPE(s, 1, LONG);
	}else{
		PUSH_TYPE(s, 0, LONG);
	}
}

/**
 * \brief Esta função verifica se o segundo elemento da stack e maior do que primeiro elemento da stack e coloca no topo da stack 0 ou 1 conforme o valor logico
 */

void MAIOR(STACK *s){

	DATA x = POP(s);
	DATA y = POP(s);
	double vx = get_double(x);
	double vy = get_double(y);
	if(vy > vx){
		PUSH_TYPE(s, 1, LONG);
	}else{
		PUSH_TYPE(s, 0, LONG);
	}
}

/**
 * \brief Esta função calcula o valor logico da negacao do topo da stack
 */

void NEGACAO(STACK *s){

	DATA x = POP(s);
	double vx = get_double(x);
	if(vx == 0){
		PUSH_TYPE(s, 1, LONG);
	}else{
		PUSH_TYPE(s, 0, LONG);
	}
}

/**
 * \brief Esta função faz a conjunção entre dois valores. Se os dois valores forem verdadeiros coloca o maior no topo da stack se não coloca 0
 */

void E(STACK *s){

	DATA x = POP(s);
	DATA y = POP(s);
	double vx = get_double(x);
	double vy = get_double(y);
	if(vx && vy){
		PUSH_LONG(s, max(vx,vy));
	}else{
		PUSH_TYPE(s, 0, LONG);
	}
}

/**
 * \brief Esta função faz a dijunção entre dois valores. Se os dois valores forem verdadeiros coloca o menor no topo da stack se não coloca o maior
 */

void OU(STACK *s){
	DATA x = POP(s);
	DATA y = POP(s);
	double vx = get_double(x);
	double vy = get_double(y);
	if(vx == 0 && vy == 0){
		PUSH_TYPE(s, 0, LONG);
	}else if(vx == 0){
		PUSH(s, y);
	}else if(vy == 0){
		PUSH(s, x);
	}else{
		PUSH_TYPE(s, max(vx,vy), DOUBLE);
	}
}

/**
 * \brief Esta função coloca o menor dos 2 valores na stack
 */

void MENOR_2_VALORES(STACK *s){

	DATA x = POP(s);
	DATA y = POP(s);
	double vx = get_double(x);
	double vy = get_double(y);
	if(vy < vx){
		PUSH_TYPE(s, vy, DOUBLE);
	}else{
		PUSH_TYPE(s, vx, DOUBLE);
	}
}

/**
 * \brief Esta função coloca o maior dos 2 valores na stack
 */

void MAIOR_2_VALORES(STACK *s){

	DATA x = POP(s);
	DATA y = POP(s);
	double vx = get_double(x);
	double vy = get_double(y);
	if(vy > vx){
		PUSH_TYPE(s, vy, DOUBLE);
	}else{
		PUSH_TYPE(s, vx, DOUBLE);
	}
}

/**
 * \brief Esta função verifica o valor logico do topo da stack. Se o valor for verdeiro coloca o segundo elemento da stack no topo da stack se não coloca o terceiro
 */

void IF_THEN_ELSE(STACK *s){

	DATA x = POP(s);
	DATA y = POP(s);
	DATA z = POP(s);
	double vz = get_double(z);
	if(vz){
		PUSH(s, y);
	}else{
		PUSH(s, x);
	}
}

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

void LOGICA(STACK *s, const char *token){

	if(strcmp(token, "=") == 0){
		IGUAL(s);
	}else if(strcmp(token, "<") == 0){
		MENOR(s);
	}else if(strcmp(token, ">") == 0){
		MAIOR(s);
	}else if(strcmp(token, "!") == 0){
		NEGACAO(s);
	}else if(strcmp(token, "e&") == 0){
		E(s);
	}else if(strcmp(token, "e|") == 0){
		OU(s);
	}else if(strcmp(token, "e<") == 0){
		MENOR_2_VALORES(s);
	}else if(strcmp(token, "e>") == 0){
		MAIOR_2_VALORES(s);
	}else if(strcmp(token, "?") == 0){
		IF_THEN_ELSE(s);
	}
}


void CREATE_STRING(STACK *s, const char *token){

	char str[50];
	char *tokencpy;

	*tokencpy = strdup(token);

	while(*tokencpy){
		
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

/**
 * \brief Esta macro serve para executar as funçoes PUSH e POP para um tipo de dados desejado
 */

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

/**
 * \brief Esta função executa o push de um elemento com um determinado tipo
 */

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

/**
 * \brief Esta função converte um DATA em DOUBLE
 * 
 * @returns Retorna um DOUBLE
 */

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
