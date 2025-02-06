#include <stdio.h>
#include <stdlib.h>

int comparaCrescente(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int comparaDecrescente(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int linhas;
    scanf("%d", &linhas);

    int pares[linhas], impares[linhas];
    int nPares = 0, nImpares = 0, valor;

    for (int i = 0; i < linhas; i++) {
        scanf("%d", &valor);
        if (valor % 2 == 0) {
            pares[nPares++] = valor;
        } else {
            impares[nImpares++] = valor;
        }
    }

    qsort(pares, nPares, sizeof(int), comparaCrescente);
    qsort(impares, nImpares, sizeof(int), comparaDecrescente);

    for (int i = 0; i < nPares; i++) {
        printf("%d\n", pares[i]);
    }
    for (int i = 0; i < nImpares; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
