#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "Fork.h"
#include "Philosopher.h"

const int NUM_PHILOSOPHERS = 3;

int main() {
    std::vector<Fork> forks(NUM_PHILOSOPHERS);
    std::vector<Philosopher> philosophers;

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        int leftForkIndex = i;
        int rightForkIndex = (i + 1) % NUM_PHILOSOPHERS;
        philosophers.emplace_back(i, forks[leftForkIndex], forks[rightForkIndex]);
    }

    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        threads.emplace_back([&philosopher = philosophers[i]]() { philosopher.dine(); });
    }

    std::cin.get();

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}