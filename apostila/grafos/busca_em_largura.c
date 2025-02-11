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

// Estrutura para representar uma fila
typedef struct {
    int itens[MAX_VERTICES];
    int frente, tras;
} Fila;

// Função para criar um grafo
Grafo* criarGrafo(int vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

// Função para adicionar uma aresta ao grafo
void adicionarAresta(Grafo* grafo, int origem, int destino) {
    // Adiciona destino na lista de adjacência de origem
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

// Funções para manipular a fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = 0;
    fila->tras = -1;
    return fila;
}

void enfileirar(Fila* fila, int valor) {
    fila->itens[++fila->tras] = valor;
}

int desenfileirar(Fila* fila) {
    return fila->itens[fila->frente++];
}

int filaVazia(Fila* fila) {
    return fila->frente > fila->tras;
}

// Função para Busca em Largura (BFS)
void BFS(Grafo* grafo, int inicio) {
    int visitado[MAX_VERTICES] = {0}; // Marca todos os vértices como não visitados
    Fila* fila = criarFila();

    printf("BFS iniciada a partir do vértice %d:\n", inicio);

    // Marca o vértice inicial como visitado e o coloca na fila
    visitado[inicio] = 1;
    enfileirar(fila, inicio);

    while (!filaVazia(fila)) {
        int vertice = desenfileirar(fila); // Recebe o vértice visitado
        printf("%d ", vertice); // Ver vértice

        Node* temp = grafo->listaAdj[vertice]; // Recebe os vizinhos do vértice visitado
        while (temp != NULL) {
            int adjacente = temp->vertice; // Recebe um vizinho do vértice visitado
            if (!visitado[adjacente]) { // Verifica se o vizinho já foi visitado
                visitado[adjacente] = 1; // Marca o vizinho como visitado
                enfileirar(fila, adjacente); // Enfilera o vizinho
            }
            temp = temp->proximo; // Recebe o próximo vizinho
        }

        // Isso é repetido até enfileirar todos os vizinhos e ir "voltando" ao desenfileirar
    }
    printf("\n");

    free(fila);
}

// Função para liberar memória do grafo
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

    BFS(grafo, 0);

    liberarGrafo(grafo);
    return 0;
}

/*

   Complexidade:
   - Criar grafo: O(V)
   - Adicionar aresta: O(E)
   - Busca em largura: O(V + E)
   
   Comentários:
   - O código cria um grafo usando uma lista de adjacência.
   - A função BFS é responsável por percorrer o grafo em largura, marcando os vértices visitados e enfileirando os vizinhos.

*/