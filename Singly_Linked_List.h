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


#endif //TAREA_SINGLY_LINKED_LIST_H
