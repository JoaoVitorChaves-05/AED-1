#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N = 0;
    char out[1000][9];

    while (N < 1000) {
        char math[10000];
        gets(math);

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
                    pilha[j] = '\0';
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
    
    for (int k = 0; k < 1000; k++)
        printf("%s\n", out[k]);
}