#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include "LLtree.h"

// Initialize the stack
void initStack(Stack* s) {
    s->top = NULL;
    return;
}

// Push a tree node onto the stack
void push(Stack* s, node* node) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->data = node;
    newStackNode->next = s->top;
    s->top = newStackNode;
    return;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Pop a node from the stack
node* pop(Stack* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    StackNode* temp = s->top;
    node* node = temp->data;
    s->top = s->top->next;
    free(temp);
    return node;
}

node* peek(Stack* s){
	if (isEmpty(s)) {
        return NULL;
    }
    return s->top->data;
}


void init_BST(BST *t){
    *t=NULL;
    return;
}

void insert_bstree(BST *t, int d){
    node *nn=(BST)malloc(sizeof(node));
    nn->data=d;
    nn->lchild=nn->rchild=NULL;
    if(*t==NULL){
        *t=nn;
        return;
    }
    node *p=*t,*q=NULL;
    while(p){
        q=p;
        if(p->data > d)
            p=p->lchild;
        else if(p->data < d)
            p=p->rchild;
        else{
            free(nn);
            return;
        }
    }
    if(q->data > d)
        q->lchild=nn;
    else if(q->data < d)
        q->rchild=nn;
    return;

}

BST createNode(int d){
	struct node *nn=(BST)malloc(sizeof(node));
    	nn->data=d;
    	nn->lchild=nn->rchild=NULL;
    	return nn;
}

BST recursive_insert(BST *t, int d){
	
    if(*t==NULL){
        return createNode(d);
    }
    node *p=*t;
    if(p->data == d)
    	return p;
    	
    if(p->data > d)
    	p->lchild = recursive_insert(&p->lchild, d);
    else if(p->data < d)
    	p->rchild = recursive_insert(&p->rchild,d);
    return p;

}
void preorder(BST t){
    if(!t)
        return ;
    printf("%d ",t->data);
    preorder(t->lchild);
    preorder(t->rchild);
    
}

void non_recursive_preorder(BST t){
	
    if (t == NULL) {
        return;
    }
    node *p = t;
    Stack s;
    initStack(&s);
    while (p || !isEmpty(&s)) {
    	if(p){
    		printf("%d ",p->data);
    		push(&s,p);
    		p=p->lchild;
    	}
    	else{
    		p = pop(&s);
    		p = p->rchild;
    	}      
}
return;
}

void inorder(BST t){
    if(!t)
        return ;
    
    inorder(t->lchild);
    printf("%d ",t->data);
    inorder(t->rchild);
    
}

void non_recursive_inorder(BST t){
	
    if (t == NULL) {
        return;
    }
    node *p = t;
    Stack s;
    initStack(&s);
    while (p || !isEmpty(&s)) {
    	if(p){
    		//printf("%d->",p->data);
    		push(&s,p);
    		p=p->lchild;
    	}
    	else{	
    		p = pop(&s);
    		printf("%d ",p->data);
    		p = p->rchild;
    	}      
}
return;
}

void postorder(BST t){
    if(!t)
        return ;
    
    postorder(t->lchild);
    postorder(t->rchild);
    printf("%d ",t->data);
    
}

void non_recursive_postorder(BST t){
	
    if (t == NULL) {
        return;
    }
    Stack s1, s2;
    initStack(&s1);
    initStack(&s2);
    
    push(&s1, t);
    
    while (!isEmpty(&s1)) {
        node *p = pop(&s1);
        push(&s2, p);
        
        // Push left and right children into s1
        if (p->lchild) {
            push(&s1, p->lchild);
        }
        if (p->rchild) {
            push(&s1, p->rchild);
        }
    }
    
    // Now print all nodes from s2 which are in post-order
    while (!isEmpty(&s2)) {
        node *p = pop(&s2);
        printf("%d ", p->data);
    }
    
    return;
}



