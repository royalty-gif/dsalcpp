/**
 *  @brief: 循环链表类模板
 */

#ifndef _CIRCLELIST_HPP_
#define _CIRCLELIST_HPP_

#include "LinkList.hpp"

namespace dsalcpp
{

template <typename T>
class CircleList : public LinkList<T>
{
protected:
    typedef typename LinkList<T>::Node Node;

    int mod(int i) const {
        return (this->length_ == 0) ? 0 : i % this->length_;
    }

    Node* last() const {
        //return this->position(this->length_-1)->next;
        return this->position(this->length_);
    }

    void lastToFirst() const {
        last()->next = this->header_.next;
    }

public:
    bool insert(const T& e) {
        return insert(this->length_, e);
    }

    bool insert(int i, const T& e) {
        bool ret = true;

        i = i % (this->length_ + 1);

        ret = LinkList<T>::insert(i, e);

        if( ret && (i == 0) ) {
            // 如果i为0，即是头节点，则需要将尾节点指向头节点的下一个节点
            lastToFirst();
        }

        return ret;
    }

    bool remove(int i) {
        bool ret  = true;
        
        i = mod(i);

        if( i == 0 ) {
            // i为0表示头节点，则需要将头节点的下一个节点删除
            Node* toDel = this->header_.next;

            if( toDel != NULL ) {
                this->header_.next = toDel->next;
                this->length_--;

                if( this->length_ > 0 ) {
                    // 删除一个节点后，仍需要保持循环的结构
                    lastToFirst();

                    if( this->current_ == toDel ) {
                        this->current_ = toDel->next;
                    }
                } else {
                    this->header_.next = NULL;
                    this->current_ = NULL;
                }

                this->destroy(toDel);
            } else {
                ret = false;
            }
        } else {
            ret = LinkList<T>::remove(i);
        }

        return ret;
    }

    bool set(int i, const T& e) {
        return LinkList<T>::set(mod(i), e);
    }

    bool get(int i, T& e) const {
        return LinkList<T>::get(mod(i), e);
    }

    T get(int i) const {
        return LinkList<T>::get(mod(i));
    }

    int find(const T& e) const {
        int ret = -1;
        Node* slider = this->header_.next;

        for(int i = 0; i < this->length_; i++) {
            if( slider->value == e ) {
                ret = i;
                break;
            }

            slider = slider->next;
        }

        return ret;
    }

    void clear() {
        while( this->length_ > 1 ) {
            remove(1);
        }

        if( this->length_ == 1 ) {
            // 删除到最后一个节点时，删除后做头节点的初始化操作
            Node* toDel = this->header_.next;

            this->header_.next = NULL;
            this->length_ = 0;
            this->current_ = NULL;

            this->destroy(toDel);
        }
    }

    bool move(int i, int step) {
        return LinkList<T>::move(mod(i), step);
    }

    bool end() {
        return (this->length_ == 0) || (this->current_ == NULL);
    }

    ~CircleList() {
        clear();
    }
};

}

#endif