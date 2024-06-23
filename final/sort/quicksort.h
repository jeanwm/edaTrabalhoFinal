#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int partition(int v[], int inicio, int fim, int *c) {
	int pivo = v[fim];
	int i    = inicio - 1;
	int j 	 = 0;

	(*c)++;

	for (j = inicio; j <= fim - 1; j++) {
		if (v[j] < pivo) {
			i++;

			swap(v, i, j);
			(*c)++;
		}
	}

	swap(v, i + 1, fim);

	(*c)++;

	return i + 1;
}

void _quicksort(int v[], int inicio, int fim, int *c) {
	(*c)++;

 	if (inicio < fim) {
 		int meio = partition(v, inicio, fim, c);

 		_quicksort(v, inicio, meio - 1, c);
 		_quicksort(v, meio + 1, fim, c);
 	}
}

int quickSort(int v[], int n) {
	int c = 0;

 	_quicksort(v, 0, n - 1, &c);

 	return c;
}