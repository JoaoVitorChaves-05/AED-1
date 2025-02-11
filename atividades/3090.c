#include <stdio.h>

void print_digits(int num);

int main(int argc, char **argv)
{
    float total_height, max_height, height_ratio;
    int num_cases, x, y, time, above_threshold, below_threshold;

    scanf("%f %f %d%*c", &total_height, &max_height, &num_cases);

    height_ratio = total_height / max_height;
    above_threshold = below_threshold = 0;

    while (num_cases--)
    {
        scanf("%d %d %u", &x, &y, &time);
        if ((float)x <= (y * height_ratio))
            above_threshold += time;
        else
            below_threshold += time;
    }

    print_digits(above_threshold);
    putchar_unlocked(' ');
    print_digits(below_threshold);
    putchar_unlocked('\n');

    return 0;
}

inline void print_digits(int num)
{
    int index = 10;
    char output_buffer[10];
    do
    {
        output_buffer[--index] = (num % 10) + '0';
        num /= 10;
    } while (num);

    do
    {
        putchar_unlocked(output_buffer[index]);
    } while (++index < 10);
}
