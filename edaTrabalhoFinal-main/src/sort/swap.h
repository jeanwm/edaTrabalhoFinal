void swap(int v[], int i, int fim) {
	int aux = v[i];
	v[i]    = v[fim];
	v[fim]  = aux;
}