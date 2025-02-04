#include <stdio.h>
#include <stdlib.h>

int inserePar(int valor, int lista[], int nPares) {
    for (int j = 0; j < nPares; j++) {
        if (lista[j] > valor) {
            for (int k = nPares; k > j; k--) {
                lista[k] = lista[k-1];
            }
            lista[j] = valor;
            return 1;
        }
    }

    lista[nPares] = valor;
    return 1;
}

int insereImpar(int valor, int lista[], int nImpares) {
    for (int j = 0; j <= nImpares; j++) {
        if (lista[j] < valor) {
            for (int k = nImpares; k > j; k--) {
                lista[k] = lista[k-1];
            }
            lista[j] = valor;
            return 1;
        }
    }

    lista[nImpares] = valor;
    return 1;
}

int main() {
    int linhas;
    scanf("%i", &linhas);

    int entradas[linhas];
    int pares[linhas];
    int impares[linhas];

    int nPares = 0;
    int nImpares = 0;

    for (int i = 0; i < linhas; i++) {
        scanf("%i", &entradas[i]);
        if (entradas[i] % 2 == 0) {
            inserePar(entradas[i], pares, nPares);
            nPares++;
        } else {
            insereImpar(entradas[i], impares, nImpares);
            nImpares++;
        }
    }

    for (int w = 0; w < nPares; w++) {
        printf("%i\n", pares[w]);
    }

    for (int w = 0; w < nImpares; w++) {
        printf("%i\n", impares[w]);
    }
}