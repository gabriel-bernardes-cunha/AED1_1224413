/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 21/11/2026
Objetivo    : Ler características de grafos e dizer sobre sua "conexão"
Dificuldade : Tentar imprimir os componentes conexos.
Uso de IA   : type cast, ver como imprimiria, usar o qtd_out.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

void selectsort(int out[], int n)
{
    int i, j, min, t;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (out[j] < out[min])
            {
                min = j;
            }
        }
        t = out[i];
        out[i] = out[min];
        out[min] = t;
    }
}

void bfs(int grafo[26][26], int fila[], int visitado[], int *inicio, int *fim, int out[], int *qtd_out)
{
    if (*inicio == *fim)
        return;

    int z = fila[(*inicio)++];

    for (int i = 0; i < 26; i++)
    {
        if (grafo[z][i] == 1 && !visitado[i])
        {
            fila[(*fim)++] = i;
            visitado[i] = 1;
        }
    }

    out[(*qtd_out)++] = z;

    bfs(grafo, fila, visitado, inicio, fim, out, qtd_out);
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int v, a;
        scanf("%d %d", &v, &a);

        int grafo[26][26] = {0};

        for (int i2 = 0; i2 < a; i2++)
        {
            char t1, t2;
            scanf(" %c %c", &t1, &t2);

            int d1 = (int)t1;
            int d2 = (int)t2;

            grafo[d1 - 97][d2 - 97] = 1;
            grafo[d2 - 97][d1 - 97] = 1;
        }

        int fila[26];
        int inicio = 0;
        int fim = 0;
        int visitado[26] = {0};

        printf("Case #%d:\n", i + 1);
        int connected = 0;

        for (int i2 = 0; i2 < v; i2++)
        {
            if (!visitado[i2])
            {
                int out[26];
                int qtd_out = 0;

                connected++;

                inicio = 0;
                fim = 0;

                fila[fim++] = i2;
                visitado[i2] = 1;

                bfs(grafo, fila, visitado, &inicio, &fim, out, &qtd_out);

                selectsort(out, qtd_out);

                for (int k = 0; k < qtd_out; k++)
                {
                    printf("%c,", out[k] + 97);
                }
                printf("\n");
            }
        }

        printf("%d connected components\n\n", connected);
    }

    return 0;
}
