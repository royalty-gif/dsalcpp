/**
 *  @brief: 队列基类类模板
 */

#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include "Object.hpp"

namespace dsalcpp
{

template < typename T >
class Queue : public Object
{
protected:
    Queue(const Queue<T>&);
    Queue<T>& operator= (const Queue<T>&);

public:
    virtual void add(const T& e) = 0;
    virtual void remove() = 0;
    virtual T front() const = 0;
    virtual void clear() = 0;
    virtual int length() const = 0;

    Queue() {}

    Queue<T>& self() {
        return *this;
    }
};

}

#endif