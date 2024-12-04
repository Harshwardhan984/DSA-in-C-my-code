

#include <stdio.h>
#include <stdlib.h>

/*

Implement ADT Binary Tree Using Linked List.

Include the following functions :

1. init_bt()

2. insert() //recursive

3. recursive_traverse() // inorder,preorder,postorder

4. count_leaf() //recursive function to count the leaf nodes in BST

5. count_nonleaf()  //recursive function to count the non-leaf nodes in BST

*/


typedef struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
} node;

typedef node* Tree;

void init_bt(Tree* t){
	*t = NULL;
	return;
}

node * newnode(int d){
	node *nn = (node*)malloc(sizeof(node));
	nn->data = d;
	nn->lchild = NULL;
	nn->rchild = NULL;
	return nn;
}

void insert(Tree *t, int d){
	 if (*t == NULL) { 
        *t = newnode(d);
        return;
    }
	if((*t)->data == d)
		return;
	if(d > (*t)->data){
		insert(&((*t)->rchild), d);
	}
	else{
		insert(&((*t)->lchild), d);
	}
}

void inorder(Tree t) {
    if (t != NULL) {
        inorder(t->lchild);
        printf("%d ", t->data);
        inorder(t->rchild);
    }
}

void preorder(Tree t) {
    if (t != NULL) {
    	printf("%d ", t->data);
        preorder(t->lchild);
        
        preorder(t->rchild);
    }
}

void postorder(Tree t) {
    if (t != NULL) {
        postorder(t->lchild);
        
        postorder(t->rchild);
        printf("%d ", t->data);
    }
}

void count_leaf(Tree t, int *leaf) {
    if (t != NULL) {
    	
    	 if(t->lchild == NULL && t->rchild == NULL){
    		(*leaf)++;
    	}
    
    
        count_leaf(t->lchild, leaf);
       
        count_leaf(t->rchild, leaf);
    }
 
    	return;
}

void count_nonleaf(Tree t, int *nonleaf) {
    if (t != NULL) {
    	
    	 if(t->lchild != NULL || t->rchild != NULL){
    		(*nonleaf)++;
    	}
    	
    
        count_nonleaf(t->lchild, nonleaf);
       
        count_nonleaf(t->rchild, nonleaf);
    }
    return;
}

int main () {
	Tree t;
	init_bt(&t);
	insert(&t, 10);
	insert(&t, 8);
	insert(&t, 4);
	insert(&t, 1);
	insert(&t, 5);
	insert(&t, 9);
	insert(&t, 6);
	insert(&t, 15);
	insert(&t, 18);
	insert(&t, 16);
	insert(&t, 14);
	insert(&t, 11);
	insert(&t, 50);
	insert(&t, 2);
	insert(&t, 3);
	insert(&t, 25);
	
	inorder(t);
	printf("\n");
	
	preorder(t);
	printf("\n");
	
	postorder(t);
	printf("\n");
	
	int leaf = 0;
	count_leaf(t, &leaf);
	printf("NO of leaf nodes is: %d\n", leaf);
	
	int nonleaf = 0;
	count_nonleaf(t, &nonleaf);
	printf("NO of non leaf nodes is: %d\n", nonleaf);
	
	return 0;
}



