// Define a structure for the Graph
typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;

void initGraph(Graph* graph, int vertices);
void addEdge(Graph* graph, int src, int dest,int weight);
void removeEdge(Graph* graph, int src, int dest);
int findMin(int *dist, int *visited,int vertex);
void Dijkstra(Graph *graph, int src);
void displayGraph(Graph* graph);
void freeGraph(Graph* graph);
