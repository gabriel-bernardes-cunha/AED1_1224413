/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 01/11/2026
Objetivo    : Imprimir os valores de uma árvore em certas ordens
Dificuldade : Ententer e realizar o pre, in e pos
Uso de IA   : Ententer e realizar o pre, in e pos. Liberar a árvore após cada caso.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *esq;
    struct no *dir;

} no;

no *Insere(no *r, int x)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->valor = x;

    no *atual = r;
    no *anterior = NULL;
    if (r == NULL)
        return novo;

    while (atual != NULL)
    {
        anterior = atual;
        if (atual->valor > novo->valor)
            atual = atual->esq; // Se novo for menor, vai pra esquerda.
        else
            atual = atual->dir; // Se novo for maior, vai pra direita.
    }
    // Agora já achamos, vamos apenas alocar (anterior pois atual é NULL).
    if (anterior->valor > novo->valor)
        anterior->esq = novo;
    else
        anterior->dir = novo;
    return r;
}

void pre(no *raiz)
{
    if (raiz == NULL)
        return;

    // Imprime a raiz primeiro
    printf(" %d", raiz->valor);

    // Percorre toda a sub-árvore esquerda
    pre(raiz->esq);

    // Percorre toda a sub-árvore direita
    pre(raiz->dir);
}

void in(no *raiz)
{
    if (raiz == NULL)
        return;

    // Percorre toda a sub-árvore esquerda
    in(raiz->esq);

    // Imprime a raiz
    printf(" %d", raiz->valor);

    // Percorre toda a sub-árvore direita
    in(raiz->dir);
}

void pos(no *raiz)
{
    if (raiz == NULL)
        return;

    // Percorre toda a sub-árvore esquerda
    pos(raiz->esq);

    // Percorre toda a sub-árvore direita
    pos(raiz->dir);

    // Imprime a raiz
    printf(" %d", raiz->valor);
}

void libera(no *raiz)
{
    if (raiz == NULL)
        return;
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

int main()
{
    int caso;
    scanf("%d", &caso);
    for (int i = 0; i < caso; i++)
    {
        int k; // k é total de números
        scanf("%d", &k);

        no *raiz = NULL;

        for (int i2 = 0; i2 < k; i2++)
        {
            int numero; // "numero" vai ser onde vou ler as entradas.

            scanf("%d", &numero);
            raiz = Insere(raiz, numero);
        }

        // Agora vamos imprimir:
        printf("Case %d:\n", i + 1);

        printf("Pre.:");
        pre(raiz);
        printf("\n");

        printf("In..:");
        in(raiz);
        printf("\n");

        printf("Post:");
        pos(raiz);
        printf("\n");

        printf("\n"); // No fim de cada caso.
        libera(raiz); // Boa prática.
    }
    return 0;
}
