
#include<stdio.h>
#include "list.h"
#include <stdbool.h>

int main(){
    list L1;
    init(&L1);
    
    insert_end(&L1, 1);
    insert_end(&L1, 2);
    insert_end(&L1, 3);
    insert_end(&L1, 4);
    traverse(L1);
    printf("\n");
    insert_beg(&L1,7);
    traverse(L1);
    printf("\n");
    delete_beg(&L1);
    traverse(L1);
    printf("\n");
    delete_end(&L1);
    traverse(L1);
   printf("\n");
   printf("%d\n", len(L1));
   insert_end(&L1, 1);
    insert_end(&L1, 2);
    insert_end(&L1, 3);
    insert_end(&L1, 4);
    insert_end(&L1, 5);
   traverse(L1);
   printf("\n");
   insert_at_post(&L1, 3, 11);
   traverse(L1);
   printf("\n");
   delete_by_value(&L1, 3);
    traverse(L1);
   printf("\n");
   delet_at_index(&L1, 2);
    traverse(L1);
   printf("\n");
   insert_at_post(&L1, 3, 11);
   traverse(L1);
   printf("\n");
   sort(&L1);
   traverse(L1);
   printf("\n");
   printf("%d\n", len(L1));
   printf("%d\n",cheak_if_present(L1, 5));
   printf("%d\n",findMiddle(L1)->data);
    return 0;
}
