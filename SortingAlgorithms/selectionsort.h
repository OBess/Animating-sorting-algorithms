#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "AbstractClasses/sortingalgoritms.h"

class SelectionSort : public SortingAlgoritms
{
public:
    SelectionSort();
    ~SelectionSort();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;
};

#endif // SELECTIONSORT_H
