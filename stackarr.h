typedef struct stack{
	int size, top;
	int * arr;
}stack;

typedef stack sk;

void init(sk* s);
int isEmpty(sk s);
void Push(sk* s, int d);
int Pop(sk* s);
int Peek(sk s);
void print_stack(sk s);
