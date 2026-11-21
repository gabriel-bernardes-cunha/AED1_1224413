/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 21/11/2026
Objetivo    : Ler características de grafos e dizer sobre sua "conexão"
Dificuldade : Tentar imprimir os componentes conexos.
Uso de IA   : type cast, ver como imprimiria
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

void bfs(int grafo[26][26], int fila[], int visitado[], int *inicio, int *fim)
{
    if (*inicio == *fim)
        return;

    int z = fila[(*inicio)++];
    printf("%c,", z + 97); // Veja bem!!

    for (int i = 0; i < 26; i++)
    {
        if (grafo[z][i] == 1 && !visitado[i])
        {
            fila[(*fim)++] = i;
            visitado[i] = 1;
        }
    }
    return bfs(grafo, fila, visitado, inicio, fim);
}

int main()
{

    int N;                      // Quantidade de casos.
    scanf("%d", &N);            // Leia quantos casos.
    for (int i = 0; i < N; i++) // Cada laço para cada caso.
    {
        int v, a;               // Vértices e Arestas.
        scanf("%d %d", &v, &a); // Leia os vértices e arestas.

        int grafo[26][26] = {0}; // Inicializo a matriz de adjacência.

        // Vamos preencher a matriz, agora, vendo onde há arestas nos determinados vértices.
        for (int i2 = 0; i2 < a; i2++)
        {
            char t1, t2;
            scanf(" %c %c", &t1, &t2); // Leio a atual aresta.

            int d1 = (int)t1; // Passa para decimal.
            int d2 = (int)t2; // Idem.

            // Exemplo, a e b -97 em cada decimal, são as colunas 0 e 1, respectivamente...
            grafo[d1 - 97][d2 - 97] = 1;
            grafo[d2 - 97][d1 - 97] = 1;
        }

        int fila[26], vi = 0;
        int inicio = 0;
        int fim = 0;
        int visitado[26] = {0};

        printf("Case #%d:\n", i + 1); // Agora vamos imprimir.
        int connected = 0;

        for (int i2 = 0; i2 < v; i2++)
        {
            if (!visitado[i2])
            {
                connected++;
                inicio = 0;
                fim = 0;
                fila[fim++] = i2;
                visitado[i2] = 1;
                bfs(grafo, fila, visitado, &inicio, &fim);
                printf("\n");
            }
        }

        printf("%d connected components\n\n", connected);
    }

    return 0;
}
