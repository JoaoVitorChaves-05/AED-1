#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_ITEMS = 1000;
const int MAX_LENGTH = 21;

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void process_list(char *list) {
    char *items[MAX_ITEMS];
    int count = 0;

    char *token = strtok(list, " ");
    while (token != NULL) {
        int exists = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(items[i], token) == 0) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            items[count] = token;
            count++;
        }
        token = strtok(NULL, " ");
    }

    qsort(items, count, sizeof(char *), compare);

    for (int i = 0; i < count; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%s", items[i]);
    }
    printf("\n");
}

int main() {

    int N;
    char list[1001];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        fgets(list, sizeof(list), stdin);
        list[strcspn(list, "\n")] = 0;
        process_list(list);
    }

    return 0;
}
