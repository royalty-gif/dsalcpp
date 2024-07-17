/**
 *  @brief: 双端队列类模板
 */

#ifndef _DUALENDQUEUE_HPP_
#define _DUALENDQUEUE_HPP_

#include "Exception.hpp"
#include "LinkQueue.hpp"

namespace dsalcpp 
{

template < typename T >
class DualEndQueue : public LinkQueue<T>
{
protected:
    typedef typename LinkQueue<T>::Node Node;

public:
    void push(const T& e) {
        Node* node = new Node();

        if( node != NULL ) {
            node->value = e;

            list_add(&node->head, &this->header_);

            this->length_++;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to add new element!");
        }
    }

    void dismiss() {
        if( this->length_ > 0 ) {
            list_head* toDel = this->header_.prev;

            list_del(toDel);

            this->length_--;

            delete list_entry(toDel, Node, head);
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current queue!");
        }
    }

    T back() const {
        if( this->length_ > 0 ) {
            return list_entry(this->header_.prev, Node, head)->value;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current queue!");
        }
    }
};

}

#endif