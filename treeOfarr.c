

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*
emplacement ADT Binary Search Tree Using an Array.

Include the following functions :

1. init_bst()

2. insert()

3. recursive_traverse() // inorder,preorder,postorder

Right child = 2i + 2;
Left child = 2i + 1;


*/

//BST implimentation by arr

typedef struct tree{
	int size;
	int *arr;
}tree;

void init_bst(tree* t, int n){
	t->size = n;
	t->arr = (int*)malloc(sizeof(int) * t->size);
	int i;
	for(i = 0; i < t->size; i++){
		t->arr[i] = INT_MIN;
	}
	return;
}

void insert(tree* t, int d) {
    int i = 0;  // Start at the root

    // Traverse until we find an empty spot (INT_MIN)
    while (i < t->size) {
        // If current node is empty, insert the value
        if (t->arr[i] == INT_MIN) {
            t->arr[i] = d;
            return;
        }

        // If the value already exists, do nothing
        if (t->arr[i] == d) {
            return;
        }

        // If value is smaller, move to the left child
        if (d < t->arr[i]) {
            i = 2 * i + 1;
        }
        // If value is greater, move to the right child
        else {
            i = 2 * i + 2;
        }
    }

    // If we reach here, it means the array is full and we couldn't insert the value
    printf("Error: Tree is full, cannot insert %d\n", d);
    return;
}

void recursive_traverse_inorder(tree* t, int i){
	// left root right 
	if(t->arr[i] == INT_MIN || i >= t->size)
		return;
	
	// Traverse the left subtree
    recursive_traverse_inorder(t, 2 * i + 1);
    
    // Print the root
    printf("%d ", t->arr[i]);
    
    // Traverse the right subtree
    recursive_traverse_inorder(t, 2 * i + 2);
	
	
}


void recursive_traverse_preorder(tree* t, int i){
	// root left  right 
	if(t->arr[i] == INT_MIN || i >= t->size)
		return;
	
	
    // Print the root
    printf("%d ", t->arr[i]);
    
    // Traverse the left subtree
    recursive_traverse_preorder(t, 2 * i + 1);
    
    
    // Traverse the right subtree
    recursive_traverse_preorder(t, 2 * i + 2);
	
	
}
	
	
void recursive_traverse_postorder(tree* t, int i){
	// left  right root
	if(t->arr[i] == INT_MIN || i >= t->size)
		return;
	
	// Traverse the left subtree
    recursive_traverse_postorder(t, 2 * i + 1);
    
    
    // Traverse the right subtree
    recursive_traverse_postorder(t, 2 * i + 2);
    
    // Print the root
    printf("%d ", t->arr[i]);
    
	
	
}
	

void printarr(tree t){
	int i =0;
	for(i = 0; i < t.size; i++){
		if(t.arr[i] == INT_MIN)
			printf("null ");
		else
			printf("%d ", t.arr[i]);
	}
	printf("\n");
	return;
}


int main() {
	tree T;
	init_bst(&T, 100);
	insert(&T, 50);
	insert(&T, 60);
	insert(&T, 70);
	insert(&T, 65);
	insert(&T, 75);
	insert(&T, 55);
	insert(&T, 62);
	insert(&T, 72);
	insert(&T, 52);
	
	
	printarr(T);
	
	recursive_traverse_inorder(&T, 0);
	printf("\n");
	
	recursive_traverse_preorder(&T, 0);
	printf("\n");
	
	recursive_traverse_postorder(&T, 0);
	printf("\n");
	
	return 0;
}





