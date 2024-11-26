#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    char nomes[100][50];
    char aux[50];

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%s", nomes[i]);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(nomes[j], nomes[min_idx]) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            strcpy(aux, nomes[i]);
            strcpy(nomes[i], nomes[min_idx]);
            strcpy(nomes[min_idx], aux);
        }
    }

    printf("%s\n", nomes[k - 1]);

    return 0;
}
