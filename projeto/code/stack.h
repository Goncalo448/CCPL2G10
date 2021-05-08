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
	STRING = 8,
	ARRAY = 16,
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
	struct stack* ARRAY;
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

/**
 * \brief Esta função converte um DATA em DOUBLE
 * 
 * @returns Retorna um DOUBLE
 */
double get_double(DATA elemento);

void PUSH_TYPE(STACK *s, double val, TYPE t);

/**
 * \brief Função que imprime a STACK
 */
void printStack(STACK *s);

/**
 * \brief Esta função soma os dois valores que estão no topo da stack e coloca o resultado no topo da stack
 */

void SOMA(STACK *s);

/**
 * \brief Esta função subtrai os dois valores que estão no topo da stack e coloca o resultado no topo da stack
 */

void SUBTRACAO(STACK *s);

/**
 * \brief Esta função multiplica os dois valores que estão no topo da stack e coloca o resultado no topo da stack
 */

void MULTIPLICACAO(STACK *s);

/**
 * \brief Esta função divide os dois valores que estão no topo da stack e coloca o resultado no topo da stack
 */

void DIVISAO(STACK *s);

/**
 * \brief Esta função vai executar uma operação aritmetica conforme o sinal que esteja no token
 */

void ARITMETICA(STACK *s, const char *token);

/**
 * \brief Esta função decrementa o valor que está no topo da stack
 */

void DECREMENT(STACK *s);

/**
 * \brief Esta função decrementa o valor que está no topo da stack
 */

void INCREMENT(STACK *s);

/**
 * \brief Esta função calcula o resto da divisao dos dois valores do topo da stack
 */

void MODULO(STACK *s);

/**
 * \brief Esta função calcula o topo da stack elevado ao segundo elemento da stack
 */

void EXPOENTE(STACK *s);

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

void MAT(STACK *s, const char *token);

/**
 * \brief Esta função compara os bits de cada elemento da stack
 */

void AND(STACK *s);

/**
 * \brief Esta função compara os bits de cada elemento da stack
 */

void OR(STACK *s);

/**
 * \brief Esta função compara os bits de cada elemento da stack
 */

void XOR(STACK *s);

/**
 * \brief Esta função compara os bits de cada elemento da stack
 */

void NOT(STACK *s);

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

void BITWISE(STACK *s, const char *token);

/**
 * \brief Esta função converte o topo da stack num inteiro
 */

void CONVERTE_INT(STACK *s);

/**
 * \brief Esta função converte o topo da stack num float
 */

void CONVERTE_FLOAT(STACK *s);

/**
 * \brief Esta função converte o topo da stack num char
 */

void CONVERTE_CHAR(STACK *s);

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

void CONVERSAO(STACK *s, const char *token);

/**
 * \brief Esta função coloca um elemento numa determinada profundidade da stack
 */

void PUSH_PROFUNDIDADE(STACK *s, int x, DATA y);

/**
 * \brief Esta função cria uma STACK de letras em que algumas delas têm valores predefinidos.
 *
 * @returns Retorna uma STACK de letras
 */

STACK *create_letter_array();

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

void VARIAVEIS(STACK *s, STACK *letras, const char *token);

/**
 * \brief Esta função duplica o valor do top da stack
 */

void DUPLICA(STACK *s);

/**
 * \brief Esta função troca os dois valores que estão no topo da stack
 */

void TROCA(STACK *s);

/**
 * \brief Esta função roda os três elemento que estão no topo da stack
 */

void RODA_ELEMENTOS(STACK *s);

/**
 * \brief Esta função coloca o elemento que se encontra numa determinada posiçao no topo da stack
 */

void N_ESIMO_ELEMENTO(STACK *s);

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

void COMANDOS_STACK(STACK *s, const char *token);

/**
 * \brief Esta função verifica se os dois elementos do topo da stack sao iguais e coloca no topo da stack 0 ou 1 conforme o valor logico
 */ 

void IGUAL(STACK *s);

/**
 * \brief Esta função verifica se o segundo elemento da stack e menor do que primeiro elemento da stack e coloca no topo da stack 0 ou 1 conforme o valor logico
 */

void MENOR(STACK *s);

/**
 * \brief Esta função verifica se o segundo elemento da stack e maior do que primeiro elemento da stack e coloca no topo da stack 0 ou 1 conforme o valor logico
 */

void MAIOR(STACK *s);

/**
 * \brief Esta função calcula o valor logico da negacao do topo da stack
 */

void NEGACAO(STACK *s);

/**
 * \brief Esta função faz a conjunção entre dois valores. Se os dois valores forem verdadeiros coloca o maior no topo da stack se não coloca 0
 */

void E(STACK *s);

/**
 * \brief Esta função faz a dijunção entre dois valores. Se os dois valores forem verdadeiros coloca o menor no topo da stack se não coloca o maior
 */

void OU(STACK *s);

/**
 * \brief Esta função coloca o menor dos 2 valores na stack
 */

void MENOR_2_VALORES(STACK *s);

/**
 * \brief Esta função coloca o maior dos 2 valores na stack
 */

void MAIOR_2_VALORES(STACK *s);

/**
 * \brief Esta função verifica o valor logico do topo da stack. Se o valor for verdeiro coloca o segundo elemento da stack no topo da stack se não coloca o terceiro
 */

void IF_THEN_ELSE(STACK *s);

/**
 * \brief Esta função determina qual a operação que o programa vai executar conforme o token
 */

void LOGICA(STACK *s, const char *token);

void CREATE_STRING(STACK *s, const char *token);

void PUSH_TO_ARRAY(STACK *s, char *str);

void CREATE_ARRAY(STACK *s, const char *token);

void COLOCA_ARRAY_STACK(STACK *s);

void BUSCA_POR_INDICE(STACK *s);

void ARRAYS(STACK *s, const char *token);


#define STACK_OPERATION_PROTO(_type, _name)  \
	void PUSH_##_name(STACK *s, _type val);  \
	_type POP_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)
STACK_OPERATION_PROTO(struct stack *, ARRAY)

#endif
