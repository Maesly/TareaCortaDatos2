//
// Created by maesly on 08/09/17.
//

#ifndef TAREA_INSERTIONSORT_H
#define TAREA_INSERTIONSORT_H
#include <iostream>

using namespace std;

// A structure to represent a node.
struct list
{
    int data;
    list *next;
};

// Function implementing insertion sort.
list* InsertinList(list *head, int n)
{
    // Creating newnode and temp node.
    list *newnode = new list;
    list *temp = new list;

    // Using newnode as the node to be inserted in the list.
    newnode->data = n;
    newnode->next = NULL;

    // If head is null then assign new node to head.
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    else
    {
        temp = head;

        // If newnode->data is lesser than head->data, then insert newnode before head.
        if(newnode->data < head->data)
        {
            newnode->next = head;
            head = newnode;
            return head;
        }

        // Traverse the list till we get value more than newnode->data.
        while(temp->next != NULL)
        {
            if(newnode->data < (temp->next)->data)
                break;

            temp=temp->next;
        }

        // Insert newnode after temp.
        newnode->next = temp->next;
        temp->next = newnode;
        return head;
    }
}

int mainInsertion()
{
    int n, i, num;
    double t1,t2;
    // Declaring head of the linked list.
    list *head = new list;
    head = NULL;

    cout<<"\nCantidad de elementos: ";
    cin>>n;
    int arr[n];
    srand(time(NULL));

    t1=clock();
    for(i = 0; i < n; i++)
    {
        int num = 1+rand() %10000;
        //cout<<"Enter element "<<i+1<<": ";
        //cin>>num;
        arr[i] = num;
        // Inserting num in the list.
        head = InsertinList(head, num);
    }
    t2 = clock();
    cout << "Insertion Sort TIME: \t: " << ((t2 - t1)/CLOCKS_PER_SEC)*1000<<endl;
/**
    // Display the sorted data.
    cout<<"\n Elementos del Insertion Sorted ";
    while(head != NULL)
    {
        cout<<"->"<<head->data;
        head = head->next;
    }
*/
    return 0;
}
#endif //TAREA_INSERTIONSORT_H
