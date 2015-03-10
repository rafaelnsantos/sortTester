/*
 * File:   insertionSort.h
 * Author: Verde
 *
 * Created on March 9, 2015, 6:15 PM
 */

#ifndef INSERTIONSORT_H
#define	INSERTIONSORT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "vetores.h"

    void insertionSort(int *a, int length) {
        int i, j, value;
        for (i = 1; i < length; i++) {
            value = a[i];
            for (j = i - 1; j >= 0 && a[j] > value; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = value;
        }
    }
    
    float insertionSortTime(int *a, int length) {
        clock_t inicio = clock();
        insertionSort(a, length);
        free(a);
        return (float) (clock() - inicio) / CLOCKS_PER_SEC;
    }
    void testarInsertion(int tam) {
        printf("\n===INSERTION SORT===\n");
        printf("Ordenados: %f segundos\n", insertionSortTime(ordenados(tam), tam));
        printf("Invertidos: %f segundos\n", insertionSortTime(invertidos(tam), tam));
        printf("Aleatorios: %f segundos\n", insertionSortTime(aleatorios(tam), tam));
    }


#ifdef	__cplusplus
}
#endif

#endif	/* INSERTIONSORT_H */

