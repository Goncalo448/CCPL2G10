typedef struct{
	long array[1024];
	int num;
}STACK;

#define PUSH(s, n)	      s.array[s.num++] = n;
#define POP(s)		      s.array[--s.num]


STACK createStack();
long TOP(STACK s);
void printStack(STACK s);
