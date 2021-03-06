/*
 * File:   shellSort.h
 * Author: Verde
 *
 * Created on March 9, 2015, 10:51 PM
 */

#ifndef SHELLSORT_H
#define	SHELLSORT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "vetores.h"

    // double shellSort(int *vet, int size) {
    //    clock_t inicio = clock();
    //     int i , j , value;
    //    int gap = 1;
    //    while(gap < size) {
    //        gap = 3*gap+1;
    //    }
    //    while ( gap > 1) {
    //        gap /= 3;
    //        for(i = gap; i < size; i++) {
    //            value = vet[i];
    //            j = i - gap;
    //            while (j >= 0 && value < vet[j]) {
    //                vet [j + gap] = vet[j];
    //                j -= gap;
    //            }
    //            vet [j + gap] = value;
    //        }
    //    }
    //    return (double) (clock() - inicio) / CLOCKS_PER_SEC;
    //}

    void shellSort(int *a, int n) {
        int h, i, j, t;
        for (h = n; h /= 2;) {
            for (i = h; i < n; i++) {
                t = a[i];
                for (j = i; j >= h && t < a[j - h]; j -= h) {
                    a[j] = a[j - h];
                }
                a[j] = t;
            }
        }
    }

    float shellSortTime(int *a, int n) {
        float t;
        clock_t inicio = clock();
        shellSort(a, n);
        t = (float) (clock() - inicio) / CLOCKS_PER_SEC;
        free(a);
        return t;
    }

    void testarShell(int tam) {
        printf("\n===SHELL SORT===\n");
        printf("Ordenados: %f segundos\n", shellSortTime(ordenados(tam), tam));
        printf("Invertidos: %f segundos\n", shellSortTime(invertidos(tam), tam));
        printf("Aleatorios: %f segundos\n", shellSortTime(aleatorios(tam), tam));
    }

#ifdef	__cplusplus
}
#endif

#endif	/* SHELLSORT_H */

