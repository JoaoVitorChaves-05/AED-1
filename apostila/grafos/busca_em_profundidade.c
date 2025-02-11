#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Estrutura para representar uma lista de adjacência
typedef struct Node {
    int vertice;
    struct Node* proximo;
} Node;

// Estrutura para representar o grafo
typedef struct {
    int numVertices;
    Node* listaAdj[MAX_VERTICES];
} Grafo;

// Criação do grafo
Grafo* criarGrafo(int vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

// Função para adicionar uma aresta em um grafo não direcionado
void adicionarAresta(Grafo* grafo, int origem, int destino) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->vertice = destino;
    novoNode->proximo = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNode;

    // Adiciona origem na lista de adjacência de destino (aresta reversa)
    novoNode = (Node*)malloc(sizeof(Node));
    novoNode->vertice = origem;
    novoNode->proximo = grafo->listaAdj[destino];
    grafo->listaAdj[destino] = novoNode;
}

// Função DFS recursiva
void DFS(Grafo* grafo, int vertice, int* visitado) {
    printf("%d ", vertice);
    visitado[vertice] = 1;

    Node* temp = grafo->listaAdj[vertice];
    while (temp != NULL) {
        int adjacente = temp->vertice;
        if (!visitado[adjacente]) {
            DFS(grafo, adjacente, visitado);
        }
        temp = temp->proximo;
    }
}

// Função para iniciar a DFS
void iniciarDFS(Grafo* grafo, int inicio) {
    int visitado[MAX_VERTICES] = {0}; // Inicializa todos os vértices como não visitados
    printf("DFS iniciada a partir do vértice %d:\n", inicio);
    DFS(grafo, inicio, visitado);
    printf("\n");
}

// Função para liberar memória
void liberarGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        Node* temp = grafo->listaAdj[i];
        while (temp) {
            Node* prox = temp->proximo;
            free(temp);
            temp = prox;
        }
    }
    free(grafo);
}

// Programa principal
int main() {
    int vertices = 6;
    Grafo* grafo = criarGrafo(vertices);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 4);
    adicionarAresta(grafo, 3, 5);
    adicionarAresta(grafo, 4, 5);

    iniciarDFS(grafo, 0);

    liberarGrafo(grafo);
    return 0;
}

/*

   Complexidade:
   - Criar grafo: O(V)
   - Adicionar aresta: O(E)
   - Busca em profundidade: O(V + E)

   Comentários:
   - O código cria um grafo usando uma lista de adjacência.
   - A função DFS percorre o grafo em profundidade, marcando os vértices visitados e chamando recursivamente para os vizinhos.
   - Pode ser implementada de forma recursiva ou iterativa (usando pilha explícita).
   - Útil para detectar ciclos, componentes conexas e ordenação topológica.

*/
