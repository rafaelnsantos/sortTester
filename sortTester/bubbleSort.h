/* 
 * File:   bubbleSort.h
 * Author: Verde
 *
 * Created on March 9, 2015, 5:30 PM
 */

#ifndef BUBBLESORT_H
#define	BUBBLESORT_H

#ifdef	__cplusplus
extern "C" {
#endif


double bubbleSort(int *array, int length)
 {
     clock_t inicio = clock();
     
     int i, j, tmp;
     for (i = 0; i < length - 1; ++i) 
     {
 
 	for (j = 0; j < length - i - 1; ++j) 
        {
 	    if (array[j] > array[j + 1]) 
            {
 		tmp = array[j];
 		array[j] = array[j + 1];
 		array[j + 1] = tmp;
 	    }
 	}
     }
     return (double)(clock() - inicio) / CLOCKS_PER_SEC;
 }

#ifdef	__cplusplus
}
#endif

#endif	/* BUBBLESORT_H */

