#include "mergesort.h"

MergeSort::MergeSort() : SortingAlgoritms("Merge sort"){}

MergeSort::~MergeSort(){}

void MergeSort::merge(int *a, int *t, int i, int l, int n, Algorithm *al){
    int j = i + l,
            n1 = std::min(j, n),
            n2 = std::min(j + l, n),
            k = i;

    if(!Algorithm::gone)
        return;

    while (i < n1 && j < n2){
        if(a[i] <= a[j]){
            t[k++] = a[i++];
            Algorithm::wait(al, 2, new int[2]{k, i});
        }
        else{
            t[k++] = a[j++];
            Algorithm::wait(al, 2, new int[2]{k, j});
        }
    }
    while (i < n1){
        t[k++] = a[i++];
        Algorithm::wait(al, 2, new int[2]{k, i});
    }
    while (j < n2){
        t[k++] = a[j++];
        Algorithm::wait(al, 2, new int[2]{k, j});
    }
    if(!Algorithm::gone)
        return;
}

void MergeSort::sort(int *a, int n, Algorithm *al){
    int *t = (int *)malloc(n * sizeof(int));
    int l = 1, i;

    while (l < n) {

        if(!Algorithm::gone)
            return;

        for (i = 0; i < n; i += 2 * l)
            this->merge(a, t, i, l, n, al);
        l *= 2;
        for (i = 0; i < n; i += 2 * l)
            this->merge(t, a, i, l, n, al);
        l *= 2;
    }

    free(t);
}

void MergeSort::execute(int *arr, int size, Algorithm *al){
    SortingAlgoritms::execute(arr, size, al);
}
