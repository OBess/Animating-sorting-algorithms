#include "sortingalgoritms.h"

SortingAlgoritms::SortingAlgoritms(std::string name) : Algorithm(name){}

SortingAlgoritms::~SortingAlgoritms(){}

void SortingAlgoritms::swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SortingAlgoritms::execute(int *arr, int size, Algorithm *al){
    Algorithm::gone = true;
    this->sort(arr, size, al);
    Algorithm::gone = false;
    Algorithm::wait(al, 0, new int[0]);
}
