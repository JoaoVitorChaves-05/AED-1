#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int numVertices;
    int ehPonderado;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
} Graph;

Graph *gr;

Graph *criaGrafo(int numVertices, int grau_max, int ehPonderado) {
    Graph *G = (Graph*) malloc(sizeof(Graph));
    G->numVertices = numVertices;
    G->ehPonderado = ehPonderado;
    G->grau_max = grau_max;
    G->grau = (int*) malloc(numVertices * sizeof(int));
    G->arestas = (int**) malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        G->arestas[i] = (int*) malloc(grau_max * sizeof(int));
        if (ehPonderado) {
            G->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }
    }
}

void liberaGrafo(Graph *G) {
    if (G != NULL) {
        for (int i = 0; i < G->numVertices; i++) {
            free(G->arestas[i]);
            if (G->ehPonderado) {
                free(G->pesos[i]);
            }
        }
        free(G->arestas);
        free(G->pesos);
        free(G->grau);
        free(G);
        G = NULL;
    }
}

void adicionaAresta(Graph *G, int origem, int destino, int eh_digrafo, float peso) {
    if (gr == NULL)
        return 0;
    if (origem < 0 || origem >= G->numVertices || destino < 0 || destino >= G->numVertices)
        return 0;

    G->arestas[origem][G->grau[origem]] = destino;
    if (gr->eh_ponderado)
        gr->pesos[origem][gr->grau[origem]] = peso;
    gr->grau[origem++];

    if (!eh_digrafo)
        adicionaAresta(G, destino, origem, 1, peso); // adiciona a aresta direcionada
    return 1;
}

int main() {
    gr = criaGrafo(10, 7, 0); // (numVertices, grau_max, grau)

}