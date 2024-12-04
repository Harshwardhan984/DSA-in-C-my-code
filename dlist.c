#include<stdio.h>
#include<stdlib.h>
#include "dlist.h"


void init(list *l){
    l->front = NULL;
    l->rear = NULL;
}


int isempty(list l){
    if(l.front ==NULL)
         return 1;
    return 0;
}



void insertright(list *l, int d) {
  node *newnode = (node*)malloc(sizeof(node));
  newnode->next =NULL;
  newnode->prev =NULL;
  newnode->data =d;
  if(!isempty(*l)){
     node *temp = l->front;
     while(temp->next!=NULL)
            temp = temp->next;
     temp->next = newnode;
     newnode->prev = temp;
     l->rear = newnode;
  }
  else{
     l->front = newnode;
     l->rear = newnode;
  }
}

void insertAtLeft(list *lst, int data) {
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode){
    	newNode->data = data;
    	newNode->next = lst->front;
    	newNode->prev = NULL;
    }
    else
    	return;

    if (lst->front != NULL) {
        lst->front->prev = newNode;
    }
     else {
        lst->rear = newNode;  
    }
    lst->front = newNode;
    return;
}



void printlistLR(list l) {    
    node *p;
    printf("Fwd: [ ");
    p = l.front;
    if(!p) {
        printf("]\n");
        return;
    }
    do {
        printf("%d ", p->data);
        p = p->next;
    }while(p != NULL);
    printf("]\n");
}

void printlistRL(list l) {
    node *p;
    printf("BWD: [ ");
    p = l.rear;
    printf("%d ", p->data);
    if(!p) {
        printf("]\n");
        return;
    }
    do {
        printf("%d ", p->data);
        p = p->prev;
    }while(p != NULL);
    printf("]\n");


}

int length(list l){
       int count =0 ;
       node*p = l.rear;
       while(p){
             count++;
             p = p->prev;
    }
    return count;
}


void reverse(list *l){
   node  *p1, *p2;
   int temp;
   p1 = l->front; 
   p2 = l->rear;
   
   while(p1!=p2 && p2 != p1->prev){
        temp = p1->data;
        p1->data = p2->data;
        p2->data = temp;
        p1=p1->next;
        p2=p2->prev;
   }
  
}



void insertsorted(list *l,int d){
	node *newnode = (node*)malloc(sizeof(node));
        newnode->next =NULL;
        newnode->prev =NULL;
        newnode->data =d;
        if(isempty(*l)){
	    l->front=newnode;
            l->rear = newnode;
            return;
        }
        node *p = l->front;
        while(p->data<d && p->next !=NULL)
             p= p->next;
        
        if(p== l->front){
           l->front = newnode;
           newnode->next = p;
           p->prev = newnode;
           return;
        }        
        
        if(p == l->rear && p->data < d){
            l->rear =newnode;
            p->next = newnode;
            newnode->prev = p;
            return;
         }

         p=p->prev;
         printf("\n%d",p->data);
         newnode->next = p->next;
         p->next = newnode;
         newnode->prev = p;
         //p->next = newnode;
        
}


void remove_from_list_byvalue(list *l, int d){
       if(isempty(*l))
            return;
       node *p = l->front;
       while(p->data!=d && p->next)
          p= p->next;
       if(p->data == d){
              p->prev->next = p->next;
              p->next->prev = p->prev;
              free(p);
       }
}


void freelist(list *l){
      node *p = l->front;
      node * q;
      while(p){
        q= p;
        p=p->next;
        free(q);
     }
     l->front =NULL;
     l->rear =NULL;
}

void sort(list *l){
 	node *p1 =l->front;
 	node *temp=NULL;
 	int x;
 	if(!p1)
	   return;
 	node *p2 = p1->next;
  	while(p2){
      		temp = p1;  
      		x = p2->data;
      		while(temp && temp->data>x){
        		 temp->next->data =temp->data;
        		 temp = temp->prev;
      		}
      		if(!temp)
        		l->front->data =x; 
      
      		else
        		temp->next->data =x;
      		p2=p2->next;
      		p1=p1->next;
	}

}


int search(list l, int d){
     node *ptr = l.front;
     
     while(ptr  && ptr->data != d)
             ptr=ptr->next;
     if(!ptr)
        return 0;  
     else
        return 1;
}

int alternate_search(list l, int d){
	node *p = l.front, *q = l.rear;
	while(p || q){
		
		if(p->data == d)
			return 1;
		else
			p = p->next;
		if(q->data == d)
			return 1;
		else
			q = q->prev;
		if(p == q)
			return 0;
		if(q -> next == p)
			return 0;
		
	}
	return 0;
}

node* Find_middle(list l){
	node *p = l.front, *q = l.rear;
	
	while(p || q){
		if(q->next == p)
			return NULL;
		printf("p is %d  q is %d \n", p->data,q->data);
		if(p == q)
			return p;
		
		p = p->next;
		q = q->prev;
	}
	return NULL;
}


list listunion(const list l1, list l2){ 
       list l3;
       init(&l3);
       node* ptr1= l1.front;
       while(ptr1){
              insertright(&l3, ptr1->data);
              ptr1=ptr1->next;
       }
       
       node* ptr2 = l2.front;
       while(ptr2){
            if(!search(l3,ptr2->data)){
                 insertright(&l3, ptr2->data);
                 
            }
            ptr2=ptr2->next;
       }
                   
       return l3;
}
            
void removeDuplicates(list *l) {
    node *current = l->front;

    while (current != NULL) {
        node *runner = current->next;
        while (runner != NULL) {
            if (runner->data == current->data) {
                node *temp = runner;
                runner = runner->next;
                if (temp->next != NULL)
                	 temp->next->prev = temp->prev;
                if (temp->prev != NULL) 
                	temp->prev->next = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
    return;
}




