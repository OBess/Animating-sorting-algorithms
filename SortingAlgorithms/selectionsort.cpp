#include "selectionsort.h"

SelectionSort::SelectionSort() : SortingAlgoritms("Selection sort"){}

SelectionSort::~SelectionSort(){}

void SelectionSort::sort(int *arr, int size, Algorithm *al){
    for (int idx_i = 0; idx_i < size - 1; idx_i++)
    {
        int min_idx = idx_i;

        if(!Algorithm::gone)
            return;
        for (int idx_j = idx_i + 1; idx_j < size; idx_j++)
        {
            if(!Algorithm::gone)
                return;

            Algorithm::wait(al, 2, new int[2]{idx_j, min_idx});
            if (arr[idx_j] < arr[min_idx])
            {
                min_idx = idx_j;
            }
        }

        if (min_idx != idx_i)
        {
            SortingAlgoritms::swap(&arr[idx_i], &arr[min_idx]);
        }
    }
}

void SelectionSort::execute(int *arr, int size, Algorithm *al){
    SortingAlgoritms::execute(arr, size, al);
}
