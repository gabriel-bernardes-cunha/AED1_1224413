/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 24/11/2026
Objetivo    : Em uma Árvore Binária de Busca, inserir, ver se existe e ditar notações (pre,in,posfixa).
Dificuldade : Sintaxe de strings e char, problemas com \n e " ".
Uso de IA   : Sintaxe como '' e "", uso de getchar, aplicação de "*primeiro" ao todo.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no
{
    char letra;
    struct no *esq;
    struct no *dir;
} no;

void existe(no *raiz, char alvo)
{
    if (raiz == NULL)
    {
        printf("%c nao existe\n", alvo);
        return;
    }

    no *atual = raiz;

    while (atual != NULL && atual->letra != alvo) // Primeiro veja NULL
    {
        if (atual->letra > alvo)
        {
            atual = atual->esq;
        }
        else
        {
            atual = atual->dir;
        }
    }

    if (atual == NULL)
        printf("%c nao existe\n", alvo);
    else
        printf("%c existe\n", alvo);
    return;
}

no *insere(no *raiz, char letter)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->letra = letter;
    novo->esq = NULL;
    novo->dir = NULL;

    if (raiz == NULL)
        return novo;

    no *atual = raiz;
    no *anterior = NULL;

    while (atual != NULL)
    {
        anterior = atual;
        if (atual->letra > novo->letra)
        {
            atual = atual->esq;
        }
        else
        {
            atual = atual->dir;
        }
    }
    atual = anterior;
    if (atual->letra > novo->letra)
    {
        atual->esq = novo;
    }
    else
    {
        atual->dir = novo;
    }
    return raiz;
}

void liberar(no *raiz)
{
    if (raiz == NULL)
        return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
    return;
}

void in(no *raiz, int *primeiro)
{
    if (raiz == NULL)
        return;

    // Percorre toda a sub-árvore esquerda
    in(raiz->esq, primeiro);

    // Imprime a raiz
    if (*primeiro)
    {
        printf("%c", raiz->letra);
        *primeiro = 0;
    }
    else
    {
        printf(" %c", raiz->letra);
    }

    // Percorre toda a sub-árvore direita
    in(raiz->dir, primeiro);
}

void pre(no *raiz, int *primeiro)
{
    if (raiz == NULL)
        return;

    // Imprime a raiz primeiro
    if (*primeiro)
    {
        printf("%c", raiz->letra);
        *primeiro = 0;
    }
    else
    {
        printf(" %c", raiz->letra);
    }

    // Percorre toda a sub-árvore esquerda
    pre(raiz->esq, primeiro);

    // Percorre toda a sub-árvore direita
    pre(raiz->dir, primeiro);
}

void pos(no *raiz, int *primeiro)
{
    if (raiz == NULL)
        return;

    // Percorre toda a sub-árvore esquerda
    pos(raiz->esq, primeiro);

    // Percorre toda a sub-árvore direita
    pos(raiz->dir, primeiro);

    // Imprime a raiz
    if (*primeiro)
    {
        printf("%c", raiz->letra);
        *primeiro = 0;
    }
    else
    {
        printf(" %c", raiz->letra);
    }
}

int main()
{
    char entrada[8], b;
    no *raiz = NULL;
    while (scanf("%s", entrada) != EOF)
    {
        int length = strlen(entrada);
        // Vamos ver se a entrada for "I/P ou o resto" (então a string terá tamanho 1)

        if (length == 1)
        {
            getchar();
            char IouP = entrada[0];
            if (IouP == 'I')
            {
                scanf("%c", &b);
                raiz = insere(raiz, b);
            }
            else
            {
                scanf("%c", &b);
                existe(raiz, b);
            }
        }

        // Caso não, vamos então ver os casos de anotação
        else
        {
            int primeiro = 1;
            if (strcmp("INFIXA", entrada) == 0)
                in(raiz, &primeiro);

            if (strcmp("PREFIXA", entrada) == 0)
                pre(raiz, &primeiro);

            if (strcmp("POSFIXA", entrada) == 0)
                pos(raiz, &primeiro);
            printf("\n");
        }
    }
    liberar(raiz);
    return 0;
}
