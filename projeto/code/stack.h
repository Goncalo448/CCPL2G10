/**
 * @file Library STACK
 */
typedef struct{
	long array[1024];
	int num;
}STACK;

/**
 * \brief Macro que contém o PUSH.
 */
#define PUSH(s, n)	      s.array[s.num++] = n;

/**
 * \brief Macro que contém o POP.
 */
#define POP(s)		      s.num--;

/**
 * \brief Função que cria uma STACK.
 */
STACK createStack();

/**
 * \brief Função que pega o valor que está no topo da STACK.
 */
long TOP(STACK s);

/**
 * \brief Função que imprime a STACK
 */
void printStack(STACK s);
