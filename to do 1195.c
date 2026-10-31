/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 31/10/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : Ententer o pre, in e pos.
-------------------------------------------------------------------------- */
#include <stdio.h>

typedef struct no
{
    int valor;
    struct no *esq;
    struct no *dir;

} no;

void imprime(int resultado[], int tamanho)
{
    for (int w; w < tamanho; w++)
    {
        printf(" %d", resultado[w]);
    }
    printf("\n");
    return;
}

void pre()
{
    return;
}

void in()
{
    return;
}

void pos()
{
    return;
}

int main()
{
    int caso;
    scanf("%d", &caso);
    for (int i = 0; i < caso; i++)
    {
        int k;
        scanf("%d", &k);

        int vetor[k];
        int resultado[k];
        for (int i2; i2 < k; i2++)
        {
            scanf("%d", &vetor[i2]);
        }

        printf("Case %d:\n", caso + 1);

        pre();
        printf("Pre.:");
        imprime(resultado, k);

        in();
        printf("In..:");
        imprime(resultado, k);

        pos();
        printf("Post:");
        imprime(resultado, k);
        printf("\n");
    }
    return 0;
}
