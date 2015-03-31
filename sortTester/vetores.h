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

//int *vetor;

int * ordenados(int tam){
    int *vetor;
    vetor = (int *) malloc (tam*sizeof(int));
    int i;
    for(i = 0; i < tam; i++){
        vetor[i] = i + 1;
        //printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    //imprimir(vetor, tam, "ordenados.txt");
    //free(vetor);
    return vetor;
}

int * invertidos(int tam){
    int *vetor;
    vetor = (int *) malloc (tam*sizeof(int));
    int i;
    for(i = 0; i < tam; i++){
        vetor[i] = tam - i;
    }
    //imprimir(vetor, tam, "invertidos.txt");
    //free(vetor);
    return vetor;
}

int * aleatorios(int tam){
    int *vetor;
    vetor = (int *) malloc (tam*sizeof(int));
    int i;
    srand(time(NULL));
    for(i = 0; i < tam; i++){
        vetor[i] = rand()%tam+1;
    }
    //imprimir(vetor, tam, "aleatorios.txt");
    //free(vetor);
    return vetor;
}

int * blocos(int tam){
    int *vetor;
    vetor = (int *) malloc (tam*sizeof(int));
    int i;
    srand(time(NULL));
    for(i = 0; i < tam*0.25; i++){
        vetor[i] = 10;
    }
    for(i = tam*0.25; i < tam*0.5; i++){
        vetor[i] = 20;
    }
    for(i = tam*0.5; i < tam*0.75; i++){
        vetor[i] = 30;
    }
    for(i = tam*0.75; i < tam; i++){
        vetor[i] = 40;
    }
    //imprimir(vetor, tam, "aleatorios.txt");
    //free(vetor);
    return vetor;
}

void imprimir(int *vetor, int tam, char *nome){
    FILE * pFile;
    int i;
    pFile = fopen (nome,"w");
    for(i = 0; i < tam; i++)
        fprintf(pFile, "%d\n",vetor[i]);
    fclose(pFile);
}

#ifdef	__cplusplus
}
#endif

#endif	/* VETORES_H */

