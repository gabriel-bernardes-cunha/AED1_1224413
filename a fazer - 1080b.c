/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 25/08/2026
Objetivo    : Realizar o exercício 1080 por alocação dinâmica.
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

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
