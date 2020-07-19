#ifndef COCKTAILSORT_H
#define COCKTAILSORT_H

#include "AbstractClasses/sortingalgoritms.h"

class CocktailSort : public SortingAlgoritms
{
public:
    CocktailSort();
    ~CocktailSort();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;
};

#endif // COCKTAILSORT_H
