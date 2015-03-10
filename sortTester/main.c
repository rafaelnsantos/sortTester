/*
 * File:   main.c
 * Author: Verde
 * http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting
 * Created on March 9, 2015, 3:21 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "shellSort.h"
#include "mergeSort.h"
#include "quickSort.h"

/*
 *
 */

int main(int argc, char** argv) {

    int op;
    int tam;

    do{
        printf("Tamanho: ");
        scanf("%d",&tam);
        //vetor = (int *) malloc (tam*sizeof(int));
        printf("1 - Bubble Sort\n");
        printf("2 - Insertion Sort\n");
        printf("3 - Selection Sort\n");
        printf("4 - Shell Sort\n");
        printf("5 - Merge Sort\n");
        printf("6 - Quick Sort\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                testarBubble(tam);
                break;

            case 2:
                testarInsertion(tam);
                break;

            case 3:
                testarSelection(tam);
                break;

            case 4:
                testarShell(tam);
                break;

            case 5:
                testarMerge(tam);
                break;

            case 6:
                testarQuick(tam);
                break;

            default:
                printf("Opcao Invalida");
                break;
        }
        printf("\n");
    }while(op != 0);
    return (EXIT_SUCCESS);
}

