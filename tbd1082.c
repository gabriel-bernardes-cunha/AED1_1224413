/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 10/11/2026
Objetivo    : Ler características de grafos e dizer sobre sua "conexão"
Dificuldade : 
Uso de IA   : type cast, 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int N;                      // Quantidade de casos.
    scanf("%d", &N);            // Leia quantos casos.
    for (int i = 0; i < N; i++) // Cada laço para cada caso.
    {
        int v, a;              // Vértices e Arestas.
        scanf("%d%d", &v, &a); // Leia os vértices e arestas.

        int matriz[v][v]; // Inicializo a matriz de adjacência.

        // Vamos preencher a matriz, a priori, com zeros.
        for (int i2 = 0; i2 < v; i2++)
        {
            for (int i3 = 0; i3 < a; i3++)
            {
                matriz[i2][i3] = 0;
            }
        }

        // Vamos preencher a matriz, agora, vendo onde há arestas nos determinados vértices.
        for (int i2 = 0; i2 < a; i2++)
        {
            char t1, t2;
            scanf("%c %c", &t1, &t2); // Leio a atual aresta.

            int d1 = (int)t1; // Passa para decimal.
            int d2 = (int)t2; // Idem.

            // Exemplo, a e b -97 em cada decimal, são as colunas 0 e 1, respectivamente...
            matriz[d1 - 97][d2 - 97] = 1;
        }

        // Agora vamos imprimir:
        printf("Case #%d:\n", i + 1);

        for (int i2 = 0; i2 < a; i2++)
        {
            // printf();
        }
    }

    return 0;
}
