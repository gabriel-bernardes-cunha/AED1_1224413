/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 31/10/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : 
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
