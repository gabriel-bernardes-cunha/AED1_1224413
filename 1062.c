/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 29/09/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>

void avalia(int wagon[])
{
    if ()
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return;
}

int main()
{
    while (1)
    {
        int N; // Número de elementos.
        scanf("%d", &N);

        int wagon[N]; // Cria o vagão a ser manipulado.

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &wagon[i]);
            if (i == N - 1)
            {
                i = 0; // Reinicio o caso, quando acabar o vagão
                // Vamos avaliar o vagão preenchido:

                avalia(wagon);

                // Veja que não vou me dar o trabalho de esvaziar o vagão pois não é necessário.
            }
            else if (wagon[i] == 0)
            {
                break; // Condição de parada de cada caso.
            }
        }
    }
    return 0;
}
