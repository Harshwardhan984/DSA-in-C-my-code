#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stacklist.h"

void init(sk* s){
	s->L = NULL;
	s->top = NULL;
	return;
}


int isempty(sk* s){
	if(s->top == NULL)
		return 1;
	else
		return 0;
}

void Push(sk* s, int d){
	
	struct node *p ;
	p = (struct node*)malloc(sizeof(struct node));
	if(p){
		p->data = d;
		p->next = NULL;
	}
	else
		return;
	if(isempty(s)){
		s->L = p;
		s->top = p;
		return;
	}
	else{
		s->top->next = p;
		s->top = s->top->next;
		return;
	}
}

int Pop(sk* s){
	if(isempty(s)){
		printf("stack is empty");
		return -1;
	}
	else{
		int tem = s->top->data;
		struct node*p = s->L;
		struct node*q = p->next;
		if(q == NULL){
			free(p);
			s->L = NULL;
			s->top = NULL;
			
			return tem;
		}
		while(q != s->top){
			p = p->next;
			q = q->next;
		}
		s->top = p;
		free(q);
		s->top->next = NULL;
		return tem;
		
	}
}

int Peek(sk s){
	if(isempty(&s)){
		printf("stack is empty");
		return -1;
	}
	else
		return s.top->data ;
}

void print_stack(sk s){
	struct node*p = s.L;
	if(s.L == NULL){
		printf("stack is empty");
		return;
	}
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return;
}
	

