#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool isValidSet(int *set) {
    int seen[SIZE + 1] = {0};

    for (int i = 0; i < SIZE; i++) {
        int num = set[i];
        if (num < 1 || num > 9 || seen[num]) {
            return false;
        }
        seen[num] = 1;
    }
    return true;
}

bool isValidRow(int game[SIZE][SIZE], int row) {
    return isValidSet(game[row]);
}

bool isValidColumn(int game[SIZE][SIZE], int col) {
    int column[SIZE];
    for (int i = 0; i < SIZE; i++) {
        column[i] = game[i][col];
    }
    return isValidSet(column);
}

bool isValidSubgrid(int game[SIZE][SIZE], int startRow, int startCol) {
    int subgrid[SIZE];
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            subgrid[index++] = game[startRow + i][startCol + j];
        }
    }
    return isValidSet(subgrid);
}

bool isValidSudoku(int game[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!isValidRow(game, i) || !isValidColumn(game, i)) {
            return false;
        }
    }

    for (int i = 0; i < SIZE; i += 3) {
        for (int j = 0; j < SIZE; j += 3) {
            if (!isValidSubgrid(game, i, j)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int nGames;

    scanf("%d", &nGames);
    getchar();
    for (int currentGame = 1; currentGame <= nGames; currentGame++) {
        int game[SIZE][SIZE];

        for (int i = 0; i < SIZE; i++) {
            char line[20];
            fgets(line, sizeof(line), stdin);

            char gameLine[9];
            int count = 0;
            for (int i = 0; i < sizeof(line); i++) {
                if (line[i] != '\0' && line[i] != '\n' && line[i] != ' ') {
                    gameLine[count] = line[i];
                    count++;
                }
            }
        }

        printf("Instancia %d\n", currentGame);
        if (isValidSudoku(game)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        if (currentGame < nGames) {
            printf("\n");
        }
    }

    return 0;
}
