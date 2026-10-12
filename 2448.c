/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 27/09/2026
Objetivo    : Calcular quantos números passo em um vetor, seguindo uma ordem dada.
Dificuldade : Inserir a busca binária no problema dado.
Uso de IA   : Entender aonde mesmo usaria busca binária.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int busca(int x, int n, int v[])
{
    // quero x, tamanho n.

    int fundo, m, teto; // fundo e teto SÃO POSIÇÕES!
    fundo = -1;
    teto = n;
    while (fundo < teto - 1) // Enquanto ainda houver "espaço".
    {
        m = (fundo + teto) / 2; // Vejo o meio.
        if (v[m] < x)
            fundo = m; // Se meu x está após o meio, procuro no "meio superior".
        else
            teto = m; // Se meu x está antes o meio, procuro no "meio inferior".
    }
    return teto; // Por que?
}

int main()
{
    int n, m; // Casas e Encomendas.
    scanf("%d %d", &n, &m);

    int casas[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &casas[i]);
    }

    int tempo = 0;
    int pos0 = 0; // Posição inicial.
    int posf = 0; // Posição final.

    int encomenda;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &encomenda);
        posf = busca(encomenda, n, casas); // n indica quantas casas tenho.

        tempo = tempo + abs(posf - pos0);
        pos0 = posf;
    }

    printf("%d\n", tempo);
    return 0;
}
