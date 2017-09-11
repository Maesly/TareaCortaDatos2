//
// Created by parallels on 9/10/17.
//

#ifndef TAREA_SINGLY_LINKED_LIST_H
#define TAREA_SINGLY_LINKED_LIST_H


#include <iostream>
#include <stdlib.h>
using namespace std;
/**
 * Inicializa el nodo
 */
struct nodo{
    int nro;
    struct nodo *sgte;
};

typedef struct nodo *Tlista;

/**
 * Inserta valores al inicio de la lista enlazada.
 */

void insertarInicio(Tlista &lista, int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}

/**
 * 
 */

/**
 * Su función es buscar el elemento deseado
 * dentro de una lista.
 */
void buscarElemento(Tlista lista, int valor)
{
    Tlista q = lista;
    int i = 1, band = 0;

    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}
/**
 * Imprime la Lista
 */
void reportarLista(Tlista lista)
{
    int i = 0;

    while(lista != NULL)
    {
        cout <<' '<< i+1 <<") " << lista->nro << endl;
        lista = lista->sgte;
        i++;
    }
}

/**
 * Eliminar Elemento
 *
 */

void eliminarElemento(Tlista &lista, int valor)
{
    Tlista p, ant;
    p = lista;

    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;

                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}

/**
 *
 * Eliminar Repetidos
 */

void eliminaRepetidos(Tlista &lista, int valor)
{
    Tlista q, ant;
    q = lista;
    ant = lista;

    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            if(q==lista) // primero elemento
            {
                lista = lista->sgte;
                delete(q);
                q = lista;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }

    }// fin del while

    cout<<"\n\n Valores eliminados..!"<<endl;
}

/**
 *
 * Main
 */

int mainSinglyLinkedList(){


    Tlista lista = NULL;

    int n;
    double t1,t2;

    cout << "\n\t\t LISTA ENLAZADA SIMPLE \n\n";

    int dato;

    cout << " Numero de elementos de la lista:  ";
    cin >> n;
    cout << endl;

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        int x = rand() % 100;
        insertarInicio(lista, x);
    }
    cout << "\n\n MOSTRANDO LISTA\n\n";
    reportarLista(lista);

    cout << "\n Valor a buscar: ";
    cin >> dato;

    /**
     * t1 y t2 miden el tiempo que tarda el algoritmo
     * en buscar un elemento
     * en la lista.
     */
    t1 = clock();
    buscarElemento(lista, dato);
    t2 = clock();
    cout << "Tiempo Búsqueda Lista Simple: \t: " << ((t2 - t1)/CLOCKS_PER_SEC)*1000<<endl;


}


#endif //TAREA_SINGLY_LINKED_LIST_H
