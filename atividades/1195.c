#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int chave;
    struct Nodo *pai, *esq, *dir;
};

struct Arvore {
    struct Nodo* raiz;
};

void inicializaNodo(struct Nodo *nodo) {
    nodo->chave = 0;
    nodo->pai = NULL;
    nodo->esq = NULL;
    nodo->dir = NULL;
}

void destroiNodo(struct Nodo *nodo) {
    if (nodo == NULL) {
        return;
    }
    nodo->chave = 0;
    nodo->pai = NULL;
    destroiNodo(nodo->esq);
    destroiNodo(nodo->dir);
    free(nodo);
}

void inicializaArvore(struct Arvore *arvore) {
    arvore->raiz = NULL;
}

void destroiArvore(struct Arvore *arvore) {
    destroiNodo(arvore->raiz);
}

struct Nodo* adicionaNodo(struct Nodo *nodo, int chave) {
    if (nodo == NULL) {
        nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
        inicializaNodo(nodo);
        nodo->chave = chave;
    } else {
        if (chave < nodo->chave) {
            nodo->esq = adicionaNodo(nodo->esq, chave);
            if (nodo->esq != NULL) {
                nodo->esq->pai = nodo;
            }
        } else if (chave > nodo->chave) {
            nodo->dir = adicionaNodo(nodo->dir, chave);
            if (nodo->dir != NULL) {
                nodo->dir->pai = nodo;
            }
        }
    }
    return nodo;
}

void adicionaArvore(struct Arvore *arvore, int chave) {
    arvore->raiz = adicionaNodo(arvore->raiz, chave);
}

struct Nodo* buscaNodo(struct Nodo *nodo, int chave) {
    if (nodo == NULL) {
        return NULL;
    } else if (chave < nodo->chave) {
        return buscaNodo(nodo->esq, chave);
    } else if (chave == nodo->chave) {
        return nodo;
    } else {
        return buscaNodo(nodo->dir, chave);
    }
}

int buscaArvore(struct Arvore *arvore, int chave) {
    return buscaNodo(arvore->raiz, chave) != NULL;
}

void removeNodo(struct Nodo *nodo) {
    if (nodo == NULL) {
        return;
    }

    struct Nodo* pai = nodo->pai;
    if (nodo->esq == NULL && nodo->dir == NULL) {
        if (pai != NULL) {
            if (pai->esq == nodo) {
                pai->esq = NULL;
            } else {
                pai->dir = NULL;
            }
        }
        destroiNodo(nodo);
    } else if (nodo->esq == NULL || nodo->dir == NULL) {
        struct Nodo *filho = nodo->esq != NULL ? nodo->esq : nodo->dir;
        if (pai != NULL) {
            if (pai->esq == nodo) {
                pai->esq = filho;
            } else {
                pai->dir = filho;
            }
        }
        destroiNodo(nodo);
    } else {
        struct Nodo* sucessor = nodo->dir;
        while (sucessor->esq != NULL) {
            sucessor = sucessor->esq;
        }
        nodo->chave = sucessor->chave;
        removeNodo(sucessor);
    }
}

void removeArvore(struct Arvore* arvore, int chave) {
    struct Nodo* nodo = buscaNodo(arvore->raiz, chave);

    if (nodo != NULL && nodo->pai == NULL) {
        if (nodo->esq == NULL && nodo->dir == NULL) {
            arvore->raiz = NULL;
        } else if (nodo->esq == NULL || nodo->dir == NULL) {
            arvore->raiz = nodo->esq != NULL ? nodo->esq : nodo->dir;
        }
    }
    removeNodo(nodo);
}

void prefixaNodo(struct Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }

    printf(" %d", nodo->chave);
    prefixaNodo(nodo->esq);
    prefixaNodo(nodo->dir);
}

void prefixaArvore(struct Arvore* arvore) {
    printf("Pre.:");
    prefixaNodo(arvore->raiz);
    printf("\n");
}

void infixaNodo(struct Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }

    infixaNodo(nodo->esq);
    printf(" %d", nodo->chave);
    infixaNodo(nodo->dir);
}

void infixaArvore(struct Arvore* arvore) {
    printf("In..:");
    infixaNodo(arvore->raiz);
    printf("\n");
}

void posfixaNodo(struct Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }

    posfixaNodo(nodo->esq);
    posfixaNodo(nodo->dir);
    printf(" %d", nodo->chave);
}

void posfixaArvore(struct Arvore* arvore) {
    printf("Post:");
    posfixaNodo(arvore->raiz);
    printf("\n");
}

int main() {
    int i, k, C, N, x;
    struct Arvore arvore;

    scanf("%d\n", &C);
    for (k = 1; k <= C; ++k) {
        scanf("%d\n", &N);

        inicializaArvore(&arvore);
        for (i = 0; i < N; ++i) {
            scanf("%d", &x);
            adicionaArvore(&arvore, x);
        }

        printf("Case %d:\n", k);
        prefixaArvore(&arvore);
        infixaArvore(&arvore);
        posfixaArvore(&arvore);
        printf("\n");

        destroiArvore(&arvore);
    }

    return 0;
}
