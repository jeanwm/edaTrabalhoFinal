void countingsort(int v[], int n, int exp, unsigned int* c) {
    int saida[n], frequencia[10] = {0};

    for (int i = 0; i < n; i++) {
        (*c)++;
        frequencia[(v[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        (*c)++;
        frequencia[i] += frequencia[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        (*c)++;
        saida[frequencia[(v[i] / exp) % 10] - 1] = v[i];
        frequencia[(v[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        (*c)++;
        v[i] = saida[i];
    }
}

int max(int v[], int n, unsigned int* c) {
    int max = v[0];

    for (int i = 1; i < n; i++){
        (*c)++;

        if (v[i] > max) {
            (*c)++;
            max = v[i];
        }
    }

    return max;
}

int radixSort(int v[], int n) {
    unsigned int c = 0;
    int m = max(v, n, &c);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        c++;
        countingsort(v, n, exp, &c);
    }

    return c;
}
