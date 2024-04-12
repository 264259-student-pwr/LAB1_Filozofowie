#pragma once

#include "Fork.h"

class Philosopher {
public:
    Philosopher(int id, Fork& leftFork, Fork& rightFork);

    void dine();

private:
    int id;
    Fork& leftFork;
    Fork& rightFork;
    bool isEating;

    void think();
    void eat();
};