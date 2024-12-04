#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stackarr.h"

void init(sk* s){
	s->size = 10;
	s->top = -1;
	s->arr = (int*)malloc(sizeof(int) * s->size);
	return;
}

int isEmpty(sk s){
	if(s->top == -1)
		return 1;
	else 
		return 0;
} 

void Push(sk* s, int d){
	if(s->top == (s->size - 1)){
		printf("stack is full");
		return;
	}
	else{
		s->top++;
		s->arr[s->top] = d;
		return;
	}
}

int Pop(sk* s){
	if(s->top == -1){
		printf("stack is empty");
		return -1;
	}
	else{
		int tem = s->arr[s->top];
		s->top--;
		return tem;
		
	}
}

int Peek(sk s){
	if(s->top == -1){
		printf("stack is empty");
		return -1;
	}
	else
		return s.arr[s.top] ;
}

void print_stack(sk s){
	int i = 0;
	while(i <= s.top){
		printf("%d ", s.arr[i]);
		i++;
	}
	printf("\n");
	return;
}
	

