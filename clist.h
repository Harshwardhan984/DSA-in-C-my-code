

// Define the structure for the node
typedef struct node {
    int data;
    struct node *next;
} node;

typedef node* CLL;  // Define CLL as a pointer to a node

// Function prototypes
void init_CLL(CLL *list);
void insert_beg(CLL *list, int data);
void insert_end(CLL *list, int data);
void insert_pos(CLL *list, int data, int pos);
void remove_beg(CLL *list);
void remove_end(CLL *list);
void remove_pos(CLL *list, int pos);
void sort(CLL *list);
void display(CLL list);
void display_bystep(CLL list);
int totalnodes(CLL list) ;
void reverse(CLL *list);
void free_list(CLL *list) ;
