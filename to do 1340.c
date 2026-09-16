/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1340
Data        : 16/09/2026
Objetivo    : Analisar qual estrutura de dados é.
Dificuldade : Construir cada verificação. 
Uso de IA   : Esqueci do break no switch.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int queue(int act[], int estrutura[], int n)
{ // FIFO, assim, vamos ver se as sequências de 1 e 2 são idênticas:
    int seq1[n], seq2[n], valor = 0;

    int x1, x2, i = 0; // Determina o decorrimento dos vetores.
    x1 = 0;            // Idem p seq1
    x2 = 0;            // Idem p seq2

    for (int i = 0; i < n; i++)
    {
        if (act[i] == 1)
        {
            seq1[x1] = estrutura[i];
            x1++;
        }
        else // act[i] == 2
        {
            seq2[x2] = estrutura[i];
            /* A partir da primeira "retirada", podemos começar a deliberar sobre a
            natureza da estrutura em mãos*/

            if (seq1[x2] != seq2[x2])
            { // O valor que acabei de tirar deve ser igual ao primeiro que coloquei.
                valor = 1;
                break;
            }
            x2++;
        }
    }

    if (valor == 0)
    { // Se for fila.
        return 1;
    }

    else
    { // Se não for fila.
        return 0;
    }
}

int stack(int act[], int estrutura[], int n)
{ // LIFO, assim,
    int seq1[n], seq2[n], valor = 0;

    int x1, x2, i = 0; // Determina o decorrimento dos vetores.
    x1 = 0;            // Idem p seq1
    x2 = 0;            // Idem p seq2

    for (int i = 0; i < n; i++)
    {
        if (act[i] == 1)
        {
            seq1[x1] = estrutura[i];
            x1++;
        }
        else // act[i] == 2
        {
            seq2[x2] = estrutura[i];

            /* A partir da primeira "retirada", podemos começar a deliberar sobre a
            natureza da estrutura em mãos*/

            if (seq2[x2] != seq1[x1 - 1])
            { // O valor que acabei de tirar deve ser igual ao que acabei de o colocar.
                valor = 1;
                break;
            }

            x2++;
        }
    }

    if (valor == 0)
    { // Se for pilha.
        return 2;
    }

    else
    { // Se não for pilha.
        return 0;
    }
}

int priority_queue(int act[], int estrutura[], int n)
{
    int seq1[n], seq2[n], valor = 0;

    int x1, x2, i = 0; // Determina o decorrimento dos vetores.
    x1 = 0;            // Idem p seq1
    x2 = 0;            // Idem p seq2

    /*Diferentemente dos outros laços,
    este também terá um modo de mostrar o maior de seq1 */
    int maior = 0;

    for (int i = 0; i < n; i++)
    {
        if (act[i] == 1)
        {

            seq1[x1] = estrutura[i];

            if (seq1[x1] > maior)
            {
                maior = seq1[x1];
            }
            x1++;
        }
        else // act[i] == 2
        {
            seq2[x2] = estrutura[i];

            /* A partir da primeira "retirada", podemos começar a deliberar sobre a
            natureza da estrutura em mãos*/

            if (seq2[x2] != maior)
            { // O valor que acabei de tirar deve ser ao maior de seq1.
                valor = 1;
                break;
            }

            x2++;
        }
    }
    if (valor == 0)
    { // Se for fila de prioridade.
        return 3;
    }
    else
    { // Se não for fila de prioridade.
        return 0;
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        // A priori, vamos guardar a estrutura.
        int estrutura[n];
        int act[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &act[i]);       // A ação, 1 ou 2.
            scanf("%d", &estrutura[i]); // Qual número.
        }

        int resultado = 0;
        resultado = resultado + queue(act, estrutura, n);
        resultado = resultado + stack(act, estrutura, n);
        resultado = resultado + priority_queue(act, estrutura, n);

        switch (resultado)
        {
        case 0:
            printf("impossible\n");
            break;

        case 1:
            printf("queue\n");
            break;

        case 2:
            printf("stack\n");
            break;

        case 3:
            printf("priority queue\n");
            break;

        default:
            printf("not sure\n");
            break;
        }
    }
    return 0;
}
