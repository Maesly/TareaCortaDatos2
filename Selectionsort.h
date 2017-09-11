//
// Created by maesly on 09/09/17.
//

#ifndef TAREA_SELECTIONSORT_H
#define TAREA_SELECTIONSORT_H
#include <iostream>

using namespace std;

// Sort arr[] of size n using Selection Sort.
void SelectionSort (int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = i+1; j < n; ++j)
        {
            // Comparing consecutive data and switching values if value at i > j.
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i]+arr[j];
                arr[j] = arr[i]-arr[j];
                arr[i] = arr[i]-arr[j];
            }
        }
        // Value at i will be minimum of all the values above this index.
    }
}

int mainSelection()
{
    int n, i;
    cout<<"\nEnter the number of data element to be sorted: ";
    cin>>n;

    int arr[n];
    for(i = 0; i < n; i++)
    {
        //cout<<"Enter element "<<i+1<<": ";
        //cin>>arr[i];
        int num = 1+rand() %10000;
        arr[i] = num;
    }
    double t1 = clock();
    SelectionSort(arr, n);
    double t2 = clock();
    cout << "Tiempo de SelectioSort: "<<((t2-t1)/CLOCKS_PER_SEC)<< endl;
    // Display the sorted data.
    cout<<"\nSelection Sorted Data ";
    for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];

    return 0;
}

#endif //TAREA_SELECTIONSORT_H
