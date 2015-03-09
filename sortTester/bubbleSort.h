/* 
 * File:   bubbleSort.h
 * Author: Verde
 *
 * Created on March 9, 2015, 5:30 PM
 */

#ifndef BUBBLESORT_H
#define	BUBBLESORT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "vetores.h"
    
float bubbleSort(int *array, int length)
 {
     clock_t inicio = clock();
     
     int i, j, tmp;
     for (i = 0; i < length - 1; ++i) 
     {
 
 	for (j = 0; j < length - i - 1; ++j) 
        {
 	    if (array[j] > array[j + 1]) 
            {
 		tmp = array[j];
 		array[j] = array[j + 1];
 		array[j + 1] = tmp;
 	    }
 	}
     }
     return (float)(clock() - inicio) / CLOCKS_PER_SEC;
 }

void testarBubble(int tam){
    printf("\n===BUBBLE SORT===\n");
    printf("Ordenados: %f segundos\n", bubbleSort(ordenados(tam), tam));
    printf("Invertidos: %f segundos\n", bubbleSort(invertidos(tam), tam));
    printf("Aleatorios: %f segundos\n", bubbleSort(aleatorios(tam), tam));
}

#ifdef	__cplusplus
}
#endif

#endif	/* BUBBLESORT_H */

