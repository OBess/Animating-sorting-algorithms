#ifndef COMBSORT_H
#define COMBSORT_H

#include "AbstractClasses/sortingalgoritms.h"

class CombSort : public SortingAlgoritms
{
public:
    CombSort();
    ~CombSort();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;
};

#endif // COMBSORT_H
