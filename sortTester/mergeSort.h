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
    
//void merge (int *a, int n, int m) {
//    int i, j, k;
//    int *x = malloc(n * sizeof (int));
//    for (i = 0, j = m, k = 0; k < n; k++) {
//        x[k] = j == n      ? a[i++]
//             : i == m      ? a[j++]
//             : a[j] < a[i] ? a[j++]
//             :               a[i++];
//    }
//    for (i = 0; i < n; i++) {
//        a[i] = x[i];
//    }
//    free(x);
//}
// 
//double mergeSort (int *a, int n) {
//    clock_t inicio = clock();
//    if (n < 2)
//        return;
//    int m = n / 2;
//    mergeSort(a, m);
//    mergeSort(a + m, n - m);
//    merge(a, n, m);
//    return (double) (clock() - inicio) / CLOCKS_PER_SEC;
//}

///function:
mergeSort(name_array);
 
 //tipo Data used:
typedef struct data{
      char*some;
      int data;
} DATA;
typedef struct _nodo{
       int key;
       DATA data;
}nodo;
 
///n is kept as global
int n;
 
void merge(nodo*a,nodo*aux,int left,int right,int rightEnd){
  int i,num,temp,leftEnd=right-1;
  temp=left;
  num=rightEnd-left+1;
  while((left<=leftEnd)&&(right<=rightEnd)){
    if(a[left].key<=a[right].key){
       aux[temp++]=a[left++];
    }
    else{
        aux[temp++]=a[right++];
    }
  }
  while(left<=leftEnd){
        aux[temp++]=a[left++];
  }
  while(right<=rightEnd){
        aux[temp++]=a[right++];
  }
  for (i=1;i<=num;i++,rightEnd--){
    a[rightEnd]=aux[rightEnd];
  }
}
void mSort(nodo*a,nodo*aux,int left,int right){
  int center;
  if (left<right){
    center=(left+right)/2;
    mSort(a,aux,left,center);
    mSort(a,aux,center+1,right);
    merge(a,aux,left,center+1,right);
  }
}
double mergeSort(nodo*p){
    clock_t inicio = clock();
    nodo*temp=(nodo*)malloc(sizeof(nodo)*n);
    mSort(p,temp,0,n-1);
    free(temp);
    return (double) (clock() - inicio) / CLOCKS_PER_SEC;
}

void testarMerge(int tam) {
        printf("\n===MERGE SORT===\n");
        printf("Ordenados: %f segundos\n", mergeSort(ordenados(tam)));
        printf("Invertidos: %f segundos\n", mergeSort(invertidos(tam)));
        printf("Aleatorios: %f segundos\n", mergeSort(aleatorios(tam)));
    }


#ifdef	__cplusplus
}
#endif

#endif	/* MERGESORT_H */

