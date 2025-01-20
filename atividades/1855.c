#include <stdio.h>
#include <string.h>

int move(int linha, int coluna, char mapa[linha][coluna], int *i, int *j, char lastDirection) {
    if (lastDirection == '>') {
        if (*j == coluna - 1) {
            return -1;
        } else {
            mapa[*i][*j] = '#';
            (*j)++;
        }
    } else if (lastDirection == 'v') {
        if (*i == linha - 1) {
            return -1;
        } else {
            mapa[*i][*j] = '#';
            (*i)++;
        }
    } else if (lastDirection == '<') {
        if (*j == 0) {
            return -1;
        } else {
            mapa[*i][*j] = '#';
            (*j)--;
        }
    } else if (lastDirection == '^') {
        if (*i == 0) {
            return -1;
        } else {
            mapa[*i][*j] = '#';
            (*i)--;
        }
    }
    return 0;
}
 
int main() {
    
    int linha;
    int coluna;
    
    scanf("%i", &coluna);
    scanf("%i", &linha);
    
    char mapa[linha][coluna];
    
    for (int w = 0; w < linha; w++) {
        scanf("%s", mapa[w]);
    }
    
    int i = 0;
    int j = 0;

    char lastDirection = mapa[i][j];
    
    while (1 == 1) {
        if (mapa[i][j] == '.') {
            int wasMoved = move(linha, coluna, mapa, &i, &j, lastDirection);

            if (wasMoved == -1) {
                printf("!\n");
                break;
            }
        } else if (mapa[i][j] == '*') {
            printf("*\n");
            break;
        } else if (mapa[i][j] == '#') {
            printf("!\n");
            break;
        } else {
            lastDirection = mapa[i][j];
            move(linha, coluna, mapa, &i, &j, lastDirection);
        }
    }
 
    return 0;
}