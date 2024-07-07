/**
 *  @brief  数组类模板基类
 */

#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include "Object.hpp"
#include "Exception.hpp"

namespace dsalcpp 
{

template < typename T > 
class Array : public Object 
{

protected:
    T* array_;

public:
    virtual bool set(int i, const T& e) {  // O(1)
        bool ret = ((0 <= i) && (i < length()));

        if( ret ) {
            array_[i] = e;
        }

        return ret;
    }

    virtual bool get(int i, T& e) const { // O(1)
        bool ret = ((0 <= i) && (i < length()));

        if( ret ) {
            e = array_[i];
        }

        return ret;
    }

    virtual T& operator[] (int i) {  // O(1)
        if( (0 <= i) && (i < length()) ) {
            return array_[i];
        } else {
            THROW_EXCEPTION(IndexOutOfBoundsException, "Paramater i is invalid ...");
        }
    }

    virtual T operator[] (int i) const { // O(1)
        return (const_cast<Array<T>&>(*this))[i];
    }

    T* array() const {
        return array_;
    }

    Array<T>& self() {
        return *this;
    }

    virtual int length() const = 0;

};

}

#endif