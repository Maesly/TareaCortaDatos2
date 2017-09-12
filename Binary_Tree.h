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

/**
 * Unir
 */

ABB unirABB(ABB izq, ABB der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

/**
 *
 * ERASE
 */


void elimina(ABB &arbol, int x)
{
    if(arbol==NULL) return;

    if(x<arbol->nro)
        elimina(arbol->izq, x);
    else if(x>arbol->nro)
        elimina(arbol->der, x);

    else
    {
        ABB p = arbol;
        arbol = unirABB(arbol->izq, arbol->der);
        delete p;
    }
}



/**
 * Main
 */
int mainBinary(){
    ABB arbol = NULL;   // Se crea un árbol

    int n;
    int dato;
    double t1,t2;

    cout << "\n\t\t   ARBOL BINARIO DE BUSQUEDA   \n\n";

    cout << " Numero de nodos del arbol:  "; //Cantidad de elementos que va a tener el árbol.
    cin >> n;
    cout << endl;

    srand(time(NULL));    //srand(time(NULL)) para evitar que rand() devuelva los mismos números.
    for(int i=0; i<n; i++)
    {
        int x = rand() % 10000;// % 1000 para que retorne números random <1000.
        insertar( arbol, x); // inserta el número en el árbol
    }

    cout << "\n Mostrando ABB \n\n";
    verArbol( arbol, 0);    //Función que realiza la gráfica del árbol

    cout<< "\n\n"<<endl;
    cout << "\n Recorridos del ABB";
    cout << "\n\n En orden   :  ";   Orden(arbol);
    //cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    //cout << "\n\n Post Orden :  ";   postOrden(arbol);

   // cout << "\n Valor a buscar: ";  //Buscar elemento
    //cin >> dato;

    /**
     * T1 y T2 miden el tiempo que tarda en buscar un elemento
     */
    int opcion = 0;
    while(opcion !=987){
        cout<<"\n"<<endl;
        cout<<"1.Buscar un Elemento"<<endl;
        cout<<"2.Eliminar Elemento"<<endl;
        cout<<"3.Ingresar Elemento"<<endl;
        cout<<"4.Salir"<<endl;
        cin>>opcion;

        switch (opcion){

            case 1:

                cout << "\n Valor a buscar: ";
                cin >> dato;

                t1 = clock();
                busquedaRec(arbol,dato);
                t2 = clock();
                cout << "\n\nTiempo Búsqueda: \t: " << ((t2 - t1)/CLOCKS_PER_SEC)*1000<<endl;
                break;

            case 2:
                cout<<"\n Mostrando Lista"<<endl;
                Orden(arbol);
                cout << "\n Valor a Eliminar: ";
                cin >> dato;
                t1 = clock();
                elimina(arbol,dato);
                t2 = clock();
                cout << "\n\nTiempo Eliminar: \t: " << ((t2 - t1)/CLOCKS_PER_SEC)*1000<<endl;
                break;


            case 3:
                cout << "\n Valor a Ingresar: ";
                cin >> dato;
                t1 = clock();
                insertar(arbol,dato);
                t2 = clock();
                Orden(arbol);
                cout << "\n\nTiempo Ingreso: \t: " << ((t2 - t1)/CLOCKS_PER_SEC)*1000<<endl;

                break;
            case 4:
                opcion = 987;
                break;

            default:
                cout<<"Opcion Incorrecta"<<endl;

        }

    }


}






#endif //TAREA_BINARY_TREE_H
