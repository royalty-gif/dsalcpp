/**
 *  @brief: 动态数组类模板
 */

#ifndef _DYNAMICARRAY_HPP_
#define _DYNAMICARRAY_HPP_

#include "Array.hpp"

namespace dsalcpp
{

template < typename T > 
class DynamicArray : public Array<T>
{
protected:
    int length_;

    T* copy(T* array, int len, int newLen) {
        T* ret = new T[newLen];

        if( ret != NULL ) {
            int size = (len < newLen) ? len : newLen;

            for(int i = 0; i < size; i++) {
                ret[i] = array[i];
            }
        }

        return ret;
    }
    void update(T* array, int length) {
        if( array != NULL ) {
            // 异常安全
            T* temp = this->array_;

            this->array_ = array;
            this->length_ = length;

            delete[] temp;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to update DynamicArray object");
        }
    }
    void init(T* array, int length) {
        if( array != NULL ) {
            this->array_ = array;
            this->length_ = length;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray object");
        }
    }

public:
    DynamicArray(int length = 0) {
        init(new T[length], length);
    }

    DynamicArray(const DynamicArray<T>& obj) {
        init(copy(obj.array_, obj.length_, obj.length_), obj.length_);
    }

    DynamicArray<T>& operator=(const DynamicArray<T>& obj) {
        if( this != &obj ) {
            update(copy(obj.array_, obj.length_, obj.length_), obj.length_);
        }

        return *this;
    }

    int length() const {
        return length_;
    };

    virtual void resize(int length) {
        if( length != length_ ) {
            update(copy(this->array_, length_, length), length);
        }
    }

    ~DynamicArray() {
        delete[] this->array_;
    }

};

}

#endif