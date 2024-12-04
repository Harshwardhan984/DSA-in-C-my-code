#include<stdio.h>
#include<stdlib.h>
#include"queuearr.h"

void init(queue* q , int size){
	q->size = size;
	q->front = 0;
	q->rare = -1;
	q->arr = (int*)malloc(sizeof(int) * q->size);
	return;
}

int isfull(queue q){
	if(q.rare == q.size -1)
		return 1;
	return 0;
}

int isempty(queue q){
	if(q.rare ==  -1)
		return 1;
	return 0;
}


void enqueue(queue* q, int d){
	if(isfull(*q))
		return;
	q->rare++;
	q->arr[q->rare] = d;
	return;
}

int dequeue(queue *q){
	if(isempty(*q))
		return 0;
	int tem = q->arr[q->front];
	int i;
	for(i=q->front; i < q->rare -1 ; i++){
		q->arr[i] = q->arr[i+1];
	}
	q->rare--;
	return tem;
}


void printque(queue q){
	if(isempty(q))
		return;
	int i;
	for(i=q.front; i < q.rare ; i++){
		printf("%d  ", q.arr[i]);
	}
	printf("\n");
	return;
}




