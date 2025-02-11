#include <stdio.h>

int main(int argc, char **argv)
{
    int arr[1010];
    int num_elements, num_queries, operation, index_a, index_b, result;

    scanf("%d %d", &num_elements, &num_queries);

    for (int i = 1; i <= num_elements; ++i)
        arr[i] = i;

    while (num_queries--)
    {
        scanf("%d %d", &operation, &index_a);

        if (operation == 1)
        {
            scanf("%d", &index_b);
            result = arr[index_a];
            arr[index_a] = arr[index_b];
            arr[index_b] = result;
        }
        else
        {
            result = 0;
            index_b = arr[index_a];

            while (index_a != index_b)
                index_b = arr[index_b], ++result;

            printf("%d\n", result);
        }
    }

    return 0;
}
