/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 03/09/2026
Objetivo    : Reorganizar uma pilha de cartas e dizer a ordem de remoção
Dificuldade : Realizar a função de reorganizar as cartas.
Uso de IA   : Sintaxe (Conflitos de typedef e tag na struct e anotação de
ponteiros (cabeça->seg e *cabeça->seg) ) e um loop infinito no printf final.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct carta
{
    int numero;
    struct carta *seg;
} carta;

void organiza(carta **head, int n) // Estabelece a fila inicial.
{
    carta *bye = (carta *)malloc(sizeof(carta));

    bye->numero = n; // O número da carta, sua identidade, não posição.
    // Apenas nomeando, exemplo: carta 2 se chama "2".

    bye->seg = NULL; // Nada após.

    if (*head == NULL)
    {
        *head = bye;
    }
    else
    {
        carta *atual = *head;
        while (atual->seg != NULL)
        {
            atual = atual->seg;
        }
        atual->seg = bye;
    }

    return;
}
void reorganiza(carta **head, int *descarte, int i, int n) // Coloca a carta seguinte na base.
{
    descarte[i] = (*head)->numero; // Para lembrar a ordem de descarte, qual carta estou descartando.

    carta *atual = *head; // Removeremos a esta cabeça.

    // n é quantas cartas ainda tenho no baralho.
    if (n == 2)
    {
        *head = (*head)->seg; // A segunda carta vira a nova cabeça
        (*head)->seg = NULL;
        free(atual); // Libera a carta descartada
        return;
    }

    else
    {
        int contador = 0; // Esse cara vai contar até nossa terceira carta.
        carta *nova;      // Será o espaço momentâneo da nova cabeça

        while (atual->seg != NULL)
        {
            contador++;
            atual = atual->seg;

            if (contador == 2)
            {
                nova = atual; // Aponta para terceira carta, assim não "perco a cabeça" depois.
            }
        }

        atual->seg = (*head)->seg; // Última aponta para segunda.
        (*head)->seg->seg = NULL;  // Segunda (nova última) aponta para nada (fim fa fila).

        atual = *head; // REUTILIZO o ponteiro atual para armazenar a cabeça antiga para a liberar depois.

        *head = nova; // Coloca a terceira carta como a nova cabeça!
    }
    free(atual);
    return;
}

int main()
{
    int n;

    while (scanf("%d", &n))
    {

        if (n == 0)
        {
            break;
        } // Fim do programa.

        carta *head = NULL; // Cria a cabeça.

        int *descarte; // Guardará a ordem da pilha de descarte.
        descarte = (int *)malloc(n * sizeof(int));

        //
        for (int o = 1; o < n + 1; o++) // Primeiro, cria a sequência original.
        {
            // A priori, organiza a FILA a ser alterada. Organizada de cima para baixo (começa do 1)
            organiza(&head, o);
        }

        for (int i = 1; i < n; i++) // Veja (n-1) laços, pois a última não será removida
        {
            reorganiza(&head, descarte, i - 1, n - i + 1);
            //(cabeça, ordem de descarte, qual carta vou descartar, quantas cartas ainda há).
        }

        printf("Discarded cards: %d", descarte[0]);

        if (n != 1) // Caso só tenha uma carta
        {
            for (int m = 1; m < n - 1; m++)
            {
                printf(", %d", descarte[m]);
            }
        }

        free(descarte);

        printf("\nRemaining card: %d\n", head->numero);
    }
    return 0;
}
