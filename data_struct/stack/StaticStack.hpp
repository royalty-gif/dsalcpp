/**
 *  @brief: 静态栈类模板
 */

#ifndef _STATICSTACK_HPP_
#define _STATICSTACK_HPP_

#include "Stack.hpp"
#include "Exception.hpp"

namespace dsalcpp
{

template < typename T, int N > 
class StaticStack : public Stack<T>
{
protected:
    T space_[N];
    int top_;
    int size_;

public:
    StaticStack() {
        top_ = -1;
        size_ = 0;
    }

    int capacity() const {
        return N;
    }

    void push(const T& e) {
        if( size_ < N ) {
            space_[++top_] = e;
            size_++;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No enough memory to push new element into stack.");
        }
    }

    void pop() {
        if( size_ > 0 ) {
            top_--;
            size_--;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in stack can be poped.");
        }
    }

    T top() const {
        if( size_ > 0 ) {
            return space_[top_];
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in stack.");
        }
    }

    void clear() {
        top_ = -1;
        size_ = 0;
    }

    int size() const {
        return size_;
    }
};

}

#endif