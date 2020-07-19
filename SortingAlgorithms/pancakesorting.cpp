#include "pancakesorting.h"

PancakeSorting::PancakeSorting() : SortingAlgoritms("Pancake sorting"){}

PancakeSorting::~PancakeSorting(){}

int PancakeSorting::findMax(int *arr, int n, Algorithm *al){
    int mi, i;
    for (mi = 0, i = 0; i < n; ++i){
        if(!Algorithm::gone)
            return 0;
        Algorithm::wait(al, 2, new int[2]{i, mi});
        if (arr[i] > arr[mi])
                mi = i;
    }
    return mi;
}

void PancakeSorting::flip(int *arr, int i, Algorithm *al){
    int temp, start = 0;
    while (start < i)
    {
        if(!Algorithm::gone)
            return;
        Algorithm::wait(al, 2, new int[2]{i, start});

        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

void PancakeSorting::sort(int *arr, int size, Algorithm *al){
    for (int curr_size = size; curr_size > 1; --curr_size)
    {
        if(!Algorithm::gone)
            return;

        int mi = this->findMax(arr, curr_size, al);

        if (mi != curr_size-1)
        {
            this->flip(arr, mi, al);

            this->flip(arr, curr_size-1, al);
        }
    }
}

void PancakeSorting::execute(int *arr, int size, Algorithm *al){
    SortingAlgoritms::execute(arr, size, al);
}
