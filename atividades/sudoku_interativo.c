#include <stdio.h>

void renderGame(char game[9][9]) {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++) {
            printf('%s ', game[i][j]);
        }
        printf('\n');
    }
}

int checkNumber(char game[9][9], int line, int col, char n) {
    for (int i = 0; i < 9; i++) {
        if (game[i][col] == n) {
            return 0;
        }
    }

    for (int j = 0; j < 9; j++) {
        if (game[line][col] == n) {
            return 0;
        }
    }

    int subgrid[2] = {((line / 3) + line % 3), ((col / 3) + col % 3)};
    

    return 1;
}

int main() {
    char game[9][9] = {};

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            game[i][j] = '*';

    int opt = 0;

    do {
        renderGame(game);
        printf("\n");
        printf("\n");
        printf("Insira -1 para sair e 1 para nova jogada: ");
        scanf("%i", opt);
        
        if (opt == 1) {
            int line, col;
            char n;

            printf("Insira a linha: ");
            scanf("%d", &line);
            printf("Insira a coluna: ");
            scanf("%d", &col);
            printf("Insira o número: ");
            printf("%d", &n);

            if (!checkNumber(game, line, col, n)) {
                printf("Jogada inválida!\n\n");
            }

            game[line][col] = n;
        }

    } while (opt != -1);
}