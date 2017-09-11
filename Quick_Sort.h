//
// Created by parallels on 9/10/17.
//

#ifndef TAREA_QUICK_SORT_H
#define TAREA_QUICK_SORT_H

#include <iostream>
#include <sys/time.h>

using namespace std;
/**quicksort ordena los elementos de un array
 * implementando Quick Sort
 */
void quicksort(int A[],int izq, int der )
{
    int i, j, x , aux;
    i = izq;
    j = der;
    x = A[ (izq + der) /2 ];
    do{
        while( (A[i] < x) && (j <= der) )
        {
            i++;
        }

        while( (x < A[j]) && (j > izq) )
        {
            j--;
        }

        if( i <= j )
        {
            aux = A[i]; A[i] = A[j]; A[j] = aux;
            i++;  j--;
        }

    }while( i <= j );
    {

        if (izq < j)
            quicksort(A, izq, j);
        if (i < der)
            quicksort(A, i, der);
    }
}

#endif //TAREA_QUICK_SORT_H
