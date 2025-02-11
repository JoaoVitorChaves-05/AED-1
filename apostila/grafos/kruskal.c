#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_ARESTAS 1000

typedef struct {
    int origem, destino, peso;
} Aresta;

typedef struct {
    int V, E;
    Aresta arestas[MAX_ARESTAS];
} Grafo;

Grafo* criarGrafo(int V, int E) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->V = V;
    grafo->E = E;
    return grafo;
}

// Função para comparar arestas pelo peso (para qsort)
int compararArestas(const void* a, const void* b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

// Estruturas para Union-Find (DSU)
int pai[MAX_VERTICES], rank[MAX_VERTICES];

// Inicializa os conjuntos
void inicializarConjuntos(int n) {
    for (int i = 0; i < n; i++) {
        pai[i] = i;
        rank[i] = 0;
    }
}

// Encontra o representante do conjunto (com compressão de caminho)
int encontrar(int v) {
    if (pai[v] == v)
        return v;
    return pai[v] = encontrar(pai[v]);
}

// Une dois conjuntos (por rank)
void unir(int v1, int v2) {
    int raiz1 = encontrar(v1);
    int raiz2 = encontrar(v2);

    if (raiz1 != raiz2) {
        if (rank[raiz1] < rank[raiz2])
            pai[raiz1] = raiz2;
        else if (rank[raiz1] > rank[raiz2])
            pai[raiz2] = raiz1;
        else {
            pai[raiz2] = raiz1;
            rank[raiz1]++;
        }
    }
}

// Algoritmo de Kruskal
void kruskal(Grafo* grafo) {
    Aresta resultado[MAX_VERTICES]; // MST resultante
    int custoTotal = 0, e = 0, i = 0;

    qsort(grafo->arestas, grafo->E, sizeof(Aresta), compararArestas);

    inicializarConjuntos(grafo->V);

    while (e < grafo->V - 1 && i < grafo->E) {
        Aresta proximaAresta = grafo->arestas[i++];
        int u = encontrar(proximaAresta.origem);
        int v = encontrar(proximaAresta.destino);

        if (u != v) {
            resultado[e++] = proximaAresta;
            unir(u, v);
            custoTotal += proximaAresta.peso;
        }
    }

    printf("Arestas da Árvore Geradora Mínima:\n");
    for (i = 0; i < e; i++)
        printf("%d - %d (Peso: %d)\n", resultado[i].origem, resultado[i].destino, resultado[i].peso);

    printf("Custo total: %d\n", custoTotal);
}

int main() {
    int V = 4, E = 5;
    Grafo* grafo = criarGrafo(V, E);

    grafo->arestas[0] = (Aresta){0, 1, 2};
    grafo->arestas[1] = (Aresta){0, 3, 5};
    grafo->arestas[2] = (Aresta){0, 2, 6};
    grafo->arestas[3] = (Aresta){1, 3, 5};
    grafo->arestas[4] = (Aresta){2, 3, 3};

    kruskal(grafo);

    free(grafo);
    return 0;
}
