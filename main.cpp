#include <iostream>

extern void arrayTest();
extern void listTest();
extern void stackTest();
extern void queueTest();
extern void sortTest();

int main() {
    std::cout << "Test all" << std::endl;
    //arrayTest();
    //listTest();
    //stackTest();
    //queueTest();
    sortTest();
    return 0;
}
