#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <thread>
#include <string>
#include <iostream>
#include <ctime>

//Abstract class for all algoritms
//that have method 'execute'

class Algorithm
{
public:
    std::string name;
    static unsigned Time;
    static bool gone;

    Algorithm(std::string name);
    virtual ~Algorithm() = 0;
    virtual void execute(int* arr, int size, Algorithm* al) = 0;

protected:
    void wait(Algorithm* alg, int size, int* positions);

private:
    static void sleep(unsigned milliseconds);
};

#endif // ALGORITHM_H
