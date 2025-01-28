#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned u, v, w;
} Vertex;

#define TRUE 1
#define FALSE 0
#define MAXSIZE 200100

Vertex graph[MAXSIZE];
int parentArray[MAXSIZE];

int kruskal(int);
int findParent(int);
int compareEdges(Vertex *, Vertex *);

int main(int argc, char **argv) {
    int edges, vertices;

    while (scanf("%d %d", &edges, &vertices), edges && vertices) {
        int i;
        unsigned totalWeight = 0;
        for (i = 0; i < vertices; ++i) {
            scanf("%d %d %d", &graph[i].v, &graph[i].u, &graph[i].w);
            totalWeight += graph[i].w;
        }

        qsort(graph, vertices, sizeof(Vertex), compareEdges);

        for (i = 1; i <= edges; ++i)
            parentArray[i] = i;

        printf("%u\n", totalWeight - kruskal(vertices));

        memset(graph, 0, sizeof(graph));
        memset(parentArray, 0, sizeof(parentArray));
    }

    return 0;
}

int findParent(int node) {
    if (node == parentArray[node])
        return node;
    return findParent(parentArray[node]);
}

int kruskal(int vertexCount) {
    int i, vertex1, vertex2;
    unsigned answer = 0;

    for (i = 0; i < vertexCount; ++i) {
        vertex1 = findParent(graph[i].v);
        vertex2 = findParent(graph[i].u);

        if (vertex1 != vertex2) {
            parentArray[vertex1] = parentArray[vertex2];
            answer += graph[i].w;
        }
    }

    return answer;
}

int compareEdges(Vertex *a, Vertex *b) {
    return a->w - b->w;
}
