/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 20/08/2026
Objetivo    : Descobrir o maior número e sua posição em uma lista de 100 números.
Dificuldade : Acabei confundindo o laço. 
Uso de IA   : Descobrir o que estava confundindo no laço (estava i > 100, era pra ser o oposto).
-------------------------------------------------------------------------- */
#include <stdio.h>

int main()
{
    int X[100], Maior, Posicao;

    for (int i = 0; i < 100; i++)
    {

        scanf("%d", &X[i]);

        if (i == 0)
        {
            Maior = X[i];
            Posicao = i;
        }

        if (X[i] > Maior)
        {
            Maior = X[i];
            Posicao = i;
        }
    }
    printf("%d\n%d\n", Maior, Posicao + 1);

    return 0;
}
