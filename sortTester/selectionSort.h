/* 
 * File:   selectionSort.h
 * Author: Verde
 *
 * Created on March 9, 2015, 10:44 PM
 */

#ifndef SELECTIONSORT_H
#define	SELECTIONSORT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "vetores.h"
    
double selectionSort(int *array, int length)
{
    clock_t inicio = clock();
    int max, i, temp;
    while (length > 0)
    {
        max = 0;
        for (i = 1; i < length; i++)
            if (array[i] > array[max])
                max = i;
 
        temp = array[length-1];
        array[length-1] = array[max];
        array[max] = temp;
        length--;
    }
    return (double) (clock() - inicio) / CLOCKS_PER_SEC;
}

    void testarSelection(int tam) {
        printf("\n===SELECTION SORT===\n");
        printf("Ordenados: %f segundos\n", selectionSort(ordenados(tam), tam));
        printf("Invertidos: %f segundos\n", selectionSort(invertidos(tam), tam));
        printf("Aleatorios: %f segundos\n", selectionSort(aleatorios(tam), tam));
    }

#ifdef	__cplusplus
}
#endif

#endif	/* SELECTIONSORT_H */
