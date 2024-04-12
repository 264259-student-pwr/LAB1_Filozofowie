#include "Fork.h"

Fork::Fork() : mutex() {}

void Fork::pickUp() {
    mutex.lock();
}

void Fork::putDown() {
    mutex.unlock();
}