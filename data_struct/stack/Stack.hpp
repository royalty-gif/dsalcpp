/**
 *  @brief: 栈类模板
 */

#ifndef STACK_H
#define STACK_H

#include "Object.hpp"

namespace dsalcpp
{

template < typename T >
class Stack : public Object
{
protected:
    Stack(const Stack<T>&);
    Stack<T>& operator= (const Stack<T>&);

public:
    virtual void push(const T& e) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual void clear() = 0;
    virtual int size() const = 0;

    Stack() {}

    Stack<T>& self() {
        return *this;
    }
};


}

#endif