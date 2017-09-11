//
// Created by maesly on 08/09/17.
//

#ifndef TAREA_BUBBLESORT_H
#define TAREA_BUBBLESORT_H
#include <iostream>

using namespace std;

// Sort arr[] of size n using Bubble Sort.
void BubbleSort (int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n-i-1; ++j)
        {
            // Comparing consecutive data and switching values if value at j > j+1.
            if (arr[j] > arr[j+1])
            {
                arr[j] = arr[j]+arr[j+1];
                arr[j+1] = arr[j]-arr[j + 1];
                arr[j] = arr[j]-arr[j + 1];
            }
        }
        // Value at n-i-1 will be maximum of all the values below this index.
    }
}
int mainBubble()
{
    int n, i;
    cout<<"\nCantidad de elementos: ";
    cin>>n;

    int arr[n];
    srand(time(NULL));
    for(i = 0; i < n; i++)
    {
        int num = 1+rand() %10000;
        //cout << num <<endl;
        //cout<<"Enter element "<<i+1<<": ";
        arr[i] = num;
        cout<< arr[i] << endl;
    }
    double t1 = clock();
    BubbleSort(arr, n);
    double t2 = clock();
    cout << "Tiempo de BubbleSort: "<<((t2 - t1)/CLOCKS_PER_SEC)*1000<< endl;

    // Display the sorted data.
    cout<<"\nDatos del Bubble Sort";
    for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];

    return 0;
}
#endif //TAREA_BUBBLESORT_H
