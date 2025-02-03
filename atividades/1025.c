#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int comparar(const void *a, const void *b);
bool buscar(unsigned *, unsigned, unsigned short);
int posicao;

void main()
{
    unsigned short i, quantidadeCasos;
    unsigned short quantidadeConsultas;
    unsigned quantidadeMarmores, numero;

    while (true)
    {
        scanf("%u %hu", &quantidadeMarmores, &quantidadeConsultas);

        if (quantidadeConsultas == 0 && quantidadeMarmores == 0)
            break;

        unsigned marmores[quantidadeMarmores];

        for (i = 0; i < quantidadeMarmores; i++)
            scanf("%u", &marmores[i]);

        qsort(marmores, quantidadeMarmores, sizeof(unsigned), comparar);

        printf("CASE# %u:\n", ++quantidadeCasos);
        while (quantidadeConsultas--)
        {
            scanf("%u", &numero);

            if (buscar(marmores, numero, quantidadeMarmores))
            {
                if (marmores[posicao - 1] == marmores[posicao])
                {
                    while (marmores[posicao - 1] == marmores[posicao])
                        posicao--;

                    printf("%u found at %u\n", numero, posicao + 1);
                }
                else
                    printf("%u found at %u\n", numero, posicao + 1);
            }
            else
                printf("%u not found\n", numero);
        }
    }
}

int comparar(const void *a, const void *b)
{
    if (*(unsigned*)a == *(unsigned *)b)
        return 0;
    else if (*(unsigned*)a > *(unsigned*)b)
        return 1;
    else
        return -1;
}

bool buscar(unsigned *marmores, unsigned numero, unsigned short tamanho)
{
    int inicio, fim, meio;
    inicio = 0;
    fim = tamanho - 1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (marmores[meio] < numero)
            inicio = meio + 1;
        else if (marmores[meio] > numero)
            fim = meio - 1;
        else
        {
            posicao = meio;
            return true;
        }
    }
    return false;
}
