#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numVertices;
    int grau_max;
    int ehPonderado;
    int *grau;
    int **arestas;
    float **pesos;
} Graph;

Graph *criaGrafo(int numVertices, int grau_max, int ehPonderado) {
    Graph *G = (Graph*) malloc(sizeof(Graph));
    if (G == NULL)
        return NULL;

    G->numVertices = numVertices;
    G->grau_max = grau_max;
    G->ehPonderado = ehPonderado;
    
    // Aloca e inicializa grau dos vértices
    G->grau = (int*) malloc(numVertices * sizeof(int));
    if (G->grau == NULL)
        return NULL;
    for (int i = 0; i < numVertices; i++)
        G->grau[i] = 0; // Inicializa grau como zero

    // Aloca matriz de adjacência para armazenar as arestas
    G->arestas = (int**) malloc(numVertices * sizeof(int*));
    if (G->arestas == NULL)
        return NULL;

    // Aloca matriz de pesos (se ponderado)
    if (ehPonderado) {
        G->pesos = (float**) malloc(numVertices * sizeof(float*));
        if (G->pesos == NULL)
            return NULL;
    } else {
        G->pesos = NULL; // Para evitar acessar memória indevida
    }

    // Aloca as listas de adjacência e, se necessário, os pesos
    for (int i = 0; i < numVertices; i++) {
        G->arestas[i] = (int*) malloc(grau_max * sizeof(int));
        if (G->arestas[i] == NULL)
            return NULL;

        if (ehPonderado) {
            G->pesos[i] = (float*) malloc(grau_max * sizeof(float));
            if (G->pesos[i] == NULL)
                return NULL;
        }
    }

    return G;
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

int adicionaAresta(Graph *G, int origem, int destino, int eh_digrafo, float peso) {
    if (G == NULL)
        return 0;
    if (origem < 0 || origem >= G->numVertices || destino < 0 || destino >= G->numVertices)
        return 0;

    G->arestas[origem][G->grau[origem]] = destino;
    if (G->ehPonderado)
        G->pesos[origem][G->grau[origem]] = peso;
    G->grau[origem]++;  // Incrementa corretamente o grau do vértice

    if (eh_digrafo == 1)
        adicionaAresta(G, destino, origem, 0, peso); // Adiciona a aresta inversa

    return 1;
}

int removeAresta(Graph *G, int origem, int destino, int eh_digrafo) {
    if (G == NULL)
        return 0;
    if (origem < 0 || origem >= G->numVertices || destino < 0 || destino >= G->numVertices)
        return 0;

    int i = 0;
    while (i < G->grau[origem] && G->arestas[origem][i]!= destino)
        i++;
    
    if (i == G->grau[origem])
        return 0;


    for (int j = i; j < G->grau[origem] - 1; j++) {
        G->arestas[origem][j] = G->arestas[origem][j+1];
        if (G->ehPonderado)
            G->pesos[origem][j] = G->pesos[origem][j+1];  // Remove peso
    }
    
    G->grau[origem]--;  // Decrementa corretamente o grau do vértice

    // Remove a aresta inversa (se for digrafo)
    if (eh_digrafo == 1) {
        removeAresta(G, destino, origem, 0);
    }

    return 1;
}

int main() {
    Graph* gr = criaGrafo(10, 7, 0); // (numVertices, grau_max, grau)
    adicionaAresta(gr, 0, 1, 0, 1); // 0 -> 1
    adicionaAresta(gr, 0, 2, 0, 2); // 0 -> 2
    adicionaAresta(gr, 1, 2, 0, 3); // 1 -> 2
    adicionaAresta(gr, 2, 3, 0, 4); // 2 -> 3
    adicionaAresta(gr, 2, 4, 0, 5); // 2 -> 4
}