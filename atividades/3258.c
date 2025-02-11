#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ARRAY_SIZE 1234

int num_elements;
double ratio;
int element_values[MAX_ARRAY_SIZE];

int calculate_min_cuts(int, double, double, int);
int compare_values(const void *, const void *);

static inline double get_max(double a, double b)
{
    return a > b ? a : b;
}

static inline double get_min(double a, double b)
{
    return a < b ? a : b;
}

int main()
{
    scanf("%lf %d", &ratio, &num_elements);

    for (int i = 0; i < num_elements; ++i)
        scanf("%d", &element_values[i]);

    qsort(element_values, num_elements, sizeof(int), compare_values);
    printf("%d\n", calculate_min_cuts(0, element_values[0], element_values[0], 0));

    return 0;
}

int calculate_min_cuts(int index, double current_min, double current_max, int current_cuts)
{
    if (index == num_elements)
        return current_cuts;

    double max_possible_value = current_min / ratio;
    double min_possible_value = current_max * ratio;
    int lower_bound = (int)ceil(element_values[index] / max_possible_value);
    int upper_bound = (int)(element_values[index] / min_possible_value);

    if (index == 0)
        lower_bound = 1, upper_bound = element_values[0];

    for (int i = lower_bound; i <= upper_bound; ++i)
    {
        double new_value = element_values[index] / i;

        if (index == 0)
            current_min = current_max = new_value;

        int result = calculate_min_cuts(index + 1, get_min(current_min, new_value), get_max(current_max, new_value), current_cuts + i - 1);
        if (result != -1)
            return result;
    }

    return -1;
}

int compare_values(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
