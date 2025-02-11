#include <stdio.h>
#include <math.h>

double variance;

double gaussian_function(double x)
{
    return exp(-x * x / (variance * 2));
}

double probability(double lower_radius, double upper_radius)
{
    return gaussian_function(lower_radius) - gaussian_function(upper_radius);
}

int main()
{
    double radii_values[7] = {0.0};
    double expected_points[] = {50.0, 25.0, 10.5, 31.5, 10.5, 21.0};

    for (int i = 1; i <= 6; ++i)
        scanf("%lf", &radii_values[i]);

    double standard_deviation;
    scanf("%lf", &standard_deviation);

    variance = standard_deviation * standard_deviation;

    double expected_value = 0.0;

    for (int i = 0; i < 6; ++i)
        expected_value += (probability(radii_values[i], radii_values[i + 1]) * expected_points[i]);

    printf("%.10g\n", expected_value);

    return 0;
}
