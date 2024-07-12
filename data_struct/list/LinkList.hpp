/**
 *  @brief: 链式线性表类模板
 */

#ifndef _LINKLIST_HPP_
#define _LINKLIST_HPP_

#include "List.hpp"
namespace dsalcpp
{

template < typename T >
class LinkList : public List<T>
{
protected:
    struct Node : public Object {
        Node* next;
        T value;
    };

    // mutable意味着是可变的，为了让position函数可以编译过    
    mutable struct : public Object {
        Node* next;
        char reserved[sizeof(T)];
    } header_;

    int length_;
    int step_;
    Node* current_;

    Node* position(int i) const {
        Node* ret = reinterpret_cast<Node*>(&header_);

        for(int p = 0; p < i; p++) {
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
    LinkList() {
        header_.next = NULL;
        length_ = 0;
        step_ = 1;
        current_ = NULL;
    }

    bool insert(int i, const T& e) {
        bool ret = ( (0 <= i) && (i <= length_) );

        if( ret ) {
            Node* node = create();

            if( node != NULL ) {
                Node* current = position(i);

                node->value = e;
                node->next = current->next;
                current->next = node;

                length_++;
            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to insert new element...");
            }
        }

        return ret;
    }

    bool insert(const T& e) {
        return insert(length_, e);
    }

    bool remove(int i) {
        bool ret = ( (0 <= i) && (i < length_) );

        if( ret ) {
            Node* current = position(i);
            Node* toDel = current->next;

            if( current_ == toDel ) {
                current_ = toDel->next;
            }

            current->next = toDel->next;

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

    virtual bool get(int i, T& e) const {
        bool ret = ( (0 <= i) && (i < length_) );

        if( ret ) {
            e = position(i)->next->value;
        }

        return ret;
    }

    virtual T get(int i) const {
        T ret;

        if( get(i, ret) ) {
            return ret;
        } else {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Invalid parameter i to get element...");
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
        while( header_.next ) {
            Node* toDel = header_.next;

            header_.next = toDel->next;

            length_--;

            destroy(toDel);
        }

        current_ = NULL;
    }

    virtual bool move(int i, int step = 1) {
        bool ret = ( (0 <= i) && (i < length_) && (step > 0) );

        if( ret ) {
            current_ = position(i)->next;
            step_ = step;
        }

        return ret;
    }

    virtual bool end() const {
        return (current_ == NULL);
    }

    virtual T current() const {
        if( !end() ) {
            return current_->value;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No value at current position...");
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

    ~LinkList() {
        clear();
    }
};


}

#endif