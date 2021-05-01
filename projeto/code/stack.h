/**
 * @file Library STACK
 */


#ifndef __STACK_H__
#define __STACK_H__

 
typedef enum
{
	LONG = 2,
	DOUBLE = 4,
	CHAR = 1,
	STRING = 8
} TYPE;


#define INTEGER (LONG | CHAR)
#define NUMBER (INTEGER | DOUBLE)


typedef struct data
{
	TYPE type;
	long LONG;
	double DOUBLE;
	char CHAR;
	char *STRING;
} DATA;


typedef struct stack
{
	DATA *array;
	int size;
	int num;
} STACK;


/**
 * \brief Função que cria uma STACK.
 */
STACK *createStack();

/**
 * \brief Esta função verifica se um dado elemento da stack é de um certo tipo
 *
 * @returns Retorna 1 ou 0
 */

int hasType(DATA x, int mask);

/**
 * \brief Esta função coloca um dado elemento no topo da stack
 */

void PUSH(STACK *s, DATA x);

/**
 * \brief Esta função apaga o topo da stack
 *
 * @returns Retorna um DATA
 */

DATA POP(STACK *s);

/**
 * \brief Função que pega o valor que está no topo da STACK.
 */

DATA TOP(STACK *s);

/**
 * \brief Esta função retorna o valor que se encontra numa dada profundidade da stack
 * 
 * @returns Retorna um DATA
 */

DATA profundidade(STACK *s, int x);

/**
 * \brief Esta função verifica se a stack está vazia
 * 
 * @returns Retorna um int
 */

int isEmpty(STACK *s);

double get_double(DATA elemento);

void PUSH_TYPE(STACK *s, double val, TYPE t);

/**
 * \brief Função que imprime a STACK
 */
void printStack(STACK *s);


void SOMA(STACK *s);

void SUBTRACAO(STACK *s);

void MULTIPLICACAO(STACK *s);

void DIVISAO(STACK *s);


void ARITMETICA(STACK *s, const char *token);


void DECREMENT(STACK *s);

void INCREMENT(STACK *s);

void MODULO(STACK *s);

void EXPOENTE(STACK *s);

void MAT(STACK *s, const char *token);

void AND(STACK *s);

void OR(STACK *s);

void XOR(STACK *s);

void NOT(STACK *s);

void BITWISE(STACK *s, const char *token);


void CONVERTE_INT(STACK *s);

void CONVERTE_FLOAT(STACK *s);

void CONVERTE_CHAR(STACK *s);

void CONVERSAO(STACK *s, const char *token);

void PUSH_PROFUNDIDADE(STACK *s, int x, DATA y);

STACK *create_letter_array();

void VARIAVEIS(STACK *s, STACK *letras, const char *token);

void DUPLICA(STACK *s);

void TROCA(STACK *s);

void RODA_ELEMENTOS(STACK *s);

void N_ESIMO_ELEMENTO(STACK *s);

void COMANDOS_STACK(STACK *s, const char *token);

void IGUAL(STACK *s);

void MENOR(STACK *s);

void MAIOR(STACK *s);

void NEGACAO(STACK *s);

void E(STACK *s);

void OU(STACK *s);

void MENOR_2_VALORES(STACK *s);

void MAIOR_2_VALORES(STACK *s);

void IF_THEN_ELSE(STACK *s);

void LOGICA(STACK *s, const char *token);


#define STACK_OPERATION_PROTO(_type, _name)  \
	void PUSH_##_name(STACK *s, _type val);  \
	_type POP_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif
