#include "algorithmarea.h"

AlgorithmArea::AlgorithmArea() : Algorithm("")
{
    this->v_sortAlgorithms.push_back(new BubbleSort);
    this->v_sortAlgorithms.push_back(new GnomeSort);
    this->v_sortAlgorithms.push_back(new InsertionSort);
    this->v_sortAlgorithms.push_back(new MergeSort);
    this->v_sortAlgorithms.push_back(new SelectionSort);
    this->v_sortAlgorithms.push_back(new CombSort);
    this->v_sortAlgorithms.push_back(new HeapSort);
    this->v_sortAlgorithms.push_back(new QuickSort);    //TODO: после него нельзя рандомайзить
    this->v_sortAlgorithms.push_back(new BogoSort);
    this->v_sortAlgorithms.push_back(new CocktailSort);
    this->v_sortAlgorithms.push_back(new PancakeSorting);

    this->init();
}

AlgorithmArea::~AlgorithmArea(){
    Algorithm::gone = false;

    for(auto i = this->v_sortAlgorithms.rbegin(); i != this->v_sortAlgorithms.rend(); i++){
        delete *i;
    }

    delete algorithm;
    delete [] this->arr;
    delete [] this->selectedArr;
}


//Initial
void AlgorithmArea::init(){
    this->numOfAlg = 0;

    this->size = 1;
    this->arr = new int [size];
    this->arr[0] = 1;

    this->selectedArr = new bool [size];

    this->generateArray(START_SIZE);

    this->algorithm = nullptr;
}
//End initial


//Getters
int AlgorithmArea::getSize(){
    return this->size;
}
int* AlgorithmArea::getArr(){
    return this->arr;
}
int AlgorithmArea::getSizeSelected(){
    return this->sizeSelected;
}
std::vector<Algorithm*> AlgorithmArea::getV_SortAlgorithms(){
    return this->v_sortAlgorithms;
}
int AlgorithmArea::indexOf(std::string name){
    int pos = 0;

    for(auto it: this->v_sortAlgorithms)
    {
        if(it->name == name)
            return pos;
        pos++;
    }

    return -1;
}
//End getters


//Setters
void AlgorithmArea::setWidget(QWidget *widget){
    this->widget = widget;
}
void AlgorithmArea::setNumOfAlg(int num){
    this->numOfAlg = num;
}
//End setters


//Logic

int* AlgorithmArea::getSelected(){
    this->sizeSelected = 0;
    std::vector<int> v;

    for(int i = 0; i < this->size; i++)
        if(this->selectedArr[i]){
            this->sizeSelected++;
            v.push_back(i);
        }

    return &v[0];
}

void AlgorithmArea::execute(int *arr, int size, Algorithm* al){
    Q_UNUSED(al);
    this->setSelectedItem(*arr, (bool)size);
}
void AlgorithmArea::execute(){
    this->algorithm = this->v_sortAlgorithms.at(this->numOfAlg);

    std::thread ([this](){ this->algorithm->execute(this->arr, this->size, this); }).detach();
}

void AlgorithmArea::generateArray(int size){
    this->size = size;

    delete [] arr;
    delete [] selectedArr;

    this->arr = new int [size];
    this->selectedArr = new bool [size];

    srand(time(NULL));
    for(int i = 0; i < size; i++){
        this->arr[i] = rand() % (MAX * 2) - MAX;
        this->selectedArr[i] = false;
    }
}

void AlgorithmArea::setSelectedItem(int i, bool b){
    if(i >= 0)
        this->selectedArr[i] = b;
    this->widget->update();
}
//End logic
