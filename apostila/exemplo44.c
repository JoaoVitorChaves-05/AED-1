#include <stdio.h>

int main() {
    int x = 1, y = 3;
    int *px = &y, *py = &y;
    *px = *px + *py;

    printf("x=%d, y=%d\n", x, y);
    printf("*px=%d, *py=%d\n", *px, *py);
    printf("*px=%p, *py=%p\n", *px, *py);
    printf("&x=%p, &y=%p\n", &x, &y);
    
    *px++;

    printf("*px=%d\n", *px);

    for (int i = 0; i < 10000; i++) {
        *px++;
        printf("*px=%d\n", *px);
    }
}
