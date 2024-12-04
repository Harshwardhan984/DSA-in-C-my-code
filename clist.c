#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include <stdbool.h>
#include "clist.h"

// Function to initialize the circular linked list
void init_CLL(CLL *list) {
    *list = NULL;
}

// Function to insert an element at the beginning
void insert_beg(CLL *list, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    if(new_node)
    	new_node->data = data;
    else
    	return;
    if (*list == NULL) {
        new_node->next = new_node;
        *list = new_node;
    } else {
        node *temp = *list;
        while (temp->next != *list) {
            temp = temp->next;
        }
        new_node->next = *list;
        temp->next = new_node;
        *list = new_node;
    }
}

// Function to insert an element at the end
void insert_end(CLL *list, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    if(new_node)
    	new_node->data = data;
    else
    	return;
    if (*list == NULL) {
        new_node->next = new_node;
        *list = new_node;
    } else {
        node *temp = *list;
        while (temp->next != *list) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *list;
    }
}

// Function to insert an element at a specific position
void insert_pos(CLL *list, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    node *new_node = (node *)malloc(sizeof(node));
    if(new_node)
    	new_node->data = data;
    else
    	return;
    if (*list == NULL) {
        if (pos == 1) {
            new_node->next = new_node;
            *list = new_node;
        } else {
            printf("Position out of bounds.\n");
        }
        return;
    }
    if (pos == 1) {
        insert_beg(list, data);
        return;
    }
    node *temp = *list;
    int count = 1;
    while (count < pos - 1 && temp->next != *list) {
        temp = temp->next;
        count++;
    }
    if (count == pos - 1) {
        new_node->next = temp->next;
        temp->next = new_node;
    } else {
        printf("Position out of bounds.\n");
        free(new_node);
    }
}

// Function to remove the element at the beginning
void remove_beg(CLL *list) {
    if (*list == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (*list == (*list)->next) {
        free(*list);
        *list = NULL;
    } else {
        node *temp = *list;
        while (temp->next != *list) {
            temp = temp->next;
        }
        node *to_delete = *list;
        temp->next = (*list)->next;
        *list = (*list)->next;
        free(to_delete);
    }
}

// Function to remove the element at the end
void remove_end(CLL *list) {
    if (*list == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (*list == (*list)->next) {
        free(*list);
        *list = NULL;
    } else {
        node *temp = *list;
        node *prev = NULL;
        while (temp->next != *list) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *list;
        free(temp);
    }
}

// Function to remove an element at a specific position
void remove_pos(CLL *list, int pos) {
    if (*list == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        remove_beg(list);
        return;
    }
    node *temp = *list;
    node *prev = NULL;
    int count = 1;
    while (count < pos && temp->next != *list) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (count == pos) {
        if (temp->next == *list) {
            prev->next = *list;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    } else {
        printf("Position out of bounds.\n");
    }
}

// Function to sort the elements in the CLL
void sort(CLL *list) {
    if (*list == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *i, *j;
    int temp;
    for (i = *list; i->next != *list; i = i->next) {
        for (j = i->next; j != *list; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to display the elements in the CLL
void display(CLL list) {
    if (list == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = list;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != list);
    printf("\n");
}

//TO display after enter n as next in circular way
void display_bystep(CLL list){
	char *c;
	if (list == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = list;
    c = (char*)malloc(sizeof(char));
    while (temp != NULL) {
    	
    	scanf("%c", c);
    	if(*c == 'e')
        	break;
        printf("%d \n", temp->data);
        
        
        temp = temp->next;
        
    }
    free(c); 
    printf("\n");
}


//count total nodes of CLL
int totalnodes(CLL list) {
    if (list == NULL) {
        return 0;
    }

    int count = 1;
    node *temp = list;
    while (temp->next != list) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to reverse the circular linked list
void reverse(CLL *list) {
    if (*list == NULL || (*list)->next == *list) {
        return;  // List is empty or has only one node
    }

    node *prev = NULL, *current = *list, *next = NULL;
    //node *last = *list;

    // Traverse the list and reverse the links
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *list);

    // Fix the last node and the head
    (*list)->next = prev;
    *list = prev;
}

// Function to free all nodes in the circular linked list
void free_list(CLL *list) {
    if (*list == NULL) {
        return;
    }

    node *current = *list, *next;

    // Make the last node's next pointer NULL to stop looping
    while (current->next != *list) {
        next = current->next;
        free(current);
        current = next;
    }
    free(current);  // Free the last node
    *list = NULL;   // Set list to NULL after freeing
}

