//
// Created by parallels on 9/10/17.
//

#ifndef TAREA_BINARY_TREE_H
#define TAREA_BINARY_TREE_H


#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo{
    int nro;
    struct Nodo *izq, *der;
};

typedef struct Nodo *ABB;  //Simplificación en el uso de variables por medio del puntero.


/**
 * Creación de Nodos
 */
ABB crearNodo(int x)
{
    ABB nuevoNodo = new(struct Nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

/**
 * Función para realizar la inserción de
 * elementos
 */
void insertar(ABB &arbol, int x)
{
    if(arbol==NULL)
    {
        arbol = crearNodo(x);
    }
    else if(x < arbol->nro)
        insertar(arbol->izq, x);
    else if(x > arbol->nro)
        insertar(arbol->der, x);
}

/**
 * Función booleana que retorna r,
 * la cual es una variable que indica
 * si se encontró el elemento o no.
 */
bool busquedaRec(ABB arbol, int dato)
{
    int r=0;

    if(arbol==NULL) {
        cout<< "Dato No Encontrado"<< endl;
        return r;
    }
    if(dato<arbol->nro) {
        r = busquedaRec(arbol->izq, dato);
    }
    else if(dato> arbol->nro) {
        r = busquedaRec(arbol->der, dato);
    }
    else {
        r = 1;   // son iguales, lo encontre
        cout << "Dato Encontrado" << endl;
    }
    return r;
}

/**
 * Imprime el árbol con un recorrido
 * preorden.
 */
void preOrden(ABB arbol)
{
    if(arbol!=NULL)
    {
        cout << arbol->nro <<" ";

        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
/**
 * Imprime el árbol con un recorrido
 * ordenado.
 */
void Orden(ABB arbol)
{
    if(arbol!=NULL)
    {
        Orden(arbol->izq);
        cout << arbol->nro << " ";
        Orden(arbol->der);
    }
}
/**
 * Imprime el árbol con un recorrido
 * postorden.
 */
void postOrden(ABB arbol)
{
    if(arbol!=NULL)
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->nro << " ";
    }
}
/**
 * Esta función realiza una visualización
 * gráfica del árbol.
 */
void verArbol(ABB arbol, int n)
{
    if(arbol==NULL)
        return;
    verArbol(arbol->der, n+1);

    for(int i=0; i<n; i++)
        cout<<"   ";

    cout<< arbol->nro <<endl;

    verArbol(arbol->izq, n+1);
}






#endif //TAREA_BINARY_TREE_H
