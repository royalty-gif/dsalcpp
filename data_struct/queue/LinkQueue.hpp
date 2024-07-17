/**
 *  @brief: 链队类模板
 *  @note: 借助Linux链表的实现
 */

#ifndef _LINKQUEUE_HPP_
#define _LINKQUEUE_HPP_

#include "Queue.hpp"
#include "LinuxList.h"
#include "Exception.hpp"

namespace dsalcpp
{

template < typename T > 
class LinkQueue : public Queue<T>
{
protected:
    struct Node : public Object {
        list_head head;
        T value;
    };

    list_head header_;
    int length_;

public:
    LinkQueue() {
        length_ = 0;
        INIT_LIST_HEAD(&header_);
    }

    void add(const T& e) {
        Node* node = new Node();

        if( node != NULL ) {
            node->value = e;

            list_add_tail(&node->head, &header_);

            length_++;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to add new element...");
        }
    }

    void remove() {
        if( length_ > 0 ) {
            list_head* toDel = header_.next;

            list_del(toDel);

            length_--;

            delete list_entry(toDel, Node, head);
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current queue...");
        }
    }

    T front() const {
        if( length_ > 0 ) {
            return list_entry(header_.next, Node, head)->value;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current queue...");
        }
    }

    void clear() {
        while( length_ > 0 ) {
            remove();
        }
    }

    int length() const {
        return length_;
    }

    ~LinkQueue() {
        clear();
    }
};

}

#endif