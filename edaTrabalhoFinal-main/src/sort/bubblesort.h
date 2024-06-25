int bubbleSort(int v[], int n) {
	int swap, i, c = 0;

	do {
		swap = 0;
		
		for (i = 0; i < n - 1; i++) {
 			if (v[i] > v[i + 1]) {
 				int aux = v[i];
 				v[i] = v[i + 1];
 				v[i + 1] = aux;
 				swap = 1; 
 				
 				c++;
 			}
			c++;
 		}
		c++;
	} while (swap);
	c++;

	return c;
}