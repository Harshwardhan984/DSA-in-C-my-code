#include <stdio.h>
#include "graph.h"

int main() {
    int vertices = 5;
    
    // Initialize graph structure
    Graph g;
    initGraph(&g, vertices);

    // Add edges
    addEdge(&g, 0, 1, 4);
    addEdge(&g, 0, 2, 1);
    addEdge(&g, 2, 1, 2);
    addEdge(&g, 1, 3, 1);
    addEdge(&g, 2, 3, 5);
    addEdge(&g, 3, 4, 3);

    // Display the graph
    displayGraph(&g);
    printf("Dijkstra's Algorithm Result:\n");
    Dijkstra(&g, 0);
    // Free the allocated memory
    freeGraph(&g);

    return 0;
}

