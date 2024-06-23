#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int bubbleSort(int v[], int n) {
	int troca, i, c = 0;

	do {
		troca = 0;
		c++;

		for (i = 0; i < n - 1; i++) {
 			if (v[i] > v[i + 1]) {
 				int aux = v[i];
 				v[i] = v[i + 1];
 				v[i + 1] = aux;
 				troca = 1; 
 				
 				c++;
 			}
 		}
	} while (troca);

	return c;
}