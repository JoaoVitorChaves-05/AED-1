#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int node1, node2, weight;
} Edge;

#define MAX_NODES 600
#define MAX_EDGES (((MAX_NODES) * (MAX_NODES - 1)) >> 1)

int parent[MAX_NODES];
int size[MAX_NODES];
Edge edges[MAX_EDGES];

int find_parent(int);
int kruskal_algorithm(int);
void swap_values(int *, int *);
int compare_edges(const void *, const void *);

int main(int argc, char **argv)
{
    int nodes, edges_count, additional_value;
    int node1, node2, weight;

    scanf("%d %d %d", &nodes, &edges_count, &additional_value);

    for (int i = 0; i < edges_count; ++i)
        scanf("%d %d %d", &edges[i].node1, &edges[i].node2, &edges[i].weight);

    for (int i = 0; i <= nodes; ++i)
        parent[i] = i, size[i] = 1;

    qsort(edges, edges_count, sizeof(Edge), compare_edges);

    printf("%d\n", kruskal_algorithm(edges_count));

    return 0;
}

int compare_edges(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

inline void swap_values(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_parent(int node)
{
    if (node == parent[node])
        return node;
    else
        return parent[node] = find_parent(parent[node]);
}

int kruskal_algorithm(int edge_count)
{
    int total_weight = 0;
    for (int i = 0; i < edge_count; ++i)
    {
        int root1 = find_parent(edges[i].node1);
        int root2 = find_parent(edges[i].node2);

        if (root1 != root2)
        {
            if (size[root1] > size[root2])
                swap_values(&root1, &root2);

            parent[root1] = root2;
            size[root2] += size[root1];

            total_weight += edges[i].weight;
        }
    }

    return total_weight * 2;
}
