/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 20/08/2026
Objetivo    : Realizar um resolvedor de um sudoku.
Dificuldade : Realizar a verificação no bloco 3x3.
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>

int vlinha(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    { // Avança as linhas.
        for (int j = 0; j < 9; j++)
        { // Avança as colunas, na linha previamente determinada.
            for (int j2 = j + 1; j2 < 9; j2++)
            { // O termo anterior é um termo fixo "j", e iremos o comparar com o resto dos termos "j2" da linha "i".
                if (sudoku[i][j] == sudoku[i][j2])
                {
                    return 0;
                }
            }
        }
    }
    return 1; // Caso nada dê errado, esta verificação acaba com sucesso.
}

int vcoluna(int sudoku[9][9])
{ // Faremos a exata mesma coisa de "vlinha", apenas trocando "j" e "i".
    for (int j = 0; j < 9; j++)
    { // Avança as colunas.
        for (int i = 0; i < 9; i++)
        { // Avança as linhas, na coluna previamente determinada.
            for (int i2 = i + 1; i2 < 9; i2++)
            { // O termo anterior é um termo fixo "i", e iremos o comparar com o resto dos termos "i2" da linha "j".
                if (sudoku[i][j] == sudoku[i2][j])
                {
                    return 0;
                }
            }
        }
    }
    return 1; // Caso nada dê errado, esta verificação acaba com sucesso.
}

int vbloco(int sudoku[9][9])
{
    /* Para facilitar, criemos um vetor com todos elementos, e então, verificar a linha*/
    int linha_bloco[9];

    // Primeiro avancemos de 3 em 3 (blocos são 3x3).
    for (int i = 0; i < 9; i = i + 3)
    {
        for (int j = 0; j < 9; j = j + 3)
        {
            int z = 0; // Será usado para percorrer a linha_bloco.

            // As coordenadas i2/j2 percorrerão o bloco.
            for (int i2 = i; i2 < i + 3; i2++)
            {
                for (int j2 = j; j2 < j + 3; j2++)
                {
                    linha_bloco[z] = sudoku[i2][j2];
                    z++;
                }
            }
            // Verifiquemos a linha_bloco agora:
            for (int o = 0; o < 9; o++)
            {
                for (int o2 = o + 1; o2 < 9; o2++)
                {
                    if (linha_bloco[o] == linha_bloco[o2])
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1; // Caso nada dê errado, esta verificação acaba com sucesso.
}

void resultado(int instancia, int r)
{
    if (r == 0)
        printf("Instancia %d\nNAO\n", instancia);
    else
    {
        printf("Instancia %d\nSIM\n", instancia);
        return;
    }
}
int main()
{
    // Cria uma matriz com o sudoku.
    int sudoku[9][9];

    int ncasos; // Quantas instâncias há.
    scanf("%d", &ncasos);

    int instancia = 0; // QUantas instâncias há.

    // Uma variável que dita o resultado.
    int r = 1;

    // "r" de resultado, por hora, verdade até que se prove o contrário.
    // "r=1" signficia que está correto, "r=0" mostra que está errado.

    /*Começemos, finalmente, analisar cada caso*/
    while (ncasos > 0)
    {
        instancia++; // Cada laço é uma instância.

        // Primeio, lê todas as colunas de uma mesma linha.
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                scanf("%d", &sudoku[i][j]);
            }
        }

        r = vlinha(sudoku);

        if (r == 1)
        {
            r = vcoluna(sudoku);
            if (r == 1)
            {
                r = vbloco(sudoku);
            }
        }
        resultado(instancia, r);

        ncasos--; // Um caso já foi visto.

        printf("\n"); // Imprime uma linha em branco após cada instância.
    }
    return 0;
}
