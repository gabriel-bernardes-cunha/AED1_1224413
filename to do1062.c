/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 29/09/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct prato
{
    int x;
    struct prato *seg;
} prato;

void push(prato **head, int valor)
{
    prato *novo = (prato *)malloc(sizeof(prato));
    novo->x = valor;
    novo->seg = *head;
    *head = novo;
    return;
}

pop(prato **head, int valor)
{
    prato *atual = *head;
    *head = (*head)->seg;
    // int x = atual->x;
    free(atual);
    // return x;
    return;
}

void avalia(int resultado)
{
    if (resultado == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return;
}

int main()
{
    while (1)
    {
        int N; // Número de elementos.
        scanf("%d", &N);
        if (N == 0)
            break;

        int wagon[N]; // Cria o vagão a ser manipulado.
        int out[N];   // Vagão de saída.

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &wagon[i]);
            if (i == N - 1)
            {
                i = 0; // Reinicio o caso, quando acabar o vagão
                // Vamos avaliar o vagão preenchido:
                // *Estamos na estação!* :

                prato *head = NULL;
                int p = 0;
                int z = 0;
                
                for (;;)
                {
                    push(&head, wagon[p]);
                    p++;
                    if ()
                }

                // Veja que não vou me dar o trabalho de esvaziar o vagão pois não é necessário.
            }
            else if (wagon[i] == 0)
            {
                break; // Condição de parada de cada caso.
            }
        }
    }
    return 0;
}
