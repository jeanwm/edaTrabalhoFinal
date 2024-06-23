#include <stdio.h>
#include <stdlib.h>

#include "sort/swap.h"
#include "sort/bubblesort.h"
#include "sort/heapsort.h"
#include "sort/insertsort.h"
#include "sort/mergesort.h"
#include "sort/quicksort.h"
#include "sort/radixsort.h"

int main() {
	int n, i, j, k;

	int seed = time(NULL);
	srand(seed);

	do {
		printf("Por favor, informe o tamanho do vetor: ");
		scanf("%d", &n);

		if (n <= 0) {
			printf("Erro: Informe um valor maior do que 0! \n");
		}
	} while(n <= 0);

	printf("Informe a base da randomizacao: ");
	scanf("%d", &j);

	if (j <= 0) {
		j = 1;
	}

	int* v = (int*) malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		v[i] = rand() % j;
	}

	printf("Vetor nao ordenado: \n");

	for (i = 0; i < n; i++) {
		printf("%d, ", v[i]);
	}

	k = mergeSort(v, n);

	printf("\nVetor ordenado: \n");
	for (i = 0; i < n; i++) {
		printf("%d, ", v[i]);
	}

	printf("\nO numero de operacoes realizadas eh: %d", k);

	return 0;
}
