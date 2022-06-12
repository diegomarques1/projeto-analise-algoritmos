// Diego Souza Lima Marques - TIA: 32039921
// Atividade 4 - Corte da Haste usando Progamação Dinâmica

#include <stdio.h>

int vet[100] = {0};

void preencheVetor(int vet[]);
int CorteHaste(int p[], int n);
int memoization(int p[], int n);

int main(void) {
  int preco[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  printf("Tamanho da haste (1 a 10): \n");
  int tam_haste;
  scanf("%d", &tam_haste);
  while (tam_haste < 1 || tam_haste > 10) // verificação de dados
  {
    printf("Tamanho inválido! Digite novamente (1 a 10): ");
    scanf("%d", &tam_haste);
  }
  int receita_max = CorteHaste(preco, tam_haste);
  printf("A receita máxima para uma haste de tamanho %d é: %d\n", tam_haste, receita_max);
}

void preencheVetor(int vet[])
{
  for (int i = 0; i < 100; i++)
  {
    vet[i] = -1; // preenche o vetor com -1, valor inválido para a receita
  }
}

int memoization(int p[], int n)
{
	if (vet[n] == -1) // se o valor ainda não foi armazenado, ele calcula e coloca no vetor
	{
		vet[n] = CorteHaste(p, n);
	}
	return vet[n]; // retorna o valor armazenado no vetor do memoization
}

int CorteHaste(int p[], int n)
{
  if (n == 0) return 0;
  int q = -1; // valor inválido para receita (negativo)
  for (int i = 0; i < n; ++i)
  {
    q = (q > p[i] + memoization(p, n - 1 - i)) ? q : p[i] + memoization(p, n - i - 1);
  } // operador ternário para ver qual é o maior entre q e o cálculo da haste
  return q; // receita máxima
}