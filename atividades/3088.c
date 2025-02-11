#include <stdio.h>

#define MAX 12345

int main(int argc, char **argv)
{
    char input_string[MAX];

    while (~scanf("%[^\n]%*c", input_string))
    {
        int index = 0;
        while (input_string[index])
        {
            if (input_string[index] == ' ')
            {
                if (input_string[index + 1] == ',' || input_string[index + 1] == '.')
                {
                    putchar_unlocked(input_string[index + 1]);
                    ++index;
                }
                else
                {
                    putchar_unlocked(input_string[index]);
                }
            }
            else
            {
                putchar_unlocked(input_string[index]);
            }

            ++index;
        }

        putchar_unlocked('\n');
    }

    return 0;
}
