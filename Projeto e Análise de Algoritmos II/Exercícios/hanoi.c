#include <stdio.h>

// n é o tamanho da torre, e é esquerda, c é centro e d é direita.

void hanoi(int n, char e, char c, char d) 
{
  if (n == 1) printf("mova de %c para %c\n", e, c);
  if (n == 1) return;
  else
  {
    hanoi(n-1, e, d, c);
    hanoi(1, e, c, d);
    hanoi(n-1, d, c, e);
  }
}
