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
    
    int op;
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
    
    do{
        printf("1 - Bubble Sort\n");
        printf("2 - Insertion Sort\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\n===BUBBLE SORT===\n");
                printf("Ordenados: %f segundos\n", bubbleSort(ordenados, tam));
                printf("Invertidos: %f segundos\n", bubbleSort(invertidos, tam));
                printf("Aleatorios: %f segundos\n", bubbleSort(aleatorios, tam));
                break;
            
            case 2:
                printf("\n===INSERTION SORT===\n");
                printf("Ordenados: %f segundos\n", insertionSort(ordenados, tam));
                printf("Invertidos: %f segundos\n", insertionSort(invertidos, tam));
                printf("Aleatorios: %f segundos\n", insertionSort(aleatorios, tam));
                break;
                
            default:
                printf("Opcao Invalida");
                break;
        }
        printf("\n");
    }while(op != 0);
    return (EXIT_SUCCESS);
}

