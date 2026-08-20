/* --------------------------------------------------------------------------
Disciplina  : Algoritmos e Estruturas de Dados I, turma IB, 2026S2
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 20/08/2026
Objetivo    : Realizar um resolvedor de um sudoku.
Aprendizado : Revisar conceitos.
-------------------------------------------------------------------------- */
#include <stdio.h>
 
int vcoluna (sudoku[9][9]) {
    for (int i=0;i<9;i++){
         for (int j=0;j<9;j++){
             for (int j2=j;j2<9;j2++){
               
             }
         }
     } 
}

int vlinha (sudoku[9][9]) {
    for (int i=0;i<9;i++){
         for (int j=0;j<9;j++){
             scanf ("%d",&sudoku[i][j]);
         }
     }
        
}

int vbloco (sudoku[9][9]) {
        
}

void resultado (int instancia, int r){
    if (r=0) 
        prinf("Instancia %d\nNAO",instancia);
    else {
    return;
} 

int main() {
    // Cria uma matriz com o sudoku.
    int sudoku[9][9];
    
    int ncasos; //Quantas instâncias há.
    scanf ("%d"ncasos);

    int instancia = 0; //QUantas instâncias há.
    
    // Uma variável que dita o resultado.
    int r=1;// "r" de resultado, por hora, verdade até que se prove o contrário.
    
    while (ncasos>0){
     instancia ++; // Cada laço é uma instância.
     
     //Primeio, lê todas as colunas de uma mesma linha.
     for (int i=0;i<9;i++){
         for (int j=0;j<9;j++){
             scanf ("%d",&sudoku[i][j]);
         }
     }
     
     r = vlinha;
     resultado (instancia,r);
     r = vcoluna;
     resultado (instancia,r);
     r = vbloco;
     resultado (instancia,r);
     
     prinf("Instancia %d\nSIM",instancia);
     
     ncasos--; // Um caso já foi visto.
   }
     return 0;
}
