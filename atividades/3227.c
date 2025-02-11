#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 123

int main()
{
    int max_balance;
    char input_string[MAX_LENGTH] = {0};

    scanf("%d", &max_balance);
    scanf("%s", input_string);

    int result = 0;
    int balance_count = 0;

    for (int i = 0; input_string[i]; ++i)
    {
        if (input_string[i] == 'M')
            ++balance_count;
        else
            --balance_count;

        if (abs(balance_count) > max_balance + 1)
        {
            result = i - 1;
            break;
        }
    }

    if (result == 0)
    {
        if (abs(balance_count) > max_balance)
            result = strlen(input_string) - 1;
        else
            result = strlen(input_string);
    }

    printf("%d\n", result);

    return 0;
}
