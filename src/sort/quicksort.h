int partition(int v[], int ini, int end, int *c) {
	int pivot = v[end];
	int i     = ini - 1;
	int j 	  = 0;

	for (j = ini; j <= end - 1; j++) {
		if (v[j] < pivot) {
			i++;

			swap(v, i, j);
			(*c)++;
		}
		(*c)++;
	}
	(*c)++;

	swap(v, i + 1, end);
	(*c)++;

	return i + 1;
}

void _quicksort(int v[], int ini, int end, int *c) {
 	if (ini < end) {
 		int meio = partition(v, ini, end, c);

 		_quicksort(v, ini, meio - 1, c);
 		_quicksort(v, meio + 1, end, c);
 	}
	(*c)++;
}

int quickSort(int v[], int n) {
	int c = 0;

 	_quicksort(v, 0, n - 1, &c);

 	return c;
}