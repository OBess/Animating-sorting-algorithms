#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "AbstractClasses/sortingalgoritms.h"

class BubbleSort : public SortingAlgoritms
{
public:
    BubbleSort();
    ~BubbleSort();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;
};

#endif // BUBBLESORT_H
