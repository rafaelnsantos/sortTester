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
        float t;
        clock_t inicio = clock();
        insertionSort(a, length);
        t = (float)(clock() - inicio) / CLOCKS_PER_SEC;
        free(a);
        return t;
    }
    
    void testarInsertion(int tam) {
//        int *vetor;
//        vetor = (int *) malloc (tam*sizeof(int));
//        vetor = invertidos(tam);
//        imprimir(vetor, tam, "vetor invertido.txt");
//        insertionSort(vetor, tam);
//        imprimir(vetor, tam, "vetor ordenado com insertion.txt");
        printf("\n===INSERTION SORT===\n");
        printf("Ordenados: %f segundos\n", insertionSortTime(ordenados(tam), tam));
        printf("Invertidos: %f segundos\n", insertionSortTime(invertidos(tam), tam));
        printf("Aleatorios: %f segundos\n", insertionSortTime(aleatorios(tam), tam));
    }


#ifdef	__cplusplus
}
#endif

#endif	/* INSERTIONSORT_H */

