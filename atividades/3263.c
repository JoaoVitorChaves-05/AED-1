#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *invert_bits(char *, size_t);
bool are_strings_equal(char *, char *, size_t);

int main()
{
    int num_operations;
    char original_string[1010] = {0};
    char modified_string[1010] = {0};

    scanf("%d", &num_operations);
    scanf("%s", original_string);
    scanf("%s", modified_string);

    size_t string_length = strlen(original_string);

    if ((num_operations % 2 == 1 && are_strings_equal(original_string, invert_bits(modified_string, string_length), string_length)) || 
        (num_operations % 2 == 0 && are_strings_equal(original_string, modified_string, string_length)))
    {
        puts("Deletion succeeded");
    }
    else
    {
        puts("Deletion failed");
    }

    return 0;
}

bool are_strings_equal(char *str1, char *str2, size_t len)
{
    for (int i = 0; i < len; ++i)
        if (str1[i] != str2[i])
            return false;

    return true;
}

char *invert_bits(char *str, size_t len)
{
    for (int i = 0; i < len; ++i)
        str[i] = (str[i] == '0') ? '1' : '0';

    return str;
}
