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

void quickS (int *a, int n) {
    clock_t inicio = clock();
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
    quickS(a, i);
    quickS(a + i, n - i);
}

double quickSort(int *a, int n) {
    clock_t inicio = clock();
    quickS(a, n);
    free(a);
    return (double) (clock() - inicio) / CLOCKS_PER_SEC;
}
void testarQuick(int tam) {
        printf("\n===QUICK SORT===\n");
        printf("Ordenados: %f segundos\n", quickSort(ordenados(tam), tam));
        printf("Invertidos: %f segundos\n", quickSort(invertidos(tam), tam));
        printf("Aleatorios: %f segundos\n", quickSort(aleatorios(tam), tam));
    }


#ifdef	__cplusplus
}
#endif

#endif	/* QUICKSORT_H */

