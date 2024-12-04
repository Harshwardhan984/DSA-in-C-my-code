#include<stdio.h>
#include<stdlib.h>
#include"cirqueuearr.h"

int main() {
	queue Q;
	init(&Q, 7);
	enqueue(&Q, 1);
	enqueue(&Q, 2);
	enqueue(&Q, 3);
	enqueue(&Q, 4);
	enqueue(&Q, 5);
	enqueue(&Q, 6);
	//printarr(Q);
	enqueue(&Q, 7);
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	//printarr(Q);
	enqueue(&Q, 1);
	enqueue(&Q, 2);
	enqueue(&Q, 3);
	
	//printarr(Q);
	enqueue(&Q, 7);
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	printf("%d\n",dequeue(&Q));
	
	//printarr(Q);
	return 0;
}
