#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void insertionsort(int v[], int n, int *c) {
 	int pivo, j;

 	for (int i = 1; i < n; i++) {
		(*c)++;

 		pivo = v[i];
		j = i - 1;

		while (j >= 0 && pivo < v[j]) {
			(*c)++;
			
			v[j + 1] = v[j]; 
			j--;
		}

		v[j + 1] = pivo;
 	}
}