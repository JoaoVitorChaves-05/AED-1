#include <stdio.h>
#include <stdlib.h>

void processPilha(int n) {
    if (n == 0) return;

    int pilha[n];
    int descartadas[n - 1];
    int topo = 0;
    int base = n;
    int descartadasIndex = 0;

    for (int i = 1; i <= n; i++) {
        pilha[i - 1] = i;
    }

    while (topo < base - 1) {
        descartadas[descartadasIndex++] = pilha[topo++];

        pilha[base] = pilha[topo];
        base++;
        topo++;
    }

    printf("Discarded cards: ");
    for (int i = 0; i < descartadasIndex; i++) {
        if (i > 0) printf(", ");
        printf("%d", descartadas[i]);
    }
    printf("\n");

    printf("Remaining card: %d\n", pilha[topo]);
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        processPilha(n);
    }

    return 0;
}
