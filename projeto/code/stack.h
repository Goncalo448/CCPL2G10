typedef struct{
	long array[1024];
	int num;
}STACK;

STACK createStack();
STACK PUSH(STACK s, long n);
STACK POP(STACK s);
long TOP(STACK s);
void printStack(STACK s);