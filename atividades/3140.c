#include <string.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char input_line[1100];
    bool inside_body = false;

    while (~scanf("%[^\n]%*c", input_line))
    {
        if (strstr(input_line, "<body>"))
        {
            inside_body = true;
            continue;
        }

        if (inside_body && strstr(input_line, "</body>"))
            inside_body = false;

        if (inside_body)
            puts(input_line);
    }

    return 0;
}
