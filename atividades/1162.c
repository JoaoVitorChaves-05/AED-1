#include <stdio.h>

unsigned ordena(int vet[], unsigned);

void main (void)
{
    unsigned casos, tamTrem;
    unsigned i;

    scanf("%u", &casos);

    while (casos--)
    {
        scanf("%u", &tamTrem);
        int vagoes[tamTrem];

        for (i = 0; i < tamTrem; i++)
            scanf("%d", &vagoes[i]);

        printf("Optimal train swapping takes %u swaps.\n", ordena(vagoes, tamTrem));
    }
}

unsigned ordena(int vet[], unsigned tam)
{
    unsigned i, j, contador = 0, aux;

    while (tam--)
    {
        for (i = 0, j = 1; i < tam; i++, j++)
            if (vet[i] > vet[j])
            {    
                contador++;
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
    }
    return contador;
}