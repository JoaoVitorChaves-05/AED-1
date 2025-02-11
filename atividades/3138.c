#include <stdio.h>
#include <string.h>

typedef struct cor
{
    int quantidade;
    long long hash_val;
} cor_t;

long long calcular_hash(const char *);
int procurar_cor(long long, size_t tamanho, cor_t *);
unsigned long long calcular_fatorial(unsigned long long);

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);

    size_t i = 0UL;
    char nome_cor[23] = {0};
    cor_t cores[23] = {0};
    int quantidade = 0;

    while (n--)
    {
        scanf("%s %d", nome_cor, &quantidade);

        long long hash_val = calcular_hash(nome_cor);
        int indice = procurar_cor(hash_val, i, cores);

        if (indice >= 0)
            cores[indice].quantidade += quantidade;
        else
            cores[i].hash_val = hash_val, cores[i++].quantidade = quantidade;
    }

    unsigned long long soma_fatoriais = 1LLU;
    unsigned long long total_elementos = 0LLU;
    for (size_t j = 0UL; j < i; ++j)
        soma_fatoriais *= calcular_fatorial(cores[j].quantidade), total_elementos += cores[j].quantidade;

    puts("Feliz aniversario Tobias!");
    printf("%llu\n", calcular_fatorial(total_elementos) / soma_fatoriais);

    return 0;
}

unsigned long long calcular_fatorial(unsigned long long n)
{
    if (n <= 1)
        return 1;
    return n * calcular_fatorial(n - 1);
}

long long calcular_hash(const char *string)
{
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_val = 0;
    long long p_pow = 1;

    for (size_t i = 0; string[i]; ++i)
    {
        hash_val = (hash_val + (string[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }

    return hash_val;
}

int procurar_cor(long long hash, size_t tamanho, cor_t *cores)
{
    for (size_t i = 0; i < tamanho; ++i)
        if (hash == cores[i].hash_val)
            return i;
    return -1;
}
