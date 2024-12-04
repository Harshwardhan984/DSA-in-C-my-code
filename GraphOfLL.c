// Graph using adt LIsts


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

//stack

typedef struct {
    int* items;
    int top;
    int size;
} Stack;

void initStack(Stack* stack, int size) {
    stack->top = -1;
    stack->size = size;
    stack->items = (int*)malloc(sizeof(int) * size);


}

bool isEmptys(Stack* stack) {
    return stack->top == -1;
}

bool isFulls(Stack* stack) {
    return stack->top == stack->size - 1;
}

void push(Stack* stack, int item) {
    if (isFulls(stack)) {
        //printf("Stack is full\n");
        return;
    }
    stack->items[++(stack->top)] = item;
}

int pop(Stack* stack) {
    if (isEmptys(stack)) {
        //printf("Stack is empty\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

int peek(Stack* stack) {
    if (isEmptys(stack)) {
        //printf("Stack is empty\n");
        return -1;
    }
    return stack->items[stack->top];
}

//queue

typedef struct {
    int* items;
    int size;
    int front, rear;
} Queue;

// Initialize the queue with a given size
void initQueue(Queue* queue, int size) {
    queue->size = size;
    queue->items = (int*)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
bool isEmptyq(Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
bool isFullq(Queue* queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

// Add an element to the queue (enqueue)
void enqueue(Queue* queue, int item) {
    if (isFullq(queue)) {
        //printf("Queue is full\n");
        return;
    }

    if (isEmptyq(queue)) {
        queue->front = 0;  // Set front to 0 if the queue is empty
    }

    queue->rear = (queue->rear + 1) % queue->size;  // Circular increment of rear
    queue->items[queue->rear] = item;
}

// Remove an element from the queue (dequeue)
int dequeue(Queue* queue) {
    if (isEmptyq(queue)) {
        //printf("Queue is empty\n");
        return -1;
    }

    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        // Queue is now empty, reset front and rear
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;  // Circular increment of front
    }

    return item;
}

// Graph Functions

typedef struct node
{
    int ver, wt;
    struct node *next;
}node;

typedef struct graphLisk
{
    int vertexs;
    node** arroflist;
}graphLisk;

void initGraph(graphLisk*  g, int vertx){
    g->vertexs = vertx;
    g->arroflist = (node**)malloc(sizeof(node*) * g->vertexs);
    int i;
    for(i = 0; i < g->vertexs; i++){
        g->arroflist[i] = NULL;
    }
    return;
}

node * creatnode(int index){
    node* nn = (node*)malloc(sizeof(node));
    nn->ver = index;
    nn->wt = INT_MAX;
    nn->next = NULL;
    return nn;
}
node * creatnodeWT(int index, int wt){
    node* nn = (node*)malloc(sizeof(node));
    nn->ver = index;
    nn->wt = wt;
    nn->next = NULL;
    return nn;
}

void addvertex(graphLisk * g, int scr, int dess){
    node * forscr = creatnode(dess);
    forscr->next = g->arroflist[scr-1];
    g->arroflist[scr-1] = forscr;

    node* fordess = creatnode(scr);
    fordess->next = g->arroflist[dess - 1];
    g->arroflist[dess - 1] = fordess;

    return;
}

void addvertexwithWT(graphLisk * g, int scr, int dess, int wt){
    node * forscr = creatnodeWT(dess, wt);
    forscr->next = g->arroflist[scr - 1];
    g->arroflist[scr - 1] = forscr;

    node* fordess = creatnodeWT(scr, wt);
    fordess->next = g->arroflist[dess - 1];
    g->arroflist[dess - 1] = fordess;

    return;
}

void deletnode(node** headAD, int d){
    if(*headAD == NULL)
        return;
       node * head = *(headAD);
    if(head->ver == d){
    	//printf("in con\n");
        node* tem = *(headAD);
        *(headAD) = tem->next;
        free(tem);
        return;
    }
    else{
        node* p = *(headAD);
        node* q = p->next;
        while(q && q->ver != d){
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
        return;
    }
}

void removeVertex(graphLisk* g, int scr, int dess){
    //remove from scr

    deletnode(&(g->arroflist[scr-1]), dess);

    //remove from dess

    deletnode(&(g->arroflist[dess-1]), scr);

    return;
}

void freeGraph(graphLisk *g){
	int i;
	for(i = 0; i < g->vertexs; i++){
		node* p = g->arroflist[i];
		while(p){
			node *tem = p->next;
			free(p);
			p = tem;
		}
		g->arroflist[i] = NULL;
	}
	
	free(g->arroflist);
	
	return;
}

void BFS(graphLisk g, int ver){
    Queue q;
    initQueue(&q, g.vertexs);
	
	 int* visited = (int*)calloc(g.vertexs, sizeof(int)); //set all to zero
	
    int *bfs = (int*)malloc(sizeof(int) * g.vertexs);
    int sbfs = 0;

    int n = ver;

    enqueue(&q, n);
    visited[ver - 1] = 1;
    bfs[sbfs] = n;
    sbfs++;

    while (!isEmptyq(&q)) {
        int n = dequeue(&q);
        node* p = g.arroflist[n - 1];  // Access adjacency list for vertex `n`

        while (p != NULL) {
            if (!visited[p->ver - 1]) {
                enqueue(&q, p->ver);
                visited[p->ver - 1] = 1;  // Mark the node as visited
                bfs[sbfs++] = p->ver;     // Add to BFS result
            }
            p = p->next;
        }
    }

    // Print BFS result
    for (int i = 0; i < sbfs; i++) {
        printf("%d", bfs[i]);
        if (i < sbfs - 1) {
            printf(" -> ");
        }
    }
    printf("\n");

    free(visited);
    free(bfs);
    return;

}

void DFS(graphLisk g, int ver){
	Stack s;
	initStack(&s, g.vertexs);
	int* visited = (int*)calloc(g.vertexs + 1, sizeof(int)); //set all to zero
	
    int *dfs = (int*)malloc(sizeof(int) * g.vertexs);
    int sdfs = 0;

    int n = ver;
    
    push(&s, n);
    visited[n] = 1;
    
    while(!isEmptys(&s)){
    	n = pop(&s);
    	dfs[sdfs] = n;
    	sdfs++;
    
    	node* p = g.arroflist[n - 1]; 
    	while (p != NULL) {
            if (!visited[p->ver]) {
                push(&s, p->ver);       // Push unvisited neighbor onto stack
                visited[p->ver] = 1;    // Mark it as visited
            }
            p = p->next;
        }
    }

	// Print DFS result
    for (int i = 0; i < sdfs; i++) {
        printf("%d", dfs[i]);
        if (i < sdfs - 1) {
            printf(" -> ");
        }
    }
    printf("\n");

    free(visited);
    free(dfs);
    return;


}

int Cheakifcircular(graphLisk g, int ver){
	Stack s;
	initStack(&s, g.vertexs);
	int* visited = (int*)calloc(g.vertexs + 1, sizeof(int)); //set all to zero
	 int* parent = (int*)calloc(g.vertexs + 1, sizeof(int));

     push(&s, ver);
    visited[ver] = 1;
    parent[ver] = -1;  // Root node has no parent

    while (!isEmptys(&s)) {
        int current = pop(&s);
        node* adj = g.arroflist[current - 1];
        
        while (adj != NULL) {
            int neighbor = adj->ver;
            if (!visited[neighbor]) {
                push(&s, neighbor);
                visited[neighbor] = 1;
                parent[neighbor] = current; // Set parent
            } 
            else if (parent[current] != neighbor) {
                // Cycle detected if revisiting node that's not parent
                free(visited);
                free(parent);
                
                return 1;
            }
            adj = adj->next;
        }
    }
    
    free(visited);
    free(parent);
    
    return 0;
}

/*
A Minimum Spanning Tree (MST) is a subset of edges in a weighted, connected, 
undirected graph that connects all the vertices with the minimum total edge weight, without forming any cycles.

Key Properties of MST
Spanning Tree:

A spanning tree of a graph connects all vertices with exactly 

V−1 edges (where 

V is the number of vertices).
It does not contain any cycles.
Minimum Total Weight:

Among all possible spanning trees, the MST has the smallest possible sum of edge weights.
Unique or Multiple MSTs:

If all edge weights are distinct, the MST is unique.
If there are multiple edges with the same weight, there can be more than one valid MST.

*/

void prims(graphLisk g, int ver){
	int totalver = g.vertexs;
	int start = ver - 1;
	int* vis = (int*)calloc(totalver, sizeof(int));


    int minwt = INT_MAX, u = start, v;

    int* MST[2];

    MST[0] = (int*)calloc(totalver - 1 , sizeof(int));
    MST[1] = (int*)calloc(totalver - 1 , sizeof(int));
	
	node *q = g.arroflist[u];
	while(q){
		if(q->wt < minwt){
			minwt = q->wt;
			v = q->ver - 1;
		}
		q = q->next;
	}
	MST[0][0] = u;
	MST[1][0] = v;
	vis[u] = 1;
	vis[v] = 1;
	
	int i;
	for(i = 1; i < totalver - 1; i++){
		minwt = INT_MAX;
		for(int j = 0; j < totalver; j++){
			if(vis[j] == 1){
				node *p = g.arroflist[j];
				while(p){
					if(vis[p->ver - 1] != 1 && p->wt < minwt){
						minwt = p->wt;
						u = j;
						v = p->ver - 1;
					}
					p = p->next;
				}
			}
		}
		MST[0][i] = u;
		MST[1][i] = v;
		vis[v] = 1;
	
	}
	
	for(int i=0; i < totalver-1; i++)
        printf("%d -> %d\n", MST[0][i] + 1, MST[1][i] +1);
        
    free(vis);
    free(MST[0]);
    free(MST[1]);
	

}

/*
void prims(graphLisk g, int ver) {
    int totalver = g.vertexs;
    int* vis = (int*)calloc(totalver, sizeof(int));  // Visited array
    int* MST[2];  // To store edges in MST
    MST[0] = (int*)malloc((totalver - 1) * sizeof(int));
    MST[1] = (int*)malloc((totalver - 1) * sizeof(int));

    int edgeCount = 0;
    int minwt, u, v;

    // Start from the given vertex
    vis[ver - 1] = 1;  // Convert to 0-based indexing

    while (edgeCount < totalver - 1) {
        minwt = INT_MAX;
        u = -1;
        v = -1;

        // Explore all visited vertices
        for (int i = 0; i < totalver; i++) {
            if (vis[i] == 1) {  // If vertex is visited
                node* p = g.arroflist[i];
                while (p) {
                    if (!vis[p->ver - 1] && p->wt < minwt) {  // Unvisited neighbor with smaller weight
                        minwt = p->wt;
                        u = i;
                        v = p->ver - 1; // Convert to 0-based indexing
                    }
                    p = p->next;
                }
            }
        }

        if (u != -1 && v != -1) {  // Valid edge found
            MST[0][edgeCount] = u;
            MST[1][edgeCount] = v;
            vis[v] = 1;  // Mark the vertex as visited
            edgeCount++;
        } else {
            printf("Graph might be disconnected. MST cannot be formed.\n");
            break;
        }
    }

    // Print the MST
    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("%d -> %d\n", MST[0][i] + 1, MST[1][i] + 1);  // Convert to 1-based indexing
    }

    // Free allocated memory
    free(vis);
    free(MST[0]);
    free(MST[1]);
}
*/

/*
Dijkstra's Algorithm (Short Explanation)
Purpose:
Finds the shortest path from a source node to all other nodes in a graph with non-negative weights.

Steps:

Initialize:

Set all distances to infinity (INF) except the source, which is 0.
Use a priority queue to store nodes by their distance.
Process:

Pick the closest unvisited node.
Update distances to its neighbors if a shorter path is found through it.
Mark the node as visited.

Repeat:
Continue until all nodes are visited or the queue is empty.

*/

int findminfromdis(int vertexs, int* vis, int* dis){
	int i, min = INT_MAX, v;
	for(i = 0; i < vertexs; i++){
		if(vis[i] != 1 && dis[i] < min){
			min = dis[i];
			v = i;
		}
	}
	return v;
}

void Dijkstras(graphLisk g, int ver){
	int totalver = g.vertexs;
	int start = ver - 1;
	int* dis = (int*)malloc(sizeof(int) * totalver);
	int* vis = (int*)calloc(totalver, sizeof(int));
	
	for(int i = 0; i < totalver; i++){
		dis[i] = INT_MAX;
	}
	
	dis[start] = 0;
	int donever = 0;
	while(donever < totalver - 1){
		int mindisver = findminfromdis(totalver, vis, dis);
		node *p = g.arroflist[mindisver];
		while(p){
			if(vis[p->ver - 1] != 1 && dis[p->ver - 1] > dis[mindisver] + p->wt){
				dis[p->ver - 1] = dis[mindisver] + p->wt;
			}
			p = p->next;
			}
		vis[mindisver] = 1;
		donever++;
	}
	
	printf("shortest dis from %d of following ver is:\n",ver);
	for(int i = 0; i < totalver; i++){
		printf("%d -> %d\n",i+1,dis[i]);
	}
	
	free(dis);
	free(vis);
	
}

void PrintShortPath(graphLisk g, int scr, int dess){
	int totalver = g.vertexs;
	int start = scr - 1;
	int* dis = (int*)malloc(sizeof(int) * totalver);
	int* vis = (int*)calloc(totalver, sizeof(int));
	
	
	int* parent = (int*)calloc(totalver + 1, sizeof(int));
	
	
	for(int i = 0; i < totalver; i++){
		dis[i] = INT_MAX;
	}
	
	dis[start] = 0;
	int donever = 0;
	while(donever < totalver - 1){
		int mindisver = findminfromdis(totalver, vis, dis);
		node *p = g.arroflist[mindisver];
		while(p){
			if(vis[p->ver - 1] != 1 && dis[p->ver - 1] > dis[mindisver] + p->wt){
				dis[p->ver - 1] = dis[mindisver] + p->wt;
				parent[p->ver] = mindisver + 1;
			}
			p = p->next;
			}
		vis[mindisver] = 1;
		donever++;
	}
	
	Stack s;
	initStack(&s, g.vertexs);
	int i = dess;
	while(i != 0){
		push(&s, i);
		i = parent[i];
	}
	
	while(!isEmptys(&s))
		printf("%d -> ", pop(&s));
	printf("\n");
	
	free(dis);
	free(vis);
	free(parent);
	return;
	
}


void printlist(node* p){
    node * q = p;
    while(q){
        printf("%d ", q->ver);
        if(q->wt != INT_MAX)
        	printf("(%d) --> ",q->wt);
        else
        	printf("--> ");
        q = q->next;
    }
    return;
}

void printgraph(graphLisk g){
    int i;
    for(i = 0; i < g.vertexs; i++){
        printf("%d == ", i+1);
        printlist(g.arroflist[i]);
        printf("\n");
    }
    return;
}

int main() {
    graphLisk G;
    initGraph(&G, 10);

/*
    addvertex(&G, 1, 3);
    addvertex(&G, 8, 9);
    addvertex(&G, 2, 5);
    addvertex(&G, 1, 8);
    addvertex(&G, 1, 2);
    addvertex(&G, 6, 7);
    addvertex(&G, 2, 3);
    //addvertex(&G, 4, 3);
    //addvertex(&G, 9, 7);
*/

    addvertexwithWT(&G, 1, 3, 12);
    addvertexwithWT(&G, 8, 9, 45);
    addvertexwithWT(&G, 2, 5, 54);
    addvertexwithWT(&G, 1, 8, 10);
    addvertexwithWT(&G, 1, 2, 15);
    addvertexwithWT(&G, 6, 7, 4);
    addvertexwithWT(&G, 2, 3, 9);
    addvertexwithWT(&G, 4, 3, 34);
    addvertexwithWT(&G, 9, 7, 25);
    addvertexwithWT(&G, 10, 7, 17);


/*
  int i, j;
    for(i = 0; i < 999; i++){
     for(j = i; j < 1000; j++){
         addvertexwithWT(&G,i+1,j+1,i+j);
      }
    }
*/
/*
// this will form square like chess
	int i, j;
	for(i = 1; i < 100; i = i + 10){
		for(j = i; j < i + 10; j++){
		if(j < i + 9)
		addvertexwithWT(&G, j, j + 1, 10);
		if(j + 10 <= 100)
		addvertexwithWT(&G, j, j + 10, 10);
	}
	}
*/
    printgraph(G);
	/*
    removeVertex(&G, 1, 3);
    removeVertex(&G, 2, 5);
   removeVertex(&G, 1, 2);
    removeVertex(&G, 4, 3);
    removeVertex(&G, 8, 1);
    removeVertex(&G, 9, 7);
    removeVertex(&G, 2, 3);
    removeVertex(&G, 6, 7);
    removeVertex(&G, 8, 9);
    */
	printf("%d\n",Cheakifcircular(G,1));
	
	prims(G, 9);
	
	Dijkstras(G, 4);
	PrintShortPath(G, 4, 6);
	
      //printgraph(G);

    BFS(G, 1);
    DFS(G, 1);
	freeGraph(&G);
    return 0;
}


