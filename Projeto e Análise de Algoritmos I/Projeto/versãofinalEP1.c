// GRUPO:
// Diego Souza Lima Marques - TIA: 32039921
// Lucas de Camargo Gonçalves - TIA: 32074964

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <errno.h>

bool ordemVet(char vetor1[10], char vetor2[10]);
void printVet(char* vetor[10][10], int contador);
void arquivoOutput1(char* vetor[10][10], int contador);
void arquivoOutput2(char* vetor[10][10], int contador);
void insertionSort(char* vetor[10][10], int* steps, int contador);
void mergeSort(char* vetor[10][10], char vetorAuxiliar[10][10], int* steps, int l, int r);

int main()
{
    setlocale(LC_ALL, "");
    FILE* file;
    errno_t exc;
    exc = fopen_s(&file, "in.txt", "r");
    char* ponteiro[10][10];
    char vetorAuxiliar[10][10];
    char vetor[10][10] = { NULL };
    int steps = 0;
    int capacity1 = sizeof(vetor) / sizeof(vetor[0]);
    int capacity2 = sizeof(vetor[0]) / sizeof(vetor[0][0]);
    for (int x = 0; x < capacity1; x++)
    {
        for (int y = 0; y < capacity2; y++)
        {
            ponteiro[x][y] = &vetor[x][y];
        }
    }
    int count = 1;
    int temp;
    int j = 0;
    if (file)
    {
        for (int i = 0; (temp = getc(file)) != EOF; i++)
        {
            if (temp != ',') vetor[j][i] = temp;
            else
            {
                i = -1;
                j++;
                count++;
            }
        }
        fclose(file);
    }

    printf("Vetor original: \n");
    printVet(ponteiro, count + 1);
    printf("\n\nVetor ordenado após o insertionSort: \n");
    insertionSort(ponteiro, &steps, count);
    printVet(ponteiro, count + 1);
    arquivoOutput1(ponteiro, count + 1);
    printf("\n\nPassos: %d\n", steps);
    steps = 0;
    printf("\n\nVetor ordenado após o mergeSort: \n");
    mergeSort(ponteiro, vetorAuxiliar, &steps, 0, count);
    printVet(ponteiro, count + 1);
    arquivoOutput2(ponteiro, count + 1);
    printf("\n\nPassos: %d\n", steps);
    printf("\n");
    system("pause");
    return 0;
}

bool ordemVet(char vetor1[10], char vetor2[10])
{
    for (int indice = 0; indice < 10; indice++)
    {
        if (vetor1[indice] != vetor2[indice])
        {
            if (vetor1[indice] < vetor2[indice]) return true;
            if (vetor1[indice] > vetor2[indice]) return false;
        }
    }
    return false;
}

void insertionSort(char* vetor[10][10], int* steps, int contador)
{
    int tamanhoVetor = 10;
    char vetAux[10];
    int i, j;
    for (i = 1; i < contador; i++)
    {
        for (int k = 0; k < tamanhoVetor; k++)
        {
            vetAux[k] = *vetor[i][k];
        }
        j = i - 1;
        while (j >= 0 && ordemVet(vetAux, *vetor[j]))
        {
            for (int m = 0; m < tamanhoVetor; m++)
            {
                *vetor[j + 1][m] = *vetor[j][m];
            }
            *steps += 1;
            j = j - 1;
        }
        for (int n = 0; n < tamanhoVetor; n++) *vetor[j + 1][n] = vetAux[n];
    }
}

void printVet(char* vetor[10][10], int contador)
{
    for (int i = 0; i < contador; i++)
    {
        for (int j = 0; j < (sizeof(*vetor) / sizeof(*vetor[0])); j++)
        {
            if (*vetor[i][j] != NULL) printf("%c", *vetor[i][j]);
        }
        printf("%c", ',');
    }
}

void arquivoOutput1(char* vetor[10][10], int contador)
{
    FILE* output;
    errno_t exc;
    exc = fopen_s(&output, "out1.txt", "w");
    for (int k = 0; k < contador; k++)
    {
        if (*vetor[k][0] != NULL) fprintf(output, "%s%c", *vetor[k], ',');
    }
    fclose(output);
}

void arquivoOutput2(char* vetor[10][10], int contador)
{
    FILE* output;
    errno_t exc;
    exc = fopen_s(&output, "out2.txt", "w");
    for (int k = 0; k < contador; k++)
    {
        if (*vetor[k][0] != NULL) fprintf(output, "%s%c", *vetor[k], ',');
    }
    fclose(output);
}

void mergeSort(char* vetor[10][10], char vetorAuxiliar[10][10], int* steps, int l, int r)
{
    if (r <= l)
    {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(vetor, vetorAuxiliar, steps, l, m);
    mergeSort(vetor, vetorAuxiliar, steps, m + 1, r);
    int LEFT = l;
    int RIGHT = m + 1;
    int tamanhoVetor = 10;
    // merge (intercala)
    for (int y = l; y <= r; y++)
    {
        if (LEFT == m + 1)
        {
            for (int x = 0; x < tamanhoVetor; x++)
            {
                vetorAuxiliar[y][x] = *vetor[RIGHT][x];
            }
            RIGHT++;
            *steps += 1;
        }
        else if (RIGHT == r + 1)
        {
            for (int m = 0; m < tamanhoVetor; m++)
            {
                vetorAuxiliar[y][m] = *vetor[LEFT][m];
            }
            LEFT++;
            *steps += 1;
        }
        else if (ordemVet(*vetor[LEFT], *vetor[RIGHT]))
        {
            for (int n = 0; n < tamanhoVetor; n++)
            {
                vetorAuxiliar[y][n] = *vetor[LEFT][n];
            }
            LEFT++;
            *steps += 1;
        }
        else
        {
            for (int a = 0; a < tamanhoVetor; a++)
            {
                vetorAuxiliar[y][a] = *vetor[RIGHT][a];
            }
            RIGHT++;
            *steps += 1;
        }
    }
    for (int y = l; y <= r; y++)
    {
        for (int x = 0; x < tamanhoVetor; x++) *vetor[y][x] = vetorAuxiliar[y][x];
    }
}
