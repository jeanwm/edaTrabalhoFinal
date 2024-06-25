void countingsort(int v[], int n, int exp, unsigned int* c) {
    int out[n], freq[10] = {0};

    for (int i = 0; i < n; i++) {
        (*c)++;
        freq[(v[i] / exp) % 10]++;
    }
    (*c)++;

    for (int i = 1; i < 10; i++) {
        (*c)++;
        freq[i] += freq[i - 1];
    }
    (*c)++;

    for (int i = n - 1; i >= 0; i--) {
        (*c)++;
        out[freq[(v[i] / exp) % 10] - 1] = v[i];
        freq[(v[i] / exp) % 10]--;
    }
    (*c)++;

    for (int i = 0; i < n; i++) {
        (*c)++;
        v[i] = out[i];
    }
    (*c)++;
}

int vector_max(int v[], int n, unsigned int* c) {
    int max = v[0];

    for (int i = 1; i < n; i++) {
        (*c)++;

        if (v[i] > max) {
            max = v[i];
        }

        (*c)++;
    }

    (*c)++;

    return max;
}

int radixSort(int v[], int n) {
    unsigned int c = 0;
    int m = vector_max(v, n, &c);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        c++;
        countingsort(v, n, exp, &c);
    }

    return c;
}
