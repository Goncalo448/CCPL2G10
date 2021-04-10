/**
 * @file Library STACK
 */


#ifndef __STACK_H__
#define __STACK_H__

 
typedef enum
{
	LONG = 1,
	DOUBLE = 2,
	CHAR = 4,
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
 * \brief Função que pega o valor que está no topo da STACK.
 */
DATA TOP(STACK *s);

void PUSH(STACK *s, DATA x);

DATA POP(STACK *s);

DATA profundidade(STACK *s, int x);

int hasType(DATA x, int mask);

int isEmpty(STACK *s);

/**
 * \brief Função que imprime a STACK
 */
void printStack(STACK *s);


#define STACK_OPERATION_PROTO(_type, _name)  \
	void PUSH_##_name(STACK *s, _type val);  \
	_type POP_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif
