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

int hasType(DATA x, int mask);

void PUSH(STACK *s, DATA x);

DATA POP(STACK *s);

/**
 * \brief Função que pega o valor que está no topo da STACK.
 */
DATA TOP(STACK *s);

DATA profundidade(STACK *s, int x);

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


#define STACK_OPERATION_PROTO(_type, _name)  \
	void PUSH_##_name(STACK *s, _type val);  \
	_type POP_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif
