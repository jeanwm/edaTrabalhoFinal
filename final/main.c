#include <stdio.h>
#include <stdlib.h>

#include "sort/operavetor.h"
#include "sort/swap.h"
#include "sort/bubblesort.h"
#include "sort/heapsort.h"
#include "sort/insertsort.h"
#include "sort/mergesort.h"
#include "sort/quicksort.h"
#include "sort/radixsort.h"

int main() {
	int repeticoes = 30;

    FILE *fptr = fopen("output.csv", "w");

    if (fptr == NULL){
        printf("falha ao abrir o arquivo");
        return -1;
    }
    
    fprintf(fptr, "Iterações, Bubble Sort, Insertion Sort, Heap Sort, Merge Sort, Quick Sort, Radix Sort\n");

    for (int n = 1; n <= 1000; n++){
        unsigned int soma_bubblesort = 0, soma_insertionsort = 0, soma_heapsort = 0, soma_mergesort = 0, soma_quicksort = 0, soma_radixsort = 0;

        for (int i = 1; i <= repeticoes; i++){
            int* v = criaVetor(n);    
            int* vetor1 = copiaVetor(v, n);
            int* vetor2 = copiaVetor(v, n);
            int* vetor3 = copiaVetor(v, n);
            int* vetor4 = copiaVetor(v, n);
            int* vetor5 = copiaVetor(v, n);

            soma_bubblesort    += bubbleSort(v, n);
            soma_insertionsort += insertionSort(vetor1, n);
            soma_heapsort 	   += heapSort(vetor2, n);
            soma_mergesort 	   += mergeSort(vetor3, n);
            soma_quicksort 	   += quickSort(vetor4, n);
            soma_radixsort 	   += radixSort(vetor5, n);

            free(v);
            free(vetor1);
            free(vetor2);
            free(vetor3);
            free(vetor4);
            free(vetor5);
        }

        unsigned int media_bubblesort 	 = soma_bubblesort / repeticoes;
        unsigned int media_insertionsort = soma_insertionsort / repeticoes;
        unsigned int media_heapsort 	 = soma_heapsort / repeticoes;
        unsigned int media_mergesort 	 = soma_mergesort / repeticoes;
        unsigned int media_quicksort	 = soma_quicksort / repeticoes;
        unsigned int media_radixsort	 = soma_radixsort / repeticoes;

        fprintf(fptr, "%d, %u, %u, %u, %u, %u, %u\n", n, media_bubblesort, media_insertionsort, media_heapsort, media_mergesort, media_quicksort, media_radixsort);
    }

    fclose(fptr);
    
    return 0;
}
