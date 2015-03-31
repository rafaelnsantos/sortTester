/*
 * File:   linearSearch.h
 * Author: UTFPR
 *
 * Created on 31 de Março de 2015, 08:36
 */

#ifndef LINEARSEARCH_H
#define	LINEARSEARCH_H

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
                achados = (int *) realloc(achados, (j + 1) * sizeof (int));
                achados[j] = i;
                //                printf("%d",achados[j]);
                j++;
            }
        }
        printf("%d achados.", j);
        //        imprimir(achados, j, "achados.txt");
        return achados;
    }

    int linearSearchU(int *a, int n, int find) {
        int i;
        for (i = 0; i < n; i++) {
            if (a[i] == find) {
                printf("Achado na posicao %d. ", i);
                return i;
            }
        }
        printf("Nao encontrado. ");
        return -1;
    }

    float linearSearchTime(int *array, int length, int num) {
        float t;
        int *aux;
        clock_t inicio = clock();
        aux = linearSearch(array, length, num);
        t = (float) (clock() - inicio) / CLOCKS_PER_SEC;
        free(aux);
        free(array);
        return t;
    }

    float linearSearchTimeUni(int *array, int length, int num) {
        float t;
        int aux;
        clock_t inicio = clock();
        aux = linearSearchU(array, length, num);
        t = (float) (clock() - inicio) / CLOCKS_PER_SEC;
        free(array);
        return t;
    }

    void testarLinearSearch(int tam) {
        int find, op;
        printf("Qual numero deseja buscar? ");
        scanf("%d", &find);
        op = modoBusca();
        printf("\n===LINEAR SEARCH TAM %d===\n", tam);
        switch (op) {
            case 1:
                printf("Ordenados: %f segundos\n", linearSearchTimeUni(ordenados(tam), tam, find));
                printf("Invertidos: %f segundos\n", linearSearchTimeUni(invertidos(tam), tam, find));
                printf("Aleatorios: %f segundos\n", linearSearchTimeUni(aleatorios(tam), tam, find));
                printf("Blocos: %f segundos\n", linearSearchTimeUni(blocos(tam), tam, find));
                break;
            case 2:
                printf("Ordenados: %f segundos\n", linearSearchTime(ordenados(tam), tam, find));
                printf("Invertidos: %f segundos\n", linearSearchTime(invertidos(tam), tam, find));
                printf("Aleatorios: %f segundos\n", linearSearchTime(aleatorios(tam), tam, find));
                printf("Blocos: %f segundos\n", linearSearchTime(blocos(tam), tam, find));
                break;
        }


    }

    int modoBusca() {
        int aux;
        printf("(1) Buscar unico valor.\n");
        printf("(2) Buscar varios\n");
        printf("\n Escolha: ");
        scanf("%d", &aux);
        return aux;
    }

#ifdef	__cplusplus
}
#endif

#endif	/* LINEARSEARCH_H */

