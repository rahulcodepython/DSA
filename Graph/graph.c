#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph
{
    int numVertices;
    int adjMatrix[MAX][MAX];
};

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void DFS(struct Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i])
        {
            DFS(graph, i, visited);
        }
    }
}

void BFS(struct Graph *graph, int startVertex)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front != rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int vertices, edges, src, dest, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter the edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int visited[MAX] = {0};

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("DFS Traversal: ");
    DFS(graph, startVertex, visited);
    printf("\n");

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    printf("BFS Traversal: ");
    BFS(graph, startVertex);
    printf("\n");

    return 0;
}