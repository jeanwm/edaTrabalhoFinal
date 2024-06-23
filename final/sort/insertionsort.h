#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int insertionSort(int v[], int n) {
 	int pivo, j, c = 0;

 	for (int i = 1; i < n; i++) {
 		pivo = v[i];
		c++;

		j = i - 1;

		while (j >= 0 && pivo < v[j]) {			
			v[j + 1] = v[j]; 
			j--;
			c += 2;
		}

		v[j + 1] = pivo;
		c++;
 	}

	return c;
}