void merge(int v[], int ini, int mid, int end, int* c) {
 	int aux[end - ini + 1];
 	int i = ini, j = mid + 1, k = 0;

 	while (i <= mid && j <= end) {
 		(*c)++;
 		aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
 	}

 	while (i <= mid) {
		aux[k++] = v[i++]; 
		(*c)++;  
	}   

 	while (j <= end) {
		aux[k++] = v[j++]; 
		(*c)++;	
	}

 	for (i = ini, k = 0; i <= end; i++, k++) {
 	 	(*c)++;

 		v[i] = aux[k];
 	}
}

void _mergesort(int v[], int ini, int end, int* c) {
 	int mid = (ini + end) / 2;

 	if (ini < end) {
 		_mergesort(v, ini, mid, c);
 		_mergesort(v, mid + 1, end, c);

 		merge(v, ini, mid, end, c);
 	}
}

int mergeSort(int v[], int n) {
	int c = 0;

 	_mergesort(v, 0, n - 1, &c);

 	return c;
}