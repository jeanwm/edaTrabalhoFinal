#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort/swap.h"
#include "sort/bubblesort.h"
#include "sort/heapsort.h"
#include "sort/insertionsort.h"
#include "sort/mergesort.h"
#include "sort/quicksort.h"
#include "sort/radixsort.h"

int* new_vector(int n) {
    int* v = malloc(sizeof(int) * n);

    if (v == NULL){
        exit(EXIT_FAILURE);
        return NULL;
    }

    static int count = 0;

    srand(time(NULL)+ count++);

    for (int i = 0; i < n; i++) {
        v[i] = rand();
    }

    return v;
}

int* cpy_vector(int v[], int n) {
    int* cpy = malloc(sizeof(int) * n);

    if (cpy == NULL) {
        exit(EXIT_FAILURE);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        cpy[i] = v[i];
    }

    return cpy;
}

int main() {
	int times = 30;

    FILE *fptr = fopen("output.csv", "w");

    if (fptr == NULL){
        printf("falha ao abrir o arquivo");

        return EXIT_FAILURE;
    }

    fprintf(fptr, "Iterações, Bubble Sort, Insertion Sort, Heap Sort, Merge Sort, Quick Sort, Radix Sort\n");

    for (int n = 1; n <= 1000; n++){
        unsigned int 
        bubblesort_sum    = 0,
        insertionsort_sum = 0,
        heapsort_sum      = 0,
        mergesort_sum     = 0,
        quicksort_sum     = 0,
        radixsort_sum     = 0;

        for (int i = 1; i <= times; i++){
            int* v = new_vector(n);

            int* v1 = cpy_vector(v, n);
            int* v2 = cpy_vector(v, n);
            int* v3 = cpy_vector(v, n);
            int* v4 = cpy_vector(v, n);
            int* v5 = cpy_vector(v, n);

            bubblesort_sum    += bubbleSort(v, n);
            insertionsort_sum += insertionSort(v1, n);
            heapsort_sum 	  += heapSort(v2, n);
            mergesort_sum 	  += mergeSort(v3, n);
            quicksort_sum 	  += quickSort(v4, n);
            radixsort_sum 	  += radixSort(v5, n);

            free(v);
            free(v1);
            free(v2);
            free(v3);
            free(v4);
            free(v5);
        }

        unsigned int bubblesort_average    = bubblesort_sum / times;
        unsigned int insertionsort_average = insertionsort_sum / times;
        unsigned int heapsort_average 	   = heapsort_sum / times;
        unsigned int mergesort_average 	   = mergesort_sum / times;
        unsigned int quicksort_average	   = quicksort_sum / times;
        unsigned int radixsort_average	   = radixsort_sum / times;

        fprintf(fptr, "%d, %u, %u, %u, %u, %u, %u\n", n,
            bubblesort_average,
            insertionsort_average,
            heapsort_average,
            mergesort_average,
            quicksort_average,
            radixsort_average
        );
    }

    fclose(fptr);
    
    return EXIT_SUCCESS;
}
