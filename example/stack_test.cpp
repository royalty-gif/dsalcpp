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
        int top = stack.top();
        std::cout << top << std::endl;
        stack.pop();
    }

    std::cout << "LinkStack test" << std::endl;
    LinkStack<int> linkStack;
    for(int i = 0; i < 10; i++) {
        linkStack.push(i);
    }

    while(linkStack.size() > 0) {
        int top = linkStack.top();
        std::cout << top << std::endl;
        linkStack.pop();
    }
}