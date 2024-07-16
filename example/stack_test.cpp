#include <iostream>
#include "StaticStack.hpp"
#include "LinkStack.hpp"

using namespace dsalcpp;

void stackTest() {
    std::cout << "StaticStack test" << std::endl;
    StaticStack<int, 5> stack;
    
    for(int i = 0; i < stack.capacity(); i++) {
        stack.push(i);
    }

    while(stack.size() > 0) {
        std::cout << stack.top() << " ";
        stack.pop();
    }

    std::cout << std::endl;

    std::cout << "LinkStack test" << std::endl;
    LinkStack<int> linkStack;
    for(int i = 0; i < 10; i++) {
        linkStack.push(i);
    }

    while(linkStack.size() > 0) {
        std::cout << linkStack.top() << " ";
        linkStack.pop();
    }

    std::cout << std::endl;
}