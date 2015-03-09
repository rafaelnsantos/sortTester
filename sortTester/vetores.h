/* 
 * File:   vetores.h
 * Author: Verde
 *
 * Created on March 9, 2015, 5:37 PM
 */

#ifndef VETORES_H
#define	VETORES_H

#ifdef	__cplusplus
extern "C" {
#endif


int * ordenados(int tam){
    int vetor[tam];
    int i;
    for(i = 0; i < tam; i++){
        vetor[i] = i + 1;
        //printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    return vetor;
}

int * invertidos(int tam){
    int vetor[tam];
    int i;
    for(i = 0; i < tam; i++){
        vetor[i] = tam - i;
    }
    return vetor;
}

int * aleatorios(int tam){
    srand(time(NULL));
    int vetor[tam];
    int i;
    for(i = 0; i < tam; i++){
        vetor[i] = rand()%tam+1;
    }
    return vetor;
}

void mostraV(int *vetor, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
}

#ifdef	__cplusplus
}
#endif

#endif	/* VETORES_H */

