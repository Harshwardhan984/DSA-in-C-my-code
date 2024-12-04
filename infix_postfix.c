#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "infix_postfix.h"

// a+b*c+d =  abc*+d+

int main() {
	char I[50];
	scanf("%s",I);
	stack s;
	init(&s);
	char P[50], c;
	int i = 0, j=0;
	while(I[i] != '\0'){
		c = I[i];
		if(isalph(c)){
			P[j++] = c;
		}
		else{
			
			if(c == '('){
				Push(&s, '(');
			}
			else if(c == ')'){
				while(! isEmpty(s) && Peek(s) != '('){
					P[j++] = Pop(&s);
				}
				Pop(&s);
			}
			else{
				if(isEmpty(s))
					Push(&s, c);
				 else if(islowprece(c,Peek(s))){
					
					while(! isEmpty(s) && Peek(s) != '('){
					P[j++] = Pop(&s);
					
				}
					Push(&s, c);
				}
				else
					Push(&s, c);
				
			}
			
			
		}
		//print_stack(s);
		//printf("%s\n", P);
		i++;
	
	}
	while(! isEmpty(s)){
					P[j++] = Pop(&s);
				}
	P[j] = '\0';
	
	printf("%s\n", P);
	
	return 0;
}
