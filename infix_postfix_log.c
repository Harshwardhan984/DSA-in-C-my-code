#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "infix_postfix.h"

void init(sk* s){
	s->size = 50;
	s->top = -1;
	s->arr = (char*)malloc(sizeof(char) * s->size);
	return;
}

int isalph(char a){
	int ac = (int)a;
	if(ac >= 65 && ac <= 116)
		return 1;
	else
		return 0; 
	
}

int isEmpty(sk s){
	if(s.top == -1)
		return 1;
	else 
		return 0;
} 

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; 
}


int islowprece(char a, char b) {
    int prec_a = precedence(a);
    int prec_b = precedence(b);
    
    return prec_a < prec_b;
}

void Push(sk* s, char d){
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

char Pop(sk* s){
	if(s->top == -1){
		printf("stack is empty");
		return '\0';
	}
	else{
		char tem = s->arr[s->top];
		s->top--;
		return tem;
		
	}
}

char Peek(sk s){
	if(s.top == -1){
		printf("stack is empty");
		return '\0';
	}
	else
		return s.arr[s.top] ;
}

void print_stack(sk s){
	int i = 0;
	while(i <= s.top){
		printf("%c ", s.arr[i]);
		i++;
	}
	printf("\n");
	return;
}
	

