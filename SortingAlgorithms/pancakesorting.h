#ifndef PANCAKESORTING_H
#define PANCAKESORTING_H

#include "AbstractClasses/sortingalgoritms.h"

class PancakeSorting : public SortingAlgoritms
{
public:
    PancakeSorting();
    ~PancakeSorting();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;

private:
    void flip(int* arr, int i, Algorithm* al);
    int findMax(int* arr, int n, Algorithm* al);
};

#endif // PANCAKESORTING_H
