#include <iostream>
#include "DynamicArray.hpp"
#include "StaticArray.hpp"

using namespace dsalcpp;
void arrayTest() {

    std::cout << "array test" << std::endl;

    StaticArray<int, 10> a;
    
    for(int i = 0; i < a.length(); i++) {
        a.set(i, i+10);
    }

    for (int i = 0; i < a.length(); i++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "================" << std::endl;

    DynamicArray<int> b(10);
    for(int i = 0; i < b.length(); i++) {
        b.set(i, i+20);
    }

    for (int i = 0; i < b.length(); i++) {
        std::cout << b[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "resize" << std::endl;
    b.resize(5);

    for (int i = 0; i < b.length(); i++) {
        std::cout << b[i] << " ";
    }

    std::cout << std::endl;
}