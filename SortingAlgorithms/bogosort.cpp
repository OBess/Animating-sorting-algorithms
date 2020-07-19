#include "bogosort.h"

BogoSort::BogoSort() : SortingAlgoritms("Bogosort"){}

BogoSort::~BogoSort(){}

int BogoSort::correct(int *arr, int size, Algorithm *al){
    while (size-- > 0){
        if(!Algorithm::gone)
             return 1;
        Algorithm::wait(al, 2, new int[2]{size-1, size});
        if (arr[size - 1] > arr[size])
            return 0;
    }
    return 1;
}

void BogoSort::shuffle(int *arr, int size, Algorithm *al){
    for (int i = 0; i < size; ++i){
        if(!Algorithm::gone)
            return;
        int i2 = (rand() % size);
        Algorithm::wait(al, 2, new int[2]{i, i2});
        SortingAlgoritms::swap(&arr[i], &arr[i2]);
    }
}

void BogoSort::sort(int *arr, int size, Algorithm *al){
    while (!this->correct(arr, size, al)){
        if(!Algorithm::gone)
            return;
        this->shuffle(arr, size, al);
    }
}

void BogoSort::execute(int *arr, int size, Algorithm *al){
    SortingAlgoritms::execute(arr, size, al);
}
