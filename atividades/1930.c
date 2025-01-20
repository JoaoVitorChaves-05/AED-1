#include <stdio.h>

int main() {
    int T1, T2, T3, T4;

    scanf("%d %d %d %d", &T1, &T2, &T3, &T4);

    int total = (T1 - 1) + (T2 - 1) + (T3 - 1) + T4;

    printf("%d\n", total);

    return 0;
}
