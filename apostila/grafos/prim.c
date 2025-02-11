#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 4  // Número de vértices

// Encontra o vértice com a menor chave (não incluído na MST)
int minChave(int chave[], bool mstSet[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && chave[v] < min) {
            min = chave[v], minIndex = v;
        }
    }
    return minIndex;
}

// Algoritmo de Prim
void prim(int grafo[V][V]) {
    int parent[V];   // Guarda a MST
    int chave[V];    // Menor peso para cada vértice
    bool mstSet[V];  // Conjunto de vértices na MST

    // Inicializa todas as chaves como infinito e mstSet como falso
    for (int i = 0; i < V; i++) {
        chave[i] = INT_MAX;
        mstSet[i] = false;
    }

    chave[0] = 0;  // Começa pelo vértice 0
    parent[0] = -1;  // Primeiro nó é a raiz da MST

    for (int count = 0; count < V - 1; count++) {
        int u = minChave(chave, mstSet);  // Pega o menor peso
        mstSet[u] = true;

        // Atualiza os pesos dos vértices adjacentes
        for (int v = 0; v < V; v++) {
            if (grafo[u][v] && !mstSet[v] && grafo[u][v] < chave[v]) {
                parent[v] = u;
                chave[v] = grafo[u][v];
            }
        }
    }

    printf("Arestas da MST:\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d (Peso: %d)\n", parent[i], i, grafo[i][parent[i]]);
    }
}

int main() {
    int grafo[V][V] = {
        {0, 2, 6, 5},
        {2, 0, 0, 5},
        {6, 0, 0, 3},
        {5, 5, 3, 0}
    };

    prim(grafo);

    return 0;
}
