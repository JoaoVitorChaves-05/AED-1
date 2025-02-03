if (mapa[i][j] == '>') {
    if (j == coluna - 1) {
        printf("!\n");
        break;
    } else {
        mapa[i][j] = '#';
        j++;
    }
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