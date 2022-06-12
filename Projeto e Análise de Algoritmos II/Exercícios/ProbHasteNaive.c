// Diego Souza Lima Marques
// TIA: 32039921

#include <stdio.h>

int max(int x, int y);
int CorteHaste (int p[], int n);

int main(void) {
  int preco[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  int tamanho_preco = sizeof(preco) / sizeof(preco[0]);
  int receita_max = CorteHaste(preco, tamanho_preco);
  printf("A receita máxima para uma haste de tamanho %d é: %d\n", tamanho_preco, receita_max);
}

int max(int x, int y) // retorna o máximo entre dois valores
{
  if (x > y) return x;
  else return y; 
}

int CorteHaste(int p[], int n)
{
  if (n == 0) return 0;
  int q = -1; // valor inválido para receita (negativo)
  for (int i = 0; i < n; ++i)
  {
    q = max(q, p[i] + CorteHaste(p, n - i - 1));
  } 
  return q; // receita máxima
}