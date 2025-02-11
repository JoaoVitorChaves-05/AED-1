#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stayInList(int n, int *list, int size) {
    for (int j = 0; j < size; j++) {
        if (list[j] == n)
            return 1;
    }
    return 0;
}

int main() {
    int qtdPessoas;
    scanf("%d", &qtdPessoas);
    int fila[qtdPessoas];
    
    for (int i = 0; i < qtdPessoas; i++) {
        scanf("%d", &fila[i]);
    }

    int qtdPessoas2;
    scanf("%d", &qtdPessoas2);
    int sairam[qtdPessoas2];
    
    for (int i = 0; i < qtdPessoas2; i++) {
        scanf("%d", &sairam[i]);
    }

    int novaFila[qtdPessoas];
    int index = 0;
    for (int i = 0; i < qtdPessoas; i++) {
        if (!stayInList(fila[i], sairam, qtdPessoas2)) {
            novaFila[index++] = fila[i];
        }
    }

    for (int i = 0; i < index; i++) {
        printf("%d", novaFila[i]);
        if (i < index - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
