
#include<stdio.h>
#include "clist.h"
#include <stdbool.h>
   
// Main function to demonstrate the usage of Circular Linked List functions
int main() {
    CLL L1;
    init_CLL(&L1);

    insert_beg(&L1, 10);
    insert_beg(&L1, 20);
    insert_end(&L1, 30);
    insert_end(&L1, 40);

    printf("List after insertions at beginning and end:\n");
    display(L1);

    insert_pos(&L1, 25, 2);
    printf("List after insertion at position 2:\n");
    display(L1);

    remove_beg(&L1);
    printf("List after removing from beginning:\n");
    display(L1);

    remove_end(&L1);
    printf("List after removing from end:\n");
    display(L1);

    remove_pos(&L1, 2);
    printf("List after removing from position 2:\n");
    display(L1);

    sort(&L1);
    printf("List after sorting:\n");
    display(L1);
    
    insert_beg(&L1, 10);
    insert_beg(&L1, 20);
    insert_end(&L1, 30);
    insert_end(&L1, 40);

    printf("List after insertions at beginning and end:\n");
    display(L1);
    
    
    printf(" %d\n",totalnodes(L1));
    
    display(L1);
    reverse(&L1); 
    display(L1);
    
    
    printf("printting cll by step enter n to next and e to end list\n");
    display_bystep(L1);
    
    
    free_list(&L1); 

    return 0;
}

