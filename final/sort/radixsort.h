#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void countingsort(int v[], int n, int exp) {
	int saida[n], frequencia[10]; 

	for (int i = 0; i < n; i++) {
		frequencia[(v[i] / exp) % 10]++;
	}

	for (int i = 1; i < 10; i++) {
		frequencia[i] += frequencia[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		saida[frequencia[(v[i] / exp) % 10] - 1] = v[i];
		saida[(v[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++) {
		v[i] = saida[i];
	}
}

int max(int v[], int n) {
	int max = v[0];

	for (int i = 1; i < n; i++) {
		if (v[i] > max) {
			max = v[i];
			return max;
		}
	}
}

int radixSort(int v[], int n) {
 	int m = max(v, n);
	int c = 0;

 	for (int exp = 1; m / exp > 0; exp *= 10) {
		c++;
 		countingsort(v, n, exp);
	}

	return c;
}