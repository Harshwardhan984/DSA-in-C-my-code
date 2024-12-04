typedef struct stack{
	int size, top;
	char * arr;
}stack;

typedef stack sk;

void init(sk* s);
int isalph(char a);
int isEmpty(sk s);
int islowprece(char a, char b);
void Push(sk* s, char d);
char Pop(sk* s);
char Peek(sk s);
void print_stack(sk s);
