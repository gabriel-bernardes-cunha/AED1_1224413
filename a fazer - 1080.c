/* --------------------------------------------------------------------------
Disciplina  : Algoritmos e Estruturas de Dados I, turma IB, 2026S2
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1180
Data        : 19/08/2026
Objetivo    : Ler uma lista de números e dizer o menor deles e sua posição na lista.
Aprendizado : Revisar conceitos.
-------------------------------------------------------------------------- */
//Por algum moivo, loop infinito

#include <stdio.h>
 
int main() {
    
    int N;
    scanf ("%d",&N);
    int X[N], Menor, Posicao;
    
    for (int i=0;i>N;i++) {
        
        scanf ("%d",&X[i]);
        
        if (i=0){
            Menor = X[i];
            Posicao = i;
        }
        
        if (X[i] < Menor){
            Menor = X[i];
            Posicao = i;
        }
    }
    printf ("Menor valor: %d\nPosicao: %d\n", Menor, Posicao);
 
    return 0;
}
