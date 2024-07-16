#include <iostream>
#include "StaticQueue.hpp"


using namespace dsalcpp;
void queueTest() {
    std::cout << "StaticQueue test" << std::endl;
    StaticQueue<int, 10> squeue;

    for (int i = 0; i < 10; i++) {
        squeue.add(i);
    }

    while ( squeue.length() > 0) {
        std::cout << squeue.front() << " ";
        squeue.remove();
    }

    std::cout << std::endl;
}