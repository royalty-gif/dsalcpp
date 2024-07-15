#include <iostream>

extern void arrayTest();
extern void listTest();
extern void stackTest();

int main() {
    std::cout << "Test all" << std::endl;
    //arrayTest();
    //listTest();
    stackTest();
    return 0;
}
