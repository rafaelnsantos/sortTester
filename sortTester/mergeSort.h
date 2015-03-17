/*
 * File:   mergeSort.h
 * Author: Verde
 *
 * Created on March 9, 2015, 11:14 PM
 */

#ifndef MERGESORT_H
#define	MERGESORT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "vetores.h"

void mergeSort( int *vetorDesorndeado, int posicaoInicio, int posicaoFim )
{
   int i,j,k,metadeTamanho,*vetorTemp;
   if ( posicaoInicio == posicaoFim ) return;

   // ordenacao recursiva das duas metades
   metadeTamanho = ( posicaoInicio+posicaoFim )/2;
   mergeSort( vetorDesorndeado, posicaoInicio, metadeTamanho);
   mergeSort( vetorDesorndeado, metadeTamanho+1,posicaoFim );

   // intercalacao no vetor temporario t
   i = posicaoInicio;
   j = metadeTamanho+1;
   k = 0;
   vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim-posicaoInicio+1));

   while( i < metadeTamanho+1 || j  < posicaoFim+1 )
   {
      if ( i == metadeTamanho+1 )
      { // i passou do final da primeira metade, pegar v[j]
         vetorTemp[k] = vetorDesorndeado[j];
         j++;
         k++;
      }
      else
      {
         if (j==posicaoFim+1)
         {
            // j passou do final da segunda metade, pegar v[i]
            vetorTemp[k] = vetorDesorndeado[i];
            i++;
            k++;
         }
         else
         {
            if (vetorDesorndeado[i] < vetorDesorndeado[j])
            {
               vetorTemp[k] = vetorDesorndeado[i];
               i++;
               k++;
            }
            else
            {
              vetorTemp[k] = vetorDesorndeado[j];
              j++;
              k++;
            }
         }
      }

   }
   // copia vetor intercalado para o vetor original
   for( i = posicaoInicio; i <= posicaoFim; i++ )
   {
      vetorDesorndeado[i] = vetorTemp[i-posicaoInicio];
   }
   free(vetorTemp);
}

float mergeSortTime (int *a, int n) {
    float t;
    clock_t inicio = clock();
    mergeSort(a, 0, n);
    t = (float)(clock() - inicio) / CLOCKS_PER_SEC;
    free(a);
    return t;
}

void testarMerge(int tam) {
        //int *vetor;
        //vetor = (int *) malloc (tam*sizeof(int));
        //vetor = aleatorios(tam);
        //mergeSort(vetor, 0,tam);
        //imprimir(vetor,tam,"vetor ordenado merge.txt");
        printf("\n===MERGE SORT===\n");
        printf("Ordenados: %f segundos\n", mergeSortTime(ordenados(tam), tam));
        printf("Invertidos: %f segundos\n", mergeSortTime(invertidos(tam), tam));
        printf("Aleatorios: %f segundos\n", mergeSortTime(aleatorios(tam), tam));
    }


#ifdef	__cplusplus
}
#endif

#endif	/* MERGESORT_H */

