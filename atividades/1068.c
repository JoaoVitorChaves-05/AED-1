#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_N = 5;

int main() {
    int N = 0;
    char out[MAX_N][9];

    while (N < MAX_N) {
        char math[10000];
        if (fgets(math, sizeof(math), stdin) == NULL) {
            break;
        }

        math[strcspn(math, "\n")] = '\0'; 

        char pilha[10000];
        int i = 0;
        int j = 0;

        while (math[i] != '\0') {
            if (math[i] == '(' || math[i] == ')') {
                if (j == 0) {
                    pilha[j] = math[i];
                    j++;
                } else if (pilha[j-1] == '(' && math[i] == ')') {
                    j--;
                } else {
                    pilha[j] = math[i];
                    j++;
                }
            }
            i++;
        }

        if (j == 0)
            strcpy(out[N], "correct");
        else
            strcpy(out[N], "incorrect");

        N++;
    }
    
    for (int k = 0; k < MAX_N; k++)
        printf("%s\n", out[k]);
}