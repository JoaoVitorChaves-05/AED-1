#include <stdio.h>
#include <string.h>

int main() {
    char L[300];
    char N[500];
    char S[50];
    char tempN[500];
    char originalL[300];

    gets(L);
    gets(N);
    gets(S);

    strcpy(originalL, L);

    if (strcmp(S, "nao") == 0) {

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

    int count = 0;

    while (names != NULL) {

        if (strcmp(S, names) == 0) {

            strcpy(tempN, N);
            
            char *newNames = strtok(tempN, " ");
            while (newNames != NULL) {
                printf(" ");
                printf("%s", newNames);
                newNames = strtok(NULL, " ");
            }
        }

        printf("%s ", names);
        count++;

        names = strtok(NULL, " ");
    }


    char *completeNames = strtok(originalL, " ");

    int count2 = 0;
    while (completeNames != NULL) {
        if (count == count2) {
            printf("%s ", completeNames);
        }

        completeNames = strtok(NULL, " ");
        count2++;
    }

    printf("\n");

    return 0;
}