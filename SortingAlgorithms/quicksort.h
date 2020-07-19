#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "AbstractClasses/sortingalgoritms.h"

class QuickSort : public SortingAlgoritms
{
public:
    QuickSort();
    ~QuickSort();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;
private:
    void qSort(int* arr, int low, int high, Algorithm* al);
    int part(int* arr, int low, int high, Algorithm* al);
};

#endif // QUICKSORT_H
