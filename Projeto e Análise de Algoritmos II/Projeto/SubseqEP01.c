// Grupo:
// Adriano Pinheiro Fernandes - TIA: 32055161
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declaração das funções do código
void printSequencia(char vet[], int n);
void preencheMatriz(int m, int n, int tamanho[1000][1000], int lcs[1000][1000]);
void encontraLcs(char seq1[], int m, char seq2[], int n, int lcs[1000][1000], int tamanho[1000][1000]);
void mostraLcs(int m, int n, int lcs[1000][1000], char seq1[1000]);

int main()
{
  int tamanho[1000][1000], lcs[1000][1000];
  char seq1[1000], seq2[1000];
  int t1, t2; // no arquivo original, as sequências possuem tamanho t1 = 10 e t2 = 7
  printf("\nDigite o tamanho da primeira subsequencia do arquivo: ");
  scanf("%d", &t1);
  printf("\nDigite o tamanho da segunda subsequencia do arquivo: ");
  scanf("%d", &t2);
  FILE* file;
  file = fopen("subseq.txt", "r"); // leitura do arquivo com as sequências
  fscanf(file, "%s", seq1);
  fscanf(file, "%s", seq2);
  printf("\nX = ");
  printSequencia(seq1, t1);
  printf("Y = ");
  printSequencia(seq2, t2);
  printf("LCS = ");
  preencheMatriz(t1, t2, tamanho, lcs);
  encontraLcs(seq1, t1, seq2, t2, lcs, tamanho);
  mostraLcs(t1, t2, lcs, seq1);
  fclose(file);
  return 0;
}

// imprimime a sequência ao usuário
void printSequencia(char vet[], int n) 
{
  for (int i = 0; i < n; i++)
  {
    printf("%c", vet[i]);
  }
  printf("%c", '\n');
}

// popula a matriz do tamanho e das direções da LCS com valores nulos
void preencheMatriz(int m, int n, int tamanho[1000][1000], int lcs[1000][1000]) 
{
  int i = 0, j = 0;
  while (i <= m) // zera todas as linhas para a coluna 0. são os casos de sub1 "algo" com sub2 "" (nada em comum)
  {
    lcs[i][0] = 0;
    tamanho[i][0] = 0;
    i++;
  }
  while (j <= n) // zera todas as colunas para a linha 0. são os casos de sub1 "" com sub2 "algo" (nada em comum)
  {
    lcs[0][j] = 0;
    tamanho[0][j] = 0;
    j++;
  }
}

// determina a lcs a partir de 2 casos (caracteres atuais das duas sequências são iguais OU diferentes), 
// indicando cada movimento na matriz a partir da mudança de tamanho da lcs
void encontraLcs(char seq1[], int m, char seq2[], int n, int lcs[1000][1000], int tamanho[1000][1000])
{
  for (int linha = 1; linha <= m; linha++)
  {
    for (int col = 1; col <= n; col++)
    {
      // caso 1: caracteres iguais, volta um na coluna e um na linha e somar 1 (diagonal)
      if (seq1[linha - 1] == seq2[col - 1]) 
      {
        tamanho[linha][col] = tamanho[linha - 1][col - 1] + 1;
        lcs[linha][col] = 1;
      }
      else // se os caracteres comparados não forem iguais, procura o maior entre o de cima e o da esquerda
      {
        bool flag = (tamanho[linha - 1][col] >= tamanho[linha][col - 1]) ? true : false; // max entre cima e esq.
        if (flag == true) // o de cima é maior
        {
          tamanho[linha][col] = tamanho[linha - 1][col];
          lcs[linha][col] = 2;
        }
        else // o da esquerda é maior
        {
          tamanho[linha][col] = tamanho[linha][col - 1];
          lcs[linha][col] = 3;
        }
      }
    }
  }
}

// função recursiva que traduz os comandos de movimentação da lcs para uma sequência inicial escolhida
void mostraLcs(int m, int n, int lcs[1000][1000], char seq1[1000])
{
  if (n == 0 || m == 0) // caso-base: tamanho 0 --> nada em comum e nada a ser impresso
  {
    return; 
  }
  // a[m-1][n-1] e a[m][n] são sempre diferentes em uma unidade (soma + 1 na diagonal do encontraLcs)
  if (lcs[m][n] == 1) // movimenta na diagonal: -1 na coluna e -1 na linha
  {
    mostraLcs(m - 1, n - 1, lcs, seq1); // recursivamente até o primeiro char da seq. 1 (X)
    printf("%c", seq1[m - 1]); // imprime os caracteres da subsequência a partir da seq. (tanto faz qual)
  }
  else if (lcs[m][n] == 2) // movimenta para cima
  {
    mostraLcs(m - 1, n, lcs, seq1);
  }
  else // movimenta para esquerda
  {
    mostraLcs(m, n - 1, lcs, seq1);
  }
}