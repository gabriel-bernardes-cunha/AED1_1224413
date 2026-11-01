/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 01/11/2026
Objetivo    : Obter pós fixo de uma árvore com apenas seu pré e in.
Dificuldade : Entender o que deveria fazer.
Uso de IA   : Auxílio na construção da função build.
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
    int casos;
    if (scanf("%d", &casos) != 1) return 0;
    
    for (int i = 0; i < casos; i++)
    {
        int n;
        scanf("%d", &n);

        char pre[n + 1], in[n + 1];
        scanf("%s %s", pre, in);

        no *raiz = build(n, pre, in);
        pos(raiz);
        printf("\n"); // Apenas a quebra de linha padrão do fim do caso
        
        libera(raiz);
    }
    return 0;
}
