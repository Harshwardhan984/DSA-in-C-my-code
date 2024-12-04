#include<stdio.h>
#include<stdlib.h>
#include"queuearr.h"

int main() {
	queue Q;
	init(&Q, 20);
	enqueue(&Q, 1);
	enqueue(&Q, 2);
	enqueue(&Q, 3);
	enqueue(&Q, 4);
	enqueue(&Q, 5);
	enqueue(&Q, 6);
	printque(Q);
	enqueue(&Q, 7);
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	printque(Q);
	return 0;
}
