#include <stdio.h>
#include <stdlib.h>

int* criaVetor(int n) {
    int* v = malloc(sizeof(int) * n);

    if (v == NULL){
        printf("falha ao alocar memoria\n");
        return NULL;
    }

    static int contador = 0;
    srand(time(NULL)+ contador++);

    for (int i = 0; i < n; i++) {
        v[i] = rand();
    }

    return v;
}


int* copiaVetor(int v[], int n) {
    int* copia = malloc(sizeof(int) * n);

    if (copia == NULL){
        printf("falha ao alocar memoria\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        copia[i] = v[i];
    }

    return copia;
}