#include <stdio.h>
#include <string.h>
 
int main() {
    
    int linha;
    int coluna;
    
    scanf("%i", &linha);
    scanf("%i", %coluna);
    
    char mapa[linha][coluna];
    
    for (int i = 0; i < linha; i++) {
        gets(mapa[linha]);
    }
    
    int i = 0;
    int j = 0;
    
    while (1 == 1) {
        if (mapa[i][j] == '>') {
            if (j == coluna - 1) {
                printf("!\n");
                break;
            } else
                j++;
        } else if (mapa[i][j] == 'v') {
            if (i == linha - 1) {
                printf("!\n");
                break;
            } else
                i++;
        } else if (mapa[i][j] == '<') {
            if (j == 0) {
                printf("!\n");
                break;
            } else
                j--;
        } else if (mapa[i][j] == '^') {
            if (i == 0) {
                printf("!\n");
                break;
            } else
                i--;
        }
    }
 
    return 0;
}