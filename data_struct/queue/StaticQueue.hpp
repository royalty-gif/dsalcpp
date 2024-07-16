/**
 *  @brief: 静态队列类模板
 */

#ifndef _STATICQUEUE_HPP_
#define _STATICQUEUE_HPP_

#include "Queue.hpp"
#include "Exception.hpp"

namespace dsalcpp
{

template < typename T, int N >
class StaticQueue : public Queue<T>
{
protected:
    T space_[N];
    int front_;
    int rear_;
    int length_;

public:
    StaticQueue() {
        front_ = 0;
        rear_ = 0;
        length_ = 0;
    }

    int capacity() {
        return N;
    }

    void add(const T& e) {
        if( length_ < N ) {
            space_[rear_] = e;
            rear_ = (rear_ + 1) % N;
            length_++;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No enough space in current queue...");
        }
    }

    void remove() {
        if( length_ > 0 ) {
            front_ = (front_ + 1) % N;
            length_--;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current queue...");
        }
    }

    T front() const {
        if( length_ > 0 ) {
            return space_[front_];
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current queue...");
        }
    }

    void clear() {
        front_ = 0;
        rear_ = 0;
        length_ = 0;
    }

    int length() const {
        return length_;
    }
};

}

#endif