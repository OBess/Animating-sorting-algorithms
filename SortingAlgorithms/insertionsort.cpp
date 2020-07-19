#include "insertionsort.h"

InsertionSort::InsertionSort() : SortingAlgoritms("Insertion sort"){}

InsertionSort::~InsertionSort(){}

void InsertionSort::sort(int *arr, int size, Algorithm *al){
    for(int i = 1; i < size; i++){

        for(int j = i; j > 0 && arr[j-1] > arr[j]; j--){
            if(!Algorithm::gone)
                return;
            Algorithm::wait(al, 2, new int[2]{j - 1, j});
            SortingAlgoritms::swap(&arr[j-1], &arr[j]);
        }

        if(!Algorithm::gone)
            return;
    }
}

void InsertionSort::execute(int *arr, int size, Algorithm *al){
    SortingAlgoritms::execute(arr, size, al);
}
