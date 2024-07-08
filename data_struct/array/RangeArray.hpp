/**
 *  @brief: 范围数组类模板
 */

#ifndef _RANGEARRAY_HPP_
#define _RANGEARRAY_HPP_

#include "Array.hpp"

namespace dsalcpp
{

template < typename T >
class RangeArray : public Array<T>
{
protected:
    int lower_;
    int upper_;

public:
    RangeArray(int lower, int upper) {  //O(1)
        lower_ = lower;
        upper_ = upper;

        this->array_ = new T[upper -  lower + 1];
        if( this->array_ == NULL ) {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create RangeArray object");
        }
    }

    RangeArray(const RangeArray<T>& obj) { //O(n)
        int len = obj.length();

        lower_ = obj.lower_;
        upper_ = obj.upper_;
        this->array_ = new T[len];

        for(int i = 0; i < len; i++) {
            this->array_[i] = obj.array_[i];
        }
    }

    bool set(int i, const T& e) {  //O(1)
        bool ret = ((lower_ <= i) && (i <= upper_));

        if( ret ) {
            this->array_[i - lower_] = e;
        }

        return ret;
    }

    bool get(int i, T& e) const { // O(1)
        bool ret = ((lower_ <= i) && (i <= upper_));

        if( ret ) {
            e = this->array_[i - lower_];
        }

        return ret;
    }

    RangeArray<T>& operator= (const RangeArray<T>& obj) { // O(n)
        if( this != &obj ) {
            // 异常安全
            int len = obj.length();
            T* toDel = this->array_;
            T* arr = new T[len];

            for(int i = 0; i < len; i++) {
                arr[i] = obj.array_[i];
            }

            lower_ = obj.lower_;
            upper_ = obj.upper_;

            this->array_ = arr;

            delete[] toDel;
        }  

        return *this;
    }

    T& operator[] (int i) { // O(1)
        if( (lower_ <= i) && (i <= upper_) ) {
            return this->array_[i - lower_];
        } else {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Index is out of bounds");
        }
    }

    T operator[] (int i) const { // O(1)
        return (const_cast<RangeArray<T>&>(*this))[i];
    }

    int lower() const { // O(1)
        return lower_;
    }   

    int upper() const { // O(1)
        return upper_;
    }

    int length() const {  // O(1)
        return upper_ - lower_ + 1;
    }

    ~RangeArray() {
        delete[] this->array_;
    }
};

}

#endif