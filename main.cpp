#include <iostream>

extern void arrayTest();
extern void listTest();
extern void stackTest();
extern void queueTest();

int main() {
    std::cout << "Test all" << std::endl;
    arrayTest();
    listTest();
    stackTest();
    queueTest();
    return 0;
}
