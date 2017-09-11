#include <iostream>
#include "Bubblesort.h"
#include "Insertionsort.h"
#include <chrono>
#include "AVL Tree.h"
#include "Mergesort.h"
#include "Selectionsort.h"
#include "Binary_Tree.h"
#include "Singly_Linked_List.h"
#include "Quick_Sort.h"


int Hub(){
    int choice = 0,item;

    while(choice != 10){
        cout<<"1.Bubble Sort"<<endl;
        cout<<"2.Insertion Sort"<<endl;
        cout<<"3.AVL Tree"<<endl;
        cout<<"4.Merge Sort"<<endl;
        cout<<"5.Selection Sort"<<endl;
        cout<<"6.Binary Tree"<<endl;
        cout<<"7.Lista Enlazada"<<endl;
        cout<<"8.Quick Sort"<<endl;
        cout<<"9.Salir"<<endl;
        cout<<"Elija una opcion"<<endl;

        cin>>choice;
        switch (choice){
            case 1:
                mainBubble();
                break;

            case 2:
                mainInsertion();
                break;

            case 3:
                mainAVL();
                break;
            case 4:
                mainMerge();
                break;
            case 5:
                mainSelection();
                break;
            case 6:
                mainBinary();
                break;
            case 7:
                mainSinglyLinkedList();
                break;
            case 8:
                mainQuickSort();
                break;
            case 9:
                choice = 10;
                break;

            default:
                cout<<"Opcion Incorrecta"<<endl;
        }

        cout<<"\n._____________Funcion_Finalizada_________."<<endl;


    }
}

int main(){
    Hub();
    //mainHub();
    return 0;

}