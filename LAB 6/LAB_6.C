// 6. Compare the performance of Dijkstra and Bellman ford algorithm for the single source shortest path problem.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define INF 99999

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Bellman-Ford Algorithm
void BellmanFord(int V, int E, struct Edge edge[], int src) {
    int dist[V];
    
    // Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int weight = edge[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edge[i].src;
        int v = edge[i].dest;
        int weight = edge[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle\n");
    }

    // Print distances
    printf("Bellman-Ford: Distances from source:\n");
    for (int i = 0; i < V; i++)
        printf("%d\t", dist[i]);
    printf("\n");
}

// Dijkstra Algorithm using adjacency matrix
void Dijkstra(int graph[10][10], int V, int src) {
    int dist[V], visited[V];

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int min = INF, min_index;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }

        visited[min_index] = 1;

        // Update distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[min_index][v] && dist[min_index] != INF && dist[min_index] + graph[min_index][v] < dist[v])
                dist[v] = dist[min_index] + graph[min_index][v];
    }

    // Print the distance array
    printf("Dijkstra: Distances from source:\n");
    for (int i = 0; i < V; i++)
        printf("%d\t", dist[i]);
    printf("\n");
}

int main() {
    int V = 5, E = 8;

    // Graph for Bellman-Ford
    struct Edge edge[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, 
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    // Graph for Dijkstra (adjacency matrix)
    int graph[10][10] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    // Measure time for Bellman-Ford Algorithm
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    BellmanFord(V, E, edge, 0);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Bellman-Ford: %f seconds\n", cpu_time_used);

    // Measure time for Dijkstra Algorithm
    start = clock();
    Dijkstra(graph, V, 0);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Dijkstra: %f seconds\n", cpu_time_used);

    return 0;
}

