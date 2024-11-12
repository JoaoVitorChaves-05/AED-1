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
    scanf("%i", &qtdPessoas);
    int fila[qtdPessoas];
    int i = 0;
    
    while(scanf("%i", &fila[i]) == 1) {
        i++;

        if (i >= qtdPessoas) {
            break;
        }
    }

    int qtdPessoas2;
    scanf("%i", &qtdPessoas2);
    int sairam[qtdPessoas2];

    i = 0;
    while(scanf("%i", &sairam[i]) == 1) {
        i++;

        if (i >= qtdPessoas2) {
            break;
        }
    }

    int novaFila[qtdPessoas];
    int index = 0;
    for (int k = 0; k < qtdPessoas; k++) {
        int stay = stayInList(fila[k], sairam, qtdPessoas2);
        if (stay == 0) {
            novaFila[index] = fila[k];
            index++;
        }
    }

    for (int w = 0; w < index; w++) {
        printf("%i", novaFila[w]);
        if (w + 1 != index)
            printf(" ");
    }

    printf("\n");
}