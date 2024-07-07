/**
 *  @brief: 静态数组类模板
 */

#ifndef _STATIC_ARRAY_HPP_
#define _STATIC_ARRAY_HPP_

#include "Array.hpp"

namespace dsalcpp
{

template < typename T, int N >
class StaticArray : public Array<T> 
{
protected:
    T space_[N];

public:
    StaticArray() { // O(1)
        this->array_ = space_;
    }

    StaticArray(const StaticArray<T, N>& obj) { // O(n)
        this->array_ = space_;

        for (int i = 0; i < N; i++) {
            this->space_[i] = obj.space_[i];
        }
    }

    StaticArray<T, N>& operator= (const StaticArray<T, N> &obj) { // O(n)
        if (this != &obj) {
            for (int i = 0; i < N; i++) {
                this->space_[i] = obj.space_[i];
            }
        }

        return *this;
    }

    int length() const {  // O(1)
        return N;
    }
};

}

#endif
