#include <iostream>

extern void arrayTest();
extern void listTest();
extern void stackTest();
extern void queueTest();
extern void sortTest();
extern void treeTest();

int main() {
    std::cout << "Test all" << std::endl;
    //arrayTest();
    //listTest();
    //stackTest();
    //queueTest();
    //sortTest();
    treeTest();
    return 0;
}
