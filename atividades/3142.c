#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    char column_name[20];

    while (~scanf("%s", column_name))
    {
        unsigned long long column_value = 0UL;

        for (int i = strlen(column_name) - 1, j = 0; i >= 0; --i, ++j)
            column_value += (column_name[i] - 'A' + 1) * (unsigned long long)pow(26, j);

        if (column_value <= 16384)
            printf("%llu\n", column_value);
        else
            puts("Essa coluna nao existe Tobias!");
    }

    return 0;
}
