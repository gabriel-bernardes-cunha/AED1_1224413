/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1191
Data        : 24/11/2026
Objetivo    : Receber notações prefixa e infixa da árvore e devolver posfixa
Dificuldade : As mesmas do 1194, são problemas muito semelhantes.
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char valor;
    struct no *esq;
    struct no *dir;
} no;

void pos(no *raiz)
{
    if (raiz == NULL)
        return;

    pos(raiz->esq);
    pos(raiz->dir);
    printf("%c", raiz->valor);
}

void libera(no *raiz)
{
    if (raiz == NULL)
        return;
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

no *build(int n, char pre[], char in[])
{
    if (n <= 0)
        return NULL;

    no *raiz = (no *)malloc(sizeof(no));
    raiz->valor = pre[0];
    raiz->esq = NULL;
    raiz->dir = NULL;

    int rindice = 0;
    while (in[rindice] != pre[0])
    {
        rindice++;
    }

    raiz->esq = build(rindice, pre + 1, in);
    raiz->dir = build(n - rindice - 1, pre + 1 + rindice, in + 1 + rindice);

    return raiz;
}

int main()
{
    char prefixo[27], infixo[27];
    no *raiz = NULL;

    while (scanf("%s", prefixo) != EOF)
    {
        scanf("%s", infixo);
        int n = strlen(infixo);

        no *raiz = build(n, prefixo, infixo);
        pos(raiz);

        printf("\n");
        libera(raiz);
    }

    return 0;
}
