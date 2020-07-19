#include "quicksort.h"

QuickSort::QuickSort() : SortingAlgoritms("Quick sort"){}

QuickSort::~QuickSort(){}

int QuickSort::part(int *arr, int low, int high, Algorithm *al){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if(!Algorithm::gone)
            return 0;

        Algorithm::wait(al, 2, new int[2]{high, i});

        if (arr[j] < pivot)
        {
            i++;
            SortingAlgoritms::swap(&arr[i], &arr[j]);
        }
        if(!Algorithm::gone)
            return 0;
    }
    SortingAlgoritms::swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort::qSort(int *arr, int low, int high, Algorithm *al){
    if(!Algorithm::gone)
        return;

    if (low < high)
    {
        int pi = part(arr, low, high, al);

        qSort(arr, low, pi - 1, al);
        qSort(arr, pi + 1, high, al);
    }
    if(!Algorithm::gone)
        return;
}

void QuickSort::sort(int *arr, int size, Algorithm *al){
    this->qSort(arr, 0, size - 1, al);
}

void QuickSort::execute(int *arr, int size, Algorithm *al){
    SortingAlgoritms::execute(arr, size, al);
}


