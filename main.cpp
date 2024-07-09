#include <iostream>

extern void arrayTest();
extern void listTest();

int main() {
    std::cout << "Test all" << std::endl;
    arrayTest();
    listTest();
    return 0;
}
