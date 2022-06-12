// Diego Souza Lima Marques - TIA: 32039921

#include <stdio.h>
#include <stdlib.h>

void PrintVet(int v[])
{
	for (int i = 0; i < 11; ++i)
	{
		printf("%d", v[i]);
		printf("%c", ' ');
	}
	printf("%c", '\n');
}

void EnderDireto(int v[], int n) // recebe o vetor e o tamanho do vetor a se ordenar
{
	int w[101] = { 0 }; // criação de um vetor auxiliar, supondo que o maior elemento possível seja 100 (enunciado)
	for (int i = 0; i < n; ++i)
	{
		w[v[i]] += 1; // armazena e atualiza a quantidade de cada número, de acordo com o índice
	}
	int i = 0;
	for (int k = 0; k < 101; ++k)
	{
		while (w[k] != 0)
		{
			v[i++] = k; // atribuição a partir do elemento. w[k] tem a quantidade de k em v[]
			w[k]--; // decrementa em 1 a quantidade do elemento k em w, até chegar em 0
		}
	}
}

int main()
{
	int v[11] = { 10, 17, 9, 9, 70, 28, 42, 33, 99, 33, 33 };
	PrintVet(v);
	EnderDireto(v, 11);
	PrintVet(v);
}