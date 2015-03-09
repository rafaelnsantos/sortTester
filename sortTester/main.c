/* 
 * File:   main.c
 * Author: Verde
 *
 * Created on March 9, 2015, 3:21 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "bubbleSort.h"
#include "insertionSort.h"
/*
 * 
 */

void mostraV(long *vetor, int tam){
    int y;
    for(y=0;y<tam;y++){
        printf("%d ", vetor[y]);
    }
}


int main(int argc, char** argv) {
    //FILE *ordenados = fopen ("ordenados.txt", "w");
    //FILE *invertidos = fopen ("invertidos.txt", "w");
    //FILE *aleatorios = fopen ("aleatorios.txt", "w");
    
    int tam;
    int i;
    printf("Tamanho(170000 max): ");
    scanf("%d",&tam);
    
    long ordenados[tam], aleatorios[tam], invertidos[tam];
    
    srand(time(NULL));
    
    for(i = 0; i < tam; i++){
        ordenados[i] = i + 1;
        invertidos[i] = tam - i;
        aleatorios[i] = rand()%tam+1;
    }
    //mostraV(aleatorios, tam);
    return (EXIT_SUCCESS);
}

