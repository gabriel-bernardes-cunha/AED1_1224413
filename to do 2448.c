/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 27/09/2026
Objetivo    : Calcular quantos números passo em um vetor, seguindo uma ordem dada.
Dificuldade : Inserir a busca binária no problema dado.
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

// Busca binária pura para achar o índice da casa
int busca_binaria(int casas[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (casas[meio] == x) return meio;
        if (casas[meio] < x) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int casas[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &casas[i]);
    }

    long long tempo = 0;
    int atual = 0; // O carteiro começa na casa de índice 0

    for (int i = 0; i < m; i++) {
        int encomenda;
        scanf("%d", &encomenda);

        int destino = busca_binaria(casas, n, encomenda);
        
        // Soma a distância absoluta entre a posição atual e o destino
        tempo += abs(destino - atual);
        atual = destino; // Atualiza a posição do carteiro
    }

    printf("%lld\n", tempo);
    return 0;
}
