/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Gabriel Bernardes Cunha
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 26/09/2026
Objetivo    : Calcular quantos números passo em um vetor, seguindo uma ordem dada.
Dificuldade : Inserir a busca binária no problema dado.
Uso de IA   : 
-------------------------------------------------------------------------- */
// Ele entrega "NO COMEÇO DO NÚMERO", cada casa é uma unidade de tempo.
// como usar busca binária nisso?

int main ()
{
  int N, M; // Casas e Encomendas. Não, não são a mesma coisa!
  scanf ("%d, %d", &N, &M);

  int casas[N], encomendas[M];
  
  for (int i = 0; i< N; i++)
    {
      scanf ("%d", &casas[i]);
    }
  
  for (int i = 0; i < M; i++)
    {
      scanf ("%d", &encomendas[i]);
    }
  return 0;
}
