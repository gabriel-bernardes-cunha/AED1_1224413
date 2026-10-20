/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1995
Data        : 20/10/2026
Objetivo    : Escrever um padrão dado
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
 
int main() {
 
    int i,j;
    i=1;
    j=60;
    for (j;j>0;j=j-5)
    {
        printf("I=%d J=%d\n",i,j);
        i=i+3;
    }
    printf("I=%d J=%d\n",i,j);
 
    return 0;
}
