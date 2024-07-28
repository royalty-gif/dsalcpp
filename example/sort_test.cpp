#include "Sort.hpp"
#include <iostream>

using namespace dsalcpp;
void sortTest() {
    int array[] = { 8, 2, 3, 5, 5, 6, 1, 8, 3, 10 };
    Sort::select(array, 10, true);

    for (int i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}
