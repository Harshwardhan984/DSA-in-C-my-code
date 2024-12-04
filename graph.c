#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include "graph.h"


// Function to initialize the graph with the specified number of vertices
void initGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = INT_MAX;  // Initialize with no edges
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest,int weight) {
    graph->adjMatrix[src][dest] = weight;
   // graph->adjMatrix[dest][src] = weight;  // For undirected graph
}

// Function to remove an edge from the graph
void removeEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 0;
   // graph->adjMatrix[dest][src] = 0;  // For undirected graph
}

// Function to print the adjacency matrix of the graph
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the vertex with the minimum distance

int findMin(int *dist, int *visited,int vertex){
	int min = INT_MAX, u = -1;
    for (int i = 0; i < vertex; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            u = i;
        }
    }
    return u;
}

// Dijkstra's algorithm

void Dijkstra(Graph *graph, int src){
	int vertices = graph->numVertices;
    int dist[vertices];    // Array to store shortest distances
    int visited[vertices]; // Array to mark visited vertices

    // Initialize distances and visited array
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0; // Distance to source is 0

    // Process all vertices
    for (int i = 0; i < vertices - 1; i++) {
        // Pick the minimum distance vertex
        int u = findMin(dist, visited, vertices);
        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && 
            	graph->adjMatrix[u][v] != INT_MAX &&
                dist[u] + graph->adjMatrix[u][v] < dist[v]) 
                {
                	dist[v] = dist[u] + graph->adjMatrix[u][v];
            }
        }
    }

    // Print the shortest distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

}
// Function to free memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
}

