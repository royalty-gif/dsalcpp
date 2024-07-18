/**
 *  @brief: 智能指针类模板
 */

#ifndef _SMARTPOINTER_HPP_
#define _SMARTPOINTER_HPP_

#include "Pointer.hpp"

namespace dsalcpp
{
    
template < typename T >
class SmartPointer : public Pointer<T>
{
public:
    SmartPointer(T* p = NULL) : Pointer<T>(p) {}

    SmartPointer(const SmartPointer<T>& obj) {
        this->ptr_ = obj.ptr_;
        const_cast<SmartPointer<T>&>(obj).ptr_ = NULL;
    }

    SmartPointer<T>& operator= (const SmartPointer<T>& obj) {
        if( this != &obj ) {
            T* p = this->ptr_;

            this->ptr_ = obj.ptr_;

            const_cast<SmartPointer<T>&>(obj).ptr_ = NULL;

            delete p;
        }

        return *this;
    }

    ~SmartPointer() {
        delete this->ptr_;
    }
};

}

#endif