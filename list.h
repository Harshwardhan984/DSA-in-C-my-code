#include <stdbool.h>
typedef struct node{
    int data;
    struct node *next;
}node;

typedef node* list;

void init(list *head);
void insert_end(list *head, int d);
void insert_at_post(list *head, int p, int d);
void insert_beg(list *head,int d);
void delete_beg(list *head);
void delete_end (list *head);
void delet_at_index(list *head, int in);
void delete_by_value(list *head, int val);
void sort(list *head);
void traverse(list head);
bool cheak_if_present(list head, int d);
int len(list head);
node* findMiddle(list head);




