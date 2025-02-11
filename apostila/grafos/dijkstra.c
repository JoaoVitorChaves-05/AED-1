#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertice, peso;
    struct Node* proximo;
} Node;

typedef struct {
    Node* listaAdj[MAX_VERTICES];
} Grafo;

typedef struct {
    int vertice, distancia;
} HeapNode;

typedef struct {
    HeapNode* array[MAX_VERTICES];
    int tamanho;
} MinHeap;

Grafo* criarGrafo(int vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    for (int i = 0; i < vertices; i++)
        grafo->listaAdj[i] = NULL;
    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino, int peso) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->vertice = destino;
    novoNode->peso = peso;
    novoNode->proximo = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNode;
}

MinHeap* criarMinHeap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->tamanho = 0;
    return heap;
}

void inserirMinHeap(MinHeap* heap, int vertice, int distancia) {
    HeapNode* novo = (HeapNode*)malloc(sizeof(HeapNode));
    novo->vertice = vertice;
    novo->distancia = distancia;
    heap->array[heap->tamanho++] = novo;
}

HeapNode* removerMinHeap(MinHeap* heap) {
    if (heap->tamanho == 0) return NULL;
    int minIndex = 0;
    for (int i = 1; i < heap->tamanho; i++)
        if (heap->array[i]->distancia < heap->array[minIndex]->distancia)
            minIndex = i;

    HeapNode* minNode = heap->array[minIndex];
    heap->array[minIndex] = heap->array[--heap->tamanho];
    return minNode;
}

void dijkstra(Grafo* grafo, int vertices, int origem) {
    int distancias[MAX_VERTICES];
    for (int i = 0; i < vertices; i++)
        distancias[i] = INT_MAX;
    distancias[origem] = 0;

    MinHeap* heap = criarMinHeap();
    inserirMinHeap(heap, origem, 0);

    while (heap->tamanho > 0) {
        HeapNode* minNode = removerMinHeap(heap);
        int u = minNode->vertice;
        free(minNode);

        Node* atual = grafo->listaAdj[u];
        while (atual != NULL) {
            int v = atual->vertice;
            int peso = atual->peso;

            if (distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
                inserirMinHeap(heap, v, distancias[v]);
            }
            atual = atual->proximo;
        }
    }

    printf("Menor distância a partir do vértice %d:\n", origem);
    for (int i = 0; i < vertices; i++)
        printf("Vértice %d -> Distância %d\n", i, distancias[i]);
}

int main() {
    int vertices = 3;
    Grafo* grafo = criarGrafo(vertices);
    
    adicionarAresta(grafo, 0, 1, 4);
    adicionarAresta(grafo, 0, 2, 1);
    adicionarAresta(grafo, 2, 1, 2);
    
    dijkstra(grafo, vertices, 0);

    return 0;
}
