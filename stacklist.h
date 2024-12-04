typedef struct node{
	int data;
	struct node* next; 
}node;

typedef  node* list;

typedef struct stack{
	struct node* top;
	list L;
	
}stack;

typedef stack sk;

void init(sk* s);
void Push(sk* s, int d);
int Pop(sk* s);
int Peek(sk s);
void print_stack(sk s);
