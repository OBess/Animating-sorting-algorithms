#ifndef MERGESORT_H
#define MERGESORT_H

#include "AbstractClasses/sortingalgoritms.h"

class MergeSort : public SortingAlgoritms
{
public:
    MergeSort();
    ~MergeSort();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;

private:
    void merge(int a[], int t[], int i, int l, int n, Algorithm *al);
};

#endif // MERGESORT_H
