#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int partition(int v[], int inicio, int fim, int *c) {
	int pivo = v[fim];	                                                        // pivo eh o ultimo elemento da particao
	int i    = inicio - 1;                                                      // indica a posicao correta do pivo ate entao
	int j 	 = 0;

	(*c)++;

	for (j = inicio; j <= fim - 1; j++) {
		if (v[j] < pivo) {                                                      // verifica se o elemento atual eh menor que o pivo
			i++;

			swap(v, i, j);                                                      // realiza a troca do elemento atual
			(*c)++;
		}
	}

	swap(v, i + 1, fim);                                                        // posiciona o pivo na posicao correta

	(*c)++;

	return i + 1;                                                               // informa o indice a ser utilizado para o proximo particionamento
}

void _quicksort(int v[], int inicio, int fim, int *c) {
	(*c)++;

 	if (inicio < fim) {
 		int meio = partition(v, inicio, fim, c);

 		_quicksort(v, inicio, meio - 1, c);                                     // antes do pivo
 		_quicksort(v, meio + 1, fim, c);                                        // depois do pivo
 	}
}

int quicksort(int v[], int n) {
	int c = 0;

 	_quicksort(v, 0, n - 1, &c);

 	return c;
}