#ifndef GNOMESORT_H
#define GNOMESORT_H

#include "AbstractClasses/sortingalgoritms.h"

class GnomeSort : public SortingAlgoritms
{
public:
    GnomeSort();
    ~GnomeSort();

protected:
    void sort(int *arr, int size, Algorithm* al) override;
    void execute(int *arr, int size, Algorithm* al) override;
};

#endif // GNOMESORT_H
