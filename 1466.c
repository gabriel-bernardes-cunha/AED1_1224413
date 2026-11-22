/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 22/11/2026
Objetivo    : Descrever em uma fila por nível uma árvore de busca
Dificuldade : Entender como faria isso dada uma árvore e não uma matriz
Uso de IA   : Realizar o BFS na árvore e na parte do "no *fila[]".
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *esq;
    struct no *dir;
} no;

no *inserir(no *r, int x)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->valor = x;

    if (r == 0)
        return novo;
    no *atual = r;
    no *anterior = NULL;
    while (atual != NULL)
    {
        anterior = atual;
        if (atual->valor > novo->valor)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    atual = anterior;
    if (atual->valor > novo->valor)
        atual->esq = novo;
    else
        atual->dir = novo;
    return r;
}

void bfs(no *r, no *fila[], int *inicio, int *fim)
{
    if (r == NULL)
        return;

    fila[(*fim)++] = r;

    while (*inicio < *fim)
    {
        no *atual = fila[(*inicio)++];

        if (atual->esq != NULL)
            fila[(*fim)++] = atual->esq;

        if (atual->dir != NULL)
            fila[(*fim)++] = atual->dir;
    }
}

void liberar(no *r)
{
    if (r == NULL)
        return;
    liberar(r->esq);
    liberar(r->dir);
    free(r);
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int m = 0; m < T; m++)
    {
        // Começo do caso
        int N; // Número de vértices
        scanf("%d", &N);
        no *r = NULL; // ta certo?

        // Preencheremos a árvore de busca:
        for (int n = 0; n < N; n++)
        {
            int t;
            scanf("%d", &t);

            r = inserir(r, t);
        }

        // Agora faremos um BFS para termos a listagem por nível:
        int inicio = 0;
        int fim = 0;
        no *fila[500] = {NULL};

        bfs(r, fila, &inicio, &fim);

        // Agora vamos imprimir a árvore:
        printf("Case %d:\n%d", m + 1, fila[0]->valor);

        for (int i = 1; i < fim; i++) // O FIM JÁ CONTA QUANTOS!
            printf(" %d", fila[i]->valor);

        printf("\n\n");

        liberar(r);
    }
    return 0;
}
