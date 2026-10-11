/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 11/10/2026
Objetivo    : Verificar se consigo reorganizar números conforme desejado.
Dificuldade : Entender a lógica por trás do confuso enunciado do exercício e também realizar o algoritimo de verificação em si.
Uso de IA   : Consertar lógica de laços e verificação (destaco que muito disso foi pelo exercício com enunciado confuso, cheguei a resolver 3 maneiras distintas pois estava bem mal formulado.
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
    *head = novo;

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
{ // A priori, vamos dividir em dois laços: o de *Números* e o de *Casos*. Veja que ambos tem a saída 0 como parada.

    while (1) // Laço que controla cada caso de *número* de elementos de vagão, não cada caso de saída, (N).
    {
        int N;           // Número de elementos.
        scanf("%d", &N); // Lê o número de elementos

        if (N == 0) // Este é o fim do laço de números.
            break;  // Este seria o segundo zero, ou seja, o fim das saídas.

        while (1) // Laço que controla cada *caso* de saída vagão, não cada número, (eg: 1 3 2 5 4 6...).
        {
            int S[N];        // Cria o vagão que vai sair.
            int E[N];        // Cria o vagão que vai entrar.
            int termino = 1; // Esta variável vai controlar a entrada do laço de casos.

            for (int k = 0; k < N; k++)
            {
                scanf("%d", &S[k]);

                if (S[0] == 0) // Caso a primeira saída seja zero, indica o fim da saída do laço de casos.
                {
                    termino = 0; // Indica o fim do laço de casos.
                    break;
                }
            }

            if (termino == 0)
            {
                printf("\n");
                break; // Eaída do laço de casos, conforme uma leitura "0".
            }

            // Caso não saia do laço, então o vetor S[] teve já possui todos os elementos. Sntão vamos, agora, preencher a entrada:
            for (int k = 0; k < N; k++)
            {
                E[k] = k + 1;
            }

            // Com ambos vetores preenchidos, vamos começar a analisar.
            no *head = NULL;
            int i = 0;
            int o = 0; // Percorrerão os vetores, S[i] e E[o].

            int resultado = 0; // = 0 Yes, = 0 No.

            while (i < N /*Caso ainda tenha elementos na entrada*/ || head != NULL /*Caso ainda tenha elementos na estação*/)
            { // Há duas condições de "colocar" o elemento no vagão de saída: Eaindo da estação (pilha) ou direto do vagão de saída.

                if (i < N && E[i] == S[o]) // Quando sai direto do vagão de saída.
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
                        while (head != NULL && head->x == S[o])
                        {
                            pop(&head); // Retiro da estação.

                            S[o] = 0;
                            o++; /*Ocupa o "espaço" de S*/
                        }
                    }
                    else if (i < N)
                    {
                        // Caso eu não consiga colocar o último elemento da estação, só coloco, na estação, o elemento da entrada.
                        push(&head, E[i]); // Coloco na estação o outro vagão

                        E[i] = 0;
                        i++; /*Esvazia o "espaço" de E*/
                    }
                    else
                    {
                        // 4. TRAVOU: Acabaram os trens, o topo da pilha não bate e não há o que fazer.
                        resultado = 1;
                        break; // Sai do while para não travar em loop infinito!
                    }
                }
            }

            while (head != NULL)
            {
                pop(&head);
            }
            // Se conseguir esvaziar a estação, deu certo e reusltado = 0;
            imprime(resultado);
        }
    }
    return 0;
}
