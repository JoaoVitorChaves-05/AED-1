#include <stdio.h>
#include <string.h>

int main() {
    char L[300];
    char N[500];
    char S[50];
    char tempN[500];

    // Use fgets para evitar overflow, já que gets é inseguro
    fgets(L, 300, stdin);
    fgets(N, 500, stdin);
    fgets(S, 50, stdin);

    // Remover a nova linha que fgets captura
    L[strcspn(L, "\n")] = 0;
    N[strcspn(N, "\n")] = 0;
    S[strcspn(S, "\n")] = 0;

    // Processa L e, ao encontrar S, imprime os tokens de N
    char *names = strtok(L, " ");
    while (names != NULL) {

        // Quando encontrar S, imprime todos os tokens de N
        if (strcmp(S, names) == 0) {
            strcpy(tempN, N);  // Preserva N usando tempN
            char *newNames = strtok(tempN, " ");
            while (newNames != NULL) {
                printf("%s ", newNames);
                newNames = strtok(NULL, " ");
            }
        }

        // Imprime o token atual de L
        printf("%s ", names);

        // Avança para o próximo token de L
        names = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}
