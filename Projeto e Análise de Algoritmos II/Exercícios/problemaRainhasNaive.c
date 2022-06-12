// Problema das n rainhas - naive/ingênuo
// Diego Souza Lima Marques
// TIA: 32039921

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void popularTabuleiro(int inicio, int n, int tabuleiro[n][n]) // impressão do tabuleiro
{
  for (int i = inicio; i < n; i++)
  {
    for (int j = inicio; j < n; j++)
    {
      tabuleiro[i][j] = 0;
    }
  }
}

bool verificarPosicao(int i, int j, int n, int tabuleiro[n][n])
{
  // verificações da linha
  for (int x = 0; x < i; x++) // linha de 0 até o ponto
  {
    if (tabuleiro[x][j] != 0) return false;
  }
  for (int y = i + 1; y < n; y++) // linha do ponto até n - 1
  {
    if (tabuleiro[y][j] != 0) return false;
  }
  
  // verificações da coluna
  for (int x = 0; x < j; x++) // coluna de 0 até o ponto
  {
    if (tabuleiro[i][x] != 0) return false;
  }
  for (int y = j + 1; y < n; y++) // coluna do ponto até n - 1
  {
    if (tabuleiro[i][y] != 0) return false;
  }

  // verificações da diagonal
  int x = i, y = j;
  while (x >= 0 && y >= 0) // diagonal para cima e para a esquerda do ponto até algum ser 0
  {
    if (tabuleiro[x--][y--] != 0) return false;
  }
  x = i, y = j;
  while (x >= 0 && y < n) // diagonal para cima e para a direita do ponto até algum ser 0
  {
    if (tabuleiro[x--][y++] != 0) return false;
  }
  x = i, y = j;
  while (x < n && y >= 0) // diagonal para baixo e para a esquerda do ponto até algum ser 0
  {
    if (tabuleiro[x++][y--] != 0) return false;
  }
  x = i, y = j;
  while (x < n && y < n) // diagonal para baixo e para a direita do ponto até algum ser 0
  {
    if (tabuleiro[x++][y++] != 0) return false;
  }
  
  // se chegar até aqui, a posição é válida para a rainha ser colocada naquele momento
  return true;
}

// programa ingênuo, mas nem tanto, pra resolver o problema das rainhas
bool rainhasNaive1(int linha, int coluna,  int n, int tabuleiro[n][n])
{
  if (coluna == n) // já foram colocadas todas as rainhas (n) no tabuleiro
  {
    return true;
  }
  
  while (linha != n) // verificar cada linha para aquela coluna
  {
    bool flag = verificarPosicao(linha, coluna, n, tabuleiro); // verifica tal posição
    if (flag == true) 
    {
      tabuleiro[linha][coluna] = 1;
      // rainhas precisam estar em colunas diferentes
      bool flagProximasRainhas = rainhasNaive1(0, coluna + 1, n, tabuleiro); 
      // testar todas as linhas para as próximas colunas
      if (flagProximasRainhas == true) 
      {
        return true;
      }
      else
      {
        // apaga todo o resto feito do tabuleiro se a tentativa de solução for errada
        popularTabuleiro(coluna, n, tabuleiro);
      }
    }
    linha++;
  }
  return false;
}

// 2ª tentativa de fazer o programa das n rainhas de maneira ingênua, mas deu errado
// programa totalmente ingênuo (mas sem permutação, porque não consegui pensar em como fazer isso)
bool rainhasNaive2(int j, int n, int tabuleiro[n][n])
{
  int count = 0;
  int incremento = 0;
  while (count != n)
  {
    // gera os índices aleatórios e mantém no intervalo possível (%n pra não estourar o limite da matriz)
    int i = rand() % n;
    while (tabuleiro[i][j] == 1) // gera novamente caso a posição seja repetida
    {
      i = rand() % n;
    }
    tabuleiro[i][j] = 1;
    j++; // incrementa a coluna (próxima rainha)
    count++;
  }
  int x = 0, y = 0;
  bool flag = true;
  while (x < n && flag == true) // verifica cada posição após colocar todas as rainhas
  {
    while (y < n)
    {
      if (tabuleiro[x][y] == 1)
      {
        flag = verificarPosicao(x, y, n, tabuleiro);
      }
      y++;
    }
    y = 0;
    x++;
  }
  
  if (flag == false)
  {
    popularTabuleiro(0, n, tabuleiro);
    rainhasNaive2(j, n, tabuleiro);
  }
  return true;
}

void mostrarSolucao(int n, int tabuleiro[n][n])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (tabuleiro[i][j] == 0) printf("0 ");
      else printf("R ");
    }
    printf("%c", '\n');
  }
}

// não utilizei o rainhasNaive2 porque ele não funciona direito e dá erro de memória.
// desculpe, prof, o problema é bem difícil de resolver de maneira ingênua.
// entendi como funciona o problema, mas grande parte das fontes que consultei
// utiliza backtracking, e foi bem difícil ter ideias pra contornar essa técnica.
// a solução 1 na qual acabei chegando é ingênua, mas não por completo,
// visto que não utilizei permutação. não consigo imaginar como fazer isso,
// ainda mais de maneira recursiva, então tentei usar a função random
// pra constantemente popular o tabuleiro, mas é totalmente ineficiente e
// acaba não populando nada.

int main(void) 
{
  int n;
  printf("Digite o tamanho do tabuleiro: ");
  scanf("%d", &n);
  int tabuleiro[n][n];
  popularTabuleiro(0, n, tabuleiro);
  bool resultado = rainhasNaive1(0, 0, n, tabuleiro);
  mostrarSolucao(n, tabuleiro);
  return 0;
}