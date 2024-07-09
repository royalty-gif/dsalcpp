#include <iostream>
#include "StaticList.hpp"

using namespace dsalcpp;

void listTest() {

    std::cout << "List Test" << std::endl;
    StaticList<int, 5> sList;

    for(int i = 0; i < sList.capacity(); i++) {
        sList.insert(i);
    }

    for(int i = 0; i < sList.capacity(); i++) {
        std::cout << sList[i] << std::endl;
    }

    std::cout << "length: " << sList.length() << std::endl;

    sList.remove(2);

    for(int i = 0; i < sList.length(); i++) {
        std::cout << sList[i] << std::endl;
    }
}
