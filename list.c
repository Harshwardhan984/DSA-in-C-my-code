#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include <stdbool.h>
#include "list.h"

void init(list *head) {
    *head = NULL;
    return;
}

/*Insert at end*/
void insert_end(list *head, int d){
    node *p, *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    if(*head == NULL){
        *head = newnode;
        return;
    }
    p = *head;
    while(p -> next) {
       p = p->next;
    }
    p->next = newnode;
    return;
}

/*Insert at beginning*/
void insert_beg(list *head, int d){
    node  *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    newnode->next = *head;
    *head = newnode;
    return;
}

// Insert at given p position
void insert_at_post(list *head, int ps, int d){
    node  *newnode, *p, *q;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        
    }
    else return;
    if(ps<=1)
    	return;
    int i=1;
    p = *head;
    q = p->next;
    while(i < ps-1) {
       p = p->next;
       q = q->next;
       i++;
    }
    newnode->next = q;
    p->next = newnode;
    return;
}

/*Deletes node at beginning*/
void delete_beg(list *head)
{
  node *p = *head;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
      return;

  // move head to next node
  *head = (*head)->next;
  free(p);
  return;
}

// Delete last node.
void delete_end (list *head)
{
  node *p = *head;
  node *q;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
  	return;

  // if Linked List has only 1 node
  if (p-> next == NULL){
      *head = NULL;
      return;
    }

  // else traverse to the last node
  while (p->next != NULL)
    {
      // store previous link node as we need to change its next val
      q = p;
      p = p->next;
    }
  // Curr assign 2nd last node's next to Null
  q->next = NULL;
  // delete the last node
  free (p);
  // 2nd last now becomes the last node
  return;
}

// Delete at given index in
void delet_at_index(list *head, int in){
	if(*head == NULL)
		return;
	node *p = *head;
	node *q = p->next;
	int count = 1;
	if(in == 0){
		*head = (*head)->next;
  		free(p);
  		return;
	}
	while(p->next != NULL){
		if(count == in)
			break;
		p = p->next;
		q = q->next;
		count++;
	}
	p->next = q->next;
	free(q);
	return;
}

//Delete the node of given data
void delete_by_value(list *head, int val){
	if(*head == NULL)
		return;
	node *p = *head;
	node *q = p->next;
	if(val == p->data){
		*head = (*head)->next;
  		free(p);
  		return;
	}
	while(p->next != NULL){
		if(val == q->data){
			break;
		}
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	free(q);
	return;
}


// Displays linked list contents.
void traverse(list head){
    printf("[");
    node *p;
    p = head;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
    return;
}

// Sort Linked List in ass order
void sort(list *head){
	node  *r = *head;
	int tem;
	while(r->next){
	//printf("inside of out loop\n");
		node  *p  = *head;
		node *q = p->next;
		while(p->next){
		if(p->data > q->data){
			tem = p->data;
			p->data = q->data;
			q->data = tem;
		}
		p = p->next;
		q = q->next;
		}
	r = r->next;
	}
	return;
}

//Cheak if given number d is in list
bool cheak_if_present(list head, int d){
	 node *p;
    p = head;
    while(p){
        if(p->data == d)
        return true;
        p = p->next;
    }
    return false;
}

//return length of list
int len(list head){
	int ans=0;
	node *p;
	 p = head;
    while(p){
    ans++;
    p = p->next;
    }
	return ans;
}

node* findMiddle(list head) {
    if (head == NULL) return NULL;

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}






