#include <iostream>
#include "StaticQueue.hpp"
#include "LinkQueue.hpp"
#include "DualEndQueue.hpp"


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

    std::cout << "LinkQueue test" << std::endl;
    LinkQueue<int> lqueue;

    for (int i = 0; i < 10; i++) {
        lqueue.add(i);
    }

    while ( lqueue.length() > 0) {
        std::cout << lqueue.front() << " ";
        lqueue.remove();
    }

    std::cout << std::endl;

    std::cout << "DualEndQueue test" << std::endl;
    DualEndQueue<int> dqueue;

    for (int i = 0; i < 10; i++) {
        dqueue.add(i);
    }

    std::cout << "front: " << dqueue.front() << std::endl;
    std::cout << "back: " << dqueue.back() << std::endl;

    dqueue.dismiss();

    std::cout << "front: " << dqueue.front() << std::endl;
    std::cout << "back: " << dqueue.back() << std::endl;

    dqueue.remove();

    std::cout << "front: " << dqueue.front() << std::endl;
    std::cout << "back: " << dqueue.back() << std::endl;
}