#include "Philosopher.h"
#include <iostream>
#include <chrono>
#include <thread>

Philosopher::Philosopher(int id, Fork& leftFork, Fork& rightFork)
    : id(id), leftFork(leftFork), rightFork(rightFork), isEating(false) {}

void Philosopher::dine() {
    while (true) {
        think();
        eat();
    }
}

void Philosopher::think() {
    std::cout << "Philosopher " << id << " is thinking." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Philosopher::eat() {
    leftFork.pickUp();
    rightFork.pickUp();

    std::cout << "Philosopher " << id << " is eating." << std::endl;
    isEating = true;

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    leftFork.putDown();
    rightFork.putDown();

    isEating = false;
}