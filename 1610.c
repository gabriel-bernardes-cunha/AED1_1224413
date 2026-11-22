/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 18/11/2026
Objetivo    : Verificar se em grafos direcionados tem um caminho circular.
Dificuldade : Entender DFS e o problema.
Uso de IA   : Entender e aplicar DFS, entender o problema, lidar com erros de memória.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

void dfs(char grafo[10005][10005], int v, int documento, int visitado[], int *ciclo)
{
    // 1 = visitando agora (está no caminho atual)
    visitado[v] = 1;

    // Percorre todos os possíveis vizinhos de 1 até documento
    for (int i = 1; i <= documento; i++)
    {
        if (grafo[v][i] == 1)
        {
            if (visitado[i] == 1)
            {
                *ciclo = 1; // Voltou para alguém que ainda estava aberto -> CICLO!
                return;
            }
            if (visitado[i] == 0)
            {
                dfs(grafo, i, documento, visitado, ciclo);
            }
        }
    }

    // 2 = já terminou de verificar todos os caminhos saindo de v
    visitado[v] = 2;
}

int main()
{
    int N;
    scanf("%d", &N);

    // 'static' mantém dentro da main sem estourar a memória da pilha
    static char grafo[10005][10005];
    int visitado[10005];

    for (int m = 0; m < N; m++)
    {
        int documento, dependencia;
        scanf("%d%d", &documento, &dependencia);

        // Zera a matriz e o vetor visitado antes de cada caso de teste
        for (int i = 1; i <= documento; i++)
        {
            visitado[i] = 0;
            for (int j = 1; j <= documento; j++)
            {
                grafo[i][j] = 0;
            }
        }

        for (int n = 0; n < dependencia; n++)
        {
            int t1, t2;
            scanf("%d%d", &t1, &t2);
            grafo[t1][t2] = 1;
        }

        int ciclo = 0;

        // Inicia a busca a partir de todos os vértices não visitados
        for (int i = 1; i <= documento; i++)
        {
            if (visitado[i] == 0)
            {
                dfs(grafo, i, documento, visitado, &ciclo);
                if (ciclo == 1)
                    break;
            }
        }

        if (ciclo == 1)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
