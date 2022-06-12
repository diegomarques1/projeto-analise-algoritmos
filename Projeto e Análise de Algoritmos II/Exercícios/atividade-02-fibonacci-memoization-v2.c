// Diego Souza Lima Marques
// TIA: 32039921

#include <stdio.h>

int vet[100] = {0}; // vetor para armazenar valores dos fibos

int memoization(int n);

int F(int n);

int main(void) 
{
  printf("Digite o valor do Fibonacci a ser calculado (limite: 99): ");
  int x;
  scanf("%d", &x);
  int y = F(x);
  printf("F() = ");
  for (int k = 0; k < (x - 1); k++)
  {
      printf("%d + ", vet[k]);
  }
  printf("%d ", vet[x-1]);
  printf("= %d\n", y);
  printf("F(%d) = %d", x, y);
}

int memoization(int n)
{
  if (vet[n] == 0 && n != 0) // se for 0, significa que não foi armazenado ainda
  {
    vet[n] = F(n);
  }
  return vet[n]; // retorna o valor armazenado
}

int F(int n) // fibonacci similar ao exemplo dado em aula
{
  if (n < 1) return 0;
  else if (n == 1) return 1;
  else return memoization(n-1) + memoization(n-2);
}