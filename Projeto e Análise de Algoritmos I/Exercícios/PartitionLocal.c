// Diego Souza Lima Marques - TIA: 32039921

#include <stdio.h>
#include <stdlib.h>

void PrintVet(int v[])
{
	for (int i = 0; i < 10; ++i)
	{
		printf("%d", v[i]);
		printf("%c", ' ');
	}
	printf("%c", '\n');
}

void PartitionLocal(int v[], int n)
{
	int p = v[0], j = n - 1;
	for (int i = 1; i < (n / 2); ++i)
	{
		if (v[i] > p)
		{
			while (j >= (n / 2))
			{
				if (v[j] <= p)
				{
					int temp = v[i];
					v[i] = v[j];
					v[j] = temp;
					break;
				}
				else
				{
					j--;
				}
			}
		}
	}
	int temp = v[(n / 2)];
	v[(n / 2)] = p;
	v[0] = temp;
}

int main()
{
	int v[10] = { 5, 5, 9, 2, 10, 3, 11, 4, 1, 7 };
	PrintVet(v);
	PartitionLocal(v, 10);
	PrintVet(v);
}

