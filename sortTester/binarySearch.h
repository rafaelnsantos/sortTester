/* 
 * File:   binarySearch.h
 * Author: UTFPR
 *
 * Created on 31 de Março de 2015, 09:02
 */

#ifndef BINARYSEARCH_H
#define	BINARYSEARCH_H

#ifdef	__cplusplus
extern "C" {
#endif

    int binarySearch(int A[], int key, int imin, int imax) {
        // test if array is empty
        if (imax < imin)
            // set is empty, so return value showing not found
            return -1;
        else {
            // calculate midpoint to cut set in half
            int imid = (imin + imax)/2;

            // three-way comparison
            if (A[imid] > key)
                // key is in lower subset
                return binarySearch(A, key, imin, imid - 1);
            else if (A[imid] < key)
                // key is in upper subset
                return binarySearch(A, key, imid + 1, imax);
            else
                // key has been found
                return imid;
        }
    }
    
    float binarySearchTime(int *array, int length, int num) {
        float t;
        int achou;
        clock_t inicio = clock();
        achou = binarySearch(array, length,0, num-1);
        t = (float) (clock() - inicio) / CLOCKS_PER_SEC;
        free(array);
        if(achou!=-1){
            printf("Pos: %d",achou);
        } else {
            printf("Nao encontrado.");
        }
        return t;
    }

    void testarBinarySearch(int tam) {
        int find;
        printf("Qual numero deseja buscar? ");
        scanf("%d",&find);
        printf("\n===BINARY SEARCH TAM %d===\n", tam);
        printf("Ordenados: %f segundos\n", binarySearchTime(ordenados(tam), tam, find));
        printf("Invertidos: %f segundos\n", binarySearchTime(invertidos(tam), tam, find));
        printf("Aleatorios: %f segundos\n", binarySearchTime(aleatorios(tam), tam, find));
        printf("Blocos: %f segundos\n", binarySearchTime(blocos(tam), tam, find));
    }

#ifdef	__cplusplus
}
#endif

#endif	/* BINARYSEARCH_H */

