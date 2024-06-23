#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void heapify(int v[], int n, int i, int *c) {
	int raiz     = i;
	int esquerda = 2 * i + 1;
	int direita  = 2 * i + 2;

	if (esquerda < n && v[esquerda] > v[raiz]) {
		(*c)++;
		raiz = esquerda;
	}

	if (direita < n && v[direita] > v[raiz]) {
		(*c)++;
		raiz = direita;
	}

	if (raiz != i) {
		(*c)++;
		swap(v, i, raiz);
		heapify(v, n, raiz, &c);
	}
}

int heapSort(int v[], int n) {
	int i = n / 2 - 1;
	int c = 0;

	for (i; i >= 0; i--) {
		c++;
		heapify(v, n, i, &c);
	}

	int j = n - 1;

	for (i; j > 0; j--) {
		c++;
 		swap(v, 0, j); 
 		heapify(v, j, 0, &c);
 	}

	return c;
}