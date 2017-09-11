//
// Created by maesly on 09/09/17.
//

#ifndef TAREA_MERGESORT_H
#define TAREA_MERGESORT_H
#include <iostream>

using namespace std;

// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;

    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }


    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i-low];
    }
}

// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        // Split the data into two half.
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);

        // Merge them to get sorted output.
        Merge(a, low, high, mid);
    }
}

int mainMerge()
{
    int n, i;
    cout<<"\nEnter the number of data element to be sorted: ";
    cin>>n;

    int arr[n];
    for(i = 0; i < n; i++)
    {
        int num = 1+rand() %10000;
        //cout<<"Enter element "<<i+1<<": ";
        //cin>>arr[i];
        arr[i] = num;
    }
    double t1 = clock();
    MergeSort(arr, 0, n-1);
    double t2 = clock();
    cout << "Tiempo de Merge Sort: "<<((t2-t1)/CLOCKS_PER_SEC)<< endl;

    // Printing the sorted data.
    cout<<"\nMerge Sorted Data ";
    for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];

    return 0;
}
#endif //TAREA_MERGESORT_H
