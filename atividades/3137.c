#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{

    int p;
    int v[] = {0, 9, 189, 2889, 38889, 488889};

    scanf("%d", &p);
    size_t index = (size_t)floor(log10(p));

    int k = ((int)pow(10, index) - 1);
    
    int q = p - k;

    printf("%ld\n", v[index] + (q * (index + 1)));

    return 0;
}