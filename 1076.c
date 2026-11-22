/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1076
Data        : 22/11/2026
Objetivo    : Quantas arestas precisava (re)desenhar para desenhar um respectivo labiritno 
Dificuldade : Entender e fazer a lógica de refazer caminhos.
Uso de IA   : Entender que era só fazer 2.contador (mas contador de arestas, não de vértices)
-------------------------------------------------------------------------- */
#include <stdio.h>

void dfs(int grafo[49][49], int v, int vertices, int visitado[], int *contador)
{
    visitado[v] = 1;

    for (int i = 0; i < vertices; i++)
    {
        if (grafo[v][i] == 1 && !visitado[i])
        {
            (*contador)++;
            dfs(grafo, i, vertices, visitado, contador);
        }
    }

    return;
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int w = 0; w < T; w++)
    {
        int nodo;
        scanf("%d", &nodo);

        int vertices, arestas;
        scanf("%d %d", &vertices, &arestas);

        int grafo[49][49] = {0};
        int visitado[49] = {0};

        for (int i = 0; i < arestas; i++)
        {
            int t1, t2;
            scanf("%d %d", &t1, &t2);

            grafo[t1][t2] = 1;
            grafo[t2][t1] = 1;
        }

        int contador = 0;
        dfs(grafo, nodo, vertices, visitado, &contador);

        printf("%d\n", 2 * contador);
    }

    return 0;
}
