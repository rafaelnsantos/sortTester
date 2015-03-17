/*
 * File:   quickSort.h
 * Author: Verde
 *
 * Created on March 9, 2015, 11:19 PM
 */

#ifndef QUICKSORT_H
#define	QUICKSORT_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "vetores.h"

void quickSort (int *a, int n) {
    int i, j, p, t;
    if (n < 2)
        return 0;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quickSort(a, i);
    quickSort(a + i, n - i);
}

float quickSortTime(int *a, int n) {
    float t;
    clock_t inicio = clock();
    quickSort(a, n);
    t = (float)(clock() - inicio) / CLOCKS_PER_SEC;
    free(a);
    return t;
}
void testarQuick(int tam) {
        printf("\n===QUICK SORT===\n");
        printf("Ordenados: %f segundos\n", quickSortTime(ordenados(tam), tam));
        printf("Invertidos: %f segundos\n", quickSortTime(invertidos(tam), tam));
        printf("Aleatorios: %f segundos\n", quickSortTime(aleatorios(tam), tam));
    }


#ifdef	__cplusplus
}
#endif

#endif	/* QUICKSORT_H */

