/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 11/10/2026
Objetivo    : Verificar se consigo reorganizar números conforme desejado.
Dificuldade : Entender a lógica por trás do confuso enunciado do exercício e também realizar o algoritimo de verificação em si.
Uso de IA   : Perceber que precisava de vários pop na estação.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int x;
    struct no *seg;
} no;

void push(no **head, int numero)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->x = numero;
    novo->seg = *head;
    *head=novo;

    return;
}

void pop(no **head)
{
    if ((*head) == NULL)
        return;

    no *atual = *head;
    *head = (*head)->seg;
    free(atual);

    return;
}

void imprime(int resultado)
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
{ // A priori, vamos dividir em dois laços: o de *Números* e o de *Casos*. Veja que ambos tem a entrada 0 como parada.

    while (1) // Laço que controla cada caso de *número* de elementos de vagão, não cada caso de entrada, (N).
    {
        int N;           // Número de elementos.
        scanf("%d", &N); // Lê o número de elementos

        if (N == 0) // Este é o fim do laço de números.
            break;  // Este seria o segundo zero, ou seja, o fim das entradas.

        while (1) // Laço que controla cada *caso* de entrada vagão, não cada número, (eg: 1 3 2 5 4 6...).
        {
            int E[N];        // Cria o vagão que vai entrar.
            int S[N];        // Cria o vagão que vai sair.
            int termino = 1; // Esta variável vai controlar a saída do laço de casos.

            for (int k = 0; k < N; k++)
            {
                scanf("%d", &E[N - k - 1]); /*O "N-k-1" é apenas um método para preencher o vagão ao contrário, visto que a entrada nos
                    dá o vagão de forma inversa (eg: "5 4 3 2 1", mas perceba que ele vai entrar na estação como "1 2 3 4 5" )*/

                if (E[N - 1] == 0) // Caso a primeira entrada seja zero, indica o fim da entrada do laço de casos.
                {
                    termino = 0; // Indica o fim do laço de casos.
                    break;
                }
            }

            if (termino == 0)
            {
                break; // Saída do laço de casos, conforme uma entrada "0".
            }

            // Caso não saia, então o vetor E[] teve já possui todos os elementos. Então vamos, agora, preencher a saída esperada:
            for (int k = 0; k < N; k++)
            {
                S[k] = N - k; // Veja que a saída é uma ordem de N elementos decrescente, por isso "N-k".
            }

            // Com ambos vetores preenchidos, vamos começar a analisar.
            no *head = NULL;
            int i = 0;
            int o = 0; // Percorrerão os vetores, E[i] e S[o].

            for (int k = 0; k < N; k++)
            { // Há duas condições de "colocar" o elemento no vagão de saída: Saindo da estação (pilha) ou direto do vagão de entrada.

                if (E[i] == S[o]) // Quando sai direto do vagão de entrada.
                {
                    E[i] = 0;
                    i++; /*Esvazia o "espaço" de E*/
                    S[o] = 0;
                    o++; /*Ocupa o "espaço" de S*/
                }
                else
                { // Caso não tenha como ir direto, analisemos a estação:

                    if (head != NULL && head->x == S[o]) // Consigo tirar algum vagão lá de dentro? (No caso, o último vagão a entrar)
                    {
                        
                        pop(&head); // Retiro da estação.

                        S[o] = 0;
                        o++; /*Ocupa o "espaço" de S*/
                    }
                    else
                    {

                        // Caso eu não consiga colocar o último elemento da estação, só coloco, na estação, o elemento da entrada.
                        push(&head, E[i]); // Coloco na estação o outro vagão

                        E[i] = 0;
                        i++; /*Esvazia o "espaço" de E*/
                    }
                }
            }
            // Meu vagão de entrada está vazio.

            // Percebe que, mesmo acabando o laço, posso ainda ter elementos na pilha, vamos tentar esvaziar.
            int resultado = 0; // Vai ditar se deu certo. Caso resultado = 0, deu certo.

            while (head != NULL)
            {
                // Analisemos a estação:

                if (head != NULL && head->x == S[o]) // Consigo tirar algum vagão lá de dentro? (No caso, o último vagão a entrar)
                {
                    pop(&head); // Retiro da estação.

                    S[o] = 0;
                    o++; /*Ocupa o "espaço" de S*/
                }
                else
                {
                    while (head != NULL)
                    {
                        pop(&head);
                    }
                    resultado = 1;
                    break;
                }
            }
            // Se conseguir esvaziar a estação, deu certo e reusltado = 0;
            imprime(resultado);
        }
    }
    return 0;
}
