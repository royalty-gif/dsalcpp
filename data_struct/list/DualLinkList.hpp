/**
 *  @brief: 双向链表类模板
 */

#ifndef _DUALLINKLIST_HPP_
#define _DUALLINKLIST_HPP_

#include "Exception.hpp"
#include "List.hpp"

namespace dsalcpp 
{

template < typename T >
class DualLinkList : public List<T>
{
protected:
    struct Node : public Object {
        T value;
        Node* prev;
        Node* next;
    };

    mutable struct : public Object {
        char reserved[sizeof(T)];
        Node* prev;
        Node* next;
    } header_;

    int length_;
    int step_;
    Node* current_;

    Node* position(int i) const {
        Node* ret = reinterpret_cast<Node*>(&header_);

        for(int p = 0; p < i; i++) {
            ret = ret->next;
        }

        return ret;
    }

    virtual Node* create() {
        return new Node();
    }

    virtual void destroy(Node* pn) {
        delete pn;
    }

public:
    DualLinkList() {
        header_.prev = NULL;
        header_.next = NULL;
        length_ = 0;
        step_ = 1;
        current_ = NULL;
    }

    bool insert(const T& e) {
        return insert(length_, e);
    }

    bool insert(int i, const T& e) {
        bool ret = ( (0 <= i) && (i <= length_) );

        if( ret ) {
            Node* node = create();

            if( node != NULL ) {
                Node* current = position(i);
                Node* next = current->next;

                node->value = e;

                node->next = next;
                current->next = node;

                if( current != reinterpret_cast<Node*>(&header_)) {
                    node->prev = current;
                } else {
                    node->prev = NULL;
                }

                if( next != NULL ) {
                    next->prev = node;
                } 

                length_++;
            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to insert new element!");
            }
        }
    }

    bool remove(int i) {
        bool ret = ( (0 <= i) && (i < length_) );

        if( ret ) {
            Node* current = position(i);
            Node* toDel = current->next;
            Node* next = toDel->next;

            if( current == toDel ) {
                current = next;
            }

            current->next = next;

            if( next != NULL ) {
                next->prev = toDel->prev;
            }

            length_--;

            destroy(toDel);
        }

        return ret;
    }

    bool set(int i, const T& e) {
        bool ret = ( (0 <= i) && (i < length_) );

        if( ret ) {
            position(i)->next->value = e;
        }

        return ret;
    }

    virtual T get(int i) const {
        T ret;

        if( !get(i, ret) ) {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Invalid parameter i to get element!");
        }

        return ret;
    }

    bool get(int i, T& e) const {
        bool ret = ( (0 <= i) && (i < length_) );

        if( ret ) {
            e = position(i)->next->value;
        }

        return ret;
    }

    int find(const T& e) const {
        int ret = -1;
        int i = 0;
        Node* node = header_.next;

        while( node ) {
            if( node->value == e ) {
                ret = i;
                break;
            } else {
                node = node->next;
                i++;
            }
        }

        return ret;
    }

    int length() const {
        return length_;
    }

    void clear() {
        while( length_ > 0 ) {
            remove(0);
        }
    }

    virtual bool move(int i, int step = 1) {
        bool ret = ( (0 <= i) && (i < length_) && (step > 0) );

        if( ret ) {
            current_ = position(i);
            step_ = step;
        }

        return ret;
    }

    virtual bool end() {
        return ( current_ == NULL );
    }

    virtual T current() {
        if( !end() ) {
            return current_->value;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "Cannot use current() for uninitialized DualLinkList!");
        }
    }

    virtual bool next() {
        int i = 0;

        while( (i < step_) && !end() ) {
            current_ = current_->next;
            i++;
        }

        return (i == step_);
    }

    virtual bool prev() {
        int i = 0;

        while( (i < step_) && !end() ) {
            current_ = current_->prev;
            i++;
        }

        return (i == step_);
    }

    ~DualLinkList() {
        clear();
    }
};

}

#endif