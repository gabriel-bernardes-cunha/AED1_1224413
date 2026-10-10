/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 03/09/2026
Objetivo    : Reorganizar uma pilha de cartas e dizer a ordem de remoção
Dificuldade : Realizar a função de reorganizar as cartas.
Uso de IA   : Sintaxe (Conflitos de typedef e tag na struct e anotação de
ponteiros (cabeça->seg e *cabeça->seg) ) e um loop infinito: no printf final e regorganiza (last->seg=NULL).
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int numero;
    struct no *seg;
} no;

void push(no **head, int n) // Estabelece a fila inicial.
{
    no *novo = (no *)malloc(sizeof(no));

    novo->numero = n; // O número da carta, sua identidade, não posição.
    // Apenas nomeando, exemplo: carta 2 se chama "2".
    novo->seg = NULL; // Nada após.

    if (*head == NULL)
    {
        *head = novo;
    }
    else
    {
        no *atual = *head;
        while (atual->seg != NULL)
        {
            atual = atual->seg;
        }
        atual->seg = novo;
    }

    return;
}

int pop(no **head, int *descarte, int k)
{
    descarte[k] = (*head)->numero; // Já descarto a carta e a guardo na pilha de descarte.

    no *atual = *head;
    *head = (*head)->seg; // Tiro da fila a carta do topo.
    free(atual);

    k++; // Retorno k++ pois ele percorre o vetor de descarte.
    return k;
}

void reorganiza(no **head) // Coloca a carta seguinte na base.
{
    /*Caso especial: com exercício mental, você percebe que sempre vai acabar com uma carta indo para baixo dela mesma.
    Neste caso, (*head)->seg = NULL indica o fim da lista: */
    if ((*head)->seg == NULL)
    {
        return;
    }

    no *last = *head;     // A carta a ser posta por último.
    *head = (*head)->seg; // Já coloco a próxima como a primeira.

    no *atual = *head;
    while (atual->seg != NULL)
    {
        atual = atual->seg;
    }
    atual->seg = last;
    last->seg = NULL;

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
        } // Fim do programa, quando n = 0.

        no *head = NULL; // Cria a cabeça.

        int *descarte;                             // Guardará a ordem da pilha de descarte.
        descarte = (int *)malloc(n * sizeof(int)); // Alocação dinâmica do vetor pilha de descarte.
        int k = 0;                                 // Será usado para percorrer o vetor descarte.

        for (int i = 1; i < n + 1; i++) // Primeiro, cria a sequência original.
        {
            // A priori, organiza a FILA a ser alterada. Organizada de cima para baixo (começa do 1)

            push(&head, i); // Neste caso o "i", além de realizar o laço, já vai contar também como o número de cada carta.
        }

        while (head->seg != NULL)
        {
            k = pop(&head, descarte, k); // Tiro a primeira carta ("k=" apenas memoriza a posição do vetor descarte).

            reorganiza(&head); // Tiro a segunda carta, para baixo.
        }

        int valor = head->numero; // Salvo o valor da útlima carta.
        free(head);               // Libero sua alocação dinâmica, pois percebea que o loop anterior não faz isso.

        if (n > 1)
        {
            printf("Discarded cards: %d", descarte[0]);
            for (int m = 1; m < n - 1; m++)
            {
                printf(", %d", descarte[m]);
            }

            printf("\n");
        }
        else
        {
            printf("Discarded cards:\n");
        }

        free(descarte);

        printf("Remaining card: %d\n", valor);
    }
    return 0;
}
