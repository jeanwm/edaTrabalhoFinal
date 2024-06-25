int insertionSort(int v[], int n) {
 	int pivot, j, c = 0;

 	for (int i = 1; i < n; i++) {
 		pivot = v[i];
		j 	  = i - 1;

		while (j >= 0 && pivot < v[j]) {			
			v[j + 1] = v[j]; 
			j--;
			c += 2;
		}

		v[j + 1] = pivot;
		c++;
 	}
	c++;

	return c;
}