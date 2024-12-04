#include "array1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

//initialise of array
void init(array* a, int size){

	a->A = (int*)malloc(sizeof(int)*size);
	a->size = size;
	a->len = 0;
	return;
}

//add element to end of array
void append(array* a, int ele){

	if(a->len < a->size){
		a->A[a->len] = ele;
		a->len++;
		printf("%d appended successfully\n",ele);
	}
	else{
		printf("Array full , append failed !\n");
	}	
	return;
}

// insert element at any index of array 
void insert_at_index(array* a, int index, int val){

	if(index < a->len){
		//replaces value at index and moves the array upto last
		for(int i=(a->len-1);i>index;i--)
		{
			a->A[i] = a->A[i-1];
		}
		a->A[index] = val;
		printf("%d inserted successfully\n",val);
	}
	else{
		printf("Invalid index , insertion failed !\n");
	}	
	return;			
}

// remove element at any index of array 
int remove_at_index(array* a, int index){

	if(index < a->len){
		int val;
		val = a->A[index]; 
		for(int i=index;i< (a->len-1) ;i++){
			a->A[i] = a->A[i+1];
		}
		a->len--;
		return val;
	}
	else{
		printf("Invalid index , deletion failed !\n");
		return -1;
	}		
}

//Display array print all elements of array
void display(array a){
	for(int i=0;i<a.len;i++){
		printf("%d ",a.A[i]);	
	}
	printf("\n");
	return;
}

//find maximum ele of array
int max(array a){

	int maxval = INT_MIN;
	
	for(int i=0;i<a.len;i++){
		if(a.A[i] > maxval)
			maxval = a.A[i];
	}
	return maxval;
}

//find minimum ele of array
int min(array a){
	int minval = INT_MAX;
	for(int i=0; i<a.len; i++){
		if(a.A[i] < minval)
			minval = a.A[i];
	}
	return minval;
}

//reverse the array
void reverse(array* a){
	int l = a->len - 1;
	for(int i=0; i< (a->len)/2 ; i++){
		//swap(a->A[l],a->A[i]);
		int temp;
		temp = a->A[i];
		a->A[i] = a->A[l];
		a->A[l] = temp;
		l--;
	}
	return;
}

// fill array with random elements
void rd(array* a){
	// calling rand() to get random elements
	srand(time(NULL));
	for (int i = a->len ; i < a->size; i++) {
		if(a->len < a->size){
    			a->A[i] = (rand() % 21);
    			a->len++;
    	      }		
	}
	return;
}

//Generate new array of size newsize with random elements and merge that with orignal array
void merge(array a,int newsize){
	array b;
	array ans;
	int  sizenew = newsize;
	init(&b,sizenew);
	rd(&b);
	printf("New array generated is : \n");
	for(int i=0; i<b.len; i++){
		printf("%d ", b.A[i]);	
	}
	printf("\n");
	int sizeans = a.len + b.len;
	init(&ans,sizeans);
	printf("The final merged array is : \n");
	int j = 0, k = 0;
	for(int i=0; i<a.len; i++){
		ans.A[i] = a.A[j];
		j++;
		ans.len++;	
	}
	for(int i=a.len; i<sizeans; i++){
		ans.A[i] = b.A[k];
		k++;
		ans.len++;	
	}
	for(int i=0; i<ans.len; i++){
		printf("%d ",ans.A[i]);
	}
	printf("\n");
	return;
}




