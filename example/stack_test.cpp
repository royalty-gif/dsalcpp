#include <iostream>
#include "StaticStack.hpp"

using namespace dsalcpp;

void stackTest() {
    StaticStack<int, 5> stack;
    
    for(int i = 0; i < stack.capacity(); i++) {
        stack.push(i);
    }

    while(stack.size() > 0) {
        int top = stack.top();
        std::cout << top << std::endl;
        stack.pop();
    }
}