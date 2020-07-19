#include "gnomesort.h"

GnomeSort::GnomeSort() : SortingAlgoritms("Gnome sort"){}

GnomeSort::~GnomeSort(){}

void GnomeSort::sort(int *arr, int size, Algorithm* al){
    int i = 0;
    while(i < size){

        if(i == 0)
            i++;

        if(!Algorithm::gone)
            return;

        this->wait(al, 2, new int[2] {i, i - 1});

        if(arr[i] >= arr[i - 1]){
            i++;
        }
        else{
            this->swap(&arr[i], &arr[i - 1]);
            i--;
        }
    }
}

void GnomeSort::execute(int *arr, int size, Algorithm* al){
    SortingAlgoritms::execute(arr, size, al);
}
