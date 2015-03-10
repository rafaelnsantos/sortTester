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

void selectionSort(int *array, int length)
{
    int max, i, temp;
    int tam = length;
    //imprimir(array, tam, "asdd.txt");
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
    //imprimir(array, tam, "asd.txt");
}

float selectionSortTime(int *array, int length){
    clock_t inicio = clock();
    selectionSort(array, length);
    free(array);
    return (float) (clock() - inicio) / CLOCKS_PER_SEC;
}

    void testarSelection(int tam) {
        //int *vetor;
        //vetor = (int *) malloc (tam*sizeof(int));
        //vetor = invertidos(tam);
        //selectionSort(vetor, tam);
        //imprimir(vetor,tam,"vetor ordenado.txt");
        printf("\n===SELECTION SORT===\n");
        printf("Ordenados: %f segundos\n", selectionSortTime(ordenados(tam), tam));
        printf("Invertidos: %f segundos\n", selectionSortTime(invertidos(tam), tam));
        printf("Aleatorios: %f segundos\n", selectionSortTime(aleatorios(tam), tam));
    }

#ifdef	__cplusplus
}
#endif

#endif	/* SELECTIONSORT_H */

