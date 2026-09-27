/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 27/09/2026
Objetivo    : Passar uma expressão algébrica infixa para pósfixa.
Dificuldade : Entender a notação pós fixa, como passar e como realizar isso em pilhas.
Uso de IA   : Para ver a pilha seria de operadores e não de operandos/string final. Perceber que não precisava do uso da
precedência na struct. Usei para consertar toda lógic de precedência (não a função, digo o loop i2 na main. Também assisti a uma videoaula. 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char x;         // Pois não é só números na expressão.
    struct no *seg; // Aponta para "anterior".
} no;

int precedencia(char op)
{
    int p = 0;
    if (op == ')' || op == '(')
        p = 4;
    else if (op == '^')
        p = 3;
    else if (op == '*' || op == '/')
        p = 2;
    else if (op == '+' || op == '-')
        p = 1;
    // Lembrete: tentar aplicar isso com switch.
    return p;
}

void push(no **head, char op)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->x = op;
    novo->seg = NULL;

    novo->seg = *head;
    *head = novo;

    return;
}

void pop(no **head)
{
    no *atual = *head;
    (*head) = (*head)->seg;

    free(atual);
    return;
}

int main()
{
    char a;
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++)
    {
        no *head = NULL;
        char expression[301];
        char postfix[301];

        fgets(expression, 301, stdin);
        expression[strcspn(expression, "\n")] = '\0';
        // Tenho a expressão completa em uma string.

        int length = strlen(expression);
        int k = 0; // Percorre postfix.

        for (int i2 = 0; i2 < length; i2++)
        {
            char atual = expression[i2];

            if (atual == '(')
            {
                // Abre parênteses: joga na pilha
                push(&head, atual);
            }
            else if (atual == ')')
            {
                // Fecha parênteses: desempilha até achar o '('
                while (head != NULL && head->x != '(')
                {
                    postfix[k] = head->x;
                    k++;
                    pop(&head);
                }
                if (head != NULL && head->x == '(')
                {
                    pop(&head); // Remove o '(' da pilha
                }
            }
            else
            {
                int p = precedencia(atual);

                if (p == 0)
                { 
                    // Operando (letra/número) vai direto para o postfix
                    postfix[k] = atual;
                    k++;
                }
                else
                {
                    // Operador comum (+, -, *, /, ^)
                    while (head != NULL && head->x != '(' && precedencia(head->x) >= p)
                    {
                        postfix[k] = head->x; // Coloco o privilegiado.
                        k++;
                        pop(&head); // Retiro-o da pilha.
                    }
                    push(&head, atual); // Agora podemos colocar o menos precedente na pilha.
                }
            }
        }
      
        while (head != NULL)
            {
                postfix[k] = head->x;
                k++;
                pop(&head);
            } // fim da expressão.
      
        postfix[k] = '\0'; // Como strlen(postfix) < strlen(expression), devido aos parenteses retirados.
        printf("%s\n", postfix);
    }
    return 0;
}
