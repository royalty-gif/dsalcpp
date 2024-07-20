/**
 *  @brief: 共享指针类模板
 */

#ifndef _SHAREDPOINTER_HPP_
#define _SHAREDPOINTER_HPP_

#include "Pointer.hpp"
#include "Exception.hpp"

namespace dsalcpp
{

template < typename T > 
class SharedPointer : public Pointer<T>
{
protected:
    int* ref_;

    void assign(const SharedPointer<T>& obj) {
        this->ref_ = obj.ref_;
        this->ptr_ = obj.ptr_;

        if( this->ref_ ) {
            (*this->ref_)++;
        }
    }

public:
    SharedPointer(T* p = NULL) : ref_(NULL) {
        if( p != NULL ) {
            ref_ = static_cast<int*>(new int);

            if( ref_ != NULL ) {
                *(this->ref_) = 1;
                this->ptr_ = p;
            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No enough memory to create SharedPointer object ...");
            }
        }
    }

    SharedPointer(const SharedPointer<T>& obj) : Pointer<T>(NULL) {
        assign(obj);
    }

    SharedPointer<T>& operator= (const SharedPointer<T>& obj) {
        if( this != &obj ) {
            clear();
            assign(obj);
        }

        return *this;
    }

    void clear() {
        T* toDel = this->ptr_;
        int* ref = this->ref_;

        this->ptr_ = NULL;
        this->ref_ = NULL;

        if( ref != NULL ) {
            (*ref)--;

            if( *ref == 0 ) {
                delete ref;
                delete toDel;
            }
        }
    }

    ~SharedPointer() {
        clear();
    }
};

template < typename T > 
static bool operator == (const T* l, const SharedPointer<T>& r) {
    return (l == r.get());
}

template < typename T > 
static bool operator != (const T* l, const SharedPointer<T>& r) {
    return (l != r.get());
}

template < typename T > 
static bool operator == (const SharedPointer<T>& l, const T* r) {
    return (l.get() == r);
}

template < typename T > 
static bool operator != (const SharedPointer<T>& l, const T* r) {
    return (l.get() != r);
}

template < typename T > 
static bool operator == (const SharedPointer<T>& l, const SharedPointer<T>& r) {
    return (l.get() == r.get());
}

template < typename T > 
static bool operator != (const SharedPointer<T>& l, const SharedPointer<T>& r) {
    return !(l == r);
}

}

#endif