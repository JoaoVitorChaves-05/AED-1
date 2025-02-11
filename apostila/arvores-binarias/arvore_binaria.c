#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um valor na árvore binária
void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else if (value < (*root)->value) {
        insert(&((*root)->left), value);
    } else {
        insert(&((*root)->right), value);
    }
}

// Função de travessia em pré-ordem
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Função de travessia em ordem
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

// Função de travessia em pós-ordem
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->value);
    }
}

int main() {
    Node *raiz = NULL;

    // Inserção de valores na árvore
    insert(&raiz, 50);
    insert(&raiz, 30);
    insert(&raiz, 20);
    insert(&raiz, 40);
    insert(&raiz, 70);
    insert(&raiz, 60);
    insert(&raiz, 80);

    // Travessia e impressão dos resultados
    printf("Busca em pré-ordem: ");
    preorderTraversal(raiz);
    printf("\n");

    printf("Busca em em-ordem: ");
    inorderTraversal(raiz);
    printf("\n");

    printf("Busca em pós-ordem: ");
    postOrderTraversal(raiz);
    printf("\n");

    return 0;
}

/*
    Pré-ordem: (R, E, D);
    Em-ordem: (E, R, D);
    Pós-ordem: (E, D, R);
*/