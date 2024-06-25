void heapify(int v[], int n, int i, int *c) {
	int root  = i;
	int left  = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && v[left] > v[root]) {
		root = left;
	}
	(*c)++;

	if (right < n && v[right] > v[root]) {
		root = right;
	}
	(*c)++;

	if (root != i) {
		swap(v, i, root);
		heapify(v, n, root, c);
	}
	(*c)++;
}

int heapSort(int v[], int n) {
	int i = n / 2 - 1;
	int c = 0;

	for (; i >= 0; i--) {
		c++;
		heapify(v, n, i, &c);
	}
	c++;

	int j = n - 1;

	for (; j > 0; j--) {
		c++;
 		swap(v, 0, j); 
 		heapify(v, j, 0, &c);
 	}
	c++;

	return c;
}