#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "AbstractClasses/sortingalgoritms.h"

class InsertionSort : public SortingAlgoritms
{
public:
    InsertionSort();
    ~InsertionSort();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;
};

#endif // INSERTIONSORT_H
