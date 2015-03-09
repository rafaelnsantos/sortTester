/* 
 * File:   main.c
 * Author: Verde
 *
 * Created on March 9, 2015, 3:21 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <ctype.h>
#include "bubbleSort.h"
#include "insertionSort.h"
#include "vetores.h"
/*
 * 
 */




int main(int argc, char** argv) {
    //FILE *ordenados = fopen ("ordenados.txt", "w");
    //FILE *invertidos = fopen ("invertidos.txt", "w");
    //FILE *aleatorios = fopen ("aleatorios.txt", "w");
    
    int op;
    int tam;
    
    
    do{
        printf("Tamanho: ");
        scanf("%d",&tam); ;

    //mostraV(vetor,tam);
    
    //mostraV(aleatorios(tam),tam);
   // mostraV(invertidos(tam),tam);
    

        printf("1 - Bubble Sort\n");
        printf("2 - Insertion Sort\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\n===BUBBLE SORT===\n");
                printf("Ordenados: %f segundos\n", bubbleSort(ordenados(tam), tam));
                printf("Invertidos: %f segundos\n", bubbleSort(invertidos(tam), tam));
                printf("Aleatorios: %f segundos\n", bubbleSort(aleatorios(tam), tam));
                break;
            
            case 2:
                printf("\n===INSERTION SORT===\n");
                printf("Ordenados: %f segundos\n", insertionSort(ordenados(tam), tam));
                printf("Invertidos: %f segundos\n", insertionSort(invertidos(tam), tam));
                printf("Aleatorios: %f segundos\n", insertionSort(aleatorios(tam), tam));
                break;
                
            default:
                printf("Opcao Invalida");
                break;
        }
        printf("\n");
    }while(op != 0);
    return (EXIT_SUCCESS);
}

