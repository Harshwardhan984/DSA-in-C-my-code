#include <stdio.h>
#include "array1.h"
#include <stdbool.h>

int main() {
    int choice;
    array a;
    bool flag = true;
    printf("Menu:\n");
    printf("1.to append\n");
    printf("2.to insert_at_index\n");
    printf("3.to remove_at_index\n");
    printf("4.to display\n");
    printf("5.to_find_max\n");
    printf("6.to_find_min\n");
    printf("7.to_reverse-array\n");
    printf("8.to_merge_arrays\n");
    printf("9.to_get_random_array\n");
    printf("10.to initialise_array\n");
    printf("Enter 0 to exit\n");
    printf("\nWhen executing program for the first time , call init()\n");
    
  while(flag == true){	
    
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
    	  case 0:
    	  	printf("Out from array !\n");
            flag = false;
            break;
        case 1:
        	printf("The value to append is : \n");
        	int appendValue;
        	scanf("%d",&appendValue);
            append(&a,appendValue);
            break;
        case 2:
        	printf("Enter the index on which you have to insert : \n");
        	int insertIndex,insertValue;
        	scanf("%d",&insertIndex);
        	printf("Enter the value which you have to insert : \n");
        	scanf("%d",&insertValue);
            insert_at_index(&a,insertIndex,insertValue);
            
            break;
        case 3:
        	printf("Enter the index from which you have to remove : \n");
        	int removeIndex;
        	scanf("%d",&removeIndex);
            int removed_val = remove_at_index(&a,removeIndex);
            printf("%d removed successfully\n",removed_val);
            break;
        case 4:
        	printf("The elements in the array are : \n");
            display(a);
            break;
        case 5:
            printf("Maximum element in the array is : %d\n",max(a));
            break;
        case 6:
            printf("Minimum element in the array is : %d\n",min(a));
            break;
        case 7:
            reverse(&a);
            printf("The reversed array is :\n");
            display(a);
            break;
        case 8:
        	printf("Enter the size of new array : \n");
        	int newsize;
        	scanf("%d",&newsize);
            merge(a,newsize);
            break;  
        case 9:
            rd(&a);
            printf("Random array generated successfully\n"); 
            break;       
        case 10:
        	printf("Enter the size of array : \n");
        	int size;
        	scanf("%d",&size);
            init(&a,size);
            printf("Array initialised successfully\n");
            break;                        
        default:
            printf("Invalid choice!\n");
    }
 }   

    return 0;
}
