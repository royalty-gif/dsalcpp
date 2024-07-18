/**
 *  @brief: 指针类模板
 */

#ifndef _POINTER_HPP_
#define _POINTER_HPP_

#include "Object.hpp"

namespace dsalcpp
{

template < typename T >
class Pointer : public Object
{
protected:
    T* ptr_;

public:
    Pointer(T* p = NULL) {
        ptr_ = p;
    }

    T* operator-> () {
        return ptr_;
    } 

    T& operator* () {
        return *ptr_;
    }

    const T& operator* () const {
        return *ptr_;
    }

    const T* operator-> () const {
        return ptr_;
    }

    bool isNull() const {
        return (ptr_ == NULL);
    }

    T* get() const {
        return ptr_;
    }

    ~Pointer() = 0;
};

template < typename T > 
Pointer<T>::~Pointer() {}

}

#endif