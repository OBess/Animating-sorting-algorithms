#ifndef SORTINGALGORITMS_H
#define SORTINGALGORITMS_H

#include "algorithm.h"

//Abstract class for all algoritms of sorting
//that have abstract class 'Algoritm'
//and method 'execute' and static method 'swap'

class SortingAlgoritms : public Algorithm
{
public:
    SortingAlgoritms(std::string name);
    ~SortingAlgoritms();
    void execute(int* arr, int size, Algorithm* al) override;

    virtual void sort(int* arr, int size, Algorithm* al) = 0;
    static void swap(int* a, int* b);
};

#endif // SORTINGALGORITMS_H
