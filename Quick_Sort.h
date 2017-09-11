//
// Created by parallels on 9/10/17.
//

#ifndef TAREA_QUICK_SORT_H
#define TAREA_QUICK_SORT_H

#define largo 10000
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

/**
 * LeeCadena() recibe un entero y un array, siendo el
 * entero la cantidad de elementos que va a tener la lista.
 * Esta funcion por medio de la función RAND(), introdcuce
 * números aleatorios a la lista.
 */
void leeCadena(int cant,int n[])
{
    int i;
    srand(time(NULL));

    for(i=0;i<cant;i++)
    {
        int x = rand();
        n[i]=x;
    }

}

/**
 * La función mestraCadena, imprime los elementos del array.
 */
void muestraCadena(int cant,int n[])
{
    int i;
    for(i=0;i<cant;i++)
    {
        cout<<n[i]<<endl;
    }
}


int mainQuickSort(){

    int A[largo],n;
    double t1,t2;

    do{
        cout<<"Cantidad de numeros a ingresar: ";cin>>n;
    }
    while(n<=0||n>largo);
    leeCadena(n,A);

    /**
     * t1 y t2 miden el tiempo que tarda en ordenar el array
     */
    t1 = clock();
    quicksort(A,0,n-1);
    t2 = clock();

    muestraCadena(n,A);
    cout << "Quick Sort TIME: \t: " << ((t2 - t1)/CLOCKS_PER_SEC)*1000<<endl;

}

#endif //TAREA_QUICK_SORT_H
