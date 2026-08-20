/* --------------------------------------------------------------------------
Disciplina  : Algoritmos e Estruturas de Dados I, turma IB, 2026S2
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 20/08/2026
Objetivo    : Realizar um resolvedor de um sudoku.
Aprendizado : Revisar conceitos.
-------------------------------------------------------------------------- */
#include <stdio.h>

int vlinha(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    { // Avança as linhas.
        for (int j = 0; j < 9; j++)
        { // Avança as colunas, na linha previamente determinada.
            for (int j2 = j; j2 < 9; j2++)
            { // O termo anterior é um termo fixo "j", e iremos o comparar com o resto dos termos "j2" da linha "i".
                if (sudoku[i][j] == sudoku[i][j2])
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int vcoluna(int sudoku[9][9])
{ // Faremos a exata mesma coisa de "vlinha", apenas trocando "j" e "i".
    for (int j = 0; j < 9; j++)
    { // Avança as colunas.
        for (int i = 0; i < 9; i++)
        { // Avança as linhas, na coluna previamente determinada.
            for (int i2 = i; i2 < 9; i2++)
            { // O termo anterior é um termo fixo "i", e iremos o comparar com o resto dos termos "i2" da linha "j".
                if (sudoku[j][i] == sudoku[j][i2])
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int vbloco(int sudoku[9][9])
{
    // Primeiro avancemos de 3 em 3 (blocos são 3x3).
    for (int i = 0; i < 9; i = i + 3)
    {
        for (int j = 0; j < 9; j = j + 3)
        {
            // Agora, avancemos dentro do bloco.
            // As coordenadas i2/j2 ditarão o ponto fixo a ser analizado.
            for (int i2 = i; i2 < i + 3; i2++)
            {
                for (int j2 = j; j2 < j + 3; j2++)
                {
                    // As coordenadas i3/j3 ditarão o ponto móvel a ser comparado com o fixo.
                    /* Percebe-se que é uma lógica semelhante às verificações anteriores,
                    apenas com */
                    for (int i3 = i2; i3 < i + 3; i3++)
                    {
                        for (int j3 = j2; j3 < j + 3; j3++)
                        {
                            if (sudoku[i2][j2] == sudoku[i3][j3])
                            {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

void resultado(int instancia, int r)
{
    if (r = 0)
        printf("Instancia %d\nNAO", instancia);
    else
    {
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
        resultado(instancia, r);
        r = vcoluna(sudoku);
        resultado(instancia, r);
        r = vbloco(sudoku);
        resultado(instancia, r);

        printf("Instancia %d\nSIM", instancia);

        ncasos--; // Um caso já foi visto.
    }
    return 0;
}
