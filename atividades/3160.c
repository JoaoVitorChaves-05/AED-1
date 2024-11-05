#include <stdio.h>
#include <string.h>

int main() {
    char L[300];
    char N[500];
    char S[50];

    gets(L);
    gets(N);
    gets(S);

    if (strcmp(S, "nao")) {
        char *names1 = strtok(L, " ");

        while (names1 != NULL) {
            printf("%s ", names1);
            names1 = strtok(NULL, " ");
        }

        char *names2 = strtok(N, " ");

        while (names2 != NULL) {
            printf("%s ", names2);
            names2 = strtok(NULL, " ");
        }

        printf("\n");
        return 0;
    }

    char *names = strtok(L, " ");

    while (names != NULL) {
        printf("%s ", names);

        if (strcmp(S, names)) {
            char *newNames = strtok(N, " ");
            
            while (newNames != NULL) {
                printf("%s ", newNames);
            }
        }
        names = strtok(NULL, " ");
    }

    return 0;
}