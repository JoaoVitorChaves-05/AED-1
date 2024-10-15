#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq;
    char palavra[20];

    arq = fopen("arquivo_palavra.txt", "w");

    if (arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    }

    printf("Escreva uma palavra para gravar no arquivo: ");
    scanf("%s", palavra);

    fprintf(arq, "%s", palavra);

    fclose(arq);

    printf("Dados gravados com sucesso!");

    return 0;
}