/**
 *  @brief: 动态顺序线性表
 */

#ifndef _DYNAMICLIST_HPP_
#define _DYNAMICLIST_HPP_

#include "SeqList.hpp"

namespace dsalcpp
{

template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    int capacity_;

public:
    DynamicList(int capacity) {
        this->array_ = new T[capacity];

        if( this->array_ != NULL ) {
            this->length_ = 0;
            this->capacity_ = capacity;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicList object");
        }
    }

    int capacity() const {
        return capacity_;
    }

    // 重新设置顺序存储空间的大小
    void resize(int capacity) {
        if( capacity != capacity_ ) {
            T* array = new T[capacity];

            if( array != NULL ) {
                int length = (this->length_ < capacity ? this->length_ : capacity);

                for(int i = 0; i < length; i++) {
                    array[i] = this->array_[i];
                }
                // 异常安全
                T* temp = this->array_;

                this->array_ = array;
                this->capacity_ = capacity;
                this->length_ = length;

                delete[] temp;
            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to resize DynamicList object");
            }
        }
    }

    ~DynamicList() {
        delete[] this->array_;
    }
};

}

#endif
