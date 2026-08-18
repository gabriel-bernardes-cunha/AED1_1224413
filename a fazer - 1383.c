#include <stdio.h>
 
int vcoluna (sudoku[9][9]) {
           
}

int vlinha (sudoku[9][9]) {
        
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
    
    int ncasos;//Quantas instâncias há.
    scanf ("%d"ncasos);
    
    // Uma variável que dita o resultado.
    int r=1;// "r" de resultado, por hora, verdade até que se prove o contrário.
    
    while (ncasos>0){
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
 
    return 0;
}
