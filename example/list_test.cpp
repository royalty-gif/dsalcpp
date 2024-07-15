#include <iostream>
#include "StaticList.hpp"
#include "DynamicList.hpp"
#include "StaticLinkList.hpp"
#include "DualCircleList.hpp"

using namespace dsalcpp;

void listTest() {

    std::cout << "List Test" << std::endl;
    std::cout << "Static List Test" << std::endl;
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

    std::cout << "Dynamic List Test" << std::endl;
    DynamicList<int> dList(5);

    for(int i = 0; i < dList.capacity(); i++) {
        dList.insert(i);
    }

    for(int i = 0; i < dList.capacity(); i++) {
        std::cout << dList[i] << std::endl;
    }

    dList.resize(2);

    for(int i = 0; i < dList.capacity(); i++) {
        std::cout << dList[i] << std::endl;
    }

    std::cout << "Static Link List Test" << std::endl;
    StaticLinkList<int, 5> sLinkList;

    for (int i = 0; i < sLinkList.capacity(); i++) {
        sLinkList.insert(i);
    }

    for(int i = 0; i < sLinkList.capacity(); i++) {
        std::cout << sLinkList.get(i) << std::endl;
    }

    std::cout << "Dual circle List Test" << std::endl;

    DualCircleList<int> dualCircleList;
    
    for (int i = 0; i < 5; i++) {
        dualCircleList.insert(i);
    }

    for(int i = 0; i < dualCircleList.length(); i++) {
        std::cout << dualCircleList.get(i) << std::endl;
    }

    dualCircleList.move(0);
    std::cout << "remove 2" << std::endl;
    dualCircleList.remove(2);

    for(int i = 0; i < dualCircleList.length(); i++) {
        std::cout << dualCircleList.get(i) << std::endl;
    }

    std::cout << "current: " << dualCircleList.current() << std::endl;
    dualCircleList.next();
    std::cout << "current: " << dualCircleList.current() << std::endl;
}
