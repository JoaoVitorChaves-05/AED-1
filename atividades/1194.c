#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No *esquerda, *direita;
} No;

No* construir_arvore(char *pre_ordem, char *in_ordem, int inicio, int fim, int *indice_pre)
{
    if (inicio > fim)
        return NULL;
    
    No *novo_no = (No*)malloc(sizeof(No));
    novo_no->dado = pre_ordem[(*indice_pre)++];
    novo_no->esquerda = novo_no->direita = NULL;
    
    if (inicio == fim)
        return novo_no;
    
    int indice_raiz;
    for (indice_raiz = inicio; indice_raiz <= fim; indice_raiz++) {
        if (in_ordem[indice_raiz] == novo_no->dado)
            break;
    }
    
    novo_no->esquerda = construir_arvore(pre_ordem, in_ordem, inicio, indice_raiz - 1, indice_pre);
    novo_no->direita = construir_arvore(pre_ordem, in_ordem, indice_raiz + 1, fim, indice_pre);
    
    return novo_no;
}

void percurso_posfixo(No *raiz)
{
    if (raiz == NULL)
        return;
    
    percurso_posfixo(raiz->esquerda);
    percurso_posfixo(raiz->direita);
    printf("%c", raiz->dado);
}

void resolver_caso(char *pre_ordem, char *in_ordem, int N)
{
    int indice_pre = 0;
    No *raiz = construir_arvore(pre_ordem, in_ordem, 0, N - 1, &indice_pre);
    percurso_posfixo(raiz);
    printf("\n");
}

int main()
{
    int C;
    scanf("%d", &C);
    
    while (C--) {
        int N;
        char pre_ordem[53], in_ordem[53];
        
        scanf("%d %s %s", &N, pre_ordem, in_ordem);
        resolver_caso(pre_ordem, in_ordem, N);
    }
    
    return 0;
}
