#include <stdio.h>
#include <stdlib.h>

int compare_descending(const void *, const void *);

int main()
{
    int num_values;
    scanf("%d", &num_values);

    int values[num_values];

    for (int i = 0; i < num_values; ++i)
        scanf("%d", &values[i]);

    qsort(values, num_values, sizeof(int), compare_descending);

    int result = values[0] + 2;
    for (int i = 1; i < num_values; ++i)
        if (i + 2 + values[i] > result)
            result = i + 2 + values[i];

    printf("%d\n", result);

    return 0;
}

int compare_descending(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
