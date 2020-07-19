#include "bubblesort.h"

BubbleSort::BubbleSort() : SortingAlgoritms("Bubble sort"){}

BubbleSort::~BubbleSort(){}

void BubbleSort::sort(int *arr, int size, Algorithm *al){
    int i, j;

    for(i = 0; i < size - 1; i++)
        for(j = 0; j < size - i - 1; j++){

            if(!Algorithm::gone)
                return;

            this->wait(al, 2, new int[2]{ j, j + 1 });

            if(arr[j] > arr[j + 1]){
                this->swap(&arr[j], &arr[j + 1]);
            }
        }
}

void BubbleSort::execute(int *arr, int size, Algorithm *al){
    SortingAlgoritms::execute(arr, size, al);
}
