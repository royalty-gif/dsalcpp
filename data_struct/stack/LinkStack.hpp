/**
 *  @brief: 链栈类模板
 */

#ifndef _LINKSTACK_HPP_
#define _LINKSTACK_HPP_

#include "Stack.hpp"
#include "LinkList.hpp"

namespace dsalcpp
{

template < typename T >
class LinkStack : public Stack<T>
{
protected:
    LinkList<T> list_;

public:
    void push(const T& e) {
        list_.insert(0, e);
    }

    void pop() {
        if( list_.length() > 0 ) {
            list_.remove(0);
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current stack.");
        }
    }

    T top() const {
        if( list_.length() > 0 ) {
            return list_.get(0);
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current stack.");
        }
    }

    void clear() {
        list_.clear();
    }

    int size() const {
        return list_.length();
    }
};


}

#endif