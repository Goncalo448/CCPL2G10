/**
 * @file Library STACK
 */

typedef enum{LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;


typedef struct data{
	TYPE type;
	long LONG;
	double DOUBLE;
	char CHAR;
	char *STRING;
}DATA;


typedef struct stack{
	DATA *array;
	int size;
	int num;
}STACK;


#define INTEGER  (LONG | CHAR)

#define NUMBER (INTEGER | DOUBLE)


/**
 * \brief Função que cria uma STACK.
 */
STACK *createStack();

/**
 * \brief Função que pega o valor que está no topo da STACK.
 */
long TOP(STACK s);

/**
 * \brief Função que imprime a STACK
 */
void printStack(STACK s);
