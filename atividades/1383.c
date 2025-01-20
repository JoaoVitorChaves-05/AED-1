#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool verificaLinha(int sudoku[SIZE][SIZE], int linha) {
    bool numeros[SIZE + 1] = {false};
    for (int i = 0; i < SIZE; i++) {
        int num = sudoku[linha][i];
        if (num < 1 || num > SIZE || numeros[num]) {
            return false;
        }
        numeros[num] = true;
    }
    return true;
}

bool verificaColuna(int sudoku[SIZE][SIZE], int coluna) {
    bool numeros[SIZE + 1] = {false};
    for (int i = 0; i < SIZE; i++) {
        int num = sudoku[i][coluna];
        if (num < 1 || num > SIZE || numeros[num]) {
            return false;
        }
        numeros[num] = true;
    }
    return true;
}

bool verificaSubmatriz(int sudoku[SIZE][SIZE], int inicioLinha, int inicioColuna) {
    bool numeros[SIZE + 1] = {false};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = sudoku[inicioLinha + i][inicioColuna + j];
            if (num < 1 || num > SIZE || numeros[num]) {
                return false;
            }
            numeros[num] = true;
        }
    }
    return true;
}

bool verificaSudoku(int sudoku[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!verificaLinha(sudoku, i) || !verificaColuna(sudoku, i)) {
            return false;
        }
    }
    for (int i = 0; i < SIZE; i += 3) {
        for (int j = 0; j < SIZE; j += 3) {
            if (!verificaSubmatriz(sudoku, i, j)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, instancia = 1;

    scanf("%d", &n);

    while (n--) {
        int sudoku[SIZE][SIZE];

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        printf("Instancia %d\n", instancia++);
        if (verificaSudoku(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
