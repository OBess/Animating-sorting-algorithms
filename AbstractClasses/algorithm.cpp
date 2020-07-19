#include "algorithm.h"

Algorithm::Algorithm(std::string name)
{
    this->name = name;
}

Algorithm::~Algorithm(){}

unsigned Algorithm::Time = 50;
bool Algorithm::gone = false;

void Algorithm::wait(Algorithm* alg, int size, int* positions){
    int i;

    for(i = 0; i < size; i++)
        alg->execute(&positions[i], true, nullptr);

    if(Algorithm::Time >= 1)
        Algorithm::sleep(Algorithm::Time);
//        std::this_thread::sleep_for(std::chrono::milliseconds(Algorithm::Time));

    for(i = 0; i < size; i++)
        alg->execute(&positions[i], false, nullptr);

    delete [] positions;
}

void Algorithm::sleep(unsigned milliseconds)
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end){}
}
