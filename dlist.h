#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next, *prev;
}node;


typedef struct list{
        node  *front, *rear;
}list;


void init(list*);
int isempty(list);
void insertright(list*, int);
void insertAtLeft(list *lst, int data);
void printlistLR(list );
void printlistRL(list );
int length(list );
void reverse(list *l);
void insertsorted(list *,int);
void remove_from_list_byvalue(list*, int);
void freelist(list*);
void sort(list*);
int search(list l, int);
int alternate_search(list , int );
node* Find_middle(list );
list listunion(const list, list);
 void removeDuplicates(list *l);          



