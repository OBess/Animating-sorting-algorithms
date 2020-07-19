#include "combsort.h"

CombSort::CombSort() : SortingAlgoritms("Comb sort"){}

CombSort::~CombSort(){}

void CombSort::sort(int *arr, int size, Algorithm *al){
    int n = 0;
    double fakt = 1.2473309;
    double step = size - 1;

    while (step >= 1)
    {
        for (int i = 0; i + step < size; ++i)
        {
            if(!Algorithm::gone)
                return;
            Algorithm::wait(al, 2, new int[2]{i, (int)(i + step)});
            if (arr[i] > arr[(int)(i + step)])
            {
                SortingAlgoritms::swap(&arr[i], &arr[(int)(i + step)]);
                ++n;
            }
        }
        step /= fakt;
    }
    for (int i = 0; i < size - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if(!Algorithm::gone)
                return;
            Algorithm::wait(al, 2, new int[2]{j, j + 1});
            if (arr[j] > arr[j + 1])
            {
                SortingAlgoritms::swap(&arr[j], &arr[j + 1]);
                swapped = true;
                ++n;
            }
        }

        if (!swapped)
            break;
    }
}

void CombSort::execute(int *arr, int size, Algorithm *al){
    SortingAlgoritms::execute(arr, size, al);
}

