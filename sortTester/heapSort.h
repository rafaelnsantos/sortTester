/* 
 * File:   heapSort.h
 * Author: UTFPR
 *
 * Created on 17 de Março de 2015, 08:01
 */

#ifndef HEAPSORT_H
#define	HEAPSORT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "vetores.h"
    
void heapSort(int *a, int n){
   long long int i = n/2, pai, filho, t;
 
   for (;;)
   {
      if (i > 0)
      {
          i--;
          t = a[i];
      }
      else
      {
          n--;
          if (n == 0)
             return;
          t = a[n];
          a[n] = a[0];
      }
 
      pai = i;
 
      //Primeiro será feita a comparação com o filho da esquerda.
      filho = i*2;
 
      while (filho < n)
      {
         //Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t)
          {
             a[pai] = a[filho];
             pai = filho;
             filho = pai*2 + 1;
          }
          else
             break;
      }
      a[pai] = t;
   }
}

float heapSortTime(int *array, int length){
    clock_t inicio = clock();
    heapSort(array, length);
    free(array);
    return (float)(clock() - inicio) / CLOCKS_PER_SEC;
}

void testarHeap(int tam){
    printf("\n===HEAP SORT===\n");
    printf("Ordenados: %f segundos\n", heapSortTime(ordenados(tam), tam));
    printf("Invertidos: %f segundos\n", heapSortTime(invertidos(tam), tam));
    printf("Aleatorios: %f segundos\n", heapSortTime(aleatorios(tam), tam));
}

#ifdef	__cplusplus
}
#endif

#endif	/* HEAPSORT_H */

