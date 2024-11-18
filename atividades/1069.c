#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
    int N;

    scanf("%i", &N);
    getchar();

    int output[N];

    for (int i = 0; i < N; i++) {
        char pilha[1000];
        char mina[1000];

        int pilhaIndex = 0;

        int contaDiamantes = 0;

        gets(mina);

        for (int j = 0; j < strlen(mina); j++) {
            if (pilhaIndex == 0 && mina[j] != '.') {
                pilha[pilhaIndex] = mina[j];
                pilhaIndex++;
            } else if (pilha[pilhaIndex-1] == '<' && mina[j] == '>') {
                pilha[pilhaIndex] = '\0';
                pilhaIndex--;
                contaDiamantes++;
                //printf("Diamente encontrado!\n");
            } else if (mina[j] == '<' || mina[j] == '>'){
                pilha[pilhaIndex] = mina[j];
                pilhaIndex++;
            }

            //printf("Ultimo elemento adicionado: %c; Elemento de comparacao: %c;\n", pilha[pilhaIndex-1], mina[j]);
        }

        output[i] = contaDiamantes;
    }
    
    for (int k = 0; k < N; k++) {
        printf("%i\n", output[k]);
    }
}