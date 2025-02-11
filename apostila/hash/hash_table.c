#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10 // Define o tamanho da tabela hash

// Estrutura para representar um nó na lista encadeada
typedef struct Node {
    char *key;  // Chave associada ao valor
    int value;  // Valor armazenado
    struct Node *next; // Ponteiro para o próximo nó
} Node;

// Estrutura para representar a tabela hash
typedef struct {
    Node *buckets[TABLE_SIZE]; // Vetor de ponteiros para listas encadeadas
} HashTable;

// Função de hash que calcula um índice baseado na chave
unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key; // Multiplica o hash por 31 e adiciona o caractere atual
        key++;
    }
    return hash % TABLE_SIZE; // Retorna o índice dentro dos limites da tabela
}

// Função para criar e inicializar uma nova tabela hash
HashTable *create_table() {
    HashTable *table = malloc(sizeof(HashTable));
    if (!table) return NULL; // Verifica se a alocação foi bem-sucedida
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL; // Inicializa todos os buckets como NULL
    }
    return table;
}

// Função para inserir um par chave-valor na tabela hash
void insert(HashTable *table, const char *key, int value) {
    unsigned int index = hash(key); // Calcula o índice da chave
    Node *newNode = malloc(sizeof(Node)); // Aloca memória para um novo nó
    newNode->key = strdup(key); // Duplica a string da chave para evitar problemas
    newNode->value = value; // Atribui o valor
    newNode->next = table->buckets[index]; // Insere o nó na frente da lista encadeada
    table->buckets[index] = newNode; // Atualiza o bucket com o novo nó
}

// Função para buscar um valor na tabela hash dado uma chave
int search(HashTable *table, const char *key, int *value) {
    unsigned int index = hash(key); // Calcula o índice da chave
    Node *current = table->buckets[index]; // Obtém a lista encadeada correspondente
    while (current) {
        if (strcmp(current->key, key) == 0) { // Compara as chaves
            *value = current->value; // Retorna o valor associado
            return 1; // Chave encontrada
        }
        current = current->next; // Avança para o próximo nó
    }
    return 0; // Chave não encontrada
}

// Função para remover um elemento da tabela hash
void delete(HashTable *table, const char *key) {
    unsigned int index = hash(key); // Calcula o índice da chave
    Node *current = table->buckets[index]; // Obtém a lista encadeada correspondente
    Node *prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) { // Se encontrou a chave
            if (prev) {
                prev->next = current->next; // Remove o nó ajustando os ponteiros
            } else {
                table->buckets[index] = current->next; // Atualiza o início da lista
            }
            free(current->key); // Libera a memória da chave
            free(current); // Libera o nó
            return;
        }
        prev = current;
        current = current->next; // Avança na lista
    }
}

// Função para liberar toda a memória alocada pela tabela hash
void free_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = table->buckets[i]; // Obtém a lista encadeada
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp->key); // Libera a memória da chave
            free(temp); // Libera o nó
        }
    }
    free(table); // Libera a estrutura da tabela hash
}

// Função principal para testar a implementação da tabela hash
int main() {
    HashTable *table = create_table(); // Cria uma nova tabela hash
    insert(table, "chave1", 10); // Insere um elemento
    insert(table, "chave2", 20); // Insere outro elemento
    
    int value;
    if (search(table, "chave1", &value)) { // Busca uma chave existente
        printf("Valor encontrado: %d\n", value);
    } else {
        printf("Chave não encontrada\n");
    }
    
    delete(table, "chave1"); // Remove um elemento
    if (search(table, "chave1", &value)) { // Busca a chave removida
        printf("Valor encontrado: %d\n", value);
    } else {
        printf("Chave não encontrada\n");
    }
    
    free_table(table); // Libera a memória alocada
    return 0;
}
