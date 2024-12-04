#include<stdio.h>
#include<stdlib.h>
#include"cirqueuearr.h"

void init(queue* q , int size){
	q->size = size;
	q->front = 0;
	q->rare = -1;
	q->arr = (int*)malloc(sizeof(int) * q->size);
}

int isempty(queue q){
	return q.rare == -1;
}

int isfull(queue q){
	return (q.rare + 1) % q.size == q.front;
}

void enqueue(queue* q, int d){
	if(isfull(*q))
		return;
	if(q->rare == -1){
		q->rare = 0;
		q->arr[q->rare] = d;
		return;
	}
	q->rare = (q->rare + 1) % q->size;
	q->arr[q->rare] = d;
}

int dequeue(queue *q){
	if(isempty(*q))
		return -1;
	int tem = q->arr[q->front];
	if(q->front == q->rare){
		q->front = 0;
		q->rare = -1;
	} else {
		q->front = (q->front + 1) % q->size;
	}
	return tem;
}

void printarr(queue q){
	int i;
	for(i=0; i < q.size; i++){
		printf("%d  ", q.arr[i]);
	}
	printf("\n");
	return;
}





