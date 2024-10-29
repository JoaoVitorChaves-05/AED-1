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

    int initialElement[2] = {line - (line % 3), col - (col % 3)};

    for (int l = initialElement[0]; l < l + 3; l++) {
        for (int c = initialElement[1]; c < c + 3; c++) {
            if (game[l][c] == n) {
                return 0;
            }
        }
    }
    

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

            while (line < 0 || line > 8) {
                printf("Insira um número entre 0 e 8: ");
                scanf("%d", &line);
            }

            printf("Insira a coluna: ");
            scanf("%d", &col);

            while (col < 0 || col > 8) {
                printf("Insira um número entre 0 e 8: ");
                scanf("%d", &col);
            }

            printf("Insira o número: ");
            printf("%d", &n);

            while (n < 0 || n > 9) {
                printf("Insira um número entre 0 e 9: ");
                scanf("%d", &line);
            }

            if (!checkNumber(game, line, col, n)) {
                printf("Jogada inválida!\n\n");
            }

            game[line][col] = n;
        }

    } while (opt != -1);
}