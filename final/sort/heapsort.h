#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void heapify(int v[], int n, int i) {
	int raiz     = i;
	int esquerda = 2 * i + 1;
	int direita  = 2 * i + 2;

	if (esquerda < n && v[esquerda] > v[raiz]) {
		raiz = esquerda;
	}

	if (direita < n && v[direita] > v[raiz]) {
		raiz = direita;
	}

	if (raiz != i) {
		swap(v, i, raiz);
		heapify(v, n, raiz);
	}
}

void heapSort(int v[], int n) {
	int i = n / 2 - 1;

	for (; i >= 0; i--) {
		heapify(v, n, i);
	}

	int j = n - 1;

	for (; j > 0; j--) {
 		swap(v, 0, j); 
 		heapify(v, j, 0);
 	}
}