/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1002
Data        : 24/09/2026
Objetivo    : Escrever a área de um círculo
Dificuldade : Conciliar os decimais
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <math.h>

int main ()
{
  double raio;
  scanf ("%lf",&raio);

  printf ("A=%0.4lf\n",3.14159*raio*raio);
  
  return 0;
}
