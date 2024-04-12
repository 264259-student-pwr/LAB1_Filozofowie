#pragma once

#include <mutex>

class Fork {
public:
    Fork();

    void pickUp();
    void putDown();

private:
    std::mutex mutex;
};