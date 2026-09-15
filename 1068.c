/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 15/09/2026
Objetivo    : Determinar se "()" está correto em expressões algébricas.
Dificuldade : Executar pilhas corretamente.
Uso de IA   : Não foi usada.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

// Como é uma base para o uso de pilhas, tomei a liberdade de usar a analogia com pratos.

typedef struct prato
{
    struct prato *seg;
} prato;

void push(prato **head)
{
    prato *novo = (prato *)malloc(sizeof(prato)); // Aloca espaço pro novo elemento.
    if (*head == NULL)
    {
        (*head) = novo;
        (*head)->seg = NULL;
        return;
    }
    else
    {
        novo->seg = *head; // Coneta o próximo prato ao topo.
        (*head) = novo;    // Novo prato é a nova cabeça.

        return;
    }
}

int pop(prato **head)
{
    if ((*head) == NULL) // Caso tenha mais ")".
    {

        return 0; // A expressão está incorreta.
    }
    // Caso não, ele só remove.
    prato *atual = *head; // Guarda o prato a ser retirado.
    *head = (*head)->seg; // O próximo é o "novo topo".

    free(atual); // Descarta o "conjunto de parênteses".
    return 1;    // Até agora, então, tudo certo.
}

int main()
{
    char expressao[1001];
    while (scanf("%s", expressao) != EOF)
    {
        prato *head = NULL;
        int valor = 1; // Determina se a expressão está correta, "por hora", sim.

        /* A dois modos para ver se está errado, ou tem mais "(" ou ")". Assim,
        deverá ser feitos duas verificações distintas*/

        // 1o: Mais ")", uma hora irá retirar um prato inexistente? ERRADO! (A)
        // 2o: Mais "(" caso acabe o laço mas ainda tem pratos? ERRADO! (B)

        // Começemos a analisar a expressão
        for (int i = 0; expressao[i] != '\0'; i++)
        {
            if (expressao[i] == '(')
            {
                push(&head);
            }
            else if (expressao[i] == ')')
            {
                valor = pop(&head);
                /* Diferente de push, a pop há uma verificação (B),
                então é uma função do tipo int*/
            }

            // Checa se está errado, caso sim, já quebra o laço.
            if (valor == 0)
            {
                printf("incorrect\n");
                break; /* Perceba que não há a necessidade algum de mais um "free".
                Pois como há mais ")", é garantido que não há mais pratos.*/
            }
        }

        // O laço acabou, agora basta realizarmos a outra verificação (A).
        if (valor != 0 && head == NULL)
        {
            printf("correct\n");
        }
        else if (valor !=0)
        {
            printf("incorrect\n");
        }

        // Antes de retornar e sair da expressão, sejamos bons cidadãos e vamos dar "free" em tudo.
        while (head != NULL)
        {
            prato *atual;
            atual = head;
            head = head->seg;
            free(atual);
        }
    }

    return 0;
}
