#ifndef BOGOSORT_H
#define BOGOSORT_H

#include "AbstractClasses/sortingalgoritms.h"

class BogoSort : public SortingAlgoritms
{
public:
    BogoSort();
    ~BogoSort();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;

private:
    void shuffle(int *arr, int size, Algorithm* al);
    int correct(int *arr, int size, Algorithm* al);
};

#endif // BOGOSORT_H
