/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 18/11/2026
Objetivo    : Verificar se em grafos direcionados tem um caminho circular.
Dificuldade : Entender DFS e o problema.
Uso de IA   : Entender e aplicar DFS, entender o problema.
-------------------------------------------------------------------------- */
#include <stdio.h>

int inicio[10005];
int destino[30005];
int proximo[30005];
int estado[10005]; // 0 = nao visitado, 1 = visitando, 2 = ja visitado

int dfs(int atual) {
    estado[atual] = 1;

    int i = inicio[atual];
    while (i != -1) {
        int vizinho = destino[i];

        if (estado[vizinho] == 1) {
            return 1; // achou ciclo
        }
        if (estado[vizinho] == 0) {
            if (dfs(vizinho) == 1) {
                return 1;
            }
        }
        i = proximo[i];
    }

    estado[atual] = 2;
    return 0;
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int documentos, dependencias;
        scanf("%d %d", &documentos, &dependencias);

        for (int i = 1; i <= documentos; i++) {
            inicio[i] = -1;
            estado[i] = 0;
        }

        for (int i = 0; i < dependencias; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            destino[i] = b;
            proximo[i] = inicio[a];
            inicio[a] = i;
        }

        int tem_loop = 0;
        for (int i = 1; i <= documentos; i++) {
            if (estado[i] == 0) {
                if (dfs(i) == 1) {
                    tem_loop = 1;
                    break;
                }
            }
        }

        if (tem_loop == 1) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
