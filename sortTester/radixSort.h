/*
 * File:   radixSort.h
 * Author: UTFPR
 *
 * Created on 17 de Março de 2015, 08:05
 */

#ifndef RADIXSORT_H
#define	RADIXSORT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "vetores.h"

void radixSort(int *vetor, int tamanho) {
    int i;
    int *b;
    b = (int *) malloc (tamanho*sizeof(int));
    //int b[tamanho];
    int maior = vetor[0];
    int exp = 1;

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }
}

float radixSortTime(int *array, int length){
    float t;
    clock_t inicio = clock();
    radixSort(array, length);
    t = (float)(clock() - inicio) / CLOCKS_PER_SEC;
    free(array);
    return t;
}

void testarRadix(int tam){
    printf("\n===RADIX SORT===\n");
    printf("Ordenados: %f segundos\n", radixSortTime(ordenados(tam), tam));
    printf("Invertidos: %f segundos\n", radixSortTime(invertidos(tam), tam));
    printf("Aleatorios: %f segundos\n", radixSortTime(aleatorios(tam), tam));
}

#ifdef	__cplusplus
}
#endif

#endif	/* RADIXSORT_H */

