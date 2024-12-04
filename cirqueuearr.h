
typedef struct queue{
	int size;
	int front;
	int rare;
	int *arr;	
}queue;

typedef struct queue queue;

void init(queue* q , int size);
void enqueue(queue* q, int d);
int dequeue(queue *q);
void printarr(queue q);
