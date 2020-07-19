#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "AbstractClasses/sortingalgoritms.h"

class HeapSort : public SortingAlgoritms
{
public:
    HeapSort();
    ~HeapSort();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;
};

#endif // HEAPSORT_H
