#include "cocktailsort.h"

CocktailSort::CocktailSort() : SortingAlgoritms("Cocktail sort"){}

CocktailSort::~CocktailSort(){}

void CocktailSort::sort(int *a, int size, Algorithm *al){
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {

        if(!Algorithm::gone)
            return;

        swapped = false;

        for (int i = start; i < end; ++i) {
            if(!Algorithm::gone)
                return;

            Algorithm::wait(al, 2, new int[2]{i, i + 1});

            if (a[i] > a[i + 1]) {
                SortingAlgoritms::swap(&a[i], &a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        --end;

        for (int i = end - 1; i >= start; --i) {

            Algorithm::wait(al, 2, new int[2]{i, i + 1});

            if(!Algorithm::gone)
                return;

            if (a[i] > a[i + 1]) {
                SortingAlgoritms::swap(&a[i], &a[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

void CocktailSort::execute(int *arr, int size, Algorithm *al){
    SortingAlgoritms::execute(arr, size, al);
}
