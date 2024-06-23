#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void bubblesort(int v[], int n, int* c) {
	int troca, i, k = 0, l = 0;

	do {
		(*c)++;
		troca = 0;

		for (i = 0; i < n - 1; i++) {
			(*c)++; 

 			if (v[i] > v[i + 1]) {
 				int aux = v[i];
 				v[i] = v[i + 1];
 				v[i + 1] = aux;
 				troca = 1; 
 				
 				k++;
 			}
 		}

 		l++;
	} while (troca);

	printf("Vetor ordenado: \n");

	for (i = 0; i < n; i++) {
		printf("%d, ", v[i]);
	}

	printf("\n");

	printf("Numero total de operacoes: %d \n", l);
	printf("Numero total de trocas: %d \n", k);
}