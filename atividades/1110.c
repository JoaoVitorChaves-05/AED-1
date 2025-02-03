#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int numero;
    struct No *proximo;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

void pop(Pilha *pilha, int *descartes);
void push(Pilha *pilha, int numero);
void moveTopo(Pilha *pilha);
void inicializarPilha(Pilha *pilha);
void limparPilha(Pilha *pilha);
short quantidadeDescartes;

void main()
{
    unsigned short carta;
    Pilha pilha;
    short i;

    while (true)
    {
        scanf("%hu", &carta);

        if (carta == 0 || carta > 50)
            return;

        inicializarPilha(&pilha);
        int descartes[carta];

        for (i = carta; i > 0; i--)
            push(&pilha, i);

        quantidadeDescartes = 0;
        pop(&pilha, descartes);

        printf("Discarded cards:");
        for (i = 0; i < quantidadeDescartes; i++)
        {
            printf(" %d", descartes[i]);
            if (i != quantidadeDescartes - 1)
                printf(",");
        }

        printf("\nRemaining card: %d\n", pilha.topo->numero);
        limparPilha(&pilha);
    }
}

void inicializarPilha(Pilha *pilha)
{
    pilha->topo = NULL;
}

void push(Pilha *pilha, int carta)
{
    No *auxiliar;
    auxiliar = (No *)malloc(sizeof(No));

    if (!auxiliar)
        exit(1);

    auxiliar->proximo = pilha->topo;
    pilha->topo = auxiliar;
    auxiliar->numero = carta;
}

void pop(Pilha *pilha, int *descartes)
{
    No *auxiliar;

    if (auxiliar)
    {
        if (!pilha->topo->proximo)
            return;

        do
        {
            auxiliar = pilha->topo;
            descartes[quantidadeDescartes++] = auxiliar->numero;
            pilha->topo = pilha->topo->proximo;
            free(auxiliar);
            moveTopo(pilha);
        } while (pilha->topo->proximo);
    }
}

void moveTopo(Pilha *pilha)
{
    No *auxiliar, *base;
    base = pilha->topo;
    auxiliar = pilha->topo;

    if (base->proximo)
    {
        while (base->proximo)
            base = base->proximo;

        pilha->topo = pilha->topo->proximo;
        auxiliar->proximo = base->proximo;
        base->proximo = auxiliar;
    }
}

void limparPilha(Pilha *pilha)
{
    No *auxiliar;
    auxiliar = pilha->topo;
    pilha->topo = NULL;
    free(auxiliar);
}
