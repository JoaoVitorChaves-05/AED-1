#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 112345

static inline int get_max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char first_string[MAX_LENGTH] = {0};
    char second_string[MAX_LENGTH] = {0};

    scanf("%s", first_string);
    scanf("%s", second_string);

    int prefix_match = 0, suffix_match = 0;
    size_t first_length = strlen(first_string);
    size_t second_length = strlen(second_string);

    while (prefix_match < first_length && prefix_match < second_length && first_string[prefix_match] == second_string[prefix_match])
        ++prefix_match;

    while (suffix_match < first_length && suffix_match < second_length && first_string[first_length - 1 - suffix_match] == second_string[second_length - 1 - suffix_match])
        ++suffix_match;

    suffix_match = second_length - suffix_match;
    int result = get_max(suffix_match - prefix_match, 0);

    printf("%d\n", get_max(result, second_length - first_length));

    return 0;
}
