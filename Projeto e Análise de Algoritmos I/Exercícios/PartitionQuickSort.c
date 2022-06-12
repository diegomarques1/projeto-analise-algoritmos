// Diego Souza Lima Marques - TIA: 32039921

// Atividade 03 - Partition 2way

#include <stdio.h>
#include <stdlib.h>

void Partition2way(int v[])
{
	int vmen[11] = { 0 };
	int vmai[11] = { 0 };
	int aux1 = 0, aux2 = 0;
	int p = v[0];
	for (int i = 1; i < 11; ++i)
	{
		if (v[i] <= p)
		{
			vmen[aux1] = v[i];
			++aux1;
		}
		else // v[i] > p
		{
			vmai[aux2] = v[i];
			++aux2;
		}
	}
	int k = 0;
	while (k < aux1)
	{
		v[k] = vmen[k];
		++k;
	}
	v[k] = p;
	k += 1;
	int temp = 0;
	aux2 += k;
	for (int j = k; j < aux2; ++j)
	{
		v[j] = vmai[temp];
		++temp;
	}
}

void PrintVet(int v[])
{
	for (int i = 0; i < 11; ++i)
	{
		printf("%d", v[i]);
		printf("%c", ' ');
	}
	printf("%c", '\n');
}

int main()
{
	int vet[11] = { 5, 2, 1, 7, 4, 1, 3, 5, 9, 10, 8};
	PrintVet(vet);
	Partition2way(vet);
	PrintVet(vet);
}