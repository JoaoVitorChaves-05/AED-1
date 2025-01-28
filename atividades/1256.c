#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hashIndex(int key) {
    return key % 13;
};

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void InsertAtEnd(Node *head, int value) {
    Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void hashPush(int *listHash, int index, int value) {
    Node *newNode = createNode(value);
    if (listHash[index])
        InsertAtEnd(listHash[index], value);
    else {
        listHash[index] = createNode(value);
    }
}

int main() {
    int nTests;

    scanf("%i", &nTests);

    for (int i = 0; i < nTests; i++) {
        int sizeArray;
        int nKeys;
        Node *array[sizeArray];

        int tmp;

        for (int j = 0; j < nKeys; j++) {
            scanf("%i", &tmp);
            int index = hashIndex(tmp);
            hashPush(array, index, tmp);
        }

        for (int k = 0; k < sizeArray; ++i) {	
			printf("%d -> ", i);
			for (int i = 0; i < sizeArray; i++) {
                Node *current = array[k];
                while (current != NULL) {
                    printf("%d -> ", current->value);
                    current = current->next;
                }
            }

			printf("\\");
			printf("\n");

		}

        if (i)
            printf("\n");
    }
}