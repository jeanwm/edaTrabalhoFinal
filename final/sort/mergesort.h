#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void merge(int v[], int inicio, int meio, int fim, int* c) {
 	int aux[fim - inicio + 1];
 	int i = inicio, j = meio + 1, k = 0;

 	while (i <= meio && j <= fim) {                                             // Intercala
 		(*c)++;
 		aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
 	}

 	while (i <= meio) aux[k++] = v[i++]; (*c)++;                                // Copia o resto do subvetor que não terminou
 	while (j <= fim) aux[k++] = v[j++]; (*c)++;                                 // Copia o resto do subvetor que não terminou


 	for (i = inicio, k = 0; i <= fim; i++, k++) {                               // Copia de volta para o vetor original
 	 	(*c)++;

 		v[i] = aux[k];
 	}
}

void _mergesort(int v[], int inicio, int fim, int* c) {
 	int meio = (inicio + fim) / 2;

 	if (inicio < fim) {
 		_mergesort(v, inicio, meio, c);                                         // Dividir
 		_mergesort(v, meio + 1, fim, c);

 		merge(v, inicio, meio, fim, c);                                         // Conquistar
 	}
}

int mergeSort(int v[], int n) {
	int c = 0;

 	_mergesort(v, 0, n - 1, &c);

 	return c;
}