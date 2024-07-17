/**
 *  @brief: 双向循环链表类模板
 *  @details: 使用Linux的双向链表实现
 */

#ifndef _DUALCIRCLELIST_HPP_
#define _DUALCIRCLELIST_HPP_

#include "DualLinkList.hpp"
#include "LinuxList.h"

namespace dsalcpp
{

template < typename T >
class DualCircleList : public DualLinkList<T>
{
protected:
    struct Node : public Object {
        list_head head;
        T value;
    };

    list_head header_;
    list_head* current_;

    list_head* position(int i) const {
        list_head* ret = const_cast<list_head*>(&header_);

        for(int p  = 0; p < i; p++) {
            ret = ret->next;
        }

        return ret;
    }

    int mod(int i) const {
        return (this->length_ == 0) ? 0 : (i % this->length_);
    }

public:
    DualCircleList() {
        this->length_ = 0;
        this->step_ = 1;

        current_ = NULL;

        INIT_LIST_HEAD(&header_);
    }

    bool insert(const T& e) {
        return insert(this->length_, e);
    }

    bool insert(int i, const T& e) {
        bool ret = true;
        Node* node = new Node();

        if( node != NULL ) {
            i = i % (this->length_ + 1);

            node->value = e;

            list_add_tail(&node->head, position(i)->next);

            this->length_++;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to insert new element!");
        }

        return ret;
    }

    bool remove(int i) {
        bool ret = true;

        i = mod(i);

        ret = ( (0 <= i) && (i < this->length_) );

        if( ret ) {
            list_head* toDel = position(i)->next;

            if( current_ == toDel ) {
                current_ = toDel->next;
            }

            list_del(toDel);

            this->length_--;

            delete list_entry(toDel, Node, head);
        }

        return ret;
    }

    bool set(int i, const T& e) {
        bool ret = true;

        i = mod(i);

        ret = ( (0 <= i) && (i < this->length_) );

        if( ret ) {
            list_entry(position(i)->next, Node, head)->value = e;
        }

        return ret;
    }
    T get(int i) const {
        T ret;

        if( !get(i, ret) ) {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Invaild parameter i to get element!");
        }

        return ret;
    }

    bool get(int i, T& e) const {
        bool ret = true;

        i = mod(i);

        ret = ( (0 <= i) && (i < this->length_) );

        if( ret ) {
            e = list_entry(position(i)->next, Node, head)->value;
        }

        return ret;
    }

    int find(const T& e) const {
        int ret = -1;
        int i = 0;
        list_head* slider = NULL;

        list_for_each(slider, &header_) {
            if( list_entry(slider, Node, head)->value == e ) {
                ret = i;
                break;
            }

            i++;
        }

        return ret;
    }

    int length() const {
        return this->length_;
    }

    void clear() {
        while( this->length_ > 0 ) {
            remove(0);
        }
    }

    bool move(int i, int step = 1) {
        bool ret = (step > 0);

        i = mod(i);

        ret = ret && ( (0 <= i) && (i < this->length_) );

        if( ret ) {
            current_ = position(i)->next;

            this->step_ = step;
        }

        return ret;
    }

    bool end() {
        return (current_ == NULL) || (this->length_ == 0);
    }

    T current() {
        
        if( !end() ) {
            return list_entry(current_, Node, head)->value;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No value at current position!");
        }
    }

    bool next() {
        int i = 0;

        while( (i < this->step_) && !end() ) {
            if( current_ != &header_ ) {
                current_ = current_->next;
                i++;
            } else {
                current_ = current_->next;
            }
        }

        if( current_ == & header_ ) {
            current_ = current_->next;
        }

        return (i == this->step_);
    }

    bool prev() {
        int i = 0;

        while( (i < this->step_) && !end() ) {
            if( current_ != &header_ ) {
                current_ = current_->prev;
                i++;
            } else {
                current_ = current_->prev;
            }
        }

        if( current_ == & header_ ) {
            current_ = current_->prev;
        }

        return(i == this->step_);
    }

    ~DualCircleList() {
        clear();
    }
};

}

#endif