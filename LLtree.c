#include<stdio.h>
#include<stdlib.h>
#include "LLtree.h"

int main(){
	BST t;
	init_BST(&t);
	insert_bstree(&t,23);
	insert_bstree(&t,13);
	insert_bstree(&t,25);
	insert_bstree(&t,34);
	insert_bstree(&t,3);
	insert_bstree(&t,1);
	insert_bstree(&t,4);
	insert_bstree(&t,24);
	preorder(t);
	printf("\n");
	non_recursive_preorder(t);
	printf("\n");
	inorder(t);
	printf("\n");
	non_recursive_inorder(t);
	printf("\n");
	postorder(t);
	printf("\n");
	non_recursive_postorder(t);
	printf("\n");
	
	return 0;
}
