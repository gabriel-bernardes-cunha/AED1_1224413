/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1340
Data        : 16/09/2026
Objetivo    : 
Dificuldade : Construir cada verificação. 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int queue()
{
    if ()
    { // Se for fila.
        return 1;
    }
    else
    { // Se não for fila.
        return 0;
    }
}

int stack()
{
    if ()
    { // Se for pilha
        return 2;
    }
    else
    { // Se não for
        return 0;
    }
}

int priority_queue()
{
    if ()
    { // Se for fila de prioridade.
        return 3;
    }
    else
    { // Se não for fila de prioridade.
        return 0;
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int resultado = 0;
        resultado = resultado + queue();
        resultado = resultado + stack();
        resultado = resultado + priority_queue();

        switch (resultado)
        {
        case 0:
            printf("impossible");

        case 1:
            printf("queue");

        case 2:
            printf("stack");

        case 3:
            printf("priority queue");

        default:
            printf("not sure");
        }
    }
    return 0;
}
