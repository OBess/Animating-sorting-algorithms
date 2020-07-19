#ifndef ALGORITHMAREA_H
#define ALGORITHMAREA_H

//Class that have state of array
//and call execute some algoritm
//and generate random array

#include <QWidget>

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <thread>

//Sorting algorithms
#include "SortingAlgorithms/gnomesort.h"
#include "SortingAlgorithms/bubblesort.h"
#include "SortingAlgorithms/insertionsort.h"
#include "SortingAlgorithms/mergesort.h"
#include "SortingAlgorithms/selectionsort.h"
#include "SortingAlgorithms/combsort.h"
#include "SortingAlgorithms/heapsort.h"
#include "SortingAlgorithms/quicksort.h"
#include "SortingAlgorithms/bogosort.h"
#include "SortingAlgorithms/cocktailsort.h"
#include "SortingAlgorithms/pancakesorting.h"

class AlgorithmArea : Algorithm
{
public:
    AlgorithmArea();
    ~AlgorithmArea();

    int getSize();
    int* getArr();
    int* getSelected();
    int getSizeSelected();
    std::vector<Algorithm*> getV_SortAlgorithms();
    int indexOf(std::string name);

    void setWidget(QWidget* widget);
    void setNumOfAlg(int num);

    void execute(int *arr, int size, Algorithm* al) override;
    void execute();

    void generateArray(int size);

    void setSelectedItem(int i, bool b);    //When set selected item call update method from Panel
private:
    void init();

    const unsigned MAX = 100;               //Max negative and positiv namber in array
    const unsigned START_SIZE = 30;

    Algorithm* algorithm;
    QWidget* widget;

    std::vector<Algorithm*> v_sortAlgorithms;

    int size;
    int* arr;
    bool* selectedArr;
    int sizeSelected;
    int numOfAlg;
};

#endif // ALGORITHMAREA_H
