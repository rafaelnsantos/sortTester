/* 
 * File:   Sequencial.h
 * Author: UTFPR
 *
 * Created on 31 de Março de 2015, 08:36
 */

#ifndef SEQUENCIAL_H
#define	SEQUENCIAL_H

#include "vetores.h"


#ifdef	__cplusplus
extern "C" {
#endif

    int * linearSearch(int *a, int n, int find) {
        int i, j = 0;
        int *achados;
//        achados = (int *) malloc(0 * sizeof (int));
        for (i = 0; i < n; i++) {
            if (a[i] == find) {
                achados = (int *) realloc(achados, (j+1) * sizeof (int));
                achados[j] = i;
//                printf("%d",achados[j]);
                j++;
            }
        }
        printf("%d achados.", j);
//        imprimir(achados, j, "achados.txt");
        return achados;
    }

    float linearSearchTime(int *array, int length, int num) {
        float t;
        clock_t inicio = clock();
        linearSearch(array, length, num);
        t = (float) (clock() - inicio) / CLOCKS_PER_SEC;
        free(array);
        return t;
    }

    void testarLinearSearch(int tam) {
        int find;
        printf("Qual numero deseja buscar? ");
        scanf("%d",&find);
        printf("\n===LINEAR SEARCH TAM %d===\n", tam);
        printf("Ordenados: %f segundos\n", linearSearchTime(ordenados(tam), tam, find));
        printf("Invertidos: %f segundos\n", linearSearchTime(invertidos(tam), tam, find));
        printf("Aleatorios: %f segundos\n", linearSearchTime(aleatorios(tam), tam, find));
        printf("Blocos: %f segundos\n", linearSearchTime(blocos(tam), tam, find));
    }


#ifdef	__cplusplus
}
#endif

#endif	/* SEQUENCIAL_H */

