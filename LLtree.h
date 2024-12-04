typedef struct node{
    int data;
    struct node *lchild;
    struct node  *rchild;
}node;


// stack
// Define the structure for a stack node
typedef struct StackNode {
    node* data;  // Pointer to tree node
    struct StackNode* next;
} StackNode;

// Define the structure for the stack
typedef struct Stack {
    StackNode* top;
} Stack;

void initStack(Stack* s);
void push(Stack* s, node* node);
int isEmpty(Stack* s);
node* pop(Stack* s);
node* peek(Stack* s);




// Tree(BST) using LL


typedef struct node* BST;

void init_BST(BST *t);
void insert_bstree(BST *t, int d);
BST createNode(int d);
BST recursive_insert(BST *t, int d);
void preorder(BST t);
void non_recursive_preorder(BST t);
void inorder(BST t);
void non_recursive_inorder(BST t);
void postorder(BST t);
void non_recursive_postorder(BST t);
