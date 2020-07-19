#include "heapsort.h"

HeapSort::HeapSort() : SortingAlgoritms("Heap sort"){}

HeapSort::~HeapSort(){}

void HeapSort::sort(int *arr, int size, Algorithm *al){
    int n2 = 0;
    for (int j = 0; j < size; j++)
    {
        for (int i = size / 2 -1 - j/2; i > -1; i--)
        {
            if(!Algorithm::gone)
                return;
            if (2 * i + 2 <= size - 1-j)
            {
                if (arr[2 * i + 1] > arr[2 * i + 2])
                {
                    n2 = 2 * i + 1;
                    Algorithm::wait(al, 2, new int[2]{i, n2});
                    if (arr[i] < arr[2 * i + 1])
                    {
                        SortingAlgoritms::swap(&arr[i], &arr[n2]);
                    }
                }
                else {
                    n2 = 2 * i + 2;
                    Algorithm::wait(al, 2, new int[2]{i, n2});
                    if (arr[i] < arr[2 * i + 2])
                    {
                        SortingAlgoritms::swap(&arr[i], &arr[n2]);
                    }
                }
            }
            else{
                if (2 * i + 1 <= size - 1-j){
                    n2 = 2 * i + 1;
                    Algorithm::wait(al, 2, new int[2]{i, n2});
                    if (arr[i] < arr[2 * i + 1]){
                        SortingAlgoritms::swap(&arr[i], &arr[n2]);
                    }
                }
            }
        }
        n2 = size - 1 - j;
        SortingAlgoritms::swap(&arr[0], &arr[n2]);
    }
}

void HeapSort::execute(int *arr, int size, Algorithm *al){
    SortingAlgoritms::execute(arr, size, al);
}
